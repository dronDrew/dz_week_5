#include "Stack_list.h"
Top::Top(char data) {
	this->data = data;
	this->next_in_stack = nullptr;
}
Stack_list::Stack_list() {
	this->lenght = 8;
	this->first = nullptr;

}
Stack_list::Stack_list(const Stack_list& a) {
	this->lenght = a.lenght;
	Top* temp = a.first;
	while (temp!=nullptr)
	{
		this->Add(temp->data);
		temp=temp->next_in_stack;
	}
}
Stack_list::Stack_list(int Lenght) {
	this->lenght = Lenght;
	this->first = nullptr;
}
void Stack_list::Add(char data) {
	if (this->lenght > 0) {
		if (this->first == nullptr)
		{
			first = new Top(data);
			this->lenght--;
		}
		else
		{
			Top* temp = this->first;
			while (temp->next_in_stack != nullptr)
			{
				temp = temp->next_in_stack;
			}
			temp->next_in_stack = new Top(data);
			this->lenght--;
		}
	}
	else
	{
		this->stack_grow();
		Top* temp = this->first;
		while (temp->next_in_stack != nullptr)
		{
			temp = temp->next_in_stack;
		}
		temp->next_in_stack = new Top(data);
		this->lenght--;
	}
}
void Stack_list::Remove_last() {
	if (this->first->next_in_stack == nullptr) {
		Top* temp = this->first;
		delete temp->next_in_stack;
		temp->next_in_stack = nullptr;
		this->lenght++;
	}
	else
	{
		Top* temp = this->first;
		while (temp->next_in_stack->next_in_stack != nullptr)
		{
			temp = temp->next_in_stack;
		}
		delete temp->next_in_stack;
		temp->next_in_stack = nullptr;
		this->lenght++;
	}
}
void Stack_list::stack_grow() {
	this->lenght++;
}
void Stack_list::Remove_all() {
	if (this->first == nullptr) {
	}
	else if (this->first->next_in_stack == nullptr) {
		Top* temp = this->first;
		delete temp;
		temp = nullptr;
		this->first = temp;
		this->lenght = 8;
	}
	else
	{
		while (this->first->next_in_stack != nullptr)
		{
			this->Remove_last();
		}
		if (this->first->next_in_stack == nullptr) {
			Top* temp = this->first;
			delete temp;
			temp = nullptr;
			this->first = temp;
		}
		this->lenght = 8;
	}
}
bool Stack_list::isEmpty() {
	if (this->first==nullptr) {
		return true;
	}
	else
	{
		return false;
	}
}
bool Stack_list::isFull() {
	if (this->lenght == 0) {
		return true;
	}
	else
	{
		return false;
	}
}
Stack_list& Stack_list::operator=(const Stack_list& a) {
	if (this->first == nullptr) {
		this->lenght = a.lenght;
		Top* temp = a.first;
		while (temp != nullptr)
		{
			this->Add(temp->data);
			temp = temp->next_in_stack;
		}
	}
	else
	{
		this->Remove_all();
		this->lenght = a.lenght;
		Top* temp = a.first;
		while (temp != nullptr)
		{
			this->Add(temp->data);
			temp = temp->next_in_stack;
		}
	}
	return *this;
}
Top** Stack_list::Clone_shift(Stack_list& a) {
	if (this->first == nullptr) {
		this->lenght = a.lenght;
		Top* temp = a.first;
		while (temp != nullptr)
		{
			this->Add(temp->data);
			temp = temp->next_in_stack;
		}
		return &a.first;
	}
	else
	{
		this->Remove_all();
		this->lenght = a.lenght;
		Top* temp = a.first;
		while (temp != nullptr)
		{
			this->Add(temp->data);
			temp = temp->next_in_stack;
		}
		return &a.first;
	}
}
Top** Stack_list::operator +(Stack_list& a) {
	Top* temp = a.first;
	while (temp != nullptr)
	{
		this->Add(temp->data);
		temp = temp->next_in_stack;
	}
	return &a.first;
}
Top** Stack_list::operator *(Stack_list& a) {
	Stack_list NewList;
	Top* this_point = this->first;
	Top* a_point = a.first;
	while (this_point!=nullptr)
	{
		while (a_point!=nullptr)
		{
			if (this->first->data == a_point->data) {
				NewList.Add(this->first->data);
			}
			a_point = a_point->next_in_stack;
		}
		this_point = this_point->next_in_stack;
		a_point = a.first;
	}
	return &NewList.first;

}
char Stack_list::Get_top() {
	if (this->first == nullptr) {
		return '0';
	}
	Top* temp = this->first;
	while (temp->next_in_stack!=nullptr)
	{
		temp = temp->next_in_stack;
	}
	return temp->data;
}