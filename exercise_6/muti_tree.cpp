#include "muti_tree.h"

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
