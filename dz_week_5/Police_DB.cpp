#include "Police_DB.h"
Ticket::Ticket(std::string problem) {
	this->problem = problem;
	this->next = nullptr;
}
Police_DB::Police_DB() {
	this->root == nullptr;
}
Police_DB::car::car(int number) {
	this->number = number;
	this->problems = nullptr;
	this->biger = nullptr;
	this->lower = nullptr;
}
bool Police_DB::Add_car(int number) {
	if (this->root == nullptr) {
		this->root = new car(number);
		return true;
	}
	else
	{
		car* temp = this->root;
		if (temp->number<number&&temp->biger==nullptr)
		{
			temp->biger = new car(number);
			return true;

		}
		while (temp->lower!=nullptr||temp->biger!=nullptr)
		{
			if (temp->number > number) {
				temp = temp->lower;
			}
			else
			{
				temp = temp->biger;
			}

		}
		if (temp->number > number) {
			temp->lower = new car(number);
			return true;
		}
		else
		{
			temp->biger = new car(number);
			return true;
		}
	}
}
void Police_DB::Add_ticket(int number,std::string prob) {
	car* temp = this->root;
	while (temp->number!=number)
	{
		if (temp->number > number) {
			temp = temp->lower;
		}
		else
		{
			temp = temp->biger;
		}
	}
	if (temp->problems==nullptr) {
		temp->problems = new Ticket(prob);
	}
	else
	{
		Ticket* temp_2 = temp->problems;
		while (temp_2->next!=nullptr) {
			temp_2 = temp_2->next;
		}
		temp_2->next = new Ticket(prob);
		
	}
}
bool Police_DB::Search_and_save_info(int number) {
	std::ofstream file;
	file.open("info_about_tickets.txt");
	if (file.is_open()) {
		car* temp = this->root;
		while (temp->number != number)
		{
			if (temp->number > number) {
				temp = temp->lower;
			}
			else
			{
				temp = temp->biger;
			}
		}
		file << "Number of car :";
		file << temp->number<<std::endl;
		if (temp->problems == nullptr) {
			file << "No tickets" << std::endl;
		}
		else
		{
			Ticket* temp_2 = temp->problems;
			while (temp_2!= nullptr) {
				file << temp_2->problem << std::endl;
				temp_2 = temp_2->next;
			}

		}
		return true;
	}
	file.close();
	return false;
}
void Police_DB::Save_all_police_DB(car &a) {
	std::ofstream file;
	file.open("info_about_tickets.txt",std::ios::app);
	if (file.is_open()) {
		car* temp = &a;
		if (temp) {
			file << "Number of car :";
			file << a.number << std::endl;
			if (a.problems == nullptr) {
				file << "No tickets" << std::endl;
			}
			else
			{
				Ticket* temp_2 = a.problems;
				while (temp_2 != nullptr) {
					file << temp_2->problem << std::endl;
					temp_2 = temp_2->next;
				}

			}
			this->Save_all_police_DB(*temp->biger);
			this->Save_all_police_DB(*temp->lower);
		}
			
	}
	file.close();
}
void Police_DB::Save_diapason(int number_from, int number_to) {
	std::ofstream file;
	file.open("info_about_tickets.txt");
	if (file.is_open()) {
		car* temp = this->root;
		if ((temp->number > number_from)&& (temp->number < number_to)) {
			while (temp->number != number_from)
			{
				if (temp->number > number_from) {
					temp = temp->lower;
				}
				else
				{
					temp = temp->biger;
				}
				file << "Number of car :";
				file << temp->number << std::endl;
				if (temp->problems == nullptr) {
					file << "No tickets" << std::endl;
				}
				else
				{
					Ticket* temp_2 = temp->problems;
					while (temp_2 != nullptr) {
						file << temp_2->problem << std::endl;
						temp_2 = temp_2->next;
					}

				}
			}
		    temp = this->root;
			while (temp->number != number_to)
			{
				
				if (temp->number > number_to) {
					temp = temp->lower;
				}
				else
				{
					temp = temp->biger;
				}
				file << "Number of car :";
				file << temp->number << std::endl;
				if (temp->problems == nullptr) {
					file << "No tickets" << std::endl;
				}
				else
				{
					Ticket* temp_2 = temp->problems;
					while (temp_2 != nullptr) {
						file << temp_2->problem << std::endl;
						temp_2 = temp_2->next;
					}

				}
			}

			
			file.close();
		}
	}
}