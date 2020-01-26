#pragma once
#include "dependies.h"
class Top {
		char data;
		Top* next_in_stack;
		friend class Stack_list;
public:
		Top(char Data);

};
class Stack_list
{
	void stack_grow();//done
	friend class Top;
public:
	int lenght;
	Top* first;

	Stack_list();//done
	Stack_list(const Stack_list &a);//done
	Stack_list(int lenght);//done
	void Add(char data);//done
	void Remove_last();//done
	void Remove_all();//done
	bool isEmpty();//done
	bool isFull();//done
	Stack_list& operator=(const Stack_list& a);//done
    Top** Clone_shift( Stack_list& a);//done
	Top** operator +(Stack_list& a);//done
	Top** operator *(Stack_list& a);//done
	char Get_top();//done

};

