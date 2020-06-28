#include"Functions.h"
#include"Persons.h"


int main()
{
	PrintShortMessage("Hello this is a small project to manage people with disadvantaged health situation!!!");
	PrintMainMenu();
	PrintShortMessage("Please make a choice (1, 2, 3 or e) !!!");

	std::vector<Persons>DataOfPersons;
	std::unordered_set<std::string>DataOfEGN;

    bool inputdata = true;

	char choise = ' ';
	std::cin >> choise;

	while (inputdata) {
		
			choise = tolower(choise);
		
		if (choise == '1') {
			PrintShortMessage("Plase write first name: ");

			std::string firstname;
			std::cin >> firstname;
			PrintShortMessage("Plase write last name: ");

			std::string lastname;
			std::cin >> lastname;
			PrintShortMessage("Plase write EGN: ");

			std::string EGN;
			std::cin >> EGN;
			std::string diseases = WriteDiseases();

			std::vector<std::string>collectfromdiseases;
			collectfromdiseases.push_back(diseases);
			
			DataOfPersons.emplace_back(firstname, lastname,EGN, collectfromdiseases);
			DataOfEGN.insert(EGN);
			inputdata = true;
			std::cout << std::endl;

			PrintShortMessage("Please make a choice (1, 2, 3 or e) !!!");
			PrintMainMenu();
			std::cin >> choise;
		}
		else if (choise == '2') {
			
			std::cout << "If you want to add new diseases in person please write correct EGN: " << std::endl;

			std::string inputEGN=checkforegn(DataOfEGN);
			if (inputEGN == "false") {
              inputdata = true;

			  PrintMainMenu();
			  std::cin >> choise;
			}
			else {
				std::string newdiseases;
				PrintShortMessage("Please write a new data:");
				std::cin >> newdiseases;
				for (size_t i = 0; i < DataOfPersons.size(); ++i) {
					if (DataOfPersons[i].GetEGN() == inputEGN) {
						DataOfPersons[i].Setdiseases(newdiseases);
					}
				}
				inputdata = true;
				PrintMainMenu();
				std::cin >> choise;
			}
			
		}
		else if (choise == '3') {
			print(DataOfPersons);
			inputdata = true;
			PrintMainMenu();
			std::cin >> choise;
		}
		else if (choise == 'e') {
			std::cout << "Close the program" << std::endl;
			inputdata = false;
		}
		else {
			PrintShortMessage("Wrong input Please try again: ");
			std::cin >> choise;
			inputdata = true;
		}
	}

}

