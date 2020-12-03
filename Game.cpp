//
//Armada
//Game.cpp
//Created by Lo Evans.
//
#include "Game.h"
#include <iostream>
#include <fstream>

using namespace std;

//Constructors
Game::Game() 
	: player1sTurn(true), gameWon(false), gameLost(false)
	{ /* intentionally blank */ }

//Acessor functions

bool Game::getPlayer1sTurn() {
	return player1sTurn;
}

bool Game::getGameWon() {
	return gameWon;
}

bool Game::getGameLost() {
	return gameLost;
}

//Mutator functions
void Game::setPlayer1sTurn(bool turn) {
	player1sTurn = turn;
}

void Game::setGameWon(bool won) {
	gameWon = won;
}

void Game::setGameLost(bool lost) {
	gameLost = lost;
}


//Game function
void Game::playGame(Player* Player1, Player2* Computer, GameBoard* Player1Ships, GameBoard* Player1Shots, GameBoard* ComputerShips, GameBoard* ComputerShots, Ship* Player1Carrier, Ship* Player1Battleship, Ship* Player1Cruiser, Ship* Player1Submarine, Ship* Player1Destroyer, Ship* ComputerCarrier, Ship* ComputerBattleship, Ship* ComputerCruiser, Ship* ComputerSubmarine, Ship* ComputerDestroyer) {
		while(true) {
		if (this -> getPlayer1sTurn()) {
			Player1 -> fireTorpedo(ComputerShips, Player1Shots, ComputerCarrier, ComputerBattleship, ComputerCruiser, ComputerSubmarine, ComputerDestroyer);
			Player1 -> checkShip(ComputerCarrier);
			Player1 -> checkShip(ComputerBattleship);
			Player1 -> checkShip(ComputerCruiser);
			Player1 -> checkShip(ComputerSubmarine);
			Player1 -> checkShip(ComputerDestroyer);
			this -> setPlayer1sTurn(false);
		} else {
			Computer -> fireTorpedo(Player1Ships, ComputerShots, Player1Carrier, Player1Battleship, Player1Cruiser, Player1Submarine, Player1Destroyer);
			Computer -> checkShip(Player1Carrier);
			Computer -> checkShip(Player1Battleship);
			Computer -> checkShip(Player1Cruiser);
			Computer -> checkShip(Player1Submarine);
			Computer -> checkShip(Player1Destroyer);
			Player1Ships -> printBoard();
			this -> setPlayer1sTurn(true);
		}

		if (Computer -> getShipCount() == 0) {
			this -> setGameWon(true);
			break;
		}

		if (Player1 -> getShipCount() == 0) {
			this -> setGameLost(true);
			break;
		}
	}

	if (this -> getGameWon()) {
		cout << "You Win!\n";

		}
	if (this -> getGameLost()) {
		cout << "You lose!\n";
		}

}

void Game::loadBoard(string fileName) {

	//Local variables
	string shipName;
	string coordinates;
	string orientation;
	char orientationVal[2];

	//Gameboard object
	GameBoard* LoadedBoard = new GameBoard;

	//Player object
	Player2* PlayerA = new Player2;

	//Ship objects
	Ship* LoadedCarrier = new Ship("Carrier", 'A', 5);
	Ship* LoadedBattleship = new Ship("Battleship", 'B', 4);
	Ship* LoadedCruiser = new Ship("Cruiser", 'C', 3);
	Ship* LoadedSubmarine = new Ship("Submarine", 'S', 3);
	Ship* LoadedDestroyer = new Ship("Destroyer", 'D', 2);

	//Opens input file stream.
  ifstream file;
  file.open("savedBoards/" + fileName);
  if (file.fail()) {
  	cerr << "File open failed!\n";
  	exit(1);
  }

	//Parses data
	for(int i = 0; i < 5; i++) {
		getline(file, shipName, ',');
		//cout << shipName << endl;
		if (shipName == "Carrier") {
			getline(file, coordinates, ',');
			//cout << coordinates << endl;
			LoadedCarrier -> setCoordinates(coordinates);
			LoadedCarrier -> setXVal(PlayerA -> parseXVal(coordinates, LoadedBoard));
			LoadedCarrier -> setYVal(PlayerA -> parseYVal(coordinates));
			getline(file, orientation);
			//cout << orientation << endl;
			orientationVal[0] = orientation[0];
			//cout << orientationVal << endl;
			LoadedCarrier -> setOrientation(orientationVal[0]);
			PlayerA -> addToShipCount();
		}
		if (shipName == "Battleship") {
			getline(file, coordinates, ',');
			LoadedBattleship -> setCoordinates(coordinates);
			LoadedBattleship -> setXVal(PlayerA -> parseXVal(coordinates, LoadedBoard));
			LoadedBattleship -> setYVal(PlayerA -> parseYVal(coordinates));
			getline(file, orientation);
			orientationVal[0] = orientation[0];
			LoadedBattleship -> setOrientation(orientationVal[0]);
			PlayerA -> addToShipCount();
		}
		if (shipName == "Cruiser") {
			getline(file, coordinates, ',');
			LoadedCruiser -> setCoordinates(coordinates);
			LoadedCruiser -> setXVal(PlayerA -> parseXVal(coordinates, LoadedBoard));
			LoadedCruiser -> setYVal(PlayerA -> parseYVal(coordinates));
			getline(file, orientation);
			orientationVal[0] = orientation[0];
			LoadedCruiser -> setOrientation(orientationVal[0]);
			PlayerA -> addToShipCount();
		}
		if (shipName == "Submarine") {
			getline(file, coordinates, ',');
			LoadedSubmarine -> setCoordinates(coordinates);
			LoadedSubmarine -> setXVal(PlayerA -> parseXVal(coordinates, LoadedBoard));
			LoadedSubmarine -> setYVal(PlayerA -> parseYVal(coordinates));
			getline(file, orientation);
			orientationVal[0] = orientation[0];
			LoadedSubmarine -> setOrientation(orientationVal[0]);
			PlayerA -> addToShipCount();
		}
		if (shipName == "Destroyer") {
			getline(file, coordinates, ',');
			LoadedDestroyer -> setCoordinates(coordinates);
			LoadedDestroyer -> setXVal(PlayerA -> parseXVal(coordinates, LoadedBoard));
			LoadedDestroyer -> setYVal(PlayerA -> parseYVal(coordinates));
			getline(file, orientation);
			orientationVal[0] = orientation[0];
			LoadedDestroyer -> setOrientation(orientationVal[0]);
			PlayerA -> addToShipCount();
		}
	}

	if (PlayerA -> getShipCount() == 5) {
		PlayerA -> addLoadedToFleet(LoadedCarrier, LoadedBoard);
		PlayerA -> addLoadedToFleet(LoadedBattleship, LoadedBoard);
		PlayerA -> addLoadedToFleet(LoadedCruiser, LoadedBoard);
		PlayerA -> addLoadedToFleet(LoadedSubmarine, LoadedBoard);
		PlayerA -> addLoadedToFleet(LoadedDestroyer, LoadedBoard);
	} else {
		if (LoadedCarrier -> getShipCoordinates() == "") {
			PlayerA -> addToFleet(LoadedCarrier, LoadedBoard);
		}
		if (LoadedBattleship -> getShipCoordinates() == "") {
			PlayerA -> addToFleet(LoadedBattleship, LoadedBoard);
		}
		if (LoadedCruiser -> getShipCoordinates() == "") {
			PlayerA -> addToFleet(LoadedCruiser, LoadedBoard);
		}
		if (LoadedSubmarine -> getShipCoordinates() == "") {
			PlayerA -> addToFleet(LoadedSubmarine, LoadedBoard);
		}
		if (LoadedDestroyer -> getShipCoordinates() == "") {
			PlayerA -> addToFleet(LoadedDestroyer, LoadedBoard);
		}
	}
	

	LoadedBoard -> printBoard();


}