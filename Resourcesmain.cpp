#include"Functions.h"
#include"Persons.h"


int main()
{
	PrintShortMessage("Hello this is a small project to manage people with disadvantaged health situation!!!");

	std::vector<Persons>DataOfPersons;
	std::unordered_set<std::string>DataOfEGN;

	bool IsRun = true;

	while (IsRun) {

		PrintShortMessage("Please make a choice (1, 2, 3 or e) !!!");
		PrintMainMenu();
		char Choise = ' ';
	    std::cin >> Choise;
		Choise = tolower(Choise);
		 
		if (Choise == '1') {
			
			std::string firstname;
			std::string lastname;
			std::string EGN;
			std::vector<std::string>collectfromdiseases;

			CreateProfil(firstname, lastname, EGN, collectfromdiseases);

			DataOfPersons.emplace_back(firstname, lastname, EGN, collectfromdiseases);
			DataOfEGN.insert(EGN);

			IsRun = true;
		}
		else if (Choise == '2') {

			std::cout << "If you want to add new diseases in person please write correct EGN: " << std::endl;

			std::string inputEGN = IsEGNExist(DataOfEGN);

			if (inputEGN == "") {
				IsRun = true;
			}
			else {
				std::string NewDiseases;
				AddNewData(NewDiseases);

				for (size_t i = 0; i < DataOfPersons.size(); ++i) {
					if (DataOfPersons[i].GetEGN() == inputEGN) {
						DataOfPersons[i].Setdiseases(NewDiseases);
					}
				}
				IsRun = true;
			}
		}
		else if (Choise == '3') {

			print(DataOfPersons);
			IsRun = true;
		}
		else if (Choise == 'e') {
			std::cout << "Close the program" << std::endl;
			IsRun = false;
		}
		else {
			PrintShortMessage("Wrong input Please try again: ");
			IsRun = true;
		}
	}
}

