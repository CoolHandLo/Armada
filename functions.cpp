//
//Armada
//functions.cpp
//Created by Lo Evans
//
#include "functions.h"
#include <iostream>

using namespace std;

//Welcomes the user 
//and calls menu().
void welcome() {

	cout << "   Welcome to ARMADA!\n";
	cout << "***Battle for the Sea***\n";
	cout << endl;
	cout << endl;
	cout << "What would you like to do?\n";
	cout << endl;

	menu();

}

//The main menu.
void menu() {

	//Variables
	char input;

	//Dialog
	cout << "Menu:\n";
	cout << "Learn to play [L]\n";
	cout << "Play new game [P]\n";
	cout << "Load game     [G]\n";
	cout << "Quit game     [Q]\n";
	cout << endl;
	cin >> input;

	if (input == 'l' || input == 'L') {
		learnToPlay();
	} else if (input == 'p' || input == 'P') {
		playNewGame();
	} else if (input == 'g' || input == 'G') {
		loadGame();
	} else if (input == 'q' || input == 'Q') {
		quitGame();
	} else {
		cout << "Please try again.\n";
		menu();
	}
}

//A guide on how to 
//play the game
void learnToPlay() {
	menu();
}

//Starts a new game.
void playNewGame() {
	menu();
}

//Loads a game from 
//savedGames directory
void loadGame() {
	menu();
}

//Exits the program.
void quitGame() {
	string input;
	cout << "Quit game?\n";
	cout << "Yes [y] or no [n]\n";
	cin >> input;
	if (input == "y" || input == "Y") {
		exit(1);
	} else {
		menu();
	}
}
