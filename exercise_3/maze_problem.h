#include<iostream>
#include<fstream>
#include<stack>
#include<string>

using namespace std;

//flag of whether find the exit or not
bool exitFinded;

struct Map {
	char **map;
	int x;
	int y;
};

struct Point {
	int x;
	int y;
};

//print the map with row and column number
void PrintMap(char **map,int a,int b) {
	cout << "ÃÔ¹¬µØÍ¼:" << endl;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			if (i == 0 && j == 0) {
				cout << "\t";
			}
			else if (i == 0 && j != 0) {
				cout << j - 1 << "ÁÐ" << "\t";
			}
			else if (i != 0 && j == 0) {
				cout << i - 1 << "ÐÐ" << "\t";
			}
			else {
				cout << map[i - 1][j - 1] << "\t";
			}
		}
		cout << endl << endl;
	}
}

//use the recursion type of DFS to find the path
void FindPath(Map t_map, int x, int y,stack<Point> &path) {
	if (t_map.map[x][y] == '2') {
		t_map.map[x][y] = 'X';
		Point thisPoint = { x,y };
		path.push(thisPoint);
		exitFinded = true;
		return;
	}
	if (exitFinded == true)
		return;

	//mark the point
	t_map.map[x][y] = 'X';
	Point thisPoint = { x,y };
	path.push(thisPoint);
	if (x > 0 && x < t_map.x - 1 && y > 0 && y < t_map.y - 1) {
		if (t_map.map[x + 1][y] == '0' || t_map.map[x + 1][y] == '2')
			FindPath(t_map, x + 1, y,path);
		if (t_map.map[x - 1][y] == '0'||t_map.map[x - 1][y] == '2')
			FindPath(t_map, x - 1, y,path);
		if (t_map.map[x][y + 1] == '0'|| t_map.map[x][y + 1] == '2')
			FindPath(t_map, x, y + 1,path);
		if (t_map.map[x][y - 1] == '0'|| t_map.map[x][y - 1] == '2')
			FindPath(t_map, x, y - 1,path);
	}

	//Delete the mark
	if (exitFinded == false) {
		t_map.map[x][y] = '0';
		path.pop();
	}
	return;
}
