//
//Armada
//Player.cpp
//Created by Lo Evans
//
#include "Player.h"
#include "Ship.h"
#include "GameBoard.h"
#include <string>
#include <iostream>
#include <cctype>

using namespace std;

//Constructors
Player::Player()
	: playerName("Player 1")
	{ /* intentionally blank*/ }
Player::Player(string name) 
	: playerName(name)
	{ /* intentionally blank*/ }
	
//Acessor functions
string Player::getPlayerName() {
	return playerName;
}
int Player::getHits() {
	return hits;
}
int Player::getMisses() {
	return misses;
}
int Player::getShipCount() {
	return shipCount;
}
int Player::getShipsSunk() {
	return shipsSunk;
}

//Mutator functions
void Player::setPlayerName(string name) {
	playerName = name;
}
void Player::addHit() {
	hits++;
}
void Player::addMiss() {
	misses++;
}
void Player::addToShipCount() {
	shipCount++;
}
void Player::subtractShipCount() {
	shipCount--;
}
void Player::sinkShip() {
	shipsSunk++;
}

//Fleet commands

//Ensures there will not 
//be 2 ships occupying 
//the same grid location.
bool Player::testSpace(Ship* Vessel, GameBoard* Board) {
	int size = Vessel -> getShipSize();
	int xVal = Vessel -> getXVal();
	int yVal = Vessel -> getYVal();
	char orientation = Vessel -> getOrientation();
	int width = Board -> getBoardWidth();
	int height = Board -> getBoardHeight();
	bool fitsOnBoard;
	bool collision = false;
	char spaceCheck;

	//If ship is horizontal.
	if (orientation == 'H' || orientation == 'h') {
		//Checks if ship will fit on the board.
		if ((xVal + (size - 1)) <= width) {
			fitsOnBoard = true;
			cout << "Ship fits on board\n";
		} else {
			cout << "The Ship is too long to deploy there!\n";
			fitsOnBoard = false;
		}
		//Checks if another ship occupies the space.
		for (int i = 0; i < size; i++) {
			spaceCheck = Board -> getChar(xVal + i, yVal);
			if (spaceCheck != '^') {
				collision = true;
			}
		}
	} 

	//If ship is vertical.
	//Checks if ship will fit on the board.
	if (orientation == 'V' || orientation == 'v') {
		if ((yVal + (size)) <= height) {
			fitsOnBoard = true;
			cout << "Ship fits on board\n";
		} else {
			cout << "The Ship is too long to deploy there.\n";
			fitsOnBoard = false;
		}
		//Checks if another ship occupies the space.
		for (int i = 0; i < size; i++) {
			spaceCheck = Board -> getChar(xVal, yVal + i);
			if (spaceCheck != '^') {
				collision = true;
			}
		}
	}

	if (collision == true) {
		cout << "That deployment will cause\n";
		cout << "a collision!\n";
	}
	//Return conditions.
	if (fitsOnBoard == true && collision == false) {
		return true;
	} else {
		return false;
	}
	
}

//Places a ship on the board
void Player::placeShip(Ship* Vessel, GameBoard* Board) {
	char shipType = Vessel -> getShipType();
	int size = Vessel -> getShipSize();
	int xVal = Vessel -> getXVal();
	int yVal = Vessel -> getYVal();
	int orientation = Vessel -> getOrientation();

	//If ship is horizontal.
	if (orientation == 'H' || orientation == 'h') {
		for (int i = 0; i < size; i++) {
			Board -> setChar(shipType, xVal + i, yVal);
		}
	}

	//If ship is vertical.
	if (orientation == 'V' || orientation == 'v') {
		for (int i = 0; i < size; i++) {
			Board -> setChar(shipType, xVal, yVal + i);
		}
	}
}

//Check the entered 
//coordinates are valid.
bool Player::testCoordinates(string coordinateVal, GameBoard* Board) {
	string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lowerCase = "abcdefghijklmnopqrstuvwxyz";
	bool alpha = false;
	bool num = false;
	bool len = false;

	//Check for quit.
	if (coordinateVal == "Q" || coordinateVal == "q") {
		string input;
		cout << "Quit game?\n";
		cout << "Yes [y] or no [n]\n";
		cin >> input;
		if (input == "y" || input == "Y") {
			exit(1);
		}
	}

	//Check the letter componet.
	for (int i = 0; i < Board -> getBoardWidth(); i++) {
		if (coordinateVal[0] == upperCase[i] || coordinateVal[0] == lowerCase[i]) {
			alpha = true;
			//cout << "alpha\n";
		}
	}

	//Check length
	if (coordinateVal.length() == 2) {
		len = true;
		//cout << "len\n";
	}

	//Check number
	if (isdigit(coordinateVal[1])) {
		num = true;
		//cout << "num\n";
	}

	//Return conditions
	if (alpha == true && num == true && len == true) {
		return true;
	} else {
		return false;
	}
}

//Check the entered
//orientation is valid.
bool Player::testOrientation(char orientationVal) {
	if (orientationVal == 'H' || orientationVal == 'h' || orientationVal == 'V' || orientationVal == 'v') {
		return true;
	} else {
		return false;
	}
}

//Parses the X value from
//the entered coordinates
int Player::parseXVal(string coordinateVal, GameBoard* board) {
	string upperCase ="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string lowerCase ="abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < board -> getBoardWidth(); i++) {
		if (coordinateVal[0] == upperCase[i] || coordinateVal[0] == lowerCase[i]) {
			return i;
		}
	}
	return -1;
}

//Parses the Y value from
//the entered coordinates.
int Player::parseYVal(string coordinateVal) {
	return coordinateVal[1] - 48;
}

//Prompts the user to add a ship
//to the board. Checks for fit 
//and places the ship.
void Player::addToFleet(Ship* Vessel, GameBoard* Board) {

	char shipOrientation;
	string shipCoordinates = "";

	cout << "What orientation would you \n";
	cout << "like your " << Vessel -> getShipName() << endl;

	while (!testOrientation(shipOrientation)) {
		cout << "horizontal [H] vertical [V]\n";
		cin >> shipOrientation;
	}
		//Sets ship orientation.
	Vessel -> setOrientation(shipOrientation);
	shipOrientation = ' ';

	Board -> printBoard();
	cout << "Where would you like to \n";
	cout << "deploy the " << Vessel -> getShipName() << endl;

	while(true) {
		cout << "Enter the coordinates.\n";
		cin >> shipCoordinates;
		if (!testCoordinates(shipCoordinates, Board)) {
			continue;
		}

		//Sets Vessel data
		Vessel -> setCoordinates(shipCoordinates);
		Vessel -> setXVal(parseXVal(shipCoordinates, Board));
		Vessel -> setYVal(parseYVal(shipCoordinates));

		if (!testSpace(Vessel, Board)) {
			continue;
		} else {
			break;
		}
	}
	shipCoordinates = "";
	placeShip(Vessel, Board);
	Board -> printBoard();
}

void Player::fireTorpedo(GameBoard* Ships, GameBoard* Shots, Ship* Carrier, Ship* BattleShip, Ship* Cruiser, Ship* Submarine, Ship* Destroyer) {
	string coordinates;
	int xValue;
	int yValue;
	char target;
	
	while(true) {
		Shots -> printBoard();
		cout << "The Capt's Shots.\n";
		cout << endl;


		//Checks coordinates, sets them
		//if they are valid.
		if (!testCoordinates(coordinates, Shots)) {
			cout << "Enter target coordinates.\n";
			cin >> coordinates;
			continue;
		} else {
			xValue = parseXVal(coordinates, Shots);
			yValue = parseYVal(coordinates);

		}

		//Reads target value
		target = Ships -> getChar(xValue, yValue);
	
		//If it's a miss.
		
		if (target == '^') {
			cout << "You missed!\n";
			this -> addMiss();
			Shots -> setChar('O', xValue, yValue);
			Ships -> setChar('O', xValue, yValue);
			Shots -> printBoard();
			cout << "The Capt's Shots.\n";
			cout << endl;
			break;
			
			//If it's already been targeted.
		} else if (target == 'O' || target == 'X') {
			Shots -> printBoard();
			cout << "Try again Capt.\n";
			cout << endl;
			continue;
			
			//If its a hit.
		} else if (isalpha(target)) {
			cout << "Hit!\n";
			cout << endl;
			this -> addHit();
			Shots -> setChar('X', xValue, yValue);
			Ships -> setChar('X', xValue, yValue);
			if (target == 'A') {
				Carrier -> subtractHitPoint();
			} else if (target == 'B') {
				BattleShip -> subtractHitPoint();
			} else if (target == 'C') {
				Cruiser -> subtractHitPoint();
			} else if (target == 'S') {
				Submarine -> subtractHitPoint();
			} else if (target == 'D') {
				Destroyer -> subtractHitPoint();
			}
			break;
		}
	}
}

void Player::checkShip(Ship* Vessel) {
	if (!Vessel -> getIsSunk()) {
		if (Vessel -> getHitPoints() == 0) { 
			this -> subtractShipCount();
			Vessel -> setIsSunk(true);
			cout << "You sunk their " << Vessel -> getShipName() << endl; 
		}
	}
}