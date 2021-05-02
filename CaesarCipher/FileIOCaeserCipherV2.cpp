/*
* Name: Mansi Patel
* Purpose: The purpose of this program is to do the caesarcipher for specified input and output files/streams using the IO redirection.
			- Ex.: $ ./caesar -e 1 3 in.txt output.txt
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
	int shiftLetter, shiftDigit, choice;
	string cipheredArg, shiftLetterArg, shiftDigitArg, inputFileArg, outputFileArg;   //vars for cmd input

	if (argc < 6 || argc > 6)
	{
		cout << "Please enter valid commands to run the program properly." << endl;
	}
	if (argc == 6)
	{
		//taking cmd line arguments and setting the varibles
		for (int counter = 0; counter < argc; counter++)
		{
			cipheredArg = argv[1];
			shiftLetterArg = argv[2];
			shiftDigitArg = argv[3];
			inputFileArg = argv[4];
			outputFileArg = argv[5];
		}

		//seeting shiftLetter var from cmd input
		int m = stoi(shiftLetterArg);         //string to int
		if (m <= 26 && m >= -26)        //shiftLetter should be <= 26 and >= -26
		{
			shiftLetter = m;
		}
		else
		{
			cout << "Invalid shiftLetter. Please try again." << endl;
			return -2;
		}

		//setting shiftDigot var from cmd input
		int n = stoi(shiftDigitArg);         //string to int
		if (n <= 10 && n >= -10)        //shiftLetter should be <= 26 and >= -26
		{
			shiftDigit = n;
		}
		else
		{
			cout << "Invalid shiftLetter. Please try again." << endl;
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
			//normal text input file
			ifstream inputEncryptedFile(inputFileArg); //text.txt

			//encrypted output file
			ofstream outputDecryptedFile(outputFileArg); //encrypted.text

			//input file is open and it is not empty
			if (inputEncryptedFile.is_open() && !(inputEncryptedFile.peek() == ifstream::traits_type::eof()))
			{
				cout << "successfully opened " << inputFileArg << " for decryption" << endl;

				//output file is open
				if (!outputDecryptedFile.fail())
				{
					cout << "successfully opened " << outputFileArg << " for writing." << endl;

					//this for loop will go through all the lines in the file
					for (int lineno = 1; getline(inputEncryptedFile, line); lineno++)
					{
						//this for loop will go through all the characters in the line
						for (int letter = 0; letter < line.size() && line[letter] != '\0'; letter++)
						{
							cipheredLetter = line[letter];

							//check for capital letters and spaces
							if ((line[letter] >= 'A' && line[letter] <= 'Z') && (line[letter] != ' '))
							{
								//encrypt the message for 'A' to 'z'
								cipheredLetter = cipheredLetter + shiftLetter;

								if (cipheredLetter > 'Z')
								{
									cipheredLetter = cipheredLetter - 'Z' + 'A' - 1;
								}
								outputDecryptedFile << cipheredLetter;
							}
							else if ((line[letter] >= 'a' && line[letter] <= 'z') && (line[letter] != ' '))
							{
								//encrypt the message for 'a' to 'z'
								cipheredLetter = cipheredLetter + shiftLetter;

								if (cipheredLetter > 'z')
								{
									cipheredLetter = cipheredLetter - 'z' + 'a' - 1;
								}
								outputDecryptedFile << cipheredLetter;
							}
							else
							{
								//encrypt the message for digits
								cipheredLetter = cipheredLetter + shiftDigit;
								outputDecryptedFile << cipheredLetter;
							}
						}
						outputDecryptedFile << endl;
					}
				}
				else
				{
					cerr << "error opening " << outputFileArg << " for writing." << endl;
				}

				inputEncryptedFile.close();			//close input filestream 
				outputDecryptedFile.close();		//close output filestream 
			}
			else
			{
				cerr << "error opening " << inputFileArg << " for writing. \n Please check whether your file has data for encryption." << endl;
			}
		}
		else if (choice == 2) //Decryption
		{
			//encrypted input file
			ifstream inputTxtFile(inputFileArg); //encrypted.text

			//decrypted output file
			ofstream outputEncryptedFile(outputFileArg); //

			//input file is open and it is not empty
			if (inputTxtFile.is_open() && !(inputTxtFile.peek() == ifstream::traits_type::eof()))
			{
				cout << "successfully opened" << inputFileArg << "for reading" << endl;

				//output file is open
				if (!outputEncryptedFile.fail())
				{
					cout << "successfully opened " << outputFileArg << " for writing." << endl;

					//this for loop will go through all the lines in the file
					for (int lineno = 1; getline(inputTxtFile, line); lineno++)
					{
						//this for loop will go through all the characters in the line
						for (int letter = 0; letter < line.size() && line[letter] != '\0'; letter++)
						{
							cipheredLetter = line[letter];
							//check for capital letters and spaces
							if ((line[letter] >= 'A' && line[letter] <= 'Z') && (line[letter] != ' '))
							{
								//decrypt the message for 'A' to 'Z'
								cipheredLetter = cipheredLetter - shiftLetter;

								if (cipheredLetter < 'A')
								{
									cipheredLetter = cipheredLetter + 'Z' - 'A' + 1;
								}
								outputEncryptedFile << cipheredLetter;
							}
							else if ((line[letter] >= 'a' && line[letter] <= 'z') && (line[letter] != ' '))
							{
								//decrypt the message for 'a' to 'z'
								cipheredLetter = cipheredLetter - shiftLetter;

								if (cipheredLetter > 'z')
								{
									cipheredLetter = cipheredLetter + 'z' - 'a' + 1;
								}
								outputEncryptedFile << cipheredLetter;
							}
							else
							{
								//decrypt the message for digits
								cipheredLetter = cipheredLetter - shiftDigit;
								outputEncryptedFile << cipheredLetter;
							}
						}
						outputEncryptedFile << endl;
					}
				}
				else
				{
					cerr << "error opening " << outputFileArg << " for writing." << endl;
				}

				inputTxtFile.close();					//close input filestream 
				outputEncryptedFile.close();			//close output filestream 
			}
			else
			{
				cerr << "error opening " << inputFileArg << " for writing. \n Please check whether your file has data for decryption.\n";
			}
		}
		else
		{
			cout << "Invalid command. \n Please try again.\n";
		}
	}
	return 0;
}
