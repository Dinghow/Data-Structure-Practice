#include "sort_summary.h"

int main(){
	//variable
	int n,label = 0;
	bool flag = false;

	cout<<"**          �����㷨�Ƚ�         **"<<endl;
	for(int i =0;i<38;i++)
		cout<<"=";
	cout<<endl<<"**        1 --- ð������         **"<<endl;
	cout<<"**        2 --- ѡ������         **"<<endl;
	cout<<"**        3 --- ֱ�Ӳ�������     **"<<endl;
	cout<<"**        4 --- ϣ������         **"<<endl;
	cout<<"**        5 --- ��������         **"<<endl;
	cout<<"**        6 --- ������           **"<<endl;
	cout<<"**        7 --- �鲢����         **"<<endl;
	cout<<"**        8 --- ��������         **"<<endl;
	cout<<"**        9 --- �˳�����         **"<<endl;
	for(int i =0;i<38;i++)
		cout<<"=";
	cout<<endl<<endl<<"������Ҫ������������ĸ���"<<endl;
	cin>>n;

	while(flag == false){
		vector<int> data(n);
		srand((unsigned)time(NULL));
		data = *new vector<int>();
		for (int i = 0; i < n; i++) {
			data.push_back(rand());
		}
		cout<<endl<<"��ѡ�������㷨��";
		cin>>label;
		switch(label){
		case 1:
			BubbleSort(data);
			break;
		case 2:
			SelectionSort(data);
			break;
		case 3:
			InsertionSort(data);
			break;
		case 4:
			ShellSort(data);
			break;
		case 5:
			QuickSort(data);
			break;
		case 6:
			HeapSort(data);
			break;
		case 7:
			MergeSort(data);
			break;
		case 8:
			RadixSort(data);
			break;
		case 9:
			flag = true;
			break;
		}
	}

	return 0;
}
