#include <iostream>
#include "Encrypt.h"
#include "Decrypt.h"

int main(void)
{
	Encrypt e;
	// replace these with a text file you want to encrypt
	// make sure the files are in the same folder as your code
	// try to change this to get user input using the GUI
	e.appendFile("Testing1.txt"); 
	e.appendFile("Testing2.txt");
	e.encryptAndSave();

	Decrypt d;
	d.setKey(e.getKey());

	std::vector<std::string> encryptedNames = e.getEncryptedFileNames();
	// try to display these in the GUI
	for (const auto& name : encryptedNames)
	{
		d.appendFile("Encrypted_" + name);
		d.appendFile("Encrypted_" + name);
	}

	d.decryptAndSaveAll();
	return 0;   
}