#include "sort_summary.h"

int main(){
	//variable
	int n,label = 0;
	bool flag = false;

	cout<<"**          排序算法比较         **"<<endl;
	for(int i =0;i<38;i++)
		cout<<"=";
	cout<<endl<<"**        1 --- 冒泡排序         **"<<endl;
	cout<<"**        2 --- 选择排序         **"<<endl;
	cout<<"**        3 --- 直接插入排序     **"<<endl;
	cout<<"**        4 --- 希尔排序         **"<<endl;
	cout<<"**        5 --- 快速排序         **"<<endl;
	cout<<"**        6 --- 堆排序           **"<<endl;
	cout<<"**        7 --- 归并排序         **"<<endl;
	cout<<"**        8 --- 基数排序         **"<<endl;
	cout<<"**        9 --- 退出程序         **"<<endl;
	for(int i =0;i<38;i++)
		cout<<"=";
	cout<<endl<<endl<<"请输入要产生的随机数的个数"<<endl;
	cin>>n;

	while(flag == false){
		vector<int> data(n);
		srand((unsigned)time(NULL));
		data = *new vector<int>();
		for (int i = 0; i < n; i++) {
			data.push_back(rand());
		}
		cout<<endl<<"请选择排序算法：";
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
