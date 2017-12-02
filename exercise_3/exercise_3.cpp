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
	cout << "迷宫地图:" << endl;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			if (i == 0 && j == 0) {
				cout << "\t";
			}
			else if (i == 0 && j != 0) {
				cout << j - 1 << "列" << "\t";
			}
			else if (i != 0 && j == 0) {
				cout << i - 1 << "行" << "\t";
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

int main() {
	//create the array and load the map
	int a, b,entr_x,entr_y;
	string map_name;
	stack<Point> path;
	char **map;
	Map t_map;
	
	cout<<"请输入需要打开的地图全名（包含后缀）：";
	cin>>map_name;
	
	ifstream in(map_name.c_str());

	in >> a >> b;
	//use second rank pointer to create a dynamic array
	map = new char *[a];
	for (int i = 0; i < a; i++) {
		map[i] = new char[b];
	}

	for(int i = 0; i<a;i++)
		for (int j = 0; j < b; j++) {
			 in >> map[i][j];
			 if (map[i][j] == '1') {
				 entr_x = i;
				 entr_y = j;
			 }

		}

	in.close();
	cout << "地图加载完毕" << endl;
	t_map.map = map;
	t_map.x = a;
	t_map.y = b;
	//print the map
	cout << "地图格式前两位为大小，0表示通路，1表示入口，2表示出口，#表示障碍物" << endl;
	PrintMap(map,a,b);

	//Find the path
	exitFinded = false;
	FindPath(t_map, entr_x, entr_y,path);
	if (!exitFinded)
		cout << "没有找到出口";
	else {
		PrintMap(map, a, b);
		//reverse the stack elements
		stack<Point> r_path;
		while (!path.empty()) {
			r_path.push(path.top());
			path.pop();
		}
		//print the path
		while (!r_path.empty()) {
			cout << "<" <<r_path.top().x << "," << r_path.top().y << ">" << " --> ";
			r_path.pop();
		}
	}

	return 0;
}
