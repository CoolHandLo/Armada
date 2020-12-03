//
//Armada
//Player2.h
//Created by Lo Evans
//
#ifndef Player2_h
#define Player2_h
#include "Player.h" 

#include <iostream>
#include <cstdlib>
#include <ctime>

class Player2: public Player {
	private:
		bool shipTargeted = false;
		int lastHitX;
		int lastHitY;
		int nextShotX;
		int nextShotY;
		//
		void placeShip(Ship* Vessel, GameBoard* Board);
		//
		bool testSpace(Ship* Vessel, GameBoard* Board);
	
	public:
		//Initiates a new random seed
		void initRandomNum();

		//
		int randomNum();

		//Checks for fit and places ship.
		void addToFleet(Ship* Vessel, GameBoard* Board);

		//Adds ships loaded from file to 
		//the board. Checks for fit and places ship.
		void addLoadedToFleet(Ship* Vessel, GameBoard* Board);

		//
		void fireTorpedo(GameBoard* Ships, GameBoard* Shots, Ship* Carrier, Ship* Battleship, Ship* Cruiser, Ship* Submarine, Ship* Destroyer);
		
		//
		void checkShip(Ship* Vessel);

};
#endif /* Player2_h */