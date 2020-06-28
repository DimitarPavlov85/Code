#include "Persons.h"
#include"Functions.h"

Persons::Persons(std::string _firstname, std::string _lastname,std::string _EGN, std::vector<std::string>_diseases)
	:firstname(_firstname),lastname(_lastname),EGN(_EGN),diseases(_diseases)
{
	printshortmessage("Your data is saved!!! ");
}
std::string Persons::GetEGN()const {
	return this->EGN;
}

std::vector<std::string>Persons:: Setdiseases(const std::string& newdata) {
	this->diseases.emplace_back(newdata);
	return diseases;
}

std::ostream& operator<<(std::ostream& out, const Persons& current) {
	out << current.firstname << " " << current.lastname<<" ";
	for (size_t i = 0; i < current.diseases.size(); i++) {
		out << current.diseases[i]<<" ";
	}
	out << std::endl;
	return out;
 }