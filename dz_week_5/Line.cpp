#include "Line.h"
Element::Element(char data) {
	this->data = data;
	this->next = nullptr;
	this->prev = nullptr;
}
Line::Line() {
	this->first = nullptr;
}
void Line::Add(char data) {
	if (this->first == nullptr) {
		this->first = new Element(data);
	}
	else
	{
		Element* temp = this->first;
		while (temp->next!=nullptr)
		{
			temp = temp->next;
		}
		temp->next = new Element(data);
		temp->next->prev = temp;
	}
}
void Line::Remove_first() {
	if (this->first->next==nullptr)
	{
		Element* temp = this->first;
		delete temp;
		temp = nullptr;
		this->first = temp;
	}
	else {
		Element* temp = this->first;
		temp = temp->next;
		delete temp->prev;
		temp->prev = nullptr;
		this->first = temp;
	}
}
void Line::Remove_all() {
	while (this->first!=nullptr)
	{
		this->Remove_first();
	}
}
bool Line::isEmpty() {
	if (this->first == nullptr) {
		return true;
	}
	return false;
}
Element** Line::clone_line(Line& a) {
	if (this->first != nullptr) {
		this->Remove_all();
		Element* temp = a.first;
		while (temp!=nullptr)
		{
			this->Add(temp->data);
			temp = temp->next;
		}
	}
	else
	{
		Element* temp = a.first;
		while (temp != nullptr)
		{
			this->Add(temp->data);
			temp = temp->next;
		}
	}
	return &this->first;
}
Element** Line::operator +(Line& a) {
	Line *newTemp = this;
	Element* temp = a.first;
	while (temp!=nullptr)
	{
		newTemp->Add(temp->data);
		temp = temp->next;
	}
	return &newTemp->first;
}
Element** Line::operator * (Line& a){
	Line newtemp;
	Element* temp_this = this->first;
	Element* temp_a = a.first;
	while (temp_this!=nullptr)
	{
		while (temp_a!=nullptr) {
			if (temp_this->data == temp_a->data) {
				newtemp.Add(temp_this->data);
			}
			temp_a = temp_a->next;
		}
		temp_a = a.first;
		temp_this = temp_this->next;
	}
	return &newtemp.first;
}
void Line::Show_line() {
	Element* temp = this->first;
	while (temp != nullptr) {
		std::cout << temp->data << std::endl;
		temp = temp->next;
	}
}
