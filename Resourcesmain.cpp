#include"Functions.h"
#include"Persons.h"


int main()
{
	PrintShortMessage("Hello this is a small project to manage people with disadvantaged health situation!!!");
	PrintMainMenu();
	PrintShortMessage("Please make a choice (1, 2, 3 or e) !!!");

	std::vector<Persons>DataOfPersons;
	std::unordered_set<std::string>DataOfEGN;

	bool IsRun = true;

	char Choise = ' ';
	std::cin >> Choise;

	while (IsRun) {

		Choise = tolower(Choise);

		if (Choise == '1') {
			PrintShortMessage("Please write first name: ");

			std::string firstname;
			std::cin >> firstname;
			PrintShortMessage("Please write last name: ");

			std::string lastname;
			std::cin >> lastname;
			PrintShortMessage("Please write EGN: ");

			std::string EGN;
			std::cin >> EGN;
			std::string diseases = WriteDiseases();

			std::vector<std::string>collectfromdiseases;
			collectfromdiseases.push_back(diseases);

			DataOfPersons.emplace_back(firstname, lastname, EGN, collectfromdiseases);
			DataOfEGN.insert(EGN);
			IsRun = true;
			std::cout << std::endl;

			PrintShortMessage("Please make a choice (1, 2, 3 or e) !!!");
			PrintMainMenu();
			std::cin >> Choise;
		}
		else if (Choise == '2') {

			std::cout << "If you want to add new diseases in person please write correct EGN: " << std::endl;

			std::string inputEGN = EGNExist(DataOfEGN);

			if (inputEGN == "") {
				IsRun = true;

				PrintMainMenu();
				std::cin >> Choise;
			}
			else {
				std::string NewDiseases;
				PrintShortMessage("Please write a new data:");
				std::cin >> NewDiseases;
				for (size_t i = 0; i < DataOfPersons.size(); ++i) {
					if (DataOfPersons[i].GetEGN() == inputEGN) {
						DataOfPersons[i].Setdiseases(NewDiseases);
					}
				}
				IsRun = true;
				PrintMainMenu();
				std::cin >> Choise;
			}

		}
		else if (Choise == '3') {
			print(DataOfPersons);
			IsRun = true;
			PrintMainMenu();
			std::cin >> Choise;
		}
		else if (Choise == 'e') {
			std::cout << "Close the program" << std::endl;
			IsRun = false;
		}
		else {
			PrintShortMessage("Wrong input Please try again: ");
			std::cin >> Choise;
			IsRun = true;
		}
	}

}

