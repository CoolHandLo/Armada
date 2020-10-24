//
//Armada
//Player2.h
//Created by Lo Evans
//
#ifndef Player2_h
#define Player2_h
#include "Player.h" 

#include <cstdlib>
#include <ctime>

class Player2: public Player {
	private:
		void placeShip(Ship* Vessel, GameBoard* Board);
		bool testSpace(Ship* Vessel, GameBoard* Board);
	public:
		void initRandomNum();
		int randomNum();
		void addToFleet(Ship* Vessel, GameBoard* Board);
		void fireTorpedo(GameBoard* Ships, GameBoard* Shots, Ship* Carrier, Ship* Battleship, Ship* Cruiser, Ship* Submarine, Ship* Destroyer);
		void checkShip(Ship* Vessel);

};
#endif /* Player2_h */