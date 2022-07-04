#include "Board.h"

Board::Board() {
	board = new int* [3];

	for (int i = 0; i < 3; i++) {
		board[i] = new int[3];
	}
	
	for (int i = 0; i < 3; i++) {
		for (int s = 0; s < 3; s++) {
			board[i][s] = 0; // 0 is for empty
		}
	}
}

bool Board:: AddtoBoard(int num, string player) {
	int row=-1, col=-1;


	if ((num / 10) > 0 && (num / 10) < 4)
		row = num / 10 - 1;
	else
		return false;

	if ((num % 10) > 0 && (num % 10) < 4)
		col = num % 10 - 1;
	else
		return false;

	if (board[row][col] != 0)
		return false;


	if (player == "Player1")
		board[row][col] = 1;
	if (player == "Player2")
		board[row][col] = 2;

	return true;
	
}

void Board:: rules() {
	string choice;
	do {
		cout << "* Enter the number you want to add tick or cross in : " << endl;
		cout << "* Enter 11 to select Row one and column one " << endl;
		cout << "* Enter 23 to select Row two and column three" << endl;
		cout << endl;
		cout << "Enter 'Yes' to confirm rules and enter the game  :   ";
		cin >> choice;
	} while (!(choice=="Yes" || choice=="yes"));
}

void Board:: display() {

	for (int r = 0; r < 3; r++) {
		for (int d = 0; d < 3; d++) {
			cout << "|\t   \t|";
		}
		cout << endl;
		for (int c = 0; c < 3; c++) {
			if (board[r][c] == 1)
				cout << "|\t \\/\t|";
			if (board[r][c] == 2)
				cout << "|\t O \t|";
			if (board[r][c] == 0)
				cout << "|\t   \t|";
		}
		cout << endl;
		if(r!=2)
		cout << "-------------------------------------------------" << endl;
	}

	cout << endl;
	cout << endl;
	for (int r = 0; r < 3; r++) {
		for (int d = 0; d < 3; d++) {
			cout << "|\t   \t|";
		}

		cout << endl;
		for (int c = 0; c < 3; c++) {
				cout << "|\t"<< r+1<<c+1<<" \t|";
		}
		cout << endl;
		if (r != 2)
			cout << "-------------------------------------------------" << endl;
	}
}


bool Board::CheckWinner() {
	
	int emptyCounter = 0;
	for (int r = 0; r < 3; r++) {
		for (int c = 0; c < 3; c++) {
			if (board[r][c] == 0)
				emptyCounter++;
		}
	}

	if (emptyCounter == 0) {
		cout << "Game Ended in a Draw ";
		return true;
	}
		
	for (int r = 0; r < 3; r++) {
		if ((board[r][0] == board[r][1] && board[r][1]== board[r][2]) && board[r][0]!=0) {
			if (board[r][0] == 1) {
				
				cout << "* Player 1 is the winner " << endl;
				return true;
			}
			if (board[r][0] == 2) {
				cout << "* Player 2 is the winner " << endl;
				return true;
			}
		}
	}

	for (int c = 0; c < 3; c++) {
		if (board[0][c] == board[1][c]&& board[1][c] == board[2][c] && board[0][c] != 0) {
			if (board[0][c] == 1) {

				cout << "* Player 1 is the winner " << endl;
				return true;
			}
			if (board[0][c] == 2) {

				cout << "* Player 2 is the winner " << endl;
				return true;
			}
		}
	}

	if (board[0][0] == board[1][1]&& board[1][1] == board[2][2] && board[0][0] != 0) {
		if (board[0][0] == 1) {
			
			cout << "* Player 1 is the winner " << endl;
			return true;
		}
		if (board[0][0] == 2) {

			cout << "* Player 2 is the winner " << endl;
			return true;
		}
	}
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != 0) {
		if (board[0][2] == 1) {

			cout << "* Player 1 is the winner " << endl;
			return true;
		}
		if (board[0][2] == 2) {

			cout << "* Player 2 is the winner " << endl;
			return true;
		}
	}

	return false;
}

void Board::game() {

	int RowColNumber;
	int counter = 0;

	rules();
	do {
		system("CLS");
		display();
		cout << endl;

		if (counter == 0 || counter % 2 == 0) {
			cout << "Player 1's Move :-  ";
			cin >> RowColNumber;
			if (AddtoBoard(RowColNumber, "Player1"))
				counter++;
		}
		else {
			cout << "Player 2's Move :-  ";
			cin >> RowColNumber;
			if (AddtoBoard(RowColNumber, "Player2"))
				counter++;
		}
		system("CLS");
		display();
	} while (!(CheckWinner()));



}

Board::~Board() {

	for (int i = 0; i < 3; i++) {
		delete[] board[i];
	}

	delete[] board;

}




