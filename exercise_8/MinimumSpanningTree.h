#include<iostream>
#include<vector>
#define MAX_VERTEX_NUM 50
#define MAX 10000

using namespace std;

//Adjacent vertex
struct CloseNode {
	char adj_vex;
	double low_cost;
};

struct Arc {
	char node1;
	char node2;
	double value;
};

struct Graph {
	vector<char> vexs;
	vector<Arc> arcs;
	double adj_table[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int vex_num, arc_num;
};

void createUDG(Graph& G);
int getLocation(Graph& G, char name);
int getMinAdjVex(Graph& G, CloseNode(&close_nodes)[MAX_VERTEX_NUM]);
void constructMST(Graph& G, char start, vector<Arc>& mst);
void displayMST(vector<Arc>& mst);

//Create the undirected graph
void createUDG(Graph& G) {
	//Initialize the adjacent table
	for (int i = 0; i < G.vex_num; i++)
		for (int j = 0; j < G.vex_num; j++)
			G.adj_table[i][j] = MAX;
	//Enter arcs and read the info to arcs and adjacent table
	for (int i = 0; i < G.arc_num; i++) {
		Arc temp;
		int x, y;

		cout << "请输入两个顶点及边：";
		cin >> temp.node1 >> temp.node2 >> temp.value;
		G.arcs.push_back(temp);
		x = getLocation(G, temp.node1);
		y = getLocation(G, temp.node2);
		G.adj_table[x][y] = G.adj_table[y][x] = temp.value;
	}
}

//Get the location of a vertex by name;
int getLocation(Graph& G, char name) {
	int location;
	for (int i = 0; i < G.vex_num; i++)
		if (G.vexs[i] == name) {
			location = i;
		}
	return location;
}

//Get the location of minimum adjacent vertex
int getMinAdjVex(Graph& G, CloseNode(&close_nodes)[MAX_VERTEX_NUM]) {
	int min = MAX,location;
	for (int i = 0; i < G.vex_num; i++) {
		if (close_nodes[i].low_cost != 0 && close_nodes[i].low_cost < min) {
			min = close_nodes[i].low_cost;
			location = i;
		}
	}
	return location;
}

//Use Prim algorithm to construct MST
void constructMST(Graph& G, char start,vector<Arc>& mst) {
	CloseNode close_nodes[MAX_VERTEX_NUM];
	int current = getLocation(G, start);

	//Initialize the close nodes
	for (int i = 0; i < G.vex_num; i++) {
		if (i != current) {
			close_nodes[i].adj_vex = start;
			close_nodes[i].low_cost = G.adj_table[current][i];
		}
		else
			close_nodes[i].low_cost = 0;
	}

	//Use recycle to add arc to MST
	for (int i = 1; i < G.vex_num; i++) {
		current = getMinAdjVex(G, close_nodes);
		Arc temp = { close_nodes[current].adj_vex,G.vexs[current],close_nodes[current].low_cost };
		mst.push_back(temp);
		close_nodes[current].low_cost = 0;
		//Compare the close nodes'value of new node and pre one to refresh the closes nodes array 
		for (int j = 0; j < G.vex_num; j++) {
			if (G.adj_table[current][j] < close_nodes[j].low_cost) {
				close_nodes[j].adj_vex = G.vexs[current];
				close_nodes[j].low_cost = G.adj_table[current][j];
			}
		}
	}
}

//Display the MST
void displayMST(vector<Arc>& mst) {
	for (auto i : mst) {
		cout << i.node1 << "-<" << i.value << ">->" << i.node2 << endl;
	}
}
