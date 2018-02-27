#pragma once
class LinkedList
{
public:
	struct node
	{
		int value;
		int row_pos = 0;
		int col_pos = 0;
		struct node *next_row;
		struct node *next_col;
	};
	node *head;
	node *head_col_1;
	node *head_col_2;

	LinkedList();
	void insertNodeColumn(int, int, int);
	void insertNodeRow(int, int, int);
	void displayNode();
	void select_row_col_swap(int &,int &, int &);
	void swap_row_col(int, int, int, int, int, int);
	void display_swap_row(int &,int &);
	void display_swap_col(int &, int &);
	void displayNodeCol();
	void displayNodeRow();
	~LinkedList();
};

