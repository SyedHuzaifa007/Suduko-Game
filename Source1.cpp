#include<iostream> 
#include<stdlib.h>
using namespace std;

const int row = 9, col = 9;

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
   cout << "*******SUDUKO GAME*******" << endl;
   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         cout << arr[i][j] << "  ";
      }
      cout << endl;
   }
}

int arr[row][col] = {0};

void check(int arr[row][9])
{
	int r, c,n;
	int count = 0;
	bool flag = true;
	bool flag2 = true;
	int temp1 = 0, temp2 = 0;
	for (int i = 0;i < row;i++)
	{
		for (int j = 0;j < col;j++)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	do {
		cout << "Enter the row number: ";
		cin >> r;
		cout << "Enter the column number: ";
		cin >> c;
		cout << "Enter the number: ";
		cin >> n;
			temp1 = r - 1;
			temp2 = c - 1;
			int temp = n;
			if (n < 1 || n>9)
			{
				flag = false;
			}
			for (int i = 0; i < row; i++)
			{
				if (arr[r - 1][i] == n)
					flag = false;
			}
			for (int i = 0; i < col; i++)
			{
				if (arr[i][c-1] == n)
					flag = false;
			}
			int startRow = r - r % 3,startCol = c - c % 3;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (arr[i + startRow][j + startCol] == n)
						flag = false;
				}
			}
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				if (flag == false) 
				{
					arr[temp1][temp2] = n;
				}
				else
				arr[temp1][temp2] = n;
			}
		}
		system("CLS");
			for (int i = 0;i < row;i++)
			{
				for (int j = 0;j < col;j++)
				{
					cout << arr[i][j] << "\t";
				}
				cout << endl;
			}
			temp = 0;
			flag = true;
		
	} while (n != -1);
}

int main()
{
	check(arr);
}