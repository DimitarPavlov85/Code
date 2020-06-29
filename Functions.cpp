#include"Functions.h"
void PrintShortMessage(const std::string& message){
	std::cout << message << std::endl;
}
void PrintMainMenu() {
	PrintShortMessage("----Menu----");
	PrintShortMessage("1.Add Person");
	PrintShortMessage("2.Add data in person");
	PrintShortMessage("3.Print data");
	PrintShortMessage("e. Exit");
}
std::string WriteDiseases() {
	std::string InputDiseases;
	std::cin.ignore();
	std::cin.clear();
	std::cout << "Please write diseases: ";
	getline(std::cin, InputDiseases);
	std::istringstream in(InputDiseases);
	std::string currentword;
	std::ostringstream out;
	while (in >> currentword) {
		out << currentword;
	}
	return out.str();
}
void CreateProfil(std::string& _firstName, std::string& _LastName,
	std::string& _EGN, std::vector<std::string>& _CollectFromDiseases) {
	PrintShortMessage("Please write first name: ");
	std::cin >> _firstName;
	PrintShortMessage("Please write last name: ");
	std::cin >> _LastName;
	PrintShortMessage("Please write EGN: ");
	std::cin >> _EGN;
	std::string diseases = WriteDiseases();
	_CollectFromDiseases.push_back(diseases);
}


std::string IsEGNExist(const std::unordered_set<std::string>& _dataofEGN) {
	std::string InputEGN;
	std::cin >> InputEGN;

	if (_dataofEGN.find(InputEGN) != _dataofEGN.end()) {
		return InputEGN;
	}
	else {
		 PrintShortMessage("Person with this EGN doesn't exist!!!");
		 return InputEGN = "";
	}
}
 
	
std::string AddNewData(std::string &NewDiseases) {
	
	PrintShortMessage("Please write a new data:");
	std::cin >> NewDiseases;
	return NewDiseases;
}


