#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<string>
#include <iostream>
#include<vector>
#include<sstream>
#include"Persons.h"
#include<unordered_set>

void printshortmessage(const std::string & message);

void PrintMainMenu();

std::string Writediseases();

std::string checkforegn( const std::unordered_set<std::string>& _dataofEGN);

template<typename T>
void print(const T& current) {
	for (size_t i = 0; i < current.size(); i++) {
        std::cout << current[i];
	}
	
}

#endif 
