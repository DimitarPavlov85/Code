#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include<string>
#include <iostream>
#include<vector>
#include<sstream>
#include"Persons.h"
#include<unordered_set>

void PrintShortMessage(const std::string & message);

void PrintMainMenu();

std::string WriteDiseases();

std::string IsEGNExist( const std::unordered_set<std::string>& _dataofEGN);

void CreateProfil(std::string & _firstName, std::string &_LastName, 
	              std::string &_EGN, std::vector<std::string> &_CollectFromDiseases);

std::string AddNewData(std::string &NewData);

template<typename T>
void print(const T& current) {
	for (size_t i = 0; i < current.size(); i++) {
        std::cout << current[i];
	}
	
}

#endif 
