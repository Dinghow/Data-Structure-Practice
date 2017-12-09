#include<iostream>
#include<ctime>
#include<vector>
#include<cstdlib>

using namespace std;

//�������Ԫ�أ����ڲ���
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
	//��ѭ������Ƚϴ�С
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < n -i- 1; j++) {
			if (data[j] > data[j + 1]) {  //���ϴ��Ԫ���������Ҳ��ƶ�
				swap(data[j], data[j + 1]);
				count++;
			}
		}
	}
	finish = clock();
	//�ó�ʱ��
	time = finish - start;
	cout<<"ð����������ʱ��:	"<<time<<"ms"<<endl;
	cout<<"ð�����򽻻�����:	"<<count<<endl<<endl;
}

void SelectionSort(vector<int> &data){
	int key,count = 0,n = data.size();
	double time = 0,start,finish;

	start = clock();
	//��ѭ���������飬��key��¼��ǰ��Сֵλ��
	for (int i = 0; i < n - 1; i++) {
		key = i;
		for (int j = i+1; j < n; j++) {
			if (data[key] > data[j]) key = j;//�Ƚϴ�С������keyֵ
		}
		//��key��¼����Сֵ���������������
		if (key != i) {
			int temp = data[i];
			data[i] = data[key];
			data[key] = temp;
			count++;
		}
	}
	finish = clock();
	//�ó�ʱ��
	time = finish - start;
	cout<<"ѡ����������ʱ��:	"<<time<<"ms"<<endl;
	cout<<"ѡ�����򽻻�����:	"<<count<<endl<<endl;
}

void InsertionSort(vector<int> &data){
	int count = 0,n = data.size();
	double time,start,finish;

	start = clock();
	for (int i = 1; i < n; i++) {
		if (data[i] < data[i - 1]) {//����i��Ԫ��С�ڵ�i-1��ʱ����������һλ
			int temp = data[i];
			int j = i - 1;
			data[i] = data[j];
			for (j; j >= 0; j--) {  //�Ƚϲ�����������в����λ��
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
	cout<<"ֱ�Ӳ�����������ʱ��:	"<<time<<"ms"<<endl;
	cout<<"ֱ�Ӳ������򽻻�����:	"<<count<<endl<<endl;
}

void ShellSort(vector<int> &data){
	int count = 0,gap,n = data.size();
	double time = 0,start,finish;

	start = clock();
	for (gap = n / 2; gap > 0; gap /= 2)
		for (int i = gap; i < n; i++)//�ӵ�gap��Ԫ�ؿ�ʼ
			if (data[i] < data[i - gap]) {//��gap���飬�ֱ��ÿ��Ԫ�ؽ��в�������
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
	cout<<"ϣ����������ʱ��:	"<<time<<"ms"<<endl;
	cout<<"ϣ�����򽻻�����:	"<<count<<endl<<endl;
}

//��������ݹ���ú���
void Qsort(vector<int> &array, int low, int high, int& count) {
	if (low >= high) return;
	int first = low, last = high;
	int key = array[first];//ѡȡ����ĵ�һ��Ԫ����Ϊ��׼Ԫ��

	while (first < last) {
		while (first < last && array[last]>key)
			--last;
		array[first] = array[last];//����һ����keyС��ֵ�ƶ�����Ͷ�
		while (first < last && array[first] < key)
			++first;
		array[last] = array[first];//����һ����key���ֵ�ƶ����߶�
		count += 2;
	}
	//����һ����key���λ�ò�Ϊkey���൱�����θ�ֵ�����������������
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
	cout<<"������������ʱ��:	"<<time<<"ms"<<endl;
	cout<<"�������򽻻�����:	"<<count<<endl<<endl;
}


//�ѻ������������Ϊ����
void MaxHeapify(vector<int> &array,int size,int element,int &count) {
	int l_child = element * 2 + 1, r_child = element * 2 + 2;
	//���������ڷ�Χ��ʱ��ѭ�����������ֵ���������Ԫ�ط�����ȷλ��
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
	//���������ڷ�Χ�ڣ�����������
	if (l_child < size&&array[l_child]>array[element]) {
		swap(array[element], array[l_child]);
		count++;
	}
	//��Ҷ�ӽڵ㣬�������
	return;
}

void HeapSort(vector<int> &data){
	int count = 0,n = data.size();
	double time,start,finish;

	start = clock();
	for (int i = n - 1; i >= 0; i--)
		MaxHeapify(data,n,i,count); //��������ʼ��������������
	//ͨ��ѭ�����������Ԫ������ŵ��������
	while (n > 0) {
		swap(data[n - 1], data[0]);
		n--;
		MaxHeapify(data,n,0,count);
	}
	finish = clock();
	time = start - finish;
	cout<<"����������ʱ��:		"<<time<<"ms"<<endl;
	cout<<"�����򽻻�����:		"<<count<<endl<<endl;
}

//������r1[i,m]��r2[m+1,n]�ϲ�Ϊr3[i,n]
void Merge(vector<int> &data,vector<int> &output, int i, int m, int n,int &count) {
	int j, k;
	//����ȡֵ�Ƚϣ���С�ķ���r3
	for (j = m+1, k = i; i <= m&&j <= n; k++) {
		if (data[j] < data[i])
			output[k] = data[j++];
		else
			output[k] = data[i++];
		count++;
	}
	//����Ƚ�����ʣ����
	while (i <= m)
		output[k++] = data[i++];
	while (j <= n)
		output[k++] = data[j++];
}

//ͨ���ݹ齫���������в��϶��֣���������
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
	cout<<"�鲢��������ʱ��:	"<<time<<"ms"<<endl;
	cout<<"�鲢���򽻻�����:	"<<count<<endl<<endl;
}

//��������е����λ��
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
	for (i = 1; i <= max; i++) {//�������λ�������������
		for (j = 0; j < 10; j++)//������������
			counts[j] = 0;
		for (j = 0; j < n; j++) {//ͳ�Ƹ������ֵ����ݸ���
			k = (data[j] / radix) % 10;
			counts[k]++;
		}
		for (j = 1; j < 10; j++)//ȷ������������������������о���λ��
			counts[j] += counts[j - 1];
		for (j = n - 1; j >= 0; j--) {//ѭ�������ݶ���temp
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
	cout<<"������������ʱ��:	"<<time<<"ms"<<endl;
	cout<<"�������򽻻�����:	"<<count<<endl<<endl;
}

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
