#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdio>

using namespace std;

bool rdiag(char play[][11], int s); 
bool ldiag(char play[][11], int s); 
bool vertical(char play[][11], int s, int x); 
bool contour(char play[][11], int s, int y); 
char gaming(int s); 
int game(char play[][11], int s, char player1[], char player2[]); 
int vvod(char play[][11]); 

void 

int vvod(char play[][11]){
	int p = 0, k = 0;
	int x, y;
	char *t = new char [255];
	gets(t);
	for(int i = 0; t[i] = '\0'; i++){
		if(((t[i] < '0') || (t[i] > '9')) && t[i] != ' ') { cout << "Error. Please enter two numbers >= 1 and <= 10 again." << endl; p = 1 k++; 				break; }
	if(p == 0)
	}
	/*do{
		cin >> x;			
		if ((x > 10) || (x < 1)) { cout << "Error. Please enter two numbers >= 1 and <= 10 again." << endl; p = 1; cin >> x; continue;}
		cin >> y;
		if ((y > 10) || (y < 1)) { cout << "Error. Please enter two numbers >= 1 and <= 10 again." << endl; p = 1; continue;}
		if (play[y - 1][x - 1] != '.')  { cout << "Error. Please enter two numbers >= 1 and <= 10 again, because this place is already entered." << endl; p = 1; continue;}
		break;
	} while (1);*/
	x--; y--;
	return (x * 10 + y);
}

bool rdiag(char play[][11], int s, int x, int y){
	if (9 - x >= y){
		x += y;
		y = 0;
	}
	else{
		y -= (9 - x);
		x = 9;
	}
	int count = 0;
	for (; y < 10, x >= 0; y++, x--){
		if (play[y][x] == gaming(s)) count++; else count = 0;
		if (count >= 5) break;
	}
	return (count >= 5);
}

bool ldiag(char play[][11], int s, int x, int y){
	if (x >= y){
		x -= y;
		y = 0;
	}
	else {
		y -= x;
		x = 0;
	}
	int count = 0;
	for (; (y < 10), (x < 10); x++, y++){
		if (play[y][x] == gaming(s)) count++; else count = 0;
		if (count >= 5) break;
	}
	return (count >= 5);
}

bool vertical(char play[][11], int s, int x){
	int count = 0;
	for (int i = 0; i < 10; i++){
		if (play[i][x] == gaming(s)) count++; else count = 0;
		if (count >= 5) break;
	}
	return (count >= 5);
}

bool contour(char play[][11], int s, int y){
	int count = 0;
	for (int i = 0; i < 10; i++){
		if (play[y][i] == gaming(s)) count++; else count = 0;
		if (count >= 5) break;
	}
	return (count >= 5);
}

char gaming(int s){
	if (s == 0) return 'x';
	return 'o';
}

int game(char play[][11], int s, char player1[], char player2[]){
	setlocale(LC_ALL, "Russian");
	for (int i = 0; i < 11; i++) cout << i << "  ";
	cout << endl;
	for (int i = 0; i < 10; i++){
		if (i != 9)cout << i + 1 << "  "; else cout << i + 1 << " ";
		for (int j = 0; j < 10; j++)
			cout << play[i][j] << "  ";
		cout << endl;
	}
	cout  << ((s == 0) ? player1 : player2) << " is walking" << endl;
	int x, y;
	x = vvod(play);
	for (int i = 0; i < 10; i++) cout << endl;
	y = x % 10;
	x = x / 10;
	play[y][x] = gaming(s);
	if (contour(play, s, y) || vertical(play, s, x)|| ldiag(play, s, x, y)|| rdiag(play, s, x, y)) {
		if (s == 0) cout << player1;
		else
			cout << player2;
		cout << " won this game";
		cout << endl;
		s = -1;
		return s;
	}
	s = (s + 1) % 2;
	return s;
}

int main(){ 
	setlocale(LC_ALL, "Russian");
	char player1[32];
	cout << "Player 1, please enter your name:  ";
	gets(player1);
	char player2[32];
	cout << "Player 2, please enter your name:  ";
	gets(player2);
	int s = 0;
	char play[11][11];
	for (int i = 0; i < 10; i++)
	for (int j = 0; j < 10; j++) play[j][i] = '.';
	int i;
	for (i = 0; i < 100, s != -1; i++){
		s = game(play, s, player1, player2);
	}
	if (i >= 99) cout << "Draw" << endl;
	return 0;
}
