#include "MinimumSpanningTree.h"

int main() {
	cout << endl;
	cout << "**        电网造价模拟系统         **" << endl;
	cout << "===================================" << endl;
	cout << "**       A --- 创建电网顶点       **" << endl;
	cout << "**       B --- 添加电网的边       **" << endl;
	cout << "**       C --- 构造最小生成树     **" << endl;
	cout << "**       D --- 显示最小生成树     **" << endl;
	cout << "**       E --- 退出程序           **" << endl;
	cout << "===================================" << endl;

	char key;
	char temp;
	Graph graph;
	vector<Arc> mst;

	while (1){
		cout <<endl<< "请选择操作:";
		cin >> key;
		switch (key){
		case 'A':
			cout << "请输入顶点个数:";
			cin >> graph.vex_num;
			cout << "请依次输入各顶点的名称：";
			for (int i = 0; i < graph.vex_num; i++) {
				cin >> temp;
				graph.vexs.push_back(temp);
			}
			break;
		case 'B':
			cout << "请输入边的总数：";
			cin >> graph.arc_num;
			createUDG(graph);
			break;
		case 'C':
			cout << "请输入起始顶点：";
			cin >> temp;
			constructMST(graph, temp, mst);
			cout << "生成Prim最小生成树！"<<endl;
			break;
		case 'D':
			cout << "最小生成树的顶点及边为：" << endl;
			displayMST(mst);
			break;
		case 'E':
			return 0;
			break;
		default:
			break;
		}
	}

	system("pause");
	return 0;
}
