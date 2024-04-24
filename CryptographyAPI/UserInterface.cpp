#ifndef USERINTERFACE_H
#define USERINTERFACE_H
#include "Decrypt.h"
#include "Encrypt.h"

class UserInterface
{
public:
	void menu()
	{
		do {
			std::cout << "Which would you like to do: " << std::endl;
			std::cout << "1.Encrypt: " << std::endl;
			std::cout << "2.Decrypt: " << std::endl;
			int choice;
			std::cin >> choice;

			if (choice != 1 || choice != 2) {
				std::cout << "Invalid selection" << std::endl;
				break;
			}
		}

	}
};


#endif
