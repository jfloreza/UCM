#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class Grid
{ 
   public:
	Grid();
	Grid(int rows, int cols);
	T getCell(int row, int col);
	void loadFromFile(string filename);
	void display();
	T solve();
   private:
	T grid[20][20];
	int Nrows, Ncols;
	int startRow, startCol, goalRow, goalCol;
};

template <typename T> Grid<T>::Grid() {

}

template <typename T> Grid<T>::Grid(int rows, int cols) {
	T grid[rows][cols];
}

template <typename T> T Grid<T>::getCell(int row, int col) { 
	T cell = grid[row][col];
	return cell;
}

template <typename T> void Grid<T>::loadFromFile(string filename) {
	
ifstream infile(filename.c_str());
char c;
int i, j;

for (i = 0; i < 9; i++) {
	for (j = 0; j < 7; j++) {
		infile >> c;
		while( (c==' ') || (c=='\t') || (c == '\n'));
		switch(c) {
			case'.': grid[i][j] = T(true); break;
			case'#': grid[i][j] = T(false); break;
			case'S': grid[i][j] = T(true); startRow = i; startCol = j; break;
			case'G': grid[i][j] = T(true); goalRow = i; goalCol = j; break;
			default : cerr << "invalid character in maze" << endl;
			}
		}
	}
}

template <typename T> void Grid<T>::display() {
	int i, j;
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 7; j++) {
			if (j == 6){cout << grid[i][j] << " " << endl;}
			else cout << grid[i][j] << " ";
		}
	}
}

template <typename T> T Grid<T>::solve() {
	stack <char> c;
	int i = startRow;
	int j = startCol;
	bool n,s,e,w;
	c.push('B');
	cout << "Start:" << startRow + 1 << " " << startCol + 1 << endl;
	cout << "End:" << goalRow + 1 << " " << goalCol + 1 << endl;
	while (!c.empty()) {
	if (i == goalRow && j == goalCol){cout << "Finished" << endl;}
		
	n = getCell(i-1, j);
	s = getCell(i+1, j);
	e = getCell(i, j+1);
	w = getCell(i, j-1);
	
	}
	cout << "No solution or failed to solve" << endl;
	cout << c.top() << endl;
}
