/*
* Name: Mansi Patel
* Purpose: The purpose of this program is to do the caesarcipher for specified input or output files/streams using the IO redirection.  
			- Ex.: $ ./caesar -e 3 < f1.txt > f2.txt
				   $ ./caesar -d 3 < f3.txt > f3.txt
* Pseducode/ Program outline logic:
			- user input in cmd for shift and input/output file and error check on it
			- decrypt the message for [A-Z,A-z,0-9]
			- logic is in place if you put the decrypted message with correct shift, program will return original message
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	string line;
	char cipheredLetter;
	int shift, choice;
	string cipheredArg, shiftArg, inputFileArg, outputFileArg;   //vars for cmd input

	if (argc == 3)
	{
		//taking cmd line arguments and setting the varibles
		for (int counter = 0; counter < argc; counter++)
		{
			cipheredArg = argv[1];
			shiftArg = argv[2];
		}

		//setting shift var from cmd input
		int m = stoi(shiftArg);         //string to int
		if (m <= 26 && m >= -26)        //shift should be <= 26 and >= -26
		{
			shift = m;
		}
		else
		{
			cout << "Invalid shift. Please try again." << endl;
			return -2;
		}

		//seeting encryption/decryption choice from cmd input
		if (cipheredArg == "-e")
		{
			choice = 1;
		}
		else if (cipheredArg == "-d")
		{
			choice = 2;
		}
		else
		{
			cout << "Not valid command." << endl;
		}

		//Encryption
		if (choice == 1)
		{
			while (getline(cin, line) && !(cin.peek() == cin.eof()))
			{
				//this for loop will go through all the characters in the line
				for (int letter = 0; letter < line.size() && line[letter] != '\0'; letter++)
				{
					cipheredLetter = line[letter];

					//check for capital letters and spaces
					if ((line[letter] >= 'A' && line[letter] <= 'Z') && (line[letter] != ' '))
					{
						//check for digits
						if ((line[letter] >= '0' && line[letter] <= '9'))
						{
							cipheredLetter = line[letter];
							cout << cipheredLetter;
						}
						else
						{
							//encrypt the message
							cipheredLetter = cipheredLetter + shift;

							if (cipheredLetter > 'Z')
							{
								cipheredLetter = cipheredLetter - 'Z' + 'A' - 1;
							}
							cout << cipheredLetter;
						}
					}
					else
					{
						cipheredLetter = line[letter];
						cout << cipheredLetter;
					}
				}
				cout << endl;
			}
		}
		else if (choice == 2) //Decryption
		{
			//this for loop will go through all the lines in the file
			while (getline(cin, line) && !(cin.peek() == cin.eof()))
			{
				//this for loop will go through all the characters in the line
				for (int letter = 0; letter < line.size() && line[letter] != '\0'; letter++)
				{
					cipheredLetter = line[letter];
					//check for capital letters and spaces
					if ((line[letter] >= 'A' && line[letter] <= 'Z') && (line[letter] != ' '))
					{
						//check for digits
						if ((line[letter] >= '0' && line[letter] <= '9'))
						{
							cipheredLetter = line[letter];
							cout << cipheredLetter;
						}
						else
						{
							//decrypt the message
							cipheredLetter = cipheredLetter - shift;

							if (cipheredLetter < 'A')
							{
								cipheredLetter = cipheredLetter + 'Z' - 'A' + 1;
							}
							cout << cipheredLetter;
						}
					}
					else
					{
						cipheredLetter = line[letter];
						cout << cipheredLetter;
					}
				}
				cout << endl;
			}

		}
	}
	else
	{
		cout << "Invalid command. \n Please try again.\n";
	}

	return 0;
}