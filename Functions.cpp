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
std::string Writediseases() {
	std::string inputdiseases;
	std::cin.ignore();
	std::cin.clear();
	std::cout << "Please write diseases: ";
	getline(std::cin, inputdiseases);
	std::istringstream in(inputdiseases);
	std::string currentword;
	std::ostringstream out;
	while (in >> currentword) {
		out << currentword;
	}
	return out.str();
}
std::string checkforegn(const std::unordered_set<std::string>& _dataofEGN) {
	std::string inputEGN;
	std::cin >> inputEGN;

	if (_dataofEGN.find(inputEGN) != _dataofEGN.end()) {
		return inputEGN;
	}
	else {
		 PrintShortMessage("Person with this EGN doesn't exist!!!");
		 return inputEGN = "false";
	}

	
}
