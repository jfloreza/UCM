#include <iostream>
#include "grid.h"

using namespace std;

int main(int argc, char *argv[]) {
	Grid<bool> map;
	map.loadFromFile("maze.txt");
	cout << "Maze loaded from text" << endl;
	map.display();
	map.solve();
	return 0;
}
