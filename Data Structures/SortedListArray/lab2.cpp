#include "SortedListByArray.h"
#include "ItemType.h"
#include <cstdlib>
#include <ctime>
#include <iostream>


void printList(SortedListByArray& list)
// Pre: list has been initialized
// Post: each component has been listed
{
	int length;
	ItemType item;

	list.ResetList();
	length = list.GetLength();
	for (int i = 0; i < length; i++)
	{
		list.GetNextItem(item);
		item.Print();
	}
}
	

int main()
{
	srand(time(NULL));
	
	SortedListByArray list1, list2, list3, list4;

	for (int i = 0; i < 10; i++)
	{
//		int j = (rand()%10 +1);
		ItemType x;
		x.Initialize(i);
		list1.InsertItem(x);
		
	}
	ItemType y;
	y.Initialize(5);

	cout << "List 1: " << endl;
	printList(list1);

	cout << "Split list into 2, at value 5." << endl;
	list1.SplitList(y, list2, list3);	
	cout << "List 2: " << endl;
	printList(list2);

	cout << "List 3: " << endl;
	printList(list3);

	cout << "Combine lists back into list 4, sorted." << endl;
	list4.MergeList(list2, list3);

	cout << "List 4: " << endl;
	printList(list4);

	return 0;
}
