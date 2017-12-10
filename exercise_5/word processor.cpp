#include "word_processor.h"

int main() {
	int function_select;
	string file_name,word_name;
	cout << "Please enter the file name you want open:";
	cin >> file_name;

	ifstream fin(file_name.c_str());
	if (fin.good() == 0) {
		cout << "Open file failed!" << endl;
		return 0;
	}

	cout << endl << "Please enter the word you want to manipulate:";
	cin >> word_name;

	while (1) {
		//Function select
		cout <<endl<< "Please select a function(0:exit,1:word count,2:word analyse in row):";
		cin >> function_select;
		switch (function_select){
		case 0:
			return 0;
			break;
		case 1:
			CountFrequency(file_name, word_name);
			break;
		case 2:
			AnalyseInRow(file_name,word_name);
			break;
		default:
			break;
		}
	}

	fin.close();

	return 0;
}
