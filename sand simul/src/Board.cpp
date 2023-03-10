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
	_board[0][5] = 2;
	_board[99][5] = 1;
	_board[99][4] = 1;
	_board[99][6] = 1;
}

void Board::UpdateBoard(std::vector<float>* Output) {
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
				Output->push_back(2 * ((static_cast<float>(j) + 1) / (_size_X)) - 1);
				Output->push_back(2 * ((static_cast<float>(i) + 1) / (_size_Y)) - 1);
				break;
			case 2:
				if (i+1<_size_Y && _board[i+1][j] == 0) {
					newboard[i+1][j] = 2;
				}
				else {
					newboard[i][j] = 2;
				}
				Output->push_back(2*((static_cast<float>(j)+1) / (_size_X))-1);
				Output->push_back(2*((static_cast<float>(i) +1)/ (_size_Y))-1);
				break;
			}
		}
	}

	for (int i = 0; i < _size_Y; ++i) {
		for (int j = 0; j < _size_X; ++j) {
			_board[i][j] = newboard[i][j];
		}
	}
	//PrintBoard();
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