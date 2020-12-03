//
//Armada
//Ship.h
//Created by Lo Evans
//
#ifndef Ship_h
#define Ship_h

#include <string>
using namespace std;

class Ship {
	private:
		//Coordinates
		string coordinates;
		int xVal; 
		int yVal;
		char orientation;

		//Ship specifications
		string shipName;
		char shipType;
		int shipSize;
		int hitPoints;
		bool isSunk;

	public:
		//Constructors
		Ship();
		Ship(string name, char type, int size);
		
		//Assecor functions
		int getXVal();
		int getYVal();
		char getOrientation();
		string getShipName();
		char getShipType();
		int getShipSize();
		string getShipCoordinates();
		int getHitPoints();
		bool getIsSunk();
		
		//Mutator functions
		void setCoordinates(string coordinateVal);
		void setOrientation(char orientationVal);
		void setXVal(int xValue);
		void setYVal(int yValue);
		void subtractHitPoint();
		void setIsSunk(bool sunk);
};


#endif /* Ship_h */