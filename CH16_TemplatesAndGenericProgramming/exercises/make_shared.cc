#include <memory>
#include <string>
#include <iostream>

namespace cplusplus_primer {

// copy from gcc
template<typename T, typename... Args>
inline std::shared_ptr<T> make_shared(Args&&... args)
{
	using T_nc = typename std::remove_const<T>::type;
	return std::allocate_shared<T>(std::allocator<T_nc>(), std::forward<Args>(args)...);
}

// template <typename T, typename... Args>
// std::shared_ptr<T> make_shared(Args&&... args)
// {
// 	return std::shared_ptr<T>(new T(std::forward<Args>(args)...));
// }

}

class Foo {
public:
	Foo() = default;
	Foo(int b): bar(b) { }

	int bar = 0;
};

int main(int argc, char const *argv[])
{
	auto num = cplusplus_primer::make_shared<int>(42);
	std::cout << *num << std::endl;

	// basic_string(size_type count, CharT ch, const Allocator& alloc = Allocator());
	auto str = cplusplus_primer::make_shared<std::string>(10, 'c');
	std::cout << *str << std::endl;

	auto foo = cplusplus_primer::make_shared<Foo>(99);
	std::cout << foo->bar << std::endl;

	return 0;
}