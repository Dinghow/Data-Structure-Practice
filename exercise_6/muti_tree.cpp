#include "muti_tree.h"

int main() {
	char key;
	string ancestor_name;
	 
	cout << "**           家谱管理系统         **" << endl;
	cout << "===================================" << endl;
	cout << "**     请选择要执行的操作 :       **" << endl;
	cout << "**       A --- 完善家庭           **" << endl;
	cout << "**       B --- 添加家庭成员       **" << endl;
	cout << "**       C --- 解散局部家庭       **" << endl;
	cout << "**       D --- 更改家庭成员姓名   **" << endl;
	cout << "**       E --- 显示子女           **" << endl;
	cout << "**       F --- 退出程序           **" << endl;
	cout << "===================================" << endl;

	cout << "首先建立一个家庭！" << endl;
	cout << "请输入祖先的姓名:";
	cin >> ancestor_name;

	cout <<"此家族的祖先是："<<ancestor_name<<endl;
	
	member ancestor(ancestor_name);
	familyTree family(ancestor);

	while (1) {
		string name_select;
		string temp_name;
		int number;
		vector<string> children_name;

		cout <<endl<<endl<< "请选择要执行的操作：";
		cin >> key;
		switch (key){
		case 'A':
			cout << "请输入要建立家庭人的姓名：";
			cin >> name_select;
			cout<< "请输入" << name_select << "的儿女人数:";
			cin >> number;
			children_name.clear();
			cout << "请依次输入" << name_select << "的儿女的姓名:";
			for (int i = 0; i < number; i++) {
				cin >> temp_name;
				children_name.push_back(temp_name);
			}
			cout << name_select << "的第一代子孙是:";
			for (auto i : children_name)
				cout << i << " ";
			family.addChild(name_select, number, children_name);
			break;
		case 'B':
			cout << "请输入要添加儿子（或女儿）的人的姓名：";
			cin >> name_select;
			cout << "请输入" << name_select << "新添加的儿子（或女儿）的姓名：";
			cin >> temp_name;
			children_name.push_back(temp_name);
			family.addChild(name_select, 1, children_name);
			cout << name_select << "的第一代子孙是：" << temp_name;
			break;
		case 'C':
			cout << "请输入要解散家庭的人的姓名：";
			cin >> name_select;
			cout << "要解散家庭的人是：" << name_select<<endl;
			family.deleteMember(name_select);
			break;
		case 'D':
			cout << "请输入要更改姓名的人的目前姓名：";
			cin >> name_select;
			cout << "请输入更改后的姓名";
			cin >> temp_name;
			family.changeName(name_select, temp_name);
			break;;
		case 'E':
			cout << "请输入要显示信息的成员姓名：";
			cin >> name_select;
			family.showNode(name_select);
			break;
		case 'F':
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}
