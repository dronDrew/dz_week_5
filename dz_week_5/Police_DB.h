#pragma once
#include "dependies.h"
class Ticket {
	friend class Police_DB;
	std::string problem;
	Ticket* next;
public:
	Ticket(std ::string problem);
};
class Police_DB {
	class car {
	public:
		int number;
		Ticket* problems;
		car* biger;
		car* lower;
		car(int number);
	};
public:
	car* root;
	Police_DB();
	bool Add_car(int number);
	void Add_ticket(int number,std::string prob);
	bool Search_and_save_info(int number);
	void Save_all_police_DB(car &root);
	void Save_diapason(int number_from, int number_to);
};