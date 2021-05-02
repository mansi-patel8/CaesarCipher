/*
* Name: Mansi Patel
* Purpose: The purpose of this program is to take the charcater shift value between +/- 26 and a plaintext message (no spaces) and returns the corresponding ciphertext. This program also does the decryption routine that reconstructs the original plaintext from the ciphertext.
* Pseducode/ Program outline logic:
			- user input for shift and error check on it
			- as for user input for messgae without spaces and only uppercase alphabets and error check on it
			- decrypt the message
			- logic is in place if you put the decrypted message with correct shift, program will return original message
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	char textMessage[1000];
	char decryptMessage[1000] = "";
	char decryptLetter;
	int shift;

	cout << "Enter shift +/- 26: ";
	cin >> shift;

	//error check for shift between -26 to +26
	if (shift < -26 || shift > 26)
	{
		cout << "Error. Please enter shift +/- 26: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin >> shift;
	}
	cin.ignore(100, '\n');

	cout << "Enter plaintext message (A-Z only, no spaces): ";
	cin.getline(textMessage, 1000);

	//error check for textMessage only between 'A' to 'Z'
	for (int i = 0; textMessage[i] != '\0'; i++)
	{
		if (textMessage[i] < 'A' || textMessage[i] > 'Z')
		{
			cout << "Error. Please enter plaintext message (A-Z only, no spaces):";
			cin.clear();
			cin.ignore(100, '\n');
			cin.getline(textMessage, 500);
		}
	}

	//decrypt the message:
	for (int i = 0; textMessage[i] != '\0'; i++)
	{
		decryptLetter = textMessage[i];

		if (textMessage[i] >= 'A' || textMessage[i] <= 'Z')
		{
			decryptLetter = decryptLetter + shift;
			if (decryptLetter > 'Z')
			{
				decryptLetter = decryptLetter - 'Z' + 'A' - 1;
			}
			decryptMessage[i] = decryptLetter;
		}
	}
	cout << "ciphertext: " << decryptMessage << endl;
	cout << "originaltext: " << textMessage << endl;

	return 0;
}