#pragma once
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Media{
    public:
		Media();
		~Media();
		void setTitle(char* title);
		void setYear(int year);
		char* getTitle();
		int getYear();
		virtual const char* getType();
		virtual void print();
		virtual void promptInput();
	private:
		char title[100];
		int year;
};