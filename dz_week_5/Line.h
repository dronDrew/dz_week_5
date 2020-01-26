#pragma once
#include"dependies.h"
class Element {
	friend class Line;
	char data;
	Element* prev;
	Element* next;
public:
	Element(char data);
};

class Line
{
	//friend class Element;
	
public:
	Element* first;
	Line();
	void Add(char data);//done
	void Remove_first();//done
	void Remove_all();//done
	bool isEmpty();//done
	void Show_line();
	Element** clone_line(Line& a);//done
	Element** operator +(Line& a);//done
	Element** operator * (Line& a);//done

};

