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
std::string EGNExist(const std::unordered_set<std::string>& _dataofEGN) {
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

