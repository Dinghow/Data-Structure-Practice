#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void greedProblem(vector<int>& lengths,int sum) {
	if (lengths.size() == 1) {
		cout << "The least cost is:" << sum;
		return;
	}
	sort(lengths.begin(), lengths.end());
	for (auto i : lengths)
		sum += i;
	lengths.pop_back();
	greedProblem(lengths, sum);
}

