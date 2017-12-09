#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>

using namespace std;

//输出数列元素，用于测试
void showArray(vector<int> &array) {
	for (auto i : array)
		cout << i << " ";
	cout << endl;
}

void BubbleSort(vector<int> &data){
	int count = 0;
	double time = 0,start,finish;
	int n = data.size();

	start = clock();
	//用循环逐个比较大小
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n -i- 1; j++) {
			if (data[j] > data[j + 1]) {  //将较大的元素向数组右侧移动
				swap(data[j], data[j + 1]);
				count++;
			}
		}
	}
	finish = clock();
	//得出时间
	time = finish - start;
	cout<<"冒泡排序所用时间:	"<<time<<"ms"<<endl;
	cout<<"冒泡排序交换次数:	"<<count<<endl<<endl;
}

void SelectionSort(vector<int> &data){
	int key,count = 0,n = data.size();
	double time = 0,start,finish;

	start = clock();
	//用循环遍历数组，用key记录当前最小值位置
	for (int i = 0; i < n - 1; i++) {
		key = i;
		for (int j = i+1; j < n; j++) {
			if (data[key] > data[j]) key = j;//比较大小，更新key值
		}
		//将key记录的最小值交换到数组最左端
		if (key != i) {
			int temp = data[i];
			data[i] = data[key];
			data[key] = temp;
			count++;
		}
	}
	finish = clock();
	//得出时间
	time = finish - start;
	cout<<"选择排序所用时间:	"<<time<<"ms"<<endl;
	cout<<"选择排序交换次数:	"<<count<<endl<<endl;
}

void InsertionSort(vector<int> &data){
	int count = 0,n = data.size();
	double time,start,finish;

	start = clock();
	for (int i = 1; i < n; i++) {
		if (data[i] < data[i - 1]) {//若第i个元素小于第i-1个时，有序表后移一位
			int temp = data[i];
			int j = i - 1;
			data[i] = data[j];
			for (j; j >= 0; j--) {  //比较查找在有序表中插入的位置
				if (temp < data[j]) {
					data[j + 1] = data[j];
					count++;
				}
				else break;
			}
			data[j + 1] = temp;
		}
	}
	finish = clock();
	time = finish - start;
	cout<<"直接插入排序所用时间:	"<<time<<"ms"<<endl;
	cout<<"直接插入排序交换次数:	"<<count<<endl<<endl;
}

void ShellSort(vector<int> &data){
	int count = 0,gap,n = data.size();
	double time = 0,start,finish;

	start = clock();
	for (gap = n / 2; gap > 0; gap /= 2)
		for (int i = gap; i < n; i++)//从第gap的元素开始
			if (data[i] < data[i - gap]) {//按gap分组，分别对每组元素进行插入排序
				int temp = data[i];
				int j = i - gap;
				while (j >= 0 && data[j] > temp) {
					data[j + gap] = data[j];
					count++;
					j -= gap;
				}
				data[j + gap] = temp;
			}
	finish = clock();
	time =finish - start ;
	cout<<"希尔排序所用时间:	"<<time<<"ms"<<endl;
	cout<<"希尔排序交换次数:	"<<count<<endl<<endl;
}

//快速排序递归调用函数
void Qsort(vector<int> &array, int low, int high, int& count) {
	if (low >= high) return;
	int first = low, last = high;
	int key = array[first];//选取数组的第一个元素作为基准元素

	while (first < last) {
		while (first < last && array[last]>key)
			--last;
		array[first] = array[last];//将第一个比key小的值移动到最低端
		while (first < last && array[first] < key)
			++first;
		array[last] = array[first];//将第一个比key大的值移动到高端
		count += 2;
	}
	//将第一个比key大的位置补为key，相当于三次赋值完成了两次两两交换
	array[first] = key;
	Qsort(array, low, first - 1, count);
	Qsort(array, first + 1, high, count);
}

void QuickSort(vector<int> &data){
	int count = 0;
	double time = 0,start,finish;

	start = clock();
	Qsort(data, 0, data.size() - 1,count);
	finish = clock();
	time = start - finish;
	cout<<"快速排序所用时间:	"<<time<<"ms"<<endl;
	cout<<"快速排序交换次数:	"<<count<<endl<<endl;
}


//堆化，将数组调整为最大堆
void MaxHeapify(vector<int> &array,int size,int element,int &count) {
	int l_child = element * 2 + 1, r_child = element * 2 + 2;
	//当子树均在范围内时，循环整理交换部分的子树，把元素放在正确位置
	while (r_child < size) {
		if (array[element] >= array[l_child] && array[element] >= array[r_child]) return;
		if (array[l_child] >= array[r_child]) {
			swap(array[element], array[l_child]);
			count++;
			element = l_child;
		}
		else {
			swap(array[element], array[r_child]);
			count++;
			element = r_child;
		}
		l_child = element * 2 + 1, r_child = element * 2 + 2;
	}
	//左子树还在范围内，整理左子树
	if (l_child < size&&array[l_child]>array[element]) {
		swap(array[element], array[l_child]);
		count++;
	}
	//到叶子节点，整理完毕
	return;
}

void HeapSort(vector<int> &data){
	int count = 0,n = data.size();
	double time,start,finish;

	start = clock();
	for (int i = n - 1; i >= 0; i--)
		MaxHeapify(data,n,i,count); //从子树开始向上整理整棵树
	//通过循环将堆中最大元素逐个放到数组最后
	while (n > 0) {
		swap(data[n - 1], data[0]);
		n--;
		MaxHeapify(data,n,0,count);
	}
	finish = clock();
	time = start - finish;
	cout<<"堆排序所用时间:		"<<time<<"ms"<<endl;
	cout<<"堆排序交换次数:		"<<count<<endl<<endl;
}

//将数组r1[i,m]与r2[m+1,n]合并为r3[i,n]
void Merge(vector<int> &data,vector<int> &output, int i, int m, int n,int &count) {
	int j, k;
	//依次取值比较，较小的放入r3
	for (j = m+1, k = i; i <= m&&j <= n; k++) {
		if (data[j] < data[i])
			output[k] = data[j++];
		else
			output[k] = data[i++];
		count++;
	}
	//处理比较完后的剩余数
	while (i <= m)
		output[k++] = data[i++];
	while (j <= n)
		output[k++] = data[j++];
}

//通过递归将待排序数列不断二分，进行排序
void Msort(vector<int> &data, vector<int> &output, int s, int t,int &count) {
	vector<int> temp(data.size());
	if (s == t) output[s] = data[s];
	else {
		int m = (s + t) / 2;
		Msort(data, temp, s, m,count);
		Msort(data, temp, m + 1, t,count);
		Merge(temp, output, s, m , t,count);
	}
}

void MergeSort(vector<int> &data){
	int count = 0,n = data.size();
	double start,finish,time;
	vector<int> output(n);

	start = clock();
	Msort(data, output, 0, n - 1,count);
	data = output;
	finish = clock();
	time = finish - start;
	cout<<"归并排序所用时间:	"<<time<<"ms"<<endl;
	cout<<"归并排序交换次数:	"<<count<<endl<<endl;
}

//求出数据中的最大位数
int MaxBit(vector<int> &data) {
	int max = 1, flag = 10;
	for (int i = 0; i < data.size(); i++) {
		while (data[i] > flag) {
			flag *= 10;
			max++;
		}
	}
	return max;
}

void RadixSort(vector<int> &data){
	int count = 0,n = data.size(),max = MaxBit(data),radix = 1,i,j,k;
	double start,finish,time;
	vector<int> temp(n),counts(10);

	start = clock();
	for (i = 1; i <= max; i++) {//根据最大位数决定排序次数
		for (j = 0; j < 10; j++)//将计数器置零
			counts[j] = 0;
		for (j = 0; j < n; j++) {//统计各个数字的数据个数
			k = (data[j] / radix) % 10;
			counts[k]++;
		}
		for (j = 1; j < 10; j++)//确定各个数字在排序完后数组中具体位置
			counts[j] += counts[j - 1];
		for (j = n - 1; j >= 0; j--) {//循环将数据读入temp
			k = (data[j] / radix) % 10;
			temp[counts[k] - 1] = data[j];
			count++;
			counts[k]--;
		}
		data = temp;
		radix *= 10;
	}
	finish = clock();
	time = finish - start;
	cout<<"基数排序所用时间:	"<<time<<"ms"<<endl;
	cout<<"基数排序交换次数:	"<<count<<endl<<endl;
}

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
