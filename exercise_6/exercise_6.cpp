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
		cout << "û���ҵ��ýڵ�!" << endl;
		return;
	}
	else {
		cout << name << "�ڵ���" << temp->children.size() << "����Ů���ֱ�Ϊ��" << endl;
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
		cout << "û���ҵ��ó�Ա!" << endl;
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
		cout << "������û���ҵ��ýڵ���Ϣ��" << endl;
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
		cout << "������û���ҵ��ýڵ���Ϣ��" << endl;
		return;
	}
	temp->name = new_name;
	cout << pre_name << "�Ѹ���Ϊ" << new_name;
}

int main() {
	char key;
	string ancestor_name;
	 
	cout << "**           ���׹���ϵͳ         **" << endl;
	cout << "===================================" << endl;
	cout << "**     ��ѡ��Ҫִ�еĲ��� :       **" << endl;
	cout << "**       A --- ���Ƽ�ͥ           **" << endl;
	cout << "**       B --- ��Ӽ�ͥ��Ա       **" << endl;
	cout << "**       C --- ��ɢ�ֲ���ͥ       **" << endl;
	cout << "**       D --- ���ļ�ͥ��Ա����   **" << endl;
	cout << "**       E --- ��ʾ��Ů           **" << endl;
	cout << "**       F --- �˳�����           **" << endl;
	cout << "===================================" << endl;

	cout << "���Ƚ���һ����ͥ��" << endl;
	cout << "���������ȵ�����:";
	cin >> ancestor_name;

	cout <<"�˼���������ǣ�"<<ancestor_name<<endl;
	
	member ancestor(ancestor_name);
	familyTree family(ancestor);

	while (1) {
		string name_select;
		string temp_name;
		int number;
		vector<string> children_name;

		cout <<endl<<endl<< "��ѡ��Ҫִ�еĲ�����";
		cin >> key;
		switch (key){
		case 'A':
			cout << "������Ҫ������ͥ�˵�������";
			cin >> name_select;
			cout<< "������" << name_select << "�Ķ�Ů����:";
			cin >> number;
			children_name.clear();
			cout << "����������" << name_select << "�Ķ�Ů������:";
			for (int i = 0; i < number; i++) {
				cin >> temp_name;
				children_name.push_back(temp_name);
			}
			cout << name_select << "�ĵ�һ��������:";
			for (auto i : children_name)
				cout << i << " ";
			family.addChild(name_select, number, children_name);
			break;
		case 'B':
			cout << "������Ҫ��Ӷ��ӣ���Ů�������˵�������";
			cin >> name_select;
			cout << "������" << name_select << "����ӵĶ��ӣ���Ů������������";
			cin >> temp_name;
			children_name.push_back(temp_name);
			family.addChild(name_select, 1, children_name);
			cout << name_select << "�ĵ�һ�������ǣ�" << temp_name;
			break;
		case 'C':
			cout << "������Ҫ��ɢ��ͥ���˵�������";
			cin >> name_select;
			cout << "Ҫ��ɢ��ͥ�����ǣ�" << name_select<<endl;
			family.deleteMember(name_select);
			break;
		case 'D':
			cout << "������Ҫ�����������˵�Ŀǰ������";
			cin >> name_select;
			cout << "��������ĺ������";
			cin >> temp_name;
			family.changeName(name_select, temp_name);
			break;;
		case 'E':
			cout << "������Ҫ��ʾ��Ϣ�ĳ�Ա������";
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