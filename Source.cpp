#include<iostream>
#include"LinkedList.h"

using namespace std;

int main() {

	LinkedList Process_Data;
	int swap1, swap2, selection;
	int size_of_matrix = 10, repeat;
	int sparseMatrix[10][10] = {
	{1,0,3,0,0,6,0,0,9,10 },
	{0,12,0,14,0,0,17,0,0,20},
	{21,0,0,0,0,0,0,28,0,0},
	{0,32,0,0,35,0,0,0,39,0},
	{41,0,43,0,0,0,0,0,0,50},
	{0,0,0,0,0,0,0,0,0,0},
	{61,0,0,0,0,0,0,0,0,0},
	{71,0,73,0,0,76,0,0,0,0},
	{0,82,0,0,85,0,87,0,0,0},
	{91,0,0,94,0,96,0,98,0,100} };
	LinkedList();
	// read and display original matrix by column
	cout << "Original Matrix by Column - A" << endl;
	for (int row = 0; row < size_of_matrix; row++) {
		for (int col = 0; col < size_of_matrix; col++) {
			Process_Data.insertNodeColumn(row, col, sparseMatrix[row][col]);
		}
	}
	Process_Data.displayNodeCol();

	// display transpose of original matrix
	cout << "Transpose Matrix - A" << endl;
	for (int col = 0; col < size_of_matrix; col++) {
		for (int row = 0; row < size_of_matrix; row++) {
			Process_Data.insertNodeColumn(row, col, sparseMatrix[row][col]);
		}
	}
	Process_Data.displayNodeCol();

	// read and display original matrix by row
	//cout << "Original Matrix by Row- A" << endl;
	for (int col = 0; col < size_of_matrix; col++) {
		for (int row = 0; row < size_of_matrix; row++) {
			Process_Data.insertNodeRow(row, col, sparseMatrix[col][row]);
		}
	}
	//Process_Data.displayNodeRow(); // to display the original matrix
	// selection what user want to swap
	// 1 - row or  2 - column
	do {
		Process_Data.select_row_col_swap(swap1, swap2, selection);
		if (selection == 1) { // to swap row
			for (int col = 0; col < size_of_matrix; col++) {
				Process_Data.swap_row_col(swap1 - 1, swap2 - 1, col, col, sparseMatrix[swap1 - 1][col], sparseMatrix[swap2 - 1][col]);
			}
			Process_Data.display_swap_row(swap1, swap2);
		}
		else if (selection == 2) { // to swap column
			for (int row = 0; row < size_of_matrix; row++) {
				Process_Data.swap_row_col(row, row, swap1 - 1, swap2 - 1, sparseMatrix[row][swap1 - 1], sparseMatrix[row][swap2 - 1]);
			}
			Process_Data.display_swap_col(swap1, swap2);
			cout << endl << endl;
		}
		
		cout << "\nDo you like to repeat (1 - Yes / 2 - No) = ";
		cin >> repeat;
		cout << endl;
	} while (repeat == 1);

	system("pause");
	return 0;
}