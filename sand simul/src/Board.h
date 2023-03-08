#pragma once

#include <vector>

#include <iostream>
#include <stdlib.h> 
class Board
{
public:
	Board(int size_x,int size_y);
	~Board() {};
	void PrintBoard();
	void UpdateBoard(std::vector<float>* Output);
private:
	int** _board;
	int _size_X;
	int _size_Y;
};

