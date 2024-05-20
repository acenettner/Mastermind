#include <iostream>
#include <random>
#include <ctime>
#include <string>
using namespace std;
int main() {
	srand(time(NULL));
	cout << "MASTERMIND" << '\n'
	<< "In this game your goal is to guess the 4 digit code." << '\n'
	<< "You have 10 chances. The code contains only numbers." << '\n'
	<< "Each digit contains a unique number. If you input a" << '\n'
	<< "number not in the code, an X will appear next to the" << '\n'
	<< "number. If a number is in the code and in the correct"<< '\n'
	<< "position, a O will appear. If a number is in the code"<< '\n'
	<< "but the position is incorrect, a * will appear." << '\n'; 
	int codeLength = 4;
	int code[codeLength];
	
	int tempMax = 0;
	// Creates code with no repeat digits
	for (int i = 0; i < codeLength; i++) {
		int index = 0;
		code[tempMax] = rand() % 10;
		do {
			if (code[tempMax] == code[index]) {
				index = 0;
				code[tempMax] = rand() % 10;
				continue;
			}
			index++;
		} while (index < tempMax);
		tempMax++;
	}
	
	string guess;
	int numGuesses = 0;
	int maxGuesses = 10;
	while(numGuesses < maxGuesses) {
		cout << "\nNumber of guess left: " << maxGuesses - numGuesses << '\n';
		cout << "Please input a 4 digit number: ";
		cin >> guess;
		if (guess.length() != codeLength) {
			cout << "\nIncorrect number of digits." << '\n';
			continue;
		}
		
		bool usesLetter = false;
		int correctPositions = 0;
		int correctNumbers = 0;
		for (int i = 0; i < guess.length(); i++) {
			if (!isdigit(guess[i])) {
				cout << "\nPlease only use numbers." << '\n';
				usesLetter = true;
				break;
			}
			
			// Check if guess has digits in code and/or in correct place
			for (int j = 0; j < codeLength; j++) {
				// convert guess from ascii value and compare
				if ((int)guess[i]-48 == code[j]) {
					if (i == j) {
						correctPositions++;
					} else {
						correctNumbers++;
					}
				}
			}
		}
		
		if (!usesLetter) {	
			if (correctPositions == 4) {
				cout << "\nYou win!" << '\n';
				break;
			}
			for (int i = 0; i < codeLength; i++) {
				if (correctPositions > 0) {
					cout << 'O';
					correctPositions--;
				} else if (correctNumbers > 0) {
					cout << '*';
					correctNumbers--;
				} else {
					cout << 'X';
				}
			}
			numGuesses++;
			if (numGuesses == maxGuesses) {
				cout << "\nYou lose." << '\n';
			}
		}
	}
	cout << "The code was: ";
	for (int i = 0; i < codeLength; i++) {
		cout << code[i];
	}
	
	return 0;
}
