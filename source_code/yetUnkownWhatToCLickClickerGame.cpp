
#include <iostream>
#include "main.h"
#include <conio.h>
#include <iterator>

//Function for all the output, that will be printed to the console

void consoleOutput() {
	system("CLS");
	std::cout << "You have " << amount << " | You gain " << addedOnClick << " per click | Next upgrade costs " << costForUpgrade << " | One letter costs 100,000" << std::endl;
	std::cout << "\n\nPress [1] to click, press [2] to upgrade and press any letter to purchase and display it (1,000 letters are max).\n\n" << std::endl;
	letterCollectionLength = std::size(letterCollection);
	if (letterCollectionLength > 1) {
		for (int i = 0; i < letterCollectionLength; i++) {
			std::cout << letterCollection[i];
		}
	}

}

//Function for all the inputs from the keyboard, also the cheat code "MONEY"

void keyInput() {
	key = _getch();

	if (key == '1') {
		amount = amount + addedOnClick;
	}
	if (key == '2' && amount >= costForUpgrade) {
		amount = amount - costForUpgrade;
		addedOnClick = addedOnClick + 1;
		costForUpgrade = costForUpgrade + 5;
	}
	if (key == 'q' || key == 'w' || key == 'e' || key == 'r' || key == 't' || key == 'z' || key == 'u' || key == 'i' || key == 'o' || key == 'p' ||
		key == 'a' || key == 's' || key == 'd' || key == 'f' || key == 'g' || key == 'h' || key == 'j' || key == 'k' || key == 'l' ||
		key == 'y' || key == 'x' || key == 'c' || key == 'v' || key == 'b' || key == 'n' || key == 'm') {
		if (amount >= 100000) {
			amount = amount - 100000;
			letterInLetterCollection = letterInLetterCollection + 1;
			letterCollection[letterInLetterCollection] = key;
		}
	}
	//Cheat code for +1,000,000 amount
	if (key == 'M') {
		key = _getch();
		if (key == 'O') {
			key = _getch();
			if (key == 'N') {
				key = _getch();
				if (key == 'E') {
					key = _getch();
					if (key == 'Y') {
						amount = amount + 1000000;
					}
				}
			}
		}
	}

}

//Main function

int main()
{
	running = true;
	while (running == true) {
		consoleOutput();
		keyInput();
	}
}
