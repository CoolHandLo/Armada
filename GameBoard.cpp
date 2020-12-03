//
//Armada
//Gameboard.cpp
//Created by Lo Evans
//
#include "GameBoard.h"
#include <iostream>

using namespace std;

GameBoard::GameBoard() {
	cleanBoard();
};

int GameBoard::getBoardWidth() {
	return boardWidth;
}

int GameBoard::getBoardHeight() {
	return boardHeight;
}

void GameBoard::cleanBoard() {
	for (int i = 0; i < boardHeight; i++) {
		for (int j = 0; j < boardWidth; j++) {
			board[i][j] = '^'; 
		}
	}
}

void GameBoard::printBoard() {
	string letters = "  ABCDEFGHIJKLMNOPQRSTUVWXYZ\n";
	for (int i = 0; i < (boardWidth + 2); i++) {
		cout << letters[i];
	}
	cout << endl;

	for (int i = 0; i < boardHeight; i++) {
		cout << i << " ";
		for (int j = 0; j < boardWidth; j++) {
			cout << board[j][i]; 
		}
		cout << endl;
	}
}

char GameBoard::getChar(int xVal, int yVal) {
	return board[xVal][yVal];
}

void GameBoard::setChar(char val, int xVal, int yVal) {
	board[xVal][yVal] = val;
}