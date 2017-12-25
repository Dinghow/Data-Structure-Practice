#include "n_queens_problem.h"

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
	system("pause");
}
