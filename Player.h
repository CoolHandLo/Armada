//
//Aramada
//Player.h
//Created by Lo Evans
//
#ifndef Player_h
#define Player_h
#include "Ship.h"
#include "GameBoard.h"

#include <string>
using namespace std;

class Player {
	private:
		string playerName;
		int hits = 0;
		int misses = 0;
		int shipCount = 0;
		int shipsSunk = 0;

		//Fleet commands
		//Tests if a ship will fit on the board.
		bool testSpace(Ship* Vessel, GameBoard* Board);

		//Places a ship on the board.
		void placeShip(Ship* Vessel, GameBoard* Board);

		//Tests if coordinates are a match to the board.
		bool testCoordinates(string coordinateVal, GameBoard* Board);

		//Test input is valid orientation. 
		bool testOrientation(char orientationVal);


	public:
		//Constructors
		Player();
		Player(string name);

		//Parses X value from coordinates.
		int parseXVal(string coordinateVal, GameBoard* Board);

		//Parses Y value from coordinates.
		int parseYVal(string coordinateVal);

		//Asseccor functions
		string getPlayerName();
		int getHits();
		int getMisses();
		int getShipCount();
		int getShipsSunk();

		//Mutator functions
		void setPlayerName(string name);

		//Adds 1 to hits.
		void addHit();
		
		//Adds 1 to misses
		void addMiss();
		
		//Adds 1 to shipCount;
		void addToShipCount();
		
		//Sibtracts 1 from shipCount;
		void subtractShipCount();
		
		//Adds 1 to shipsSunk;
		void sinkShip();
		
		//Fleet Commands

		//Prompts the user to add a ship
		//to the board. Checks for fit 
		//and places the ship.
		void addToFleet(Ship* Vessel, GameBoard* Board);

		//Main game play function. 
		void fireTorpedo(GameBoard* Ships, GameBoard* Shots, Ship* Carrier, Ship* Battleship, Ship* Cruiser, Ship* Submarine, Ship* Destroyer);

		//Checks if ship is sunk.
		void checkShip(Ship* Vessel);
};

#endif /* Player_h */