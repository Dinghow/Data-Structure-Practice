#include <iostream>
#include<string>
#include<vector>

using namespace std;

//Create node class
class member {
public:
	string name;
	//Use vector to save the node's children
	vector<member*> children;
	member(string m_name):name(m_name){}
};

//Create the muti-way tree class
class familyTree {
private:
	member ancestor;
public:
	member* getAncestor() { return &ancestor; }
	familyTree(member& m_ancestor):ancestor(m_ancestor){}
	member* searchMember(string name,member* node,bool& flag,bool child_model);
	void addChild(string name, int children_number,vector<string>& children_name);
	void showNode(string name);
	void deleteMember(string name);
	void deleteNode(member* node);
	void changeName(string pre_name,string new_name);
};

//Display the node information
void familyTree::showNode(string name) {
	bool flag = false;
	member* temp = searchMember(name,&ancestor,flag,false);
	if (temp == NULL) {
		cout << "没有找到该节点!" << endl;
		return;
	}
	else {
		cout << name << "节点有" << temp->children.size() << "个子女，分别为：" << endl;
		for (auto i : temp->children) {
			cout << i->name << " ";
		}
	}
}

//Search node of parent node by name and return its address
member* familyTree::searchMember(string name, member* node,bool& flag,bool child_model) {
	member* find = NULL;
	if (node) {
		//Search node by name
		if (node->name == name && !child_model) {
			find = node;
			flag = true;
		}
		//Search parent node
		else if (child_model) {
			for (auto i : node->children) {
				if (i->name == name) {
					find = node;
					flag = true;
				}
			}
		}
		if (!flag) {
			for (auto iter = node->children.begin(); iter != node->children.end(); iter++) {
				find = searchMember(name, *iter, flag, child_model);
				if (flag)
					break;
			}
		}
	}
	return find;
}

//Add children to a node
void familyTree::addChild(string name,int children_number,vector<string>& children_name) {
	bool flag = false;
	member* parent = searchMember(name, getAncestor(), flag,false);
	if (parent == NULL) {
		cout << "没有找到该成员!" << endl;
	}
	else {
		for (int i = 0; i < children_number;i++) {
			member* child = new member(children_name[i]);
			parent->children.push_back(child);
		}
	}
}

//Delete a node
void familyTree::deleteNode(member* node) {
	if (node->children.size() != 0) {
		for (int i = node->children.size() - 1; i >= 0;i--) {
			deleteNode(node->children[i]);
			node->children.pop_back();
		}
	}
	if(node->children.size() == 0)
		delete node;
}

//Delete a member
void familyTree::deleteMember(string name) {
	bool flag = false;
	member* temp = searchMember(name, getAncestor(), flag, true);
	if (temp == NULL) {
		cout << "家族中没有找到该节点信息！" << endl;
		return;
	}
	for (vector<member*>::iterator ite = temp->children.begin(); ite != temp->children.end();) {
		if ((*ite)->name == name) {
			showNode(name);
			deleteNode(*ite);
			ite = temp->children.erase(ite);
			break;
		}
		else
			ite++;
	}
}

//Change the node info
void familyTree::changeName(string pre_name,string new_name) {
	bool flag = false;
	member* temp = searchMember(pre_name,getAncestor(),flag,false);
	if (temp == NULL) {
		cout << "家族中没有找到该节点信息！" << endl;
		return;
	}
	temp->name = new_name;
	cout << pre_name << "已更名为" << new_name;
}

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