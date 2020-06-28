#ifndef PERSONS_H
#define PERSONS_H
#include"Functions.h"
#include<unordered_set>
class Persons
{
public:
	Persons(std::string _firstname, std::string _lastname,std::string EGN, std::vector<std::string>diseases);
	std::string GetEGN()const;

	std::vector<std::string> Setdiseases(const std::string& newdata);

	friend std::ostream& operator<<(std::ostream& out, const Persons& current);
   
private:
	std::string firstname;
	std::string lastname;
	const std::string EGN;
	std::vector<std::string>diseases;
	
};

#endif 