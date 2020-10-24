//
//Armada
//Ship.cpp
//Created by Lo Evans
//
#include "Ship.h"

#include <string>

using namespace std;

//Constructors
Ship::Ship() {
	/* intentionally blank */
}
Ship::Ship(string name, char type, int size, int HP)
	: shipName(name), shipType(type), shipSize(size), hitPoints(HP), isSunk(false)
	{ /* intentionally blank */ }


//Accessor functions
int Ship::getXVal() {
	return xVal;
}

int Ship::getYVal() {
	return yVal;
}

char Ship::getOrientation() {
	return orientation;
}

string Ship::getShipName() {
	return shipName;
}

char Ship::getShipType() {
	return shipType;
}

int Ship::getShipSize() {
	return shipSize;
}

string Ship::getShipCoordinates() {
	return coordinates;
}

int Ship::getHitPoints() {
	return hitPoints;
}

bool Ship::getIsSunk() {
	return isSunk;
}

//Mutator functions
void Ship::setCoordinates(string coordinateVal) {
	coordinates = coordinateVal;
}

void Ship::setOrientation(char orientationVal) {
	orientation = orientationVal;
}

void Ship::setXVal(int xValue) {
	xVal = xValue;
}

void Ship::setYVal(int yValue) {
	yVal = yValue;
}

void Ship::subtractHitPoint() {
	hitPoints--;
}

void Ship::setIsSunk(bool sunk) {
	isSunk = sunk;
}
