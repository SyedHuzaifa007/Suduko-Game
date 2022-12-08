#include<iostream> 
#include<fstream>
using namespace std;

const int row = 9, col = 9;
//Initializing the 9x9 Matrix with some random numbers
int arr[row][col] = {
				{6,4,0,0,0,0,0,0,0},
				{0,0,0,0,1,0,0,0,0},
				{0,0,0,7,0,0,0,0,0},
				{0,0,0,0,0,0,0,0,3},
				{0,0,0,9,0,0,0,0,4},
				{8,0,0,0,3,0,0,0,9},
				{0,0,0,0,0,0,0,3,0},
				{0,0,0,0,0,0,0,0,7},
				{0,0,0,0,6,0,0,9,0}
			};

//Function to display the board
void display_board(int arr[9][9]) {
	cout << "**********SUDUKO GAME***********" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << arr[i][j] << " | ";
		}
		cout << endl;
	}
}

//Function to save the game
void save_game(int arr[row][col]) {
	bool flag = true;
	char option;
	while (flag == true) {
		cout << "\nEnter the slot you want to save game\n1) G1\n2) G2\n3) G3: ";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			system("cls");
			display_board(arr);
			cout << endl << "Invalid Input, Try Again" << endl;
		}
		else if (option == '1') {
			ofstream file1;
			file1.open("g1.txt");
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					file1 << arr[i][j] << " ";
				}
				cout << endl;
			}
			file1.close();
			system("cls");
			display_board(arr);
			cout << endl << "Game Saved Successfully, Thanks for Playing" << endl;
			break;
		}
		else if (option == '2') {
			ofstream file2;
			file2.open("g2.txt");
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					file2 << arr[i][j] << " ";
				}
				cout << endl;
			}
			file2.close();
			system("cls");
			display_board(arr);
			cout << endl << "Game Saved Successfully, Thanks for Playing" << endl;
			break;
		}
		else if (option == '3') {
			ofstream file3;
			file3.open("g3.txt");
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					file3 << arr[i][j] << " ";
				}
				cout << endl;
			}
			file3.close();
			system("cls");
			display_board(arr);
			cout << endl << "Game Saved Successfully, Thanks for Playing" << endl;
			break;
		}
		else {
			system("cls");
			display_board(arr);
			cout << endl << "Only three game slots are available";
		}
	}
}

//Function to load the game
void load_game(int arr[row][col]) {
	bool flag = true;
	char option;
	while (flag == true) {
		cout << "\nEnter the slot you want to save game\n1) G1\n2) G2\n3) G3: ";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			system("cls");
			display_board(arr);
			cout << "Invalid Input, Try Again";
		}
		else if (option == '1') {
			ifstream file1;
			file1.open("g1.txt");
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					file1 >> arr[i][j];
				}
			}
			file1.close();
			system("cls");
			display_board(arr);
			cout << endl << "Game loaded successfully, You can play now" << endl;
			break;
		}
		else if (option == '2') {
			ifstream file2;
			file2.open("g2.txt");
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					file2 >> arr[i][j];
				}
			}
			file2.close();
			system("cls");
			display_board(arr);
			cout << endl << "Game loaded successfully, You can play now" << endl;
			break;
		}
		else if (option == '3') {
			ifstream file3;
			file3.open("g3.txt");
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					file3 >> arr[i][j];
				}
			}
			file3.close();
			system("cls");
			display_board(arr);
			cout << endl << "Game loaded successfully, You can play now" << endl;
			break;
		}
		else {
			system("cls");
			display_board(arr);
			cout << endl << "Only three game slots are available";
		}
	}
}

//Function to avoid repitition in row, column and 3x3 matrix
bool check_rcm(int arr[9][9], int n, int c, int r) {
	c = c - 1;
	r = r - 1;
	for (int i = 0; i < 9; i++) {
		if (arr[i][c] == n) {
			cout << endl << "Invalid Input, Entered value exsists in the same 'Column', Enter Again" << endl;
			return false;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (arr[r][i] == n) {
			cout << endl << "Invalid Input, Entered value exsists in the same 'Row', Enter Again" << endl;
			return false;
		}
	}
	r = r - r % 3;
	c = c - c % 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (arr[i + r][j + c] == n) {
				cout << endl << "Invalid Input, Entered value exsists in the '3x3 Matrix', Enter Again" << endl;
				return false;
			}
		}
	}
	return true;
}

// Main menu funtion
bool main_menu(int arr[row][col]) {
	bool flag = true;
	char option;
	while (flag != false) {
		cout << "\nChoose an option to continue:\nc --> Continue\ns --> Save The Game\nq --> Quit The Game: \n";
		cin >> option;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(CHAR_MAX, '\n');
			cout << "\nInvalid Input: Try Again\n";
		}
		else if (option == 'q') {
			system("cls");
			display_board(arr);
			flag = false;
			return true;
		}
		else if (option == 's') {
			system("cls");
			display_board(arr);
			save_game(arr);
		}
		else if (option == 'c') {
			system("cls");
			flag = false;
			cout << endl << "Thanks for playing the game!!";
			return false;
		}
		else {
			system("cls");
			display_board(arr);
			cout << endl << "Invalid Input, Try Again" << endl;
		}
	}
}

//Function to input array
void input_arr(int arr[row][col]) {
	int count = 0;
	bool status = false;
	int row_num = 0, col_num = 0, num = 0;
	while (status == false) {
		//num = 0, row = 0, col = 0;
		cout << endl << "Enter the row number: ";
		cin >> row_num;
		cout << endl << "Enter the column number: ";
		cin >> col_num;
		if (!cin.good()) {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			system("cls");
			display_board(arr);
			cout << endl << "Invalid Input, Try Again" << endl;
		}
		else if (row_num < 1 || row_num > 9 || col_num < 1 || col_num > 9) {
			system("cls");
			cout << endl << "Entered row or column doesn't exsist, Input again";
			continue;
		}
		else if (arr[row_num - 1][col_num - 1] != 0) {
			system("cls");
			display_board(arr);
			cout << endl << "There is already a value in the box, Input again" << endl;
		}
		else {
			cout << endl << "Enter the number: ";
			cin >> num;
			if (!cin.good()) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				system("cls");
				display_board(arr);
				cout << endl << "Invalid Input, Try Again";
			}
			else if (num < 1 || num > 9) {
				system("cls");
				display_board(arr);
				cout << "\nExceeded the Range: Try Again\n";
				continue;
			}
			else if (check_rcm(arr, num, col_num, row_num) == false) {
				system("cls");
				display_board(arr);
				check_rcm(arr, num, col_num, row_num);
				continue;
			}
			else {
				arr[row_num - 1][col_num - 1] = num;
				system("cls");
				display_board(arr);
				count++;
				if (count == 3) {
					main_menu(arr);
					if (main_menu(arr) != true) {
						break;
					}
					if (main_menu(arr) != false) {
						system("cls");
						display_board(arr);
						continue; 
                    }
		        }
	        } 
        }
    }
}

//Driver Program
int main() {
	char option;
	bool loop = false;
	int arr2[row][col];
	while (loop == false) {
		cout << "\tWELCOME TO SUDUKO\n";
		cout << "\n--------------------------MENU--------------------------\n";
		cout << endl << "Select an option from the below menu\nNOTE: You can save or quit the game after 3 moves";
		cout << "\ns-> Start A New Game\nl-> Load Game\nq-> Quit: \n";
		cin >> option;
		if (option == 's') {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++)
				{
					arr2[i][j] = arr[i][j];
				}
			}
			system("cls");
			display_board(arr2);
			input_arr(arr2);
		}
		else if (option == 'l') {
			system("cls");
			load_game(arr2);
			input_arr(arr2);
		}
		else if (option == 'q') {
			cout << endl << "Thanks for playing the game, See you soon" << endl;
			break;
		}
		else {
			system("cls");
			cout << endl << "Invalid Input" << endl;
		}
	}
}