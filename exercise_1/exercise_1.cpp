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
		if (newStudent.gender == "��")
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
		if (newStudent.gender == "��")
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
			cout << "�ÿ�����Ϣ������" << endl;
	}

	//Display the Linklist
	void ShowAll() {
		Node *temp = head;
		cout <<endl<< "����" << "\t" << "����" << "\t" << "�Ա�"<<"\t"<< "����"<<"\t"<< "�������" << endl;
		for (int i = 0; i < length; i++) {
			temp = temp->pNext;
			ShowNode(temp);
		}
	}

	//Delete node by key words
	void DeleteNode(int number) {
		Node *del = SearchNode(number);
		if (del != NULL) {
			cout << "��ɾ���Ŀ�����Ϣ�ǣ�";
			ShowNode(del);
			Node *temp = head;
			while (temp->pNext != NULL) {
				if (temp->pNext->stu.number == number)
					break;
				temp = temp->pNext;
			}
			temp->pNext = temp->pNext->pNext;
			if (del->stu.gender == "��")
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
		cout << "����" << length << "������"<<endl;
		cout << "���������У�" << boy_amount << "��" << "Ů���У�" << girl_amount << "��" << endl;
	}
};

int main() {
	int amount;
	LinkList students;

	cout << "�����뽨��������Ϣϵͳ��" << endl;
	cout << "�����뿼������:";
	cin >> amount;
	cout << endl << "���������뿼���Ŀ��ţ��������Ա������Լ��������" << endl;
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
		cout << "��ѡ����Ҫ���еĲ�����1Ϊ���룬2Ϊɾ����3Ϊ���ң�4Ϊ�޸ģ�5Ϊͳ�ƣ�0Ϊȡ��������" << endl;
		cin >> key;
		switch (key){
		case 1:
			int position;
			cout << "��������Ҫ����Ŀ���λ�ã�" << endl;
			cin >> position;
			cout << "����������Ҫ����Ŀ������ţ��������Ա������Լ��������" << endl;
			cin >> temp2.number >> temp2.name >> temp2.gender >> temp2.age >> temp2.position;
			students.InsertNode(temp2, position);
			break;
		case 2:
			cout << "��������Ҫɾ���Ŀ������ţ�" << endl;
			cin >> number;
			students.DeleteNode(number);
			break;
		case 3:
			cout << "��������Ҫ���ҵĿ������ţ�" << endl;
			cin >> number;
			cout << "����" << "\t" << "����" << "\t" << "�Ա�" << "����" << "�������" << endl;
			students.ShowNode(students.SearchNode(number));
			break;
		case 4:
			cout << "��������Ҫ�޸ĵĿ������ţ�" << endl;
			cin >> number;
			temp3 = students.SearchNode(number);
			if (temp3) {
				int modify_key;
				cout << "��ѡ����Ҫ�޸ĵ���Ϣ: (1Ϊ���ţ�2Ϊ������3Ϊ�Ա�4Ϊ���䣬5Ϊ�������)" << endl;
				cin >> modify_key;
				cout << "�������µ���Ϣ��" << endl;
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