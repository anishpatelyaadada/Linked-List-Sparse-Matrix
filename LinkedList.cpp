#include "LinkedList.h"
#include <iostream>

using namespace std;


LinkedList::LinkedList()
{
	head = nullptr;
	head_col_1 = nullptr;
	head_col_2 = nullptr;
}
// read all data by column by column
void LinkedList::insertNodeColumn(int row, int col, int data) {
	node *newNode;
	node *traverse = new node;
	newNode = new node;
	newNode->row_pos = row;
	newNode->col_pos = col;
	newNode->value = data;
	newNode->next_col = nullptr;

	//insert the data if the head is empty
	if (head == nullptr) {
		head = newNode; // assign new node to head as there is not content in the list
	}
	else {
		traverse = head;
		// while loop to check whose next memeber point to nullptr
		while (traverse->next_col)
			traverse = traverse->next_col;
		
		traverse->next_col = newNode;
		traverse = head; // circular linked list
	}
}

// read all data by row by row
void LinkedList::insertNodeRow(int row, int col, int data) {
	node *newNode;
	node *traverse = new node;
	newNode = new node;
	newNode->row_pos = row;
	newNode->col_pos = col;
	newNode->value = data;
	newNode->next_row = nullptr;

	//insert the data if the head is empty
	if (head == nullptr) {
		head = newNode; // assign new node to head as there is not content in the list
	}
	else {
		traverse = head;
		// while loop to check whose next memeber point to nullptr
		while (traverse->next_row)		
			traverse = traverse->next_row;
		
		traverse->next_row = newNode;
		traverse = head; // circular linked list
	}
}

//swap two row of the matrix
// 1 - in below function represent the first data such as row, col, data of the pointer
// 2 - in below function represent the first data such as row, col, data of the pointer
// above two pointer switch their value using linked list
void LinkedList::swap_row_col(int row1, int row2, int col1, int col2, int data1, int data2) {
	node *newNode1, *newNode2; //  place data into the new node to insert into the linked list
	node *traverse1 = new node; // traverse 1st row till end
	node *traverse2 = new node; // traverse 2st row till end
	// 1 node to assign data
	newNode1 = new node;
	newNode1->row_pos = row1;
	newNode1->col_pos = col1;
	newNode1->value = data1;
	newNode1->next_col = nullptr;
	// 2 node to assign data
	newNode2 = new node;
	newNode2->row_pos = row2;
	newNode2->col_pos = col2;
	newNode2->value = data2;
	newNode2->next_col = nullptr;

	//insert the data if the head is empty
	if (head_col_1 == nullptr || head_col_2 == nullptr) {
		//switch content of two node as we want to swap the row
		head_col_1 = newNode2; // assign new node to head as there is not content in the list
		head_col_2 = newNode1;
	}
	else { // if the head is not null then process this condition
		traverse1 = head_col_1;
		traverse2 = head_col_2;
		// while loop to check last position the linked list
		while (traverse1->next_col && traverse2->next_col) {
			traverse1 = traverse1->next_col;
			traverse2 = traverse2->next_col;
		}
		//switch content of two node as we want to swap the row 
		traverse1->next_col = newNode2;
		traverse2->next_col = newNode1;
		traverse1 = head_col_1; // circular linked list which point to head 
		traverse2 = head_col_2; // circular linked list which point to head 
	}
}

// swap content of two row by using input of user
void LinkedList::display_swap_row(int &Swap1, int &Swap2) {
	node *data1, *data2; // to assign data of two row 
	node *remainin_data; // to assign data of entire matrix
	data1 = head_col_1; // to assign head of row 1
	data2 = head_col_2; // to assign head to row 2
	remainin_data = head; // to assign head of entire matrix

	// create condition for each swaping; for Swap1 = 2
	// such as: -swap1_range_left = 10 * (Swap1 - 1) + 1 = 10 * (2-1)+1 = 11 Position; start the loop
	//  such as: -swap1_range_right = 10 * Swap1 = 10 * 2 = 20 Position; end the loop 
	int swap1_range_left = 10 * (Swap1 - 1) + 1;
	int swap1_range_right = 10 * Swap1;
	int swap2_range_left = 10 * (Swap2 - 1) + 1;
	int swap2_range_right = 10 * Swap2;
	int j = 1;
	cout << endl << "Swaping of two Rows.\n";
	while (remainin_data->next_row)
	{
		// condition to display the swap data 1
		if ((swap1_range_left <= j) && (swap1_range_right >= j)) {
			while (data1->next_col)
			{
				cout << data1->value << " ";
				data1 = data1->next_col;
				remainin_data = remainin_data->next_row;
				if (swap1_range_right == j)
					break;
				j++;
			}
			//	cout << endl;
			cout << data1->value << " ";
		}
		else if ((swap2_range_left <= j) && (swap2_range_right >= j)) { // condition to display the swap data 2
			while (data2->next_col)
			{
				cout << data2->value << " ";
				data2 = data2->next_col;
				remainin_data = remainin_data->next_row;
				if (swap2_range_right == j)
					break;
				j++;
			}
			//cout << endl;
			cout << data2->value << " ";
		}
		else {// condition to display remaining data in martix
			cout << remainin_data->value << " ";
		}
		remainin_data = remainin_data->next_row;

		if (j % 10 == 0)
		{
			cout << endl;
		}

		j++;
	}
	remainin_data = nullptr;
	//head = nullptr;
	head_col_1 = nullptr;
	head_col_2 = nullptr;
	cout << endl;
}

// swap content of two row by using input of user
void LinkedList::display_swap_col(int &Swap1, int &Swap2) {
	node *data1, *data2; // to assign data of two row 
	node *remainin_data; // to assign data of entire matrix
	data1 = head_col_1; // to assign head of row 1
	data2 = head_col_2; // to assign head to row 2
	remainin_data = head; // to assign head of entire matrix

	int Swap1_left = Swap1;
	int swap2_right = Swap2;
	int increase_value = 10;
	int j = 1;
	cout << endl << "Swaping of two Columns.\n";

	while (remainin_data->next_row)
	{
		if (Swap1 == j) {
			if (data1->next_col)
			{
				cout << data1->value << " ";
				data1 = data1->next_col;
				cout << remainin_data->value << " ";
				remainin_data = remainin_data->next_row;
				j++;


				Swap1 = Swap1 + increase_value;
			}
		}
		else if (Swap2 == j) { // condition to display the swap data 2

			if (data2->next_col)
			{
				cout << data2->value << " ";
				data2 = data2->next_col;
				cout << remainin_data->value << " ";
				remainin_data = remainin_data->next_row;
				j++;

				Swap2 = Swap2 + increase_value;
			}
		}// condition to display the swap data 1 
		else if (Swap1_left != j || swap2_right != j) {// condition to display remaining data in martix
			cout << remainin_data->value << " ";
		}
		remainin_data = remainin_data->next_row;
		if (j % 10 == 0) {
			cout << endl;
		}
		j++;
	}
	remainin_data = nullptr;
	head = nullptr;
	cout << endl;
}

// display the matrix by column and their transpose
void LinkedList::displayNodeCol() {
	node *data;
	data = head;
	int i = 1;
	while (data->next_col)
	{
		cout << data->value << " ";
		data = data->next_col;
		if (i % 10 == 0)
		{
			cout << endl;
		}

		i++;
	}
	data = nullptr;
	head = nullptr;
	cout << endl << endl;
}

// display the matrix by row
void LinkedList::displayNodeRow() {
	node *data;
	data = head;
	int i = 1;
	while (data->next_row)
	{
		cout << data->value << " ";
		data = data->next_row;
		if (i % 10 == 0)
		{
			cout << endl;
		}

		i++;
	}
	data = nullptr;
	cout << endl << endl;
}

// just for learning purpose to display two swap column 
// not in use in main function
void LinkedList::displayNode() {
	node *data1, *data2; // to assign data of two row 
	data1 = head_col_1; // to assign head of row 1
	data2 = head_col_2; //
	while (data1->next_col)
	{
		cout << data1->value << " ";
		data1 = data1->next_col;
	}
	//	cout << endl;
	cout << data1->value << " " << endl;

	while (data2->next_col)
	{
		cout << data2->value << " ";
		data2 = data2->next_col;
	}
	//cout << endl;
	cout << data2->value << " " << endl;
}

// selection function to select row / column for swap
void LinkedList::select_row_col_swap(int &swap1, int &swap2, int &selection) {
	
	cout << endl << "To Swap the column and row use following key.\n";
	cout << "1. Row \n2. Column \nSelection = ";
	cin >> selection;
	switch (selection)
	{
	case 1:
			cout << "Enter Row 1 = ";
			cin >> swap1;
			cout << "Enter Row 2 = ";
			cin >> swap2;
			break;
	case 2:
		cout << "Enter Column 1 = ";
		cin >> swap1;
		cout << "Enter Column 2 = ";
		cin >> swap2;
		break;
	default:
		cout << "In appropriate selection. Try again!\n";
		select_row_col_swap(swap1, swap2, selection);
		break;
	}
}

LinkedList::~LinkedList()
{
}
