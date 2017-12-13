#include"greedy_problem.h"

int main() {
	int N, temp, sum = 0;
	vector<int> lengths;

	cout << "how many pieces of wood do you want to get? "<<endl;
	cin >> N;
	cout << "Please enter the length of each wood:" << endl;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		lengths.push_back(temp);
	}
	greedProblem(lengths, sum);

	return 0;
}
