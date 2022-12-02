#include <iostream>
#include <string.h>
using namespace std;

const int row = 9, column = 9;
int r_num, c_num, num;
//Generating 9x9 null grid
int arr[row][column] = {0};

//Function to initialize the game with some random numbers
void rand_num(int arr[9][9]) {
   srand(time(0));
   for (int i = 0; i < 32; i++) {
   int row = (rand() % 9) + 1;
   int col = (rand() % 9) + 1;
   arr[row][col] = (rand() % 9) + 1;
   }
}

//Function to display the board
void display_board(int arr[9][9]) {
   for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
         cout << arr[i][j] << "  ";
      }
      cout << endl;
   }
}

//Function to check the elements of row to avoid repition
void check_row(int r_num, int num) {
   int arr_1[row];
   for (int i = 0; i < row; i++) {
      arr_1[i] = arr[r_num][i];
   }
   for (int i = 0; i < row; i++) {
         if (arr_1[i] == num) {
            cout << "This number already exsist in this row, Please Enter Again!" << endl;
         }
      }
   
   }


//Function to check if the input number exsists in the row or column
void check_input(int arr[9][9],int num) {
   for (int i = 0; i < row; i++) {
         
      }
   }   

int main()
{
   //Displaying the board
   display_board(arr);
   cout << endl;
   // Displaying the initialized board
   rand_num(arr);
   display_board(arr);
   cout << endl;
   //Taking input from the user
   for (int i = 0;;i++) {
      cout << "Enter the row number: ";
      cin >> r_num;
      cout << "Enter the column number: ";
      cin >> c_num;
      cout << "Enter the number: ";
      cin >> num;
      if (num < 0 || row <= 0 || column <= 0) {
         cout << "Invalid Input, Enter Again";
      }
      if (num > 9 || row > 9 || column > 9) {
          cout << "Invalid Input, Enter Again";
      }
      if (!int(num) || !int(row) || !int(column)) {
         cout << "Invalid Input Try Again and Enter A Number Between (0-9): ";
         break;
      }
      display_board(arr);
      check_row(r_num, num);
   }
}