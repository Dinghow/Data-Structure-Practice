#include<iostream>

using namespace std;

int counter = 0;

//Initial the chessboard
void initial(int* board,int N) {
	for (int i = 0; i < N; i++) {
		board[i] = -1;
	}
}

//Judge whether the point can be placed
bool valid(int *board,int N,int row, int col) {
	for (int i = 0; i < N; i++) {
		//As we use single dimension array,we needn't consider conflict of row,we just judge the conflict of column of diagonal
		if (board[i] == col || (abs(i - row) == abs(board[i] - col) && board[i]!= -1))
			return false;
	}
	return true;
}

//Place queen on the position
void place(int *board,int row, int col) {
	board[row] = col;
}

//Print the chessboard
void printBoard(int *board,int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (j == board[i])
				cout << 'X';
			else
				cout << '0';
		}
		cout << endl;
	}
	cout << endl;
}

//Use recursion to find solutions
void placeQueen(int *board, int N, int row) {
	//If the last row have found,print the solution
	if (row == N) {
		printBoard(board,N);
		counter++;
	}
	else {
		for (int i = 0; i < N; i++) {
			if (valid(board,N, row, i)) {
				place(board,row, i);
				placeQueen(board,N,row + 1);
			}
		}
		//If this row cannot find answer,clean the board
		board[row] = -1;
	}
}


int main() {
	int N, *board;

	cout << "There is a N¡ÁN chessboard,put N queens on it ";
	cout<<"with the limits that any two queens cannot be in the same row,column,or diagnoal!"<<endl;
	cout << "Please enter the N value:";

	cin >> N;
	cout << endl<<"Solutions:"<<endl<<endl;
	//Use single dimension array solve the chessboard,array index indicates row,value means column
	board = new int[N];
	initial(board,N);
	placeQueen(board, N, 0);

	cout << "There are " << counter << " solutions!" << endl;

	return 0;
}