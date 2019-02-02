// TestApp.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MazeGame.h"
#include "CheckWriter.h"


int main()
{
	int game_choice;
	cout << "Press 1 for Check-writer (convert numbers to words)" << endl << "Press 2 for Game" << endl;
	cin >> game_choice;
	switch (game_choice)
	{
	case 1: 
		int number_for_check;
		cout << endl << "Type number for check" << endl;;
		cin >> number_for_check;
		CheckWriter check_number;
		cout << check_number.convertToWords(number_for_check);
		break;
	case 2:
		MazeGame maze;
		maze.playGame();
		break;
	}
	return 0;
}
