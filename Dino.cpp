#include <conio.h>
#include <iostream>
#include <windows.h>
using namespace std;

bool GameOver = false;
bool isJumping = false;
int DinoX = 5;
int DinoY;
int ObstacleX;
int Score = 0;
int JumpCount = 0;
	
const int Width = 50;
const int Height = 10;
	
void Draw(){
		for (int Y = 0; Y < Height; Y++){
			
			for(int X = 0; X < Width; X++){
				
				if (X == 5 && Y == DinoY){
					cout << "D";
				}
				else if (X == ObstacleX && Y == Height - 1){
					cout << "|";
				}
				else {
					cout << " ";
				}
			}
			cout << endl;
		}
		cout << endl;	
}

void Input(){
	if (kbhit()){
		char Key = getch();
			if (Key == ' '){
				isJumping = true;
			}
	}
}

void logic(){
	if (isJumping){
		DinoY--;
		JumpCount++;
	}
	if (JumpCount >= 5){
		isJumping = false;
		JumpCount = 0;
	}
	if(!isJumping && DinoY < Height - 1){
		DinoY++;
	}
	if (ObstacleX == DinoX && DinoY == Height - 1){
		GameOver = true;
	}
	ObstacleX--;
	if (ObstacleX < 0){
		ObstacleX = Width - 1;
		Score++;
	}
}

int main(){
	DinoY = Height - 1;
	ObstacleX = Width - 1; 
	
	while(!GameOver) {
	system("cls");
	Draw();
	Input();
	logic();
	Sleep(100);
	}
	cout << "Game Over! Your Score is: " << Score << endl;
	return 0;
}