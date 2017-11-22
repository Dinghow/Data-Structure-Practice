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
	void AddNode(Student newStudent) {
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
	void InsertNode(Student newStudent, int position) {
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
		cout << "其中男生有：" << boy_amount << "名" << "女生有：" << girl_amount << "名" << endl;
	}
};

int main() {
	int amount;
	LinkList students;

	cout << "首先请建立考生信息系统！" << endl;
	cout << "请输入考生人数:";
	cin >> amount;
	cout << endl << "请依次输入考生的考号，姓名，性别，年龄以及报考类别！" << endl;
	for (int i = 0; i < amount; i++) {
		Student temp;
		cin >> temp.number >> temp.name >> temp.gender >> temp.age >> temp.position;
		students.AddNode(temp);
	}
	
	while (1) {
		short key = 0;
		Student temp2;
		Node *temp3 = NULL;
		int number;
		students.ShowAll();
		cout << "请选择您要进行的操作（1为插入，2为删除，3为查找，4为修改，5为统计，0为取消操作）" << endl;
		cin >> key;
		switch (key){
		case 1:
			int position;
			cout << "请输入你要插入的考生位置：" << endl;
			cin >> position;
			cout << "请依次输入要插入的考生考号，姓名，性别，年龄以及报考类别！" << endl;
			cin >> temp2.number >> temp2.name >> temp2.gender >> temp2.age >> temp2.position;
			students.InsertNode(temp2, position);
			break;
		case 2:
			cout << "请输入你要删除的考生考号：" << endl;
			cin >> number;
			students.DeleteNode(number);
			break;
		case 3:
			cout << "请输入你要查找的考生考号：" << endl;
			cin >> number;
			cout << "考号" << "\t" << "姓名" << "\t" << "性别" << "年龄" << "报考类别" << endl;
			students.ShowNode(students.SearchNode(number));
			break;
		case 4:
			cout << "请输入你要修改的考生考号：" << endl;
			cin >> number;
			temp3 = students.SearchNode(number);
			if (temp3) {
				int modify_key;
				cout << "请选择你要修改的信息: (1为考号，2为姓名，3为性别，4为年龄，5为报考类别)" << endl;
				cin >> modify_key;
				cout << "请输入新的信息：" << endl;
				switch (modify_key) {
				case 1:
					cin >> temp3->stu.number;
					break;
				case 2:
					cin >> temp3->stu.name;
					break;
				case 3:
					cin >> temp3->stu.gender;
					break;
				case 4:
					cin >> temp3->stu.age;
					break;
				case 5:
					cin >> temp3->stu.position;
					break;
				default:
					break;
				}
			}
		case 5:
			students.AnalyseInfo();
			break;
		case 0:
			break;
		default:
			break;
		}
	}

	return 0;
}