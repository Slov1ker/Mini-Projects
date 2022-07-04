#pragma once

#include<iostream>
using namespace std;
#include<iomanip>
#include<string>
#include<fstream>

class Board {
private:

	int** board;


public:
	Board();
	bool AddtoBoard(int,string);

	void rules();

	void display();

	bool CheckWinner();

	void game();


	~Board();




};