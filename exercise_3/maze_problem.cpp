#include "maze_problem.h"

int main() {
	//create the array and load the map
	int a, b,entr_x,entr_y;
	string map_name;
	stack<Point> path;
	char **map;
	Map t_map;
	
	cout<<"��������Ҫ�򿪵ĵ�ͼȫ����������׺����";
	cin>>map_name;
	
	ifstream in(map_name.c_str());
	if(!in){
		cout<<"û���ҵ��õ�ͼ��"<<endl;
		return 0;
	}
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
	cout << "��ͼ�������" << endl;
	t_map.map = map;
	t_map.x = a;
	t_map.y = b;
	//print the map
	cout << "��ͼ��ʽǰ��λΪ��С��0��ʾͨ·��1��ʾ��ڣ�2��ʾ���ڣ�#��ʾ�ϰ���" << endl;
	PrintMap(map,a,b);

	//Find the path
	exitFinded = false;
	FindPath(t_map, entr_x, entr_y,path);
	if (!exitFinded)
		cout << "û���ҵ�����";
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
	
	system("pause");
	return 0;
}
