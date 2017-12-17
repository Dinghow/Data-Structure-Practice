#include "student_info_system.h"

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
			return 0;
			break;
		default:
			break;
		}
	}

	return 0;
}
