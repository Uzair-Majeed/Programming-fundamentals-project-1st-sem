//============================================================================
// Name        : pf project.cpp
// Author      : UZAIR MAJEED
// RollNo      : 23i-3063
// Copyright   : (c) Reserved
// Description : Basic 2D RISK GAME 
//============================================================================

#ifndef CENTIPEDE_CPP_
#define CENTIPEDE_CPP_
#include "util.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include<string>
#include<cmath>
using namespace std;

//------------------------------------------------------------------------------------------------------------------------//
// MY FUNCTIONS
//I ADDED COMMENTS WITH FUNCTIONS DEFINTIONS. FEEL FREE TO CHECK THEM OUT

void boardDisplay();
void boardBoundary();
void menu2Display();
bool winCondition(char color[50]);
void displayScores(int scores[4]);
void attackTerritory(int selterr[50], char color[50], string players[4]);
void drawTroop(int x, int y, int pl1troop);
void miniFun(int x, int y, int pl1troop, int selterr[50], char color[50], int i);
void displayTroops(int p1[50], int pltroop, int selterr[50], char color[50]);
void placeTroops(int troops, int selterr[50], char color[50]);
void troopsSelect(int selterr[50], char color[50]);
int diceroll();
void checkConditions(int selterr[50], char color[50], int i);
void updatedBoardDisplay(int selterr[50], char color[50]);
void writeHighScore(string players[4], int scores[4]);
void readHighScore(string players[4], int scores[4]);
void displayHighScore();
void userInfo(string players[4]);
void instructions();
void credits();
void menuDisplay();
void GameDisplay();

//--------------------------------------------------------------------------------------------------------------------//
//PRE DEFINED FUNCTIONS
void MouseClicked(int button, int state, int x, int y);
void MouseMoved(int x, int y);
void MousePressedAndMoved(int x, int y);
void Timer(int m);
void PrintableKeys(unsigned char key, int x, int y);
void NonPrintableKeys(int key, int x, int y);
void SetCanvasSize(int width, int height);
int menu = 0;

//-----------------------------------------------------------------------------------------------------------------------//
//MAIN FUNCTION
int main(int argc, char* argv[]) {


		int width = 1020, height = 840;
		InitRandomizer();
		glutInit(&argc, argv); 
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); 
		glutInitWindowPosition(50, 50); 
		glutInitWindowSize(width, height); 
		glutCreateWindow("PF Project");
		SetCanvasSize(width, height); 
		srand(time(0));

		glutDisplayFunc(GameDisplay);
		glutSpecialFunc(NonPrintableKeys);
		glutKeyboardFunc(PrintableKeys); 
		glutTimerFunc(1000.0, Timer, 0);

		glutMouseFunc(MouseClicked);
		glutPassiveMotionFunc(MouseMoved); 
		glutMotionFunc(MousePressedAndMoved); 

		glutMainLoop();
		return 1;
}
#endif /* AsteroidS_CPP_ */

//----------------------------------------------------------------------------------------
//This function below displays the board that i have made using shapes other than squares . 
void boardDisplay() {

	glClearColor(1.0, 0.89, 0.77, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	DrawLine(50, 700, 50, 30, 5, colors[RED]);
	DrawLine(50, 700, 950, 700, 5, colors[RED]);
	DrawLine(950, 700, 950, 30, 5, colors[RED]);
	DrawLine(50, 30, 950, 30, 5, colors[RED]);
	DrawString(55, 800, "Player 1 is assigned White color and Player 2 is assigned Orange color", colors[BLACK]);
	DrawString(55, 750, "SWITCH TO TERMINAL SCREEN KINDLY", colors[BLACK]);

	//This is Continent 1 with 10 territories
	DrawString(55, 660, "Continent 1", colors[BLACK]);
	DrawTriangle(55, 650, 205, 650, 55, 500, colors[RED]);
	DrawTriangle(55, 500, 150, 150, 150, 450, colors[RED]);
	DrawTriangle(55, 500, 205, 650, 150, 450, colors[RED]);
	DrawTriangle(150, 450, 205, 650, 205, 450, colors[RED]);
	DrawRectangle(150, 450, 56, -150, colors[RED]);
	DrawRectangle(150, 300, 56, -150, colors[RED]);
	DrawTriangle(305, 650, 205, 500, 205, 650, colors[RED]);
	DrawTriangle(305, 375, 205, 500, 205, 300, colors[RED]);
	DrawTriangle(305, 375, 205, 150, 205, 300, colors[RED]);
	DrawTriangle(305, 375, 305, 650, 205, 500, colors[RED]);

	//This Is Continent 2 with 10 territories
	DrawString(355, 660, "Continent 2", colors[BLACK]);
	DrawTriangle(355, 650, 355, 500, 455, 500, colors[YELLOW]);
	DrawTriangle(405, 400, 355, 500, 555, 500, colors[YELLOW]);
	DrawTriangle(355, 650, 455, 650, 455, 500, colors[YELLOW]);
	DrawTriangle(405, 400, 555, 400, 555, 500, colors[YELLOW]);
	DrawRectangle(455, 650, 56, -150, colors[YELLOW]);
	DrawRectangle(511, 650, 45, -150, colors[YELLOW]);
	DrawRectangle(556, 650, 100, -75, colors[YELLOW]);
	DrawTriangle(555, 500, 555, 400, 655, 500, colors[YELLOW]);
	DrawTriangle(555, 575, 555, 500, 655, 500, colors[YELLOW]);
	DrawTriangle(555, 575, 655, 575, 655, 500, colors[YELLOW]);

	//This is CONTINENT 3 with 20 terrories
	DrawString(700, 660, "Continent 3", colors[BLACK]);
	DrawTriangle(700, 650, 700, 500, 800, 500, colors[BLUE]);
	DrawTriangle(900, 650, 900, 500, 800, 500, colors[BLUE]);
	DrawTriangle(750, 575, 800, 500, 850, 575, colors[BLUE]);
	DrawTriangle(750, 575, 800, 650, 850, 575, colors[BLUE]);
	DrawTriangle(700, 650, 800, 650, 750, 575, colors[BLUE]);
	DrawTriangle(900, 650, 800, 650, 850, 575, colors[BLUE]);
	DrawRectangle(700, 500, 56, -150, colors[BLUE]);
	DrawRectangle(756, 500, 100, -75, colors[BLUE]);
	DrawRectangle(756, 425, 100, -75, colors[BLUE]);
	DrawRectangle(756, 350, 100, -75, colors[BLUE]);
	DrawRectangle(756, 275, 100, -75, colors[BLUE]);
	DrawRectangle(900, 500, -56, -150, colors[BLUE]);
	DrawRectangle(700, 350, 56, -150, colors[BLUE]);
	DrawRectangle(900, 350, -56, -150, colors[BLUE]);
	DrawTriangle(700, 200, 700, 50, 800, 200, colors[BLUE]);
	DrawTriangle(900, 200, 900, 50, 800, 200, colors[BLUE]);
	DrawTriangle(750, 125, 800, 200, 850, 125, colors[BLUE]);
	DrawTriangle(750, 125, 800, 50, 850, 125, colors[BLUE]);
	DrawTriangle(700, 50, 800, 50, 750, 125, colors[BLUE]);
	DrawTriangle(900, 50, 800, 50, 850, 125, colors[BLUE]);

	//This is CONTINENT 4 with 10 territories
	DrawString(355, 330, "Continent 4", colors[BLACK]);
	DrawTriangle(355, 320, 355, 250, 280, 250, colors[PURPLE]);
	DrawRectangle(355, 320, 250, -70, colors[PURPLE]);
	DrawRectangle(280, 250, 75, -125, colors[PURPLE]);
	DrawTriangle(280, 125, 355, 125, 355, 55, colors[PURPLE]);
	DrawRectangle(355, 55, 250, 70, colors[PURPLE]);
	DrawTriangle(605, 320, 605, 250, 680, 250, colors[PURPLE]);
	DrawTriangle(605, 125, 605, 55, 680, 125, colors[PURPLE]);
	DrawRectangle(605, 250, 75, -125, colors[PURPLE]);
	DrawRectangle(355, 250, 125, -125, colors[PURPLE]);
	DrawRectangle(605, 250, -125, -125, colors[PURPLE]);

	boardBoundary();
	glutSwapBuffers();
}

//For boundary I used Draw line Function to display to differentiate between territories .
//I also used DrawString Function to Numbers different territories from (0-49).
void boardBoundary() {
	DrawString(58, 600, "0", colors[BLACK]);
	DrawString(100, 400, "1", colors[BLACK]);
	DrawString(180, 600, "2", colors[BLACK]);
	DrawString(180, 450, "3", colors[BLACK]);
	DrawString(170, 340, "4", colors[BLACK]);
	DrawString(170, 250, "5", colors[BLACK]);
	DrawString(230, 600, "6", colors[BLACK]);
	DrawString(210, 450, "7", colors[BLACK]);
	DrawString(220, 280, "8", colors[BLACK]);
	DrawString(280, 560, "9", colors[BLACK]);

	DrawLine(55, 650, 205, 650, 1, colors[BLACK]);
	DrawLine(205, 650, 55, 500, 1, colors[BLACK]);
	DrawLine(55, 500, 55, 650, 1, colors[BLACK]);
	DrawLine(55, 500, 150, 150, 1, colors[BLACK]);
	DrawLine(150, 150, 150, 450, 1, colors[BLACK]);
	DrawLine(150, 450, 55, 500, 1, colors[BLACK]);
	DrawLine(55, 500, 205, 650, 1, colors[BLACK]);
	DrawLine(205, 650, 150, 450, 1, colors[BLACK]);
	DrawLine(150, 450, 55, 500, 1, colors[BLACK]);
	DrawLine(150, 450, 205, 650, 1, colors[BLACK]);
	DrawLine(205, 650, 205, 450, 1, colors[BLACK]);
	DrawLine(205, 450, 150, 450, 1, colors[BLACK]);
	DrawLine(150, 450, 205, 650, 1, colors[BLACK]);
	DrawLine(205, 650, 205, 300, 1, colors[BLACK]);
	DrawLine(150, 300, 205, 300, 1, colors[BLACK]);
	DrawLine(205, 450, 150, 450, 1, colors[BLACK]);
	DrawLine(305, 650, 205, 650, 1, colors[BLACK]);
	DrawLine(205, 650, 205, 500, 1, colors[BLACK]);
	DrawLine(205, 500, 305, 650, 1, colors[BLACK]);
	DrawLine(305, 375, 205, 500, 1, colors[BLACK]);
	DrawLine(205, 500, 205, 300, 1, colors[BLACK]);
	DrawLine(205, 300, 305, 375, 1, colors[BLACK]);
	DrawLine(205, 150, 150, 150, 1, colors[BLACK]);
	DrawLine(205, 150, 305, 375, 1, colors[BLACK]);
	DrawLine(305, 650, 305, 375, 1, colors[BLACK]);
	DrawLine(205, 150, 205, 300, 1, colors[BLACK]);

	DrawString(355, 600, "10", colors[BLACK]);
	DrawString(370, 470, "11", colors[BLACK]);
	DrawString(430, 575, "12", colors[BLACK]);
	DrawString(500, 450, "13", colors[BLACK]);
	DrawString(460, 630, "14", colors[BLACK]);
	DrawString(520, 630, "15", colors[BLACK]);
	DrawString(580, 630, "16", colors[BLACK]);
	DrawString(605, 470, "17", colors[BLACK]);
	DrawString(560, 540, "18", colors[BLACK]);
	DrawString(605, 550, "19", colors[BLACK]);

	DrawLine(355, 650, 355, 500, 1, colors[BLACK]);
	DrawLine(355, 500, 455, 500, 1, colors[BLACK]);
	DrawLine(455, 500, 355, 650, 1, colors[BLACK]);
	DrawLine(405, 400, 355, 500, 1, colors[BLACK]);
	DrawLine(355, 500, 555, 500, 1, colors[BLACK]);
	DrawLine(555, 500, 405, 400, 1, colors[BLACK]);
	DrawLine(355, 650, 455, 650, 1, colors[BLACK]);
	DrawLine(455, 650, 455, 500, 1, colors[BLACK]);
	DrawLine(455, 500, 355, 650, 1, colors[BLACK]);
	DrawLine(405, 400, 555, 400, 1, colors[BLACK]);
	DrawLine(555, 400, 555, 500, 1, colors[BLACK]);
	DrawLine(555, 500, 405, 400, 1, colors[BLACK]);
	DrawLine(455, 650, 511, 650, 1, colors[BLACK]);
	DrawLine(511, 650, 511, 500, 1, colors[BLACK]);
	DrawLine(511, 500, 455, 500, 1, colors[BLACK]);
	DrawLine(455, 500, 556, 500, 1, colors[BLACK]);
	DrawLine(556, 500, 556, 650, 1, colors[BLACK]);
	DrawLine(556, 650, 455, 650, 1, colors[BLACK]);
	DrawLine(455, 500, 556, 500, 1, colors[BLACK]);
	DrawLine(556, 500, 556, 650, 1, colors[BLACK]);
	DrawLine(556, 650, 455, 650, 1, colors[BLACK]);
	DrawLine(555, 500, 655, 500, 1, colors[BLACK]);
	DrawLine(655, 500, 555, 575, 1, colors[BLACK]);
	DrawLine(555, 575, 655, 575, 1, colors[BLACK]);
	DrawLine(655, 575, 655, 500, 1, colors[BLACK]);
	DrawLine(655, 500, 555, 575, 1, colors[BLACK]);
	DrawLine(556, 650, 656, 650, 1, colors[BLACK]);
	DrawLine(656, 575, 656, 650, 1, colors[BLACK]);
	DrawLine(656, 500, 555, 400, 1, colors[BLACK]);

	DrawString(700, 520, "20", colors[BLACK]);
	DrawString(870, 510, "21", colors[BLACK]);
	DrawString(790, 550, "22", colors[BLACK]);
	DrawString(790, 620, "23", colors[BLACK]);
	DrawString(740, 590, "24", colors[BLACK]);
	DrawString(820, 630, "25", colors[BLACK]);
	DrawString(700, 360, "26", colors[BLACK]);
	DrawString(790, 480, "27", colors[BLACK]);
	DrawString(790, 400, "28", colors[BLACK]);
	DrawString(790, 330, "29", colors[BLACK]);
	DrawString(790, 250, "30", colors[BLACK]);
	DrawString(860, 360, "31", colors[BLACK]);
	DrawString(700, 330, "32", colors[BLACK]);
	DrawString(860, 330, "33", colors[BLACK]);
	DrawString(740, 160, "34", colors[BLACK]);
	DrawString(860, 160, "35", colors[BLACK]);
	DrawString(790, 160, "36", colors[BLACK]);
	DrawString(790, 100, "37", colors[BLACK]);
	DrawString(740, 90, "38", colors[BLACK]);
	DrawString(840, 90, "39", colors[BLACK]);

	DrawLine(700, 650, 800, 500, 1, colors[BLACK]);
	DrawLine(900, 650, 800, 500, 1, colors[BLACK]);
	DrawLine(700, 650, 900, 650, 1, colors[BLACK]);
	DrawLine(700, 650, 700, 50, 1, colors[BLACK]);
	DrawLine(900, 650, 900, 50, 1, colors[BLACK]);
	DrawLine(700, 50, 800, 200, 1, colors[BLACK]);
	DrawLine(900, 50, 800, 200, 1, colors[BLACK]);
	DrawLine(700, 50, 900, 50, 1, colors[BLACK]);
	DrawLine(750, 575, 800, 650, 1, colors[BLACK]);
	DrawLine(850, 575, 800, 650, 1, colors[BLACK]);
	DrawLine(750, 575, 850, 575, 1, colors[BLACK]);
	DrawLine(700, 500, 900, 500, 1, colors[BLACK]);
	DrawLine(750, 125, 850, 125, 1, colors[BLACK]);
	DrawLine(750, 125, 800, 50, 1, colors[BLACK]);
	DrawLine(850, 125, 800, 50, 1, colors[BLACK]);
	DrawLine(700, 200, 900, 200, 1, colors[BLACK]);
	DrawLine(700, 350, 900, 350, 1, colors[BLACK]);
	DrawLine(756, 500, 756, 200, 1, colors[BLACK]);
	DrawLine(856, 500, 856, 200, 1, colors[BLACK]);
	DrawLine(756, 425, 856, 425, 1, colors[BLACK]);
	DrawLine(756, 275, 856, 275, 1, colors[BLACK]);

	DrawString(330, 280, "40", colors[BLACK]);
	DrawString(450, 300, "41", colors[BLACK]);
	DrawString(300, 230, "42", colors[BLACK]);
	DrawString(300, 100, "43", colors[BLACK]);
	DrawString(450, 100, "44", colors[BLACK]);
	DrawString(610, 280, "45", colors[BLACK]);
	DrawString(630, 100, "46", colors[BLACK]);
	DrawString(630, 220, "47", colors[BLACK]);
	DrawString(370, 220, "48", colors[BLACK]);
	DrawString(500, 220, "49", colors[BLACK]);

	DrawLine(355, 320, 355, 55, 1, colors[BLACK]);
	DrawLine(605, 320, 605, 55, 1, colors[BLACK]);
	DrawLine(280, 125, 680, 125, 1, colors[BLACK]);
	DrawLine(280, 250, 680, 250, 1, colors[BLACK]);
	DrawLine(280, 250, 280, 125, 1, colors[BLACK]);
	DrawLine(680, 250, 680, 125, 1, colors[BLACK]);
	DrawLine(480, 250, 480, 125, 1, colors[BLACK]);
	DrawLine(355, 320, 605, 320, 1, colors[BLACK]);
	DrawLine(355, 55, 605, 55, 1, colors[BLACK]);
	DrawLine(355, 320, 280, 250, 1, colors[BLACK]);
	DrawLine(280, 125, 355, 55, 1, colors[BLACK]);
	DrawLine(605, 55, 680, 125, 1, colors[BLACK]);
	DrawLine(680, 250, 605, 320, 1, colors[BLACK]);

}


//----------------------------------------------------------------------------------------------------------------------------------------//
//This Function basically asks the user to attack, move or pass the turn.
// Like before i used Draw String functions to display the options.
void menu2Display() {
	glClearColor(1.0, 0.89, 0.77, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	DrawRectangle(250, 500, 400, 50, colors[GREEN]);
	DrawString(300, 525, "Press A to MOVE TROOPS", colors[BLACK]);


	DrawRectangle(250, 400, 400, 50, colors[RED]);
	DrawString(300, 425, "Press B to ATTACK TROOPS", colors[BLACK]);


	DrawRectangle(250, 300, 400, 50, colors[PURPLE]);
	DrawString(300, 325, "Press C to PASS YOUR TURN", colors[BLACK]);
	glutSwapBuffers();
	
}

// This Function checks if all elements in the color array are the same.
//If yes , it return true, if not , it returns false.
//for this i initializzed a variable with the first element of array and made a loops that iterates 50 times.
//to check whether the next element is same as the first one . 
bool winCondition(char color[50]) {
	char firstColor = color[0];

	for (int i = 1; i < 50; i++) {
		if (color[i] != firstColor) {
			return false; 
		}
	}
	return true;
}

//----------------------------------------------------------------------------------------------------------------------------------------//
//This Function Displays Scores of the players at the end of attack territory function on glut screen.
//again , i used draw string function to show the score.
void displayScores(int scores[4]) {
	glClearColor(1.0, 0.89, 0.77, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	DrawString(250, 650, "Player 1 score : " + to_string(scores[0]), colors[BLACK]);
	DrawString(250, 450, "Player 2 score : " + to_string(scores[1]), colors[BLACK]);
	DrawString(250, 350, "THANK YOU FOR PLAYING : " + to_string(scores[1]), colors[BLACK]);
	
	glutSwapBuffers();
}

//----------------------------------------------------------------------------------------------------------------------------------------//
//In This function , I just make the whole updated board again using a loop that i used earlier.
//Then,I took the territory the player want to attack and the territory player wants to attack from
//in a loop that iterates till the winCondition function returns true .
//I have rolled dice for each turn and whoever wins dice basically wins the attack and is assigned a score of 5 (THAT I STORE IN AN ARRAY)
//if the player loses the dice roll the opposite player retains the territory.
//i have also made the turn go counter clockwise.
//this was the logic of this function.
//If a player1 won the diceroll , i stored that elemetn of color array to 'w' character representing wHITE color
//Similarly , for player 2 , i stored that element of color array to 'p' character representing Orange color
//Then , again i call the checkConditions Function , to make the updated board for each turn. but sometimes it malfunctions due to too many nested loops.
//Once all territories get same color, the loop ends and the player with higher scores gets the win . 
//I also call the writeHighscore function to update the values of highscore in the file.
void attackTerritory(int selterr[50], char color[50],string players[4]) {
	glClearColor(1.0, 0.89, 0.77, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 50; i++) {
		glClearColor(1.0, 0.89, 0.77, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		checkConditions(selterr, color, i);

		glutSwapBuffers();
	}
	int currentPlayer = 1;
	int scores[4] = { 0 };

	glClearColor(1.0, 0.89, 0.77, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	while (!winCondition(color)) {
		char wonDice = '\0';
		int terr = 0;
		int attackterr = 0;
		int dice1 = 0;
		int dice2 = 0;
		
		cout << "\n-------------------------------------------\n" << endl;


		do {
			cout << "Player " << currentPlayer << " enter the territory you want to attack from: ";
			cin >> terr;
		} while (terr < 0 || terr > 49);

		do {
			cout << "Player " << currentPlayer << " enter the territory you want to attack on: ";
			cin >> attackterr;
		} while (attackterr < 0 || attackterr > 49);

		cout << "\n-------------------------------------------\n" << endl;

		do {
			dice1 = diceroll();
			dice2 = diceroll();

			cout << "Player " << currentPlayer << "'s dice: " << dice1 << endl;
			cout << "Player " << 3 - currentPlayer << "'s dice: " << dice2 << endl;
			cout << "\n-------------------------------------------\n" << endl;

			if (dice1 > dice2) {
				cout << "Player " << currentPlayer << " won the dice roll." << endl;
				if (currentPlayer == 1) {
					wonDice = 'w';
					
				}
				else if (currentPlayer == 2){
					wonDice = 'p';
					
				}
			}
			else if (dice1 < dice2) {
				cout << "Player " << currentPlayer << " lost the dice roll." << endl;
				if (currentPlayer == 1) {
					wonDice = 'p';
					
				}
				else if (currentPlayer == 2){
					wonDice = 'w';
					
				}
			}
			else {
				cout << "Dice values are equal. Rolling again.\n";
			}

		} while (dice1 == dice2);

		cout << "\n-------------------------------------------\n" << endl;

		if (wonDice == 'w') {
			color[attackterr] = 'w';
			scores[currentPlayer - 1] += 5;
		}
		else if (wonDice == 'p') {
			color[attackterr] = 'p';
		}
		currentPlayer = 3 - currentPlayer; 

		glClearColor(1.0, 0.89, 0.77, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);

		for (int i = 0; i < 50; i++) {
			glClearColor(1.0, 0.89, 0.77, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);
			
			checkConditions(selterr, color, i);

			glutSwapBuffers();
		}
	}

	if (scores[0] > scores[1]) {
		cout << "CONGRATULATIONS TO PLAYER 1 ON BECOMING WORLD CONQUEROR" << endl;
	}
	if (scores[0] < scores[1]) {
		cout << "CONGRATULATIONS TO PLAYER 2 ON BECOMING WORLD CONQUEROR" << endl;
	}
	displayScores(scores);
	writeHighScore(players, scores);
		
}

//----------------------------------------------------------------------------------------------------------------------------------------//
// All the consective three functions below is used to display troops on glut screen . I tried to display the troops in the desired territory .
// but it only displays once . i Tried to display troops using Draw CIRCLE Function.
// the arrays i used stores the troops number in it max 5. but below function fail to display the troops in the territory successfully.
//
void drawTroop(int x, int y, int pl1troop) {
	for (int j = 0; j < pl1troop; j++) {
		DrawCircle(x, y, 4, colors[BLACK]);
		y -= 8;
	}
}

void miniFun(int x,int y,int pl1troop,int selterr[50],char color[50],int i) {
	glClearColor(1.0, 0.89, 0.77, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	checkConditions(selterr, color, i);
	drawTroop(x, y, pl1troop);
	glutSwapBuffers();
}
void displayTroops(int p1[50], int pltroop, int selterr[50], char color[50]) {
	glClearColor(1.0, 0.89, 0.77, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 50; i++) {
		if (p1[i] == 0) {
			miniFun(65, 570, pltroop, selterr, color,i);
		}
		else if (p1[i] == 1) {
			miniFun(130, 400, pltroop, selterr, color,i);
		}
		else if (p1[i] == 2) {
			miniFun(100, 270, pltroop, selterr, color,i);
		}
		else if (p1[i] == 3) {
			miniFun(180, 480, pltroop, selterr, color, i);
		}
		else if (p1[i] == 4) {
			miniFun(180, 380, pltroop, selterr, color, i);
		}
		else if (p1[i] == 5) {
			miniFun(180, 240, pltroop, selterr, color, i);
		}
		else if (p1[i] == 6) {
			miniFun(220, 580, pltroop, selterr, color, i);
		}
		else if (p1[i] == 7) {
			miniFun(130, 400, pltroop, selterr, color, i);
		}
		else if (p1[i] == 8) {
			miniFun(220, 250, pltroop, selterr, color, i);
		}
		else if (p1[i] == 9) {
			miniFun(240, 540, pltroop, selterr, color, i);
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------------------------------//
//This function asks the userthe desired territory to place troops.
//then it asks how many troops does it want to place in the desired territory.
// i have made 2 arrays for player 1 and 2 that can stores the number of troops in it.
//I have taken input in a loop that iterates till the troops become zero.
//At the end , I have called the display troops Function.
void placeTroops(int troops, int selterr[50], char color[50]) {
	cout << "\n---------------------------------------------\n" << endl;
	const int num = 50;
	int p1[num] = { 0 };
	int p2[num] = { 0 };
	int pl1troop = 0, pl2troop = 0;
	int tnum1 = 0, tnum2 = 0;

	do {
		do {
			cout << "Player 1: Enter the territory where you want to place your troops (0-49): ";
			cin >> tnum1;
		} while (tnum1 < 0 || tnum1>49);

		do {
			cout << "How many troops you want to place in territory " << tnum1 << " (Max: 5 troops): ";
			cin >> pl1troop;
		} while (pl1troop < 1 || pl1troop>5);

		p1[tnum1] += pl1troop;
		troops -= pl1troop;
		cout << "\nTroops placed. Remaining troops: " << troops << endl;
		displayTroops(p1, pl1troop, selterr, color);
	} while (troops > 0);
	troops = 20;
	cout << "\n---------------------------------------------\n" << endl;
	do {
		do {
			cout << "Player 2: Enter the territory where you want to place your troops (0-49): ";
			cin >> tnum2;
		} while (tnum2 < 0 || tnum2>49);

		do {
			cout << "How many troops you want to place in territory " << tnum2 << " (Max: 5 troops): ";
			cin >> pl2troop;
		} while (pl2troop < 1 || pl2troop>5);

		p2[tnum2] += pl2troop;
		troops -= pl2troop;
		cout << "\nTroops placed. Remaining troops: " << troops << endl;
		displayTroops(p1, pl2troop, selterr, color);
	} while (troops > 0);

	cout << "\n---------------------------------------------\n" << endl;
}

//--------------------------------------------------------------------------------------------------------------------------------------------//
//I have assigned each player 20 troops.
// This function ask the players to enter the number and type of troops they want.
//  I have asked which type of troops the players want ,either cavalry,infantry or cannons and stored them in a 2D array where ;
//   the first dimension represents the player number and the second one represent the 3 types of troops.
//    I have taken input in a loop that iterates until the sum of all types of troops is 20.
//      At the end, I have displayed them and called the placeTroops Function that is defined above.
void troopsSelect(int selterr[50], char color[50]) {
	cout << "\n---------------------------------------------\n" << endl;
	cout << "All players initially have 20 troops.You can customize ur troops tnto \ninfantry(1 unit),cavalry(2 unit) and cannons(5 unit)" << endl;
	int troops = 20;
	int agents[2][3] = {0};

	cout << "\n---------------------------------------------\n" << endl;
	do {
		cout << "PLAYER 1: Enter number of infantry troops you want" << endl;
		cin >> agents[0][0];
		cout << "Troops Left :    " << (20 - agents[0][0]) << endl;
		cout << "PLAYER 1: Enter number of cavalry troops you want" << endl;
		cin >> agents[0][1];
		cout << "Troops Left :    " << (20 - (agents[0][0] + (agents[0][1] * 2))) << endl;
		cout << "PLAYER 1: Enter number of cannon troops you want" << endl;
		cin >> agents[0][2];
		cout << "Troops Left :    " << (20 - (agents[0][0] + (agents[0][1] * 2) + (agents[0][2] * 5))) << endl;
	} while (agents[0][0] + (agents[0][1] * 2) + (agents[0][2] * 5) != troops);
	cout << endl;

	cout << "\n---------------------------------------------\n" << endl;
	do {
		cout << "PLAYER 2: Enter number of infantry troops you want" << endl;
		cin >> agents[1][0];
		cout << "Troops Left :    " << (20 - agents[1][0]) << endl;
		cout << "PLAYER 2: Enter number of cavalry troops you want" << endl;
		cin >> agents[1][1];
		cout << "Troops Left :    " << (20 - (agents[1][0] + (agents[1][1] * 2))) << endl;
		cout << "PLAYER 2: Enter number of cannon troops you want" << endl;
		cin >> agents[1][2];
		cout << "Troops Left :    " << (20 - (agents[1][0] + (agents[1][1] * 2) + (agents[1][2] * 5))) << endl;
	} while (agents[1][0] + (agents[1][1] * 2) + (agents[1][2] * 5) != troops);
	cout << endl;

	cout << "\n---------------------------------------------\n" << endl;
	cout << "PLAYER 1 has selected the following troops:" << endl;
	cout << "Infantry: " << agents[0][0] << endl;
	cout << "Cavalry: " << agents[0][1] << endl;
	cout << "Cannon: " << agents[0][2] << endl << endl;
	cout << "\n---------------------------------------------\n" << endl;
	cout << "PLAYER 2 has selected the following troops:" << endl;
	cout << "Infantry: " << agents[1][0] << endl;
	cout << "Cavalry: " << agents[1][1] << endl;
	cout << "Cannon: " << agents[1][2] << endl;

	placeTroops(troops, selterr, color);

}

//--------------------------------------------------------------------------------------------------------------------------------------------//
//This function just generates a random number from 1 to 6 . i have called its seed (i.e srand(time(0))) in the int main function.
int diceroll() {
	return rand() % 6 + 1;
}

//--------------------------------------------------------------------------------------------------------------------------------------------//
//This function takes the territories stored in array as parameter as well as the color stores in that territory.
//Then it checks 50 conditions based on who territory to mark it according to the players colors either white or orange.
//This function is also iterating 50 times in loop for each territory . 
void checkConditions(int selterr[50], char color[50], int i) {
	
	boardDisplay();
	// Conditions for Shape 0
	if (selterr[i] == 0) {
		if (color[i] == 'w') {
			DrawTriangle(55, 650, 205, 650, 55, 500, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(55, 650, 205, 650, 55, 500, colors[ORANGE]);
		}
	}
	// Conditions for Shape 1
	else if (selterr[i] == 1) {
		if (color[i] == 'w') {
			DrawTriangle(55, 500, 150, 150, 150, 450, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(55, 500, 150, 150, 150, 450, colors[ORANGE]);
		}
	}
	// Conditions for Shape 2
	else if (selterr[i] == 2) {
		if (color[i] == 'w') {
			DrawTriangle(55, 500, 205, 650, 150, 450, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(55, 500, 205, 650, 150, 450, colors[ORANGE]);
		}
	}
	// Conditions for Shape 3
	else if (selterr[i] == 3) {
		if (color[i] == 'w') {
			DrawTriangle(150, 450, 205, 650, 205, 450, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(150, 450, 205, 650, 205, 450, colors[ORANGE]);
		}
	}
	// Conditions for Shape 4
	else if (selterr[i] == 4) {
		if (color[i] == 'w') {
			DrawRectangle(150, 450, 56, -150, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(150, 450, 56, -150, colors[ORANGE]);
		}
	}
	// Conditions for Shape 5
	else if (selterr[i] == 5) {
		if (color[i] == 'w') {
			DrawRectangle(150, 300, 56, -150, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(150, 300, 56, -150, colors[ORANGE]);
		}
	}
	// Conditions for Shape 6
	else if (selterr[i] == 6) {
		if (color[i] == 'w') {
			DrawTriangle(305, 650, 205, 500, 205, 650, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(305, 650, 205, 500, 205, 650, colors[ORANGE]);
		}
	}
	// Conditions for Shape 7
	if (selterr[i] == 7) {
		if (color[i] == 'w') {
			DrawTriangle(305, 375, 205, 500, 205, 300, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(305, 375, 205, 500, 205, 300, colors[ORANGE]);
		}
	}
	// Conditions for Shape 8
	else if (selterr[i] == 8) {
		if (color[i] == 'w') {
			DrawTriangle(305, 375, 205, 150, 205, 300, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(305, 375, 205, 150, 205, 300, colors[ORANGE]);
		}
	}
	// Conditions for Shape 9
	else if (selterr[i] == 9) {
		if (color[i] == 'w') {
			DrawTriangle(305, 375, 305, 650, 205, 500, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(305, 375, 305, 650, 205, 500, colors[ORANGE]);
		}
	}

	// Conditions for Shape 10
	else if (selterr[i] == 10) {
		if (color[i] == 'w') {
			DrawTriangle(355, 650, 355, 500, 455, 500, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(355, 650, 355, 500, 455, 500, colors[ORANGE]);
		}
	}

	// Conditions for Shape 11
	else if (selterr[i] == 11) {
		if (color[i] == 'w') {
			DrawTriangle(405, 400, 355, 500, 555, 500, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(405, 400, 355, 500, 555, 500, colors[ORANGE]);
		}
	}

	// Conditions for Shape 12
	else if (selterr[i] == 12) {
		if (color[i] == 'w') {
			DrawTriangle(355, 650, 455, 650, 455, 500, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(355, 650, 455, 650, 455, 500, colors[ORANGE]);
		}
	}

	// Conditions for Shape 13
	else if (selterr[i] == 13) {
		if (color[i] == 'w') {
			DrawTriangle(405, 400, 555, 400, 555, 500, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(405, 400, 555, 400, 555, 500, colors[ORANGE]);
		}
	}

	// Conditions for Shape 14
	else if (selterr[i] == 14) {
		if (color[i] == 'w') {
			DrawRectangle(455, 650, 56, -150, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(455, 650, 56, -150, colors[ORANGE]);
		}
	}

	// Conditions for Shape 15
	else if (selterr[i] == 15) {
		if (color[i] == 'w') {
			DrawRectangle(511, 650, 45, -150, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(511, 650, 45, -150, colors[ORANGE]);
		}
	}

	// Conditions for Shape 16
	else if (selterr[i] == 16) {
		if (color[i] == 'w') {
			DrawRectangle(556, 650, 100, -75, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(556, 650, 100, -75, colors[ORANGE]);
		}
	}

	// Conditions for Shape 17
	else if (selterr[i] == 17) {
		if (color[i] == 'w') {
			DrawTriangle(555, 500, 555, 400, 655, 500, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(555, 500, 555, 400, 655, 500, colors[ORANGE]);
		}
	}

	// Conditions for Shape 18
	else if (selterr[i] == 18) {
		if (color[i] == 'w') {
			DrawTriangle(555, 575, 555, 500, 655, 500, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(555, 575, 555, 500, 655, 500, colors[ORANGE]);
		}
	}

	// Conditions for Shape 19
	else if (selterr[i] == 19) {
		if (color[i] == 'w') {
			DrawTriangle(555, 575, 655, 575, 655, 500, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(555, 575, 655, 575, 655, 500, colors[ORANGE]);
		}
	}
	// Conditions for Shape 20
	else if (selterr[i] == 20) {
		if (color[i] == 'w') {
			DrawTriangle(700, 650, 700, 500, 800, 500, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(700, 650, 700, 500, 800, 500, colors[ORANGE]);
		}
	}

	// Conditions for Shape 21
	else if (selterr[i] == 21) {
		if (color[i] == 'w') {
			DrawTriangle(900, 650, 900, 500, 800, 500, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(900, 650, 900, 500, 800, 500, colors[ORANGE]);
		}
	}

	// Conditions for Shape 22
	else if (selterr[i] == 22) {
		if (color[i] == 'w') {
			DrawTriangle(750, 575, 800, 500, 850, 575, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(750, 575, 800, 500, 850, 575, colors[ORANGE]);
		}
	}

	// Conditions for Shape 23
	else if (selterr[i] == 23) {
		if (color[i] == 'w') {
			DrawTriangle(750, 575, 800, 650, 850, 575, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(750, 575, 800, 650, 850, 575, colors[ORANGE]);
		}
	}

	// Conditions for Shape 24
	else if (selterr[i] == 24) {
		if (color[i] == 'w') {
			DrawTriangle(700, 650, 800, 650, 750, 575, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(700, 650, 800, 650, 750, 575, colors[ORANGE]);
		}
	}

	// Conditions for Shape 25
	else if (selterr[i] == 25) {
		if (color[i] == 'w') {
			DrawTriangle(900, 650, 800, 650, 850, 575, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(900, 650, 800, 650, 850, 575, colors[ORANGE]);
		}
	}

	// Conditions for Shape 26
	else if (selterr[i] == 26) {
		if (color[i] == 'w') {
			DrawRectangle(700, 500, 56, -150, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(700, 500, 56, -150, colors[ORANGE]);
		}
	}

	// Conditions for Shape 27
	else if (selterr[i] == 27) {
		if (color[i] == 'w') {
			DrawRectangle(756, 500, 100, -75, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(756, 500, 100, -75, colors[ORANGE]);
		}
	}

	// Conditions for Shape 28
	else if (selterr[i] == 28) {
		if (color[i] == 'w') {
			DrawRectangle(756, 425, 100, -75, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(756, 425, 100, -75, colors[ORANGE]);
		}
	}

	// Conditions for Shape 29
	else if (selterr[i] == 29) {
		if (color[i] == 'w') {
			DrawRectangle(756, 350, 100, -75, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(756, 350, 100, -75, colors[ORANGE]);
		}
	}

	// Conditions for Shape 30
	else if (selterr[i] == 30) {
		if (color[i] == 'w') {
			DrawRectangle(756, 275, 100, -75, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(756, 275, 100, -75, colors[ORANGE]);
		}
	}

	// Conditions for Shape 31
	else if (selterr[i] == 31) {
		if (color[i] == 'w') {
			DrawRectangle(900, 500, -56, -150, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(900, 500, -56, -150, colors[ORANGE]);
		}
	}

	// Conditions for Shape 32
	else if (selterr[i] == 32) {
		if (color[i] == 'w') {
			DrawRectangle(700, 350, 56, -150, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(700, 350, 56, -150, colors[ORANGE]);
		}
	}

	// Conditions for Shape 33
	else if (selterr[i] == 33) {
		if (color[i] == 'w') {
			DrawRectangle(900, 350, -56, -150, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(900, 350, -56, -150, colors[ORANGE]);
		}
	}

	// Conditions for Shape 34
	else if (selterr[i] == 34) {
		if (color[i] == 'w') {
			DrawTriangle(700, 200, 700, 50, 800, 200, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(700, 200, 700, 50, 800, 200, colors[ORANGE]);
		}
	}

	// Conditions for Shape 35
	else if (selterr[i] == 35) {
		if (color[i] == 'w') {
			DrawTriangle(900, 200, 900, 50, 800, 200, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(900, 200, 900, 50, 800, 200, colors[ORANGE]);
		}
	}

	// Conditions for Shape 36
	else if (selterr[i] == 36) {
		if (color[i] == 'w') {
			DrawTriangle(750, 125, 800, 200, 850, 125, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(750, 125, 800, 200, 850, 125, colors[ORANGE]);
		}
	}

	// Conditions for Shape 37
	else if (selterr[i] == 37) {
		if (color[i] == 'w') {
			DrawTriangle(750, 125, 800, 50, 850, 125, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(750, 125, 800, 50, 850, 125, colors[ORANGE]);
		}
	}

	// Conditions for Shape 38
	else if (selterr[i] == 38) {
		if (color[i] == 'w') {
			DrawTriangle(700, 50, 800, 50, 750, 125, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(700, 50, 800, 50, 750, 125, colors[ORANGE]);
		}
	}

	// Conditions for Shape 39
	else if (selterr[i] == 39) {
		if (color[i] == 'w') {
			DrawTriangle(900, 50, 800, 50, 850, 125, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(900, 50, 800, 50, 850, 125, colors[ORANGE]);
		}
	}


	// Conditions for Shape 40
	else if (selterr[i] == 40) {
		if (color[i] == 'w') {
			DrawTriangle(355, 320, 355, 250, 280, 250, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(355, 320, 355, 250, 280, 250, colors[ORANGE]);
		}
	}

	// Conditions for Shape 41
	else if (selterr[i] == 41) {
		if (color[i] == 'w') {
			DrawRectangle(355, 320, 250, -70, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(355, 320, 250, -70, colors[ORANGE]);
		}
	}

	// Conditions for Shape 42
	else if (selterr[i] == 42) {
		if (color[i] == 'w') {
			DrawRectangle(280, 250, 75, -125, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(280, 250, 75, -125, colors[ORANGE]);
		}
	}

	// Conditions for Shape 43
	else if (selterr[i] == 43) {
		if (color[i] == 'w') {
			DrawTriangle(280, 125, 355, 125, 355, 55, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(280, 125, 355, 125, 355, 55, colors[ORANGE]);
		}
	}

	// Conditions for Shape 44
	else if (selterr[i] == 44) {
		if (color[i] == 'w') {
			DrawRectangle(355, 55, 250, 70, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(355, 55, 250, 70, colors[ORANGE]);
		}
	}

	// Conditions for Shape 45
	else if (selterr[i] == 45) {
		if (color[i] == 'w') {
			DrawTriangle(605, 320, 605, 250, 680, 250, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(605, 320, 605, 250, 680, 250, colors[ORANGE]);
		}
	}

	// Conditions for Shape 46
	else if (selterr[i] == 46) {
		if (color[i] == 'w') {
			DrawTriangle(605, 125, 605, 55, 680, 125, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawTriangle(605, 125, 605, 55, 680, 125, colors[ORANGE]);
		}
	}

	// Conditions for Shape 47
	else if (selterr[i] == 47) {
		if (color[i] == 'w') {
			DrawRectangle(605, 250, 75, -125, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(605, 250, 75, -125, colors[ORANGE]);
		}
	}

	// Conditions for Shape 48
	else if (selterr[i] == 48) {
		if (color[i] == 'w') {
			DrawRectangle(355, 250, 125, -125, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(355, 250, 125, -125, colors[ORANGE]);
		}
	}

	// Conditions for Shape 49
	else if (selterr[i] == 49) {
		if (color[i] == 'w') {
			DrawRectangle(605, 250, -125, -125, colors[WHITE]);
		}
		else if (color[i] == 'p') {
			DrawRectangle(605, 250, -125, -125, colors[ORANGE]);
		}
	}
	//Here nothing new just adding boundary and number to the new updated map.
	boardBoundary();
}

//--------------------------------------------------------------------------------------------------------------------------------------------//
//In This function . I am marking the territories .
//I have Assigned Player 1 White Color and Player 2 Orange Color.
//I have rolled dice roll for first player and then the turn passes counter clockwise.
//I have currently stored territories numbers in an array with size 50 (from 0-49)
// I have also made an array of color with size 50 which stores the color (either white or orange ) based on player who marks the territory
//Once a territory is selected by player i have a function (i.e ,checkConditions) that checks 50 conditions to change
//the color of that specific territory to either white or orange
//At the end, I have called troopsCustomization function that is declared and defined above.

void updatedBoardDisplay(int selterr[50],char color[50]) {
	cout << "-------------------------------------------------" << endl;
	cout << "\nPlease Select your territories\n" << endl;
	
	int valid[50] = { 0 };
	int count1 = 0, count2 = 0;
	char startPlayer = '\0';

	int dice1 = diceroll();
	int dice2 = diceroll();

	do {
		cout << "Player 1's dice : " << dice1 << endl;
		cout << "Player 2's dice : " << dice2 << endl;
		cout << "\n-------------------------------------------\n" << endl;
	} while (dice1 == dice2);

	if (dice1 > dice2) {
		cout << "Player 1 won dice roll ";
		startPlayer = 'w';
	}
	else {
		cout << "Player 2 won dice roll ";
		startPlayer = 'p';
	}
	cout << "\n-------------------------------------------\n" << endl;
	char col = startPlayer;

	glClearColor(1.0, 0.89, 0.77, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < 50; i++) {
		cout << "Player ";

		if (col == 'w') {
			color[i] = 'w';
			cout << "1 turn : " << endl;
		}
		else {
			color[i] = 'p';
			cout << "2 turn : " << endl;
		}

		//VALIDATION OF ARRAY SO THAT NO INPUT NUM IS OUTSIDE OF [0,49] RANGE. 
		//AND THE PERSON CAN NOT MARK THE TERRITORY THAT IS ALREADY MARKED. 

		do {
			cout << "\nIn which territory do you wish to mark your troops ? " << endl;
			cin >> selterr[i];
		} while (selterr[i] < 0 || selterr[i]>49);

		valid[i] = selterr[i];

		for (int j = 0; j < i; j++) {

			while (valid[i] == selterr[j]) {
				cout << "\nThis territory is already marked ! Enter again" << endl;
				cin >> selterr[i];
				valid[i] = selterr[i];
				j = 0;
			}
		}

		glClearColor(1.0, 0.89, 0.77, 1.0);
		glClear(GL_COLOR_BUFFER_BIT);
		checkConditions(selterr, color, i);
		glutSwapBuffers();

		if (col == 'w') {
			count1++;
			col = 'p';
		}
		else {
			count2++;
			col = 'w';
		}
	}
	cout << "\n---------------------------------------------\n" << endl;
	cout << "All territories are marked" << endl;
	cout << "The territories occupied by Player 1 is : " << count1 << endl;
	cout << "The territories occupied by Player 2 is : " << count2 << endl;
	cout << "\n---------------------------------------------\n" << endl;

	int e=0;
	do {
		cout << "Press 1 to continue to troops Customization : " << endl;
		cin >> e;
	} while (e != 1);

		troopsSelect(selterr, color);
	
}

//--------------------------------------------------------------------------------------------------------------------------------------------//
//This function is used to write to a file at the end of the game and adds score to the file(highScores.txt) that is saved permanently.
void writeHighScore(string players[4], int scores[4]) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 3; j++) {
			if (scores[j] < scores[j + 1]) {
				int temp = scores[j];
				scores[j] = scores[j + 1];
				scores[j + 1] = temp;

				string t = players[j];
				players[j] = players[j + 1];
				players[j + 1] = t;
			}
		}

	}
	ofstream obj("highScores.txt", ios::out);

	for (int i = 0; i < 4; i++) {
		obj << players[i] << "\t" << scores[i] << endl;
	}

	obj.close();
}

//--------------------------------------------------------------------------------------------------------------------------------------------//
//This function is used to read from the file (highScores.txt) that i have fed data in writeHighscore Function.
void readHighScore(string players[4], int scores[4]) {
	ifstream obj("highScores.txt", ios::in);

	if (obj.is_open()) {
		for (int i = 0; i < 4; i++) {
			obj >> players[i];
			obj >> scores[i];
		}
		obj.close();
	}
	else {
		for (int i = 0; i < 4; i++) {
			scores[i] = 0;
		}
	}
}

//--------------------------------------------------------------------------------------------------------------------------------------------//
//This function is used to display HIGHSCORES by reading from the file (highScores.txt).
void displayHighScore() {
	string players[4] ;
	int scores[4] = { 0 };
	glClearColor(1.0, 0.89, 0.77, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	int y = 700;
	readHighScore(players, scores);

	for (int i = 0; i < 4; i++) {
		DrawString(120, y, "Player : " + players[i], colors[BLACK]);
		DrawString(420, y, "Score : " + to_string(scores[i]), colors[BLACK]);
		y -= 100;
	}

	DrawRectangle(50, 800, 100, -50, colors[GRAY]);
	DrawString(50 + 25, 800 - 25, "BACK", colors[BLACK]);
	glutSwapBuffers();
}

//--------------------------------------------------------------------------------------------------------------------------------------------//
//This function takes names of the players and stores them in an array of string that it takes as argument in the Gameplay Function.
void userInfo(string players[4]) {

	int num = 0;
	do {
		cout << "ENTER THE NUMBER OF PLAYERS PLAYING THIS GAME (2-4): ";
		cin >> num;
		if (num < 2 || num>4) {
			cout << "\n\tWrong input !! " << endl;
		}
	} while (num < 2 ||  num>4);

	cout << "-----------------------------------------------------------\n" << endl;
	if (num == 2) {
		cout << "Player 1 : Enter your name ";
		cin >> players[0];
		cout << "Player 2 : Enter your name ";
		cin >> players[1];
	}
	else if (num == 3) {
		cout << "Player 1 : Enter your name ";
		cin >> players[0];
		cout << "Player 2 : Enter your name ";
		cin >> players[1];
		cout << "Player 3 : Enter your name ";
		cin >> players[2];
	}
	else if (num == 4) {
		cout << "Player 1 : Enter your name ";
		cin >> players[0];
		cout << "Player 2 : Enter your name ";
		cin >> players[1];
		cout << "Player 3 : Enter your name ";
		cin >> players[2];
		cout << "Player 4 : Enter your name ";
		cin >> players[3];
	}
	

}

//--------------------------------------------------------------------------------------------------------------------------------------------//
//THIS FUNCTION DISPLAYS INSTRUCTIONS FOR THE GAME NOTHING NEW
void instructions() {
	glClearColor(1.0, 0.89, 0.77, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	DrawString(200, 750, "Objective:", colors[BLACK]);
	DrawString(100, 770-80, "The primary objective of Risk is to achieve world domination", colors[BLACK]);

	DrawString(100, 740 - 80, "Components:", colors[BLACK]);
	DrawString(100, 710 - 80, "- Game board: A world map divided into territories, continents,&regions.", colors[BLACK]);
	DrawString(100, 680 - 80, "- Armies: Plastic miniatures representing military units.", colors[BLACK]);
	DrawString(100, 650 - 80, "- Cards: Divided into three types - Infantry, Cavalry, and Artillery.", colors[BLACK]);
	DrawString(100, 620 - 80, "- Dice: Used for resolving battles.", colors[BLACK]);
	DrawString(100, 590 - 80, "Strategies:", colors[BLACK]);
	DrawString(100, 560 - 80, "- Expansion: Secure continents for bonus reinforcements.", colors[BLACK]);
	DrawString(100, 530 - 80, "- Defensive Play: Fortify borders and build up armies before launching attacks.", colors[BLACK]);
	DrawString(100, 500 - 80, "- Alliances: Diplomacy can be a key aspect, but alliances can be broken at any time.", colors[BLACK]);
	DrawString(100, 470 - 80, "Gameplay:", colors[BLACK]);
	DrawString(100, 440 - 80, "Players take turns in a clockwise order, and each turn is divided into 3 phases:", colors[BLACK]);
	DrawString(120, 410 - 80, "j) To start the game each player will roll a dice. The one with the highest number will take the first turn.", colors[BLACK]);
	DrawString(120, 380 - 80, "k) Every player will start occupying territories in clockwise order by clicking on a particular territory.", colors[BLACK]);
	DrawString(120, 350 - 80, "l) Once the territories are occupied, the player with the maximum number of territories should be selected.", colors[BLACK]);
	DrawString(120, 320 - 80, "m) Starting with the player with the highest number of territories gets to go first and place additional units on the board.", colors[BLACK]);
	DrawString(120, 290 - 80, "- Attack Phase: Players can attack adjacent territories using dice rolls to determine the outcome of battles.", colors[BLACK]);
	DrawString(120, 260 - 80, "- Fortification Phase: Players can move armies between their territories to reinforce borders or consolidate forces.", colors[BLACK]);
	DrawString(120, 230 - 80, "n) Card Phase: Players receive cards for conquering territories. Sets of cards can be traded for additional armies.", colors[BLACK]);
	DrawString(100, 200 - 80, "Winning the Game:", colors[BLACK]);
	DrawString(120, 170 - 80, "o) A player wins by eliminating opponents and controlling all territories ",colors[BLACK]);
	DrawString(120, 140 - 80,"or by achieving a specific mission, depending on the game variant.", colors[BLACK]);

	DrawRectangle(50, 800, 100, -50, colors[GRAY]);
	DrawString(50 + 25, 800 - 25, "Back", colors[BLACK]);
	glutSwapBuffers();
}

//--------------------------------------------------------------------------------------------------------------------------------------------//
//THIS FUNCTION DISPLAYS CREDITS SECTION IN MENU . NOTHING MORE, I JUST USED DRAW STRING FUNCTION TO DISPLAY STRINGS.
void credits() {
	glClearColor(1.0, 0.89, 0.77, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	DrawString(100, 680, "CREATED BY \"UZAIR MAJEED\"", colors[BLACK]);
	DrawString(100, 650, "ROLL NUMBER: 23I-3063", colors[BLACK]);
	DrawString(100, 620, "SECTION: SE-B", colors[BLACK]);
	DrawString(100, 590, "COURSE: PROGRAMMING FUNDAMENTALS", colors[BLACK]);
	DrawString(100, 560, "COURSE INSTRUCTOR AND DEPARTMENT HOD:", colors[BLACK]);
	DrawString(100, 530, "\"SIR NAVEED AHMED\"", colors[BLACK]);
	DrawString(100, 500, "CONTACT ME AT: i233063@isb.nu.edu.pk", colors[BLACK]);

	DrawRectangle(50, 800, 100, -50, colors[GRAY]);
	DrawString(50 + 25, 800 - 25, "BACK", colors[BLACK]);
	glutSwapBuffers();

}

//--------------------------------------------------------------------------------------------------------------------------------------------//
//THIS FUNCTION DISPLAYS MENU FOR THE USER. I USED DRAWSTRING AND DRAW RECTANGLE FUNCTION TO DISPLAY DIFFERENT OPTION IN MENU.
void menuDisplay() {
	glClearColor(1.0, 0.89, 0.77, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);

	DrawString(250, 800, "WELCOME TO RISK GAME", colors[RED]);
	DrawString(250, 700, "MENU", colors[RED]);

	DrawRectangle(250, 600, 400, 50, colors[GRAY]);
	DrawString(300, 625, "Press 1 to START GAME", colors[BLACK]);

	
	DrawRectangle(250, 500, 400, 50, colors[GRAY]);
	DrawString(300, 525, "Press 2 to access HIGHSCORES", colors[BLACK]);

	
	DrawRectangle(250, 400, 400, 50, colors[GRAY]);
	DrawString(300, 425, "Press 3 to see INSTRUCTIONS", colors[BLACK]);

	
	DrawRectangle(250, 300, 400, 50, colors[GRAY]);
	DrawString(300, 325, "Press 4 to see CREDITS", colors[BLACK]);

	
	DrawRectangle(250, 200, 400, 50, colors[GRAY]);
	DrawString(300, 225, "Press 5 to QUIT GAME", colors[BLACK]);

	glutSwapBuffers();

}
//--------------------------------------------------------------------------------------------------------------------------------------------//
//THIS IS THE MAIN GAMEPLAY FUNCTION
//I have declared array of players and territories int his function.
//The main this function does is that it used global variable (menu) and uses switch statement
//to call the desired function based on value of menu variable.
//the value of menu variable depends upon the key pressed in glut screen.
void GameDisplay() {
	string players[4];

	int selterr[50] = { 0 };
	char color[50] = { 0 };
	int e = 0;

	switch (menu) {
	case 0: {
		menuDisplay();
		break;
	}
	case 1: {
		boardDisplay();
		userInfo(players);
		cout << "----------------------------------------------------------------------\n";
		do {
			cout << "Press 1 to continue back to GAME : " << endl;
			cin >> e;
		} while (e != 1);

		if (e == 1) {
			updatedBoardDisplay(selterr,color);
			glutSwapBuffers();
			
			menu2Display();

			char key = '\0';
			do {
				cout << "ENTER YOUR DESIRED OPTION PLEASE : " << endl;
				cin >> key;
			} while (key != 'a' && key != 'A' && key != 'b' && key != 'B' && key != 'c' && key != 'C');

			attackTerritory(selterr, color,players);
		}
		break;
	}
	case 2: {
		displayHighScore();
		break;
	}
	case 3: {
		instructions();
		break;
	}
	case 4:{
		credits();
		break;
	}
	case 5: {
		exit(0);
		break;
	}
	}
}
//--------------------------------------------------------------------------------------------------------------------------------------------//
void SetCanvasSize(int width, int height) {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

//--------------------------------------------------------------------------------------------------------------------------------------------//
void NonPrintableKeys(int key, int x, int y) {
	if (key
		== GLUT_KEY_LEFT) {

	}
	else if (key
		== GLUT_KEY_RIGHT) {

	}
	else if (key
		== GLUT_KEY_UP) {

	}

	else if (key
		== GLUT_KEY_DOWN) {

	}


	glutPostRedisplay();

}

//--------------------------------------------------------------------------------------------------------------------------------------------//
//In this function , once a key is pressed,it updates the value of global variable (menu) which is then used in the gameDisplay FUNCTION.
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == '1') {
		menu = 1;
	}

	else if (key == '2') {
		menu = 2;
	}

	else if (key == '3') {
		menu = 3;
	}

	else if (key == '4') {
		menu = 4;
	}

	else if (key == '5') {
		menu = 5;
	}
	else if (key == static_cast<char>(27)) {
		menu = 0;
	}
	glutPostRedisplay();

}

//--------------------------------------------------------------------------------------------------------------------------------------------//
void Timer(int m) {

	glutTimerFunc(1000.0, Timer, 0);
}

void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {

	glutPostRedisplay();
}

//--------------------------------------------------------------------------------------------------------------------------------------------//
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) 
	{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	}
	else if (button == GLUT_RIGHT_BUTTON) 
	{

	}
glutPostRedisplay();
}

//---------------------------------------------------------------THE-----------END-------------------------------------------------------------//