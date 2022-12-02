#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;

ifstream file_read;
ofstream file_write; 

const int row = 9, column = 9;
int r_num, c_num, num;
//Generating 9x9 null grid
int arr[row][column] = {0};
int arr_r[9];
int arr_c[9];
int arr_s[3][3] = {0};

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

void pop_arr_r(int arr_r[9]) {
   for (int i = 0; i < 9; i++) {
      arr_r[i] = arr[r_num-1][i];
   }
}

void pop_arr_c(int arr_c[9]) {
   for (int i = 0; i < 9; i++) {
      arr_c[i] = arr[c_num-1][i];
   }
}

//Function to check the elements of row to avoid repition
void check_row(int r_num, int num) {
   pop_arr_r(arr_r);
   for (int i = 0; i < row; i++) {
         if (arr_r[i] != num && num >= 0 && num < 10) {
            arr[r_num-1][c_num-1] = num;
            display_board(arr);
            cout << endl;
            break;
         }
         else if (arr_r[i] == num) {
            cout << "This number already exsist in this row, Please Enter Again!" << endl;
         }
         break;
      }
   }

//Function to check the elements of column to avoid repition
void check_column(int c_num, int num) {
   pop_arr_c(arr_c);
   for (int i = 0; i < column; i++) {
         if (arr_c[i] != num && num >= 0 && num < 10) {
            arr[r_num-1][c_num-1] = num;
            display_board(arr);
            cout << endl;
            break;
         }
         else if (arr_c[i] == num) {
            cout << "This number already exsist in this column, Please Enter Again!" << endl;
         }
         break;
      }
}

//Function to check if the input number exsists in the row or column
void check_matrix(int arr[9][9],int num) {
   for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 3; j++) {
            arr_s[i][j] = arr[i][j];
         }
      }
   }   

int main() {
   // Displaying the initialized board
   rand_num(arr);
   display_board(arr);
   cout << endl;
   //Taking input from the user
   for (int i = 0 ;; i++) {
      cout << "Enter the row number: ";
      cin >> r_num;
      cout << "Enter the column number: ";
      cin >> c_num;
      cout << "Enter the number: ";
      cin >> num;
      cout << endl;
      //Checking the validity of input
      if (num < 0 || row <= 0 || column <= 0) {
         cout << "Invalid Input, Enter Again";
         cout << endl;
      }
      if (num > 9 || row > 9 || column > 9) {
          cout << "Invalid Input, Enter Again";
          cout << endl;
      }
      if (!int(num) || !int(row) || !int(column)) {
         cout << "Invalid Input, Enter Again";
         cout << endl;
      }
      //Checking if the number exsist in the input row
      check_row(r_num, num);
      check_column(c_num, num);
   }
}