/****************************************************************************
 *
 *   Copyright (c) 2017 Henry Zhang. All rights reserved.
 *
 ****************************************************************************/

/**
 * @file ex16_11.cc
 *
 * The following definition of List is incorrect. How would you fix it?
 * as commented below.
 *
 * @author Herny Zhang	<zhanghui629@gmail.com>
 */


// template <typename elemType>
// class ListItem;

// template <typename elemType>
// class List
// {
// public:
// 	List<elemType>();
// 	List<elemType>(const List<elemType> &);
// 	List<elemType>& operator=(const List<elemType> &);
// 	~List();
// 	void insert(ListItem<elemType> *ptr, elemType value);
// 	//                 ^^^^^^^^^^  -- template is not a type, the type must be provided

// private:
// 	ListItem<elemType> *front, *end;
// 	//      ^^^^^^^^ -- template is not a type, the type must be provided
// };


template <typename elemType>
class ListItem;

template <typename elemType>
class List
{
public:
	List();
	List(const List<elemType> &);
	List& operator=(const List<elemType> &);
	~List();
	void insert(ListItem<elemType>* ptr, elemType value);
	//                 ^^^^^^^^^^  -- template is not a type, the type must be provided

private:
	ListItem<elemType>* front;
	ListItem<elemType>* end;
	//      ^^^^^^^^ -- template is not a type, the type must be provided
};

int main(int argc, char const *argv[])
{
	// List<int> list;
	// Not instantiate template class,
	// So we could compile this codes.
	return 0;
}
