#include <string>
#include <iostream>

// template<unsigned H, unsigned W>
// class Screen;

// template<unsigned H, unsigned W>
// std::ostream& operator<<(std::ostream& os, const Screen<H, W>& s);
// template<unsigned H, unsigned W>
// std::istream& operator>>(std::istream& is, Screen<H, W>& s);

template<unsigned H, unsigned W>
class Screen {
	friend std::ostream& operator<<(std::ostream& os, const Screen<H, W>& s)
	{
		for (auto h = 0; h < s.height; ++h)
			os << s.contents.substr(0, W) << std::endl;
		return os;
	}

	friend std::istream& operator>>(std::istream& is, Screen<H, W>& s)
	{
		char a;
		is >> a;
		std::string temp(H*W, a);
		s.contents = std::move(temp);
		return is;
	}

public:
	using pos = std::string::size_type;
	Screen() = default;  // needed because Screen has another constructor
	// cursor initialized to 0 by its in-class initializer
	Screen(char c) : contents(H * W, c) { }

	// implicitly inline
	// get the character at the cursor
	char get() const
	{
		return contents[cursor];
	}

	// explicitly inline
	inline char get(pos ht, pos wd) const;
	Screen& clear(char = bkground);
private:
	static const char bkground = ' ';
public:
	Screen& move(pos r, pos c);      // can be made inline later
	Screen& set(char);
	Screen& set(pos, pos, char);
	// display overloaded on whether the object is const or not
	Screen& display(std::ostream& os)
	{
		do_display(os);
		return *this;
	}
	const Screen& display(std::ostream& os) const
	{
		do_display(os);
		return *this;
	}
private:
	// function to do the work of displaying a Screen
	void do_display(std::ostream& os) const { os << contents; }
	pos cursor = 0;
	pos height = H;
	pos width = W;
	std::string contents;
};

template <unsigned H, unsigned W>
Screen<H, W>& Screen<H, W>::clear(char c)
{
	contents = std::string(height*width, c);
	return *this;
}

// we can specify inline on the definition
template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::move(pos r, pos c)
{
	pos row = r * width; // compute the row location
	cursor = row + c;    // move cursor to the column within that row
	return *this;        // return this object as an lvalue
}

template <unsigned H, unsigned W>
char Screen<H, W>::get(pos r, pos c) const // declared as inline in the class
{
	pos row = r * width;      // compute row location
	return contents[row + c]; // return character at the given column
}

template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::set(char c)
{
	contents[cursor] = c; // set the new value at the current cursor location
	return *this;         // return this object as an lvalue
}

template <unsigned H, unsigned W>
inline Screen<H, W>& Screen<H, W>::set(pos r, pos col, char ch)
{
	contents[r*width + col] = ch;  // set specified location to given value
	return *this;                  // return this object as an lvalue
}

// template <unsigned H, unsigned W>
// std::ostream& operator<<(std::ostream& os, const Screen<H, W>& s)
// {
// 	for (auto h = 0; h < s.height; ++h)
// 		os << s.contents.substr(0, W) << std::endl;
// 	return os;
// }

// template <unsigned H, unsigned W>
// std::istream& operator>>(std::istream& is, const Screen<H, W>& s)
// {
// 	char a;
// 	is >> a;
// 	std::string temp(H*W, a);
// 	s.contents = std::move(temp);
// 	return is;
// }