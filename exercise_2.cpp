#include<iostream>
#include<vector>

using namespace std;

struct Node {
	int postion;
	Node *pNext;
	Node(int n):postion(n),pNext(NULL){}
	Node():postion(0),pNext(NULL){}
};

//Create a circular link list to stimulate Joseph circle
class CircularLinkList {
private:
	Node *head;
	Node *tail;
	int length;
public:
	CircularLinkList() {
		head = new Node(0);
	}
	
	CircularLinkList(int amount) {
		head = new Node(0);
		if (amount <= 0) {
			cout << "Amount Error!"<<endl;
			return;
		}
		//initialize all the nodes
		Node* first = new Node(1);
		head->pNext = first;
		length = amount;
		
		Node* temp = first;
		for (int i = 2; i <= amount; i++) {
			Node* newNode = new Node(i);
			temp->pNext = newNode;
			temp = temp->pNext;
		}

		//Mark the tail
		temp->pNext = first;
		tail = temp;
	}

	//Delete node
	void DeleteNode(Node *node) {
		Node* temp = head;
		while (temp->pNext->postion != node->postion && temp!= tail) {
			temp = temp->pNext;
		}
		if (temp != tail) {
			Node *delNode = temp->pNext;
			temp->pNext = temp->pNext->pNext;
			delete delNode;
			length--;
		}
		return;
	}

	//Remove people in terms of start and gap
	void JosephStart(int start, int gap, int survival) {
		Node* temp = head;
		for (int i = 1; i <= start; i++) {
			temp = temp->pNext;
		}
		while (length > survival) {
			int k = 1;
			for (int i = 0; i < gap-1; i++) {
				temp = temp->pNext;
			}
			Node* delNode = temp;
			temp = temp->pNext;
			cout << "第" << k << "个死者的位置时：" << "\t" << delNode->postion << endl;
			DeleteNode(delNode);
			k++;
		}
		cout << endl << "最后剩下" << survival << "人" << endl;
		cout << "剩余生者的位置为：";
		Node* show = head->pNext;
		for (int i = 0; i < survival; i++) {
			cout << "\t" << show->postion;
			show = show->pNext;
		}
		return;
	}
};

int main() {
	int total, start, gap, survival;
	cout << "现有N个人围成一圈，从第S个人开始依次报数，报M的人出局，再由下一个人开始报数，如此循环，直至剩下K个人为止"<<endl;
	cout <<endl << "请输入生死游戏的总人数N：";
	cin >> total;
	cout << "请输入游戏开始的位置：";
	cin >> start;
	cout << "请输入死亡数字M：";
	cin >> gap;
	cout << "请输入剩余的生者人数K：";
	cin >> survival;
	
	CircularLinkList joseph_circle(total);
	joseph_circle.JosephStart(start, gap, survival);
	
	return 0;
}