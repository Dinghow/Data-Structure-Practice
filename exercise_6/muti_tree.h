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
