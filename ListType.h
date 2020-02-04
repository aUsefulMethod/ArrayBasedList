#pragma once

class ListType {

private:

	int count;
	int maxSize = 10;
	int * array = new int[maxSize];
	

public :

	void clear();
	int getCount() const;
	void add(int item);
	void insertItem(int item, int insertionIndex);
	void deleteItem(int item);
	bool isEmpty() const;
	bool isFull() const;
	void show();
	void menu();
	
	ListType();

	~ListType();

};
