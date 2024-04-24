#include <iostream>
#include <string>
#include "Encrypt.h"
#include "Decrypt.h"
#include "Account.h"

int main() {
    int select = 0;
    bool isAuthenticated = false;

    do {
        std::cout << "Make a selection:\n";
        std::cout << "1 - Create an account\n";
        std::cout << "2 - Login\n";
        std::cin >> select;

        // Clear the input buffer to handle the newline character
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (select != 1 && select != 2);

    Account a;

    switch (select) {
    case 1:
        a.createAccount();
        isAuthenticated = a.login();
        break;
    case 2:
        isAuthenticated = a.login();
        break;
    default:
        std::cout << "Invalid selection\n";
    }

    if (isAuthenticated) {
        Encrypt e;
        Decrypt d;
        std::string fileName;

        // Get the file name from the user to encrypt
        std::cout << "Enter the name of the file you want to encrypt: ";
        std::getline(std::cin, fileName);
        e.appendFile(fileName);

        // Encrypt and save the file
        e.encryptAndSave();

        // Setup decrypter with the same key
        d.setKey(e.getKey());
        std::vector<std::string> encryptedNames = e.getEncryptedFileNames();

        for (const auto& name : encryptedNames) {
            d.appendFile("Encrypted_" + name);
        }

        // Decrypt all encrypted files
        d.decryptAndSaveAll();

        std::cout << "Encryption and decryption completed successfully.\n";
    }
    else {
        std::cout << "Login failed or no actions performed.\n";
    }

    return 0;
}
