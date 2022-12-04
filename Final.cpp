#include<iostream> 
#include<fstream>
#include<stdlib.h>
using namespace std;

const int row = 9, col = 9;
int arr[row][col] = { 0 };

//Function to initialize the game with some random numbers
void rand_num(int arr[9][9]) {
	srand(time(0));
	for (int i = 1; i <= 32; i++) {
		int row = (rand() % 9) + 1;
		int col = (rand() % 9) + 1;
		arr[row][col] = (rand() % 9) + 1;
	}
}

//Function to display the board
void display_board(int arr[9][9]) {
	cout << "************SUDUKO GAME************" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j] << " | ";
		}
		cout << endl;
	}
}

//Function to avoid repitition in row, column and 3x3 matrix
bool check_rcm(int arr[9][9], int n, int col, int row) {
	col = col - 1;
	row = row - 1;
	for (int r = 0; r < 9; r++) {
		if (arr[r][col] == n) {
			cout << "\nInvalid Input, Entered value exsists in the same 'Column', Enter Again\n";
			return false;
		}
	}
	for (int c = 0; c < 9; c++) {
		if (arr[row][c] == n) {
			cout << "\nInvalid Input, Entered value exsists in the same 'Row', Enter Again\n";
			return false;
		}
	}
	row = row - row % 3;
	col = col - col % 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i + row][j + col] == n) {
				cout << "\nInvalid Input, Entered value exsists in the '3x3 Matrix', Enter Again\n";
				return false;
			}
		}
	}
	return true;
}

//Driver Program
int main () {
	char character;
	cout << "Press '1' to Load Game\nPress '2' to Start New Game\nPress '3' to Exit: ";
	cin >> character;
	cout << endl;
	ofstream fw;
	if (character == '1') {
		fw.open("f1.text");
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				fw << arr[i][j] << " ";
			}
			fw << endl;
		}
		fw.close();
		int r_num, c_num, num;
		int count = 0;
		rand_num(arr);
		display_board(arr);
		do {
			//Checking the validity of the input
			for (int i = 0;;i++) {
				cout << endl;
				cout << "Enter the row number: ";
				cin >> r_num;
				if (r_num <= 0 || r_num > 9) {
					cout << "Invalid Input, Enter Again" << endl;
				}
				else {
					break;
				}
			}
			for (int i = 0;;i++) {
				cout << "Enter the column number: ";
				cin >> c_num;
				if (c_num <= 0 || c_num > 9) {
					cout << "Invalid Input, Enter Again" << endl;
				}
				else {
					break;
				}
			}
			for (int i = 0;;i++) {
				cout << "Enter the number: ";
				cin >> num;
				if (num <= 0 || num > 9) {
					cout << "Invalid Input, Enter Again" << endl;
				}
				else {
					break;
				}
			}

			bool flag = check_rcm(arr, num, c_num, r_num);

			if (flag == true) {
			arr[r_num - 1][c_num - 1] = num;
			count++;
			}

			cout << endl;
			display_board(arr);

			// Logic: Declare the user winner if all the 81 boxes are filled with non zero elements
      		if (count == 81) {
      			cout << endl << "***Congratulations***\nYou Won The Game";
   			}
		} while (num != -1);
	}
}
