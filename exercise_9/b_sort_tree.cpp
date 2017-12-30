#include "b_sort_tree.h"

int main() {
	//UI
	cout << "**        Binary-Sort-Tree        **" << endl;
	cout << "======================================"<<endl;
	cout << "**        1 --- Build the BST     **" << endl;
	cout << "**        2 --- Insert element    **" << endl;
	cout << "**        3 --- Search element    **" << endl;
	cout << "**        4 --- Exit              **" << endl;
	cout << "======================================" << endl;

	int function_select;
	BST bs_tree;

	while (1) {
		int temp_key;
		Node* temp_node;
		bool flag;
		cout << endl <<endl<< "Please select:";
		cin >> function_select;
		switch (function_select){
		case 1:
			cout << "Please input key to create Bsort_Tree£¨Enter 0 to finish inputting):"<<endl;
			while (cin>>temp_key && temp_key) {
				temp_node = new Node(temp_key);
				bs_tree.addChild(bs_tree.getRoot(),temp_node);
			}
			cout << "Bsort_Tree is:";
			bs_tree.inorder(bs_tree.getRoot());
			break;
		case 2:
			cout << "Please input key which inserted:";
			cin >> temp_key;
			temp_node = new Node(temp_key);
			bs_tree.addChild(bs_tree.getRoot(), temp_node);
			cout << "Bsort_Tree is:";
			bs_tree.inorder(bs_tree.getRoot());
			break;
		case 3:
			cout << "Please input key which searched:";
			cin >> temp_key;
			flag = false;
			bs_tree.searchNode(bs_tree.getRoot(), temp_key,flag);
			if (!flag)
				cout << temp_key << " not exist!";
			break;
		case 4:
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}
