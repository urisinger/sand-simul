#include "Board.h"

Board::Board(int size_x, int size_y) {
	_size_X=size_x;
	_size_Y=size_y;
	_board = new int* [size_y];
	for (int i = 0; i < size_y; ++i) {
		_board[i] = new int[size_x];
		for (int j = 0; j < size_x; ++j) {
			_board[i][j] = 0;
		}
	}
	_board[3][5] = 2;
}

void Board::UpdateBoard(std::vector<float>* Output, float screen_X, float screen_Y) {
	int** newboard = new int* [_size_Y];
	for (int i = 0; i < _size_Y; ++i) {
		newboard[i] = new int[_size_X];
		for (int j = 0; j < _size_X; ++j) {
			newboard[i][j] = 0;
		}
	}


	for (int i = 0; i < _size_Y; ++i) {
		for (int j = 0; j < _size_X; ++j) {
			switch (_board[i][j]) {
			case 0:
				break;
			case 1:
				newboard[i][j] = 1;
			case 2:
				if (i < 0 && _board[i-1][j] == 0) {
					newboard[i-1][j] = 2;
					Output->push_back(2*((j) / _size_X)-1);
					Output->push_back(2*((i-1) / _size_Y)-1);
				}
				else {
					newboard[i][j] = 2;
					Output->push_back(2*(j / _size_X) - 1);
					Output->push_back(2*(i / _size_Y) - 1);
				}
			}
		}
	}

	for (int i = 0; i < _size_Y; ++i) {
		for (int j = 0; j < _size_X; ++j) {
			_board[i][j] = newboard[i][j];
		}
	}
	PrintBoard();
}

void Board::PrintBoard() {
	system("CLS");
	for (int i = 0; i < _size_Y; ++i) {
		for (int j = 0; j < _size_X; ++j) {
			std::cout << _board[i][j] << "|";
		}
		std::cout << std::endl;
	}
}