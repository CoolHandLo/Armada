//
//Armada
//functions.cpp
//Created by Lo Evans
//
#include "functions.h"
#include "Game.h"

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
//Tempoary Variables
	string name;
	char shipOrientation;
	string shipCoordinates = "";
	char autoDeploy; 

	//Game object
	Game* NewGame = new Game;
	
	//Player objects
	Player* Player1 = new Player;
	Player2* Computer = new Player2;
	
	//Human players boards
	GameBoard* Player1Ships = new GameBoard;
	GameBoard* Player1Shots = new GameBoard;

	//Computer players boards
	GameBoard* Player2Ships = new GameBoard;
	GameBoard* Player2Shots = new GameBoard;

	//Human players ships
	Ship* Player1Carrier = new Ship("Carrier", 'A', 5, 5);
	Player1 -> addToShipCount();
	Ship* Player1Battleship = new Ship("Battleship", 'B', 4, 4);
	Player1 -> addToShipCount();
	Ship* Player1Cruiser = new Ship("Cruiser", 'C', 3, 3);
	Player1 -> addToShipCount();
	Ship* Player1Submarine = new Ship("Submarine", 'S', 3, 3);
	Player1 -> addToShipCount();
	Ship* Player1Destroyer = new Ship("Destoyer", 'D', 2, 2);
	Player1 -> addToShipCount();

	//Computer players ships
	Ship* Player2Carrier = new Ship("Carrier", 'A', 5, 5);
	Computer -> addToShipCount();
	Ship* Player2Battleship = new Ship("Battleship", 'B', 4, 4);
	Computer -> addToShipCount();
	Ship* Player2Cruiser = new Ship("Cruiser", 'C', 3, 3);
	Computer -> addToShipCount();
	Ship* Player2Submarine = new Ship("Submarine", 'S', 3, 3);
	Computer -> addToShipCount();
	Ship* Player2Destroyer = new Ship("Destoyer", 'D', 2, 2);

	//Sets boards to pre-game state.
	Player1Ships -> cleanBoard();
	Player1Shots -> cleanBoard();
	Player2Ships -> cleanBoard();
	Player2Shots -> cleanBoard();

	//Sets players name.
	cout << endl;
	cout << "What do your friends call you?\n";
	cin >> name;
	Player1 -> setPlayerName(name);
	
	//Places ships
	cout << "Capt. " << Player1 -> getPlayerName() << endl;
	cout << "It's time to launch the fleet.\n";
	cout << endl;

	//Auto placement option
	cout << "Would you like the computer\n";
	cout << "to deploy the fleet for you?\n";
	cout << "Yes [Y] or No [N]\n";
	cin >> autoDeploy;
	do {
		if (autoDeploy == 'Y' || autoDeploy == 'y' || autoDeploy == 'N' || autoDeploy == 'n') {
			if (autoDeploy == 'Y' || autoDeploy == 'y') {
				Computer -> initRandomNum();
				Computer -> addToFleet(Player1Carrier, Player1Ships);
				Computer -> addToFleet(Player1Battleship, Player1Ships);
				Computer -> addToFleet(Player1Cruiser, Player1Ships);
				Computer -> addToFleet(Player1Submarine, Player1Ships);
				Computer -> addToFleet(Player1Destroyer, Player1Ships);
				Player1Ships -> printBoard();
				cout << "Your fleet Capt. " << Player1 -> getPlayerName() << endl;
				cout << endl;
			} else if (autoDeploy == 'N' || autoDeploy == 'n') {
				Player1 -> addToFleet(Player1Carrier, Player1Ships);
				Player1 -> addToFleet(Player1Battleship, Player1Ships);
				Player1 -> addToFleet(Player1Cruiser, Player1Ships);
				Player1 -> addToFleet(Player1Submarine, Player1Ships);
				Player1 -> addToFleet(Player1Destroyer, Player1Ships);
				Player1Ships -> printBoard();
				cout << "Your fleet Capt. " << Player1 -> getPlayerName() << endl;
			}
			break;
		} else {
			continue;
		}
	}while(true);

	//Generates computer players board.
	if (autoDeploy == 'N' || autoDeploy == 'n') {
			Computer -> initRandomNum();
	}
	Computer -> addToFleet(Player2Carrier, Player2Ships);
	Computer -> addToFleet(Player2Battleship, Player2Ships);
	Computer -> addToFleet(Player2Cruiser, Player2Ships);
	Computer -> addToFleet(Player2Submarine, Player2Ships);
	Computer -> addToFleet(Player2Destroyer, Player2Ships);

	//Game play
	NewGame -> playGame(Player1, Computer, Player1Ships, Player1Shots, Player2Ships, Player2Shots, Player1Carrier, Player1Battleship, Player1Cruiser, Player1Submarine, Player1Destroyer, Player2Carrier, Player2Battleship, Player2Cruiser, Player2Submarine, Player2Destroyer);

	//Deleting pointers.
	delete NewGame;
	delete Player1;
	delete Computer;
	delete Player1Ships;
	delete Player1Shots;
	delete Player2Ships;
	delete Player2Shots;
	delete Player1Carrier;
	delete Player1Battleship;
	delete Player1Cruiser;
	delete Player1Submarine;
	delete Player1Destroyer;
	delete Player2Carrier;
	delete Player2Battleship;
	delete Player2Cruiser;
	delete Player2Submarine;
	delete Player2Destroyer;
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
