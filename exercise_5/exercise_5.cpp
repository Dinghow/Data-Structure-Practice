#include<iostream>
#include<fstream>
#include<string>
#include<vector>

using namespace std;

//Create a class to save words
class word {
private:
	int frequency;
	string name;
public:
	bool compare(string &r);
	word();
	word(string &r);
	void addFrequency();
	friend ostream& operator<<(ostream &os, const word &obj);
	string getName();
};

word::word() {
	frequency = 0;
}

word::word(string &r) {
	frequency = 0;
	name = r;
}

bool word::compare(string &r) {
	if (name == r) {
		this->addFrequency();
		return true;
	}
	else
		return false;
}

void word::addFrequency() {
	frequency++;
}

string word::getName() {
	return name;
}

//Overload <<
ostream& operator<<(ostream &os, const word &obj) {
	os << obj.name << ": " << obj.frequency<<" times ";
	return os;
}

//Count the word's frequency
void CountFrequency(string file_name,string target_word) {
	//Open file in the function,to make sure every time the function is called,the buffer is new
	ifstream fin(file_name.c_str());
	if (fin.good() == 0) {
		cout << "Open file failed!" << endl;
		return;
	}
	char *str = new char[100];
	word* key = new word(target_word);

	while (!fin.eof()) {
		int i = 0;
		bool flag = 0;
		while (fin.get(str[i++])) {
			if (str[i - 1] >= 65 && str[i - 1] <= 90)
				str[i - 1] += 32;
			else if (str[i - 1] < 97 || str[i - 1]>122) {
				str[i - 1] = '\0';
				break;
			}
		};
		str[i] = '\0';
		string temp2(str);

		if (target_word == temp2)
			key->addFrequency();
	}
	cout << *key;
}

//Find the word's row number,its frequency in the row and position in the row
void AnalyseInRow(string file_name, string target_word) {
	int line = 1;
	int word_time = 0;
	int position_counter = 1;
	vector<int> position;
	//Open file in the function,to make sure every time the function is called,the buffer is new
	ifstream fin(file_name.c_str());
	if (fin.good() == 0) {
		cout << "Open file failed!" << endl;
		return;
	}
	char *str = new char[100];

	while (!fin.eof()) {
		int i = 0;
		bool flag = 0;
		while (fin.get(str[i++])) {
			//Once get '\n',output information of this line and reload for the next line
			if (str[i - 1] == '\n') {
				cout << target_word << " have appeared " << word_time << " times in line " << line;
				cout << " and the positions are: "<<endl<<endl;
				for (auto iter = position.begin(); iter != position.end(); iter++)
					cout << *iter << " ";
				cout << endl;
				line++;
				word_time = 0;
				position_counter = 1;
				position.clear();
			}
			if (str[i - 1] >= 65 && str[i - 1] <= 90)
				str[i - 1] += 32;
			else if (str[i - 1] < 97 || str[i - 1]>122) {
				str[i - 1] = '\0';
				break;
			}
		};
		str[i] = '\0';
		string temp2(str);
		if (target_word == temp2) {
			word_time++;
			position.push_back(position_counter);
		}
		position_counter++;
	}

}

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