#include"Functions.h"
#include"Persons.h"


int main()
{
	printshortmessage("Hello this is a small project to manage people with disadvantaged health situation!!!");
	PrintMainMenu();
	printshortmessage("Please make a choice (1, 2, 3 or e) !!!");

	std::vector<Persons>dataofpersons;
	std::unordered_set<std::string>dataofEGN;

    bool inputdata=true;

	char choice = ' ';
	std::cin >> choice;

	while (inputdata) {
		if (choice == 'E') {
			choice = tolower(choice);
		}
		if (choice == '1') {
			printshortmessage("Plase write first name: ");

			std::string firstname;
			std::cin >> firstname;
			printshortmessage("Plase write last name: ");

			std::string lastname;
			std::cin >> lastname;
			printshortmessage("Plase write EGN: ");

			std::string EGN;
			std::cin >> EGN;
			std::string diseases = Writediseases();

			std::vector<std::string>collectfromdiseases;
			collectfromdiseases.push_back(diseases);
			
			dataofpersons.emplace_back(firstname, lastname,EGN, collectfromdiseases);
			dataofEGN.insert(EGN);
			inputdata = true;
			std::cout << std::endl;

			printshortmessage("Please make a choice (1, 2, 3 or e) !!!");
			PrintMainMenu();
			std::cin >> choice;
		}
		else if (choice == '2') {
			
			std::cout << "If you want to add new diseases in person please write correct EGN: " << std::endl;

			std::string inputEGN=checkforegn(dataofEGN);
			if (inputEGN == "false") {
              inputdata = true;

			  PrintMainMenu();
			  std::cin >> choice;
			}
			else {
				std::string newdiseases;
				printshortmessage("Please write a new data:");
				std::cin >> newdiseases;
				for (size_t i = 0; i < dataofpersons.size(); ++i) {
					if (dataofpersons[i].GetEGN() == inputEGN) {
						dataofpersons[i].Setdiseases(newdiseases);
					}
				}
				inputdata = true;
				PrintMainMenu();
				std::cin >> choice;
			}
			
		}
		else if (choice == '3') {
			print(dataofpersons);
			inputdata = true;
			PrintMainMenu();
			std::cin >> choice;
		}
		else if (choice == 'e') {
			std::cout << "Close the program" << std::endl;
			inputdata = false;
		}
		else {
			printshortmessage("Wrong input Please try again: ");
			std::cin >> choice;
			inputdata = true;
		}
	}

}

