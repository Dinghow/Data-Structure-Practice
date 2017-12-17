#include<iostream>
#include <string>

using namespace std;

//Save student's information
struct Student {
	int number;
	string name;
	string gender;
	int age;
	string position;
};

//Linklist node
struct Node {
	Student stu;
	string headNode;
	Node *pNext;
	Node(Student member) :stu(member), pNext(NULL){}
	Node(string head):headNode(head),pNext(NULL){}
};

//Linklist class
class LinkList {
private:
	Node *head;
	int length;
	int boy_amount;
	int girl_amount;
public:
	//Constructor
	LinkList() {
		head = new Node("head");
		length = 0;
		boy_amount = 0;
		girl_amount = 0;
	};

	//Add node at the list tail
	void AddNode(Student& newStudent) {
		Node *node = new Node(newStudent);
		Node *temp = head;
		if (newStudent.gender == "男")
			boy_amount++;
		else
			girl_amount++;
		//find the tail node
		while (temp->pNext!=NULL){
			temp = temp->pNext;
		}
		temp->pNext = node;
		length++;
	}

	//Insert node at a precise position
	void InsertNode(Student &newStudent, int position) {
		Node *temp = head;
		Node *node = new Node(newStudent);
		if (newStudent.gender == "男")
			boy_amount++;
		else
			girl_amount++;
		for (int i = 0; i < position-1; i++) {
			if (i <= length)
				temp = temp->pNext;
		}
		node->pNext = temp->pNext;
		temp->pNext = node;
		length++;
	}

	//Display node information
	void ShowNode(Node *node) {
		if (node != NULL) {
			Student stu = node->stu;
			cout << stu.number << "\t" << stu.name << "\t" << stu.gender << "\t" << stu.age << "\t" << stu.position << endl;
		}
		else
			cout << "该考生信息不存在" << endl;
	}

	//Display the Linklist
	void ShowAll() {
		Node *temp = head;
		cout <<endl<< "考号" << "\t" << "姓名" << "\t" << "性别"<<"\t"<< "年龄"<<"\t"<< "报考类别" << endl;
		for (int i = 0; i < length; i++) {
			temp = temp->pNext;
			ShowNode(temp);
		}
	}

	//Delete node by key words
	void DeleteNode(int number) {
		Node *del = SearchNode(number);
		if (del != NULL) {
			cout << "你删除的考生信息是：";
			ShowNode(del);
			Node *temp = head;
			while (temp->pNext != NULL) {
				if (temp->pNext->stu.number == number)
					break;
				temp = temp->pNext;
			}
			temp->pNext = temp->pNext->pNext;
			if (del->stu.gender == "男")
				boy_amount--;
			else
				girl_amount--;
			delete del;
			length--;
		}
	}

	//Search student by key words
	Node* SearchNode(int number) {
		Node *temp = head;
		while (temp->pNext != NULL) {
			if (temp->pNext->stu.number == number)
				break;
			temp = temp->pNext;
		}
		if (temp->pNext == NULL) {
			return NULL;
		}
		else 
			return temp->pNext;
	}

	//Modify the information
	void ModifyNode(int number,Student &newMessage) {
		Node *temp = SearchNode(number);
		if (temp) {
			temp->stu = newMessage;
		}
	}

	//Analyse the information
	void AnalyseInfo() {                                                     
		cout << "共有" << length << "名考生"<<endl;
		cout << "其中男生有：" << boy_amount << "名" <<endl<< "女生有：" << girl_amount << "名" << endl;
	}
};
