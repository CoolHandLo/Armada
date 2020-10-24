//
//Armada
//Player2.cpp
//Created by Lo Evans
//
#include "Player2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


int Player2::randomNum() {
	srand(rand());
	return rand() % 10;
}

void Player2::initRandomNum() {
	srand(time(NULL));
}

bool Player2::testSpace(Ship* Vessel, GameBoard* Board) {
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
		} else {
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
		} else {
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


	//Return conditions.
	if (fitsOnBoard == true && collision == false) {
		return true;
	} else {
		return false;
	}
}

void Player2::placeShip(Ship* Vessel, GameBoard* Board) {
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

void Player2::addToFleet(Ship* Vessel, GameBoard* Board) {
	int num = randomNum();
	char shipOrientation;

	//Assigns ship orientation.
	if (num < 5) { 
		shipOrientation = 'H';
		Vessel -> setOrientation(shipOrientation);
	} else {
		shipOrientation = 'V';
		Vessel -> setOrientation(shipOrientation);
	}
	
	while(true) {
		//Assigns ship coordinates
		Vessel -> setXVal(randomNum());
		Vessel -> setYVal(randomNum());

		if (testSpace(Vessel, Board)) {
			break;
		} 
	}
	placeShip(Vessel, Board);
}

void Player2::fireTorpedo(GameBoard* Ships, GameBoard* Shots, Ship* Carrier, Ship* BattleShip, Ship* Cruiser, Ship* Submarine, Ship* Destroyer) {
	string coordinates;
	int xValue;
	int yValue;
	char target;
	
	while(true) {
		xValue = this -> randomNum();
		yValue = this -> randomNum();
		
		//Reads target value
		target = Ships -> getChar(xValue, yValue);

		//If it's a miss.
		if (target == '^') {
			cout << "The opposing fleet has missed!\n";
			this -> addMiss();
			Shots -> setChar('O', xValue, yValue);
			Ships -> setChar('O', xValue, yValue);
			break;

			//If it's already been targeted.
		} else if (target == 'O' || target == 'X') {
			continue;

			//If its a hit.
		} else if (isalpha(target)) {
			this -> addHit();
			Shots -> setChar('X', xValue, yValue);
			Ships -> setChar('X', xValue, yValue);
			if (target == 'A') {
				Carrier -> subtractHitPoint();
				cout << "Your Carrier has been hit!\n";
			} else if (target == 'B') {
				BattleShip -> subtractHitPoint();
				cout << "Your Battleship has been hit!\n";
			} else if (target == 'C') {
				Cruiser -> subtractHitPoint();
				cout << "Your Cruiser has been hit!\n";
			} else if (target == 'S') {
				Submarine -> subtractHitPoint();
				cout << "Your Submarine has been hit!\n";
			} else if (target == 'D') {
				Destroyer -> subtractHitPoint();
				cout << "Your Destroyer has been hit!\n";
			}
			break;
		}
	}
}
//Ckecks if a ship is sunk. 
void Player2::checkShip(Ship* Vessel) {
	if (!Vessel -> getIsSunk()) {
		if (Vessel -> getHitPoints() == 0) {
			this -> subtractShipCount();
			Vessel -> setIsSunk(true);
			cout << "They sunk your " << Vessel -> getShipName() << endl; 
		}
	}
}