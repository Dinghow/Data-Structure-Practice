#include "student_info_system.h"

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
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}
