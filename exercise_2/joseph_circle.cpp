#include "joseph_circle.h"

int main() {
	int total, start, gap, survival;
	cout << "����N����Χ��һȦ���ӵ�S���˿�ʼ���α�������M���˳��֣�������һ���˿�ʼ���������ѭ����ֱ��ʣ��K����Ϊֹ"<<endl;
	cout <<endl << "������������Ϸ��������N��";
	cin >> total;
	cout << "��������Ϸ��ʼ��λ�ã�";
	cin >> start;
	cout << "��������������M��";
	cin >> gap;
	cout << "������ʣ�����������K��";
	cin >> survival;
	
	CircularLinkList joseph_circle(total);
	joseph_circle.JosephStart(start, gap, survival);
	
	return 0;
}
