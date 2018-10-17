#include "UnsortedListByArray.h"

//constructor
UnsortedListByArray::UnsortedListByArray()
{
  length = 0;
}

//check whether the list is full
bool UnsortedListByArray::IsFull() const
{
  return (length == MAX_ITEM);
}

//check how many elements are in this list
int UnsortedListByArray::GetLength( ) const
{
  return length;
}

//check whether there is element in this list
bool UnsortedListByArray::IsEmpty() const
{
  return (length == 0);
}

//Pre: the list should not be full
// Post: item is in the list.
void UnsortedListByArray::InsertItem(ItemType item)
{
  info[length] = item;
  length++;
}

// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged.
void UnsortedListByArray::RetrieveItem(ItemType& item, bool& found) 
{
  bool moreToSearch;
  int location = 0;
  found = false;
  moreToSearch = (location < length);
  while (moreToSearch && !found) 
  {
    switch (item.ComparedTo(info[location]))
    { case LESS    : 
      case GREATER : location++;
                     moreToSearch = (location < length);
                     break;
      case EQUAL   : found = true;
                     item = info[location];
                     break;
    }
  }
}

// Pre: item's key has been inititalized.
//	One and only one element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item�s.
void UnsortedListByArray::DeleteItem ( ItemType  item ) 
{    
  int  location  =  0 ;

  while (item.ComparedTo (info[location])  !=  EQUAL)
         location++;
  // move last element into position where item was located

  info [location] = info [length - 1 ] ;
  length-- ; //the length of the list is decreased
}

// Pre:  N/A   
// Post: the list is empty
void UnsortedListByArray::MakeEmpty()
{
   length = 0;
}


// Pre:  List has been inititalized.
// Post: Current position is prior to first element.
void UnsortedListByArray::ResetList ( )  
{    
  currentPos  =  -1 ;
}

// Pre:  List has been initialized. Current position is 
//       defined. 
//       Element at current position is not last in list.
// Post: Current position is updated to next position.
// 	  item is a copy of element at current position.
void UnsortedListByArray::GetNextItem ( ItemType&  item )  
{
  currentPos++  ;
  item = info [currentPos] ;
}


// Pre:: List has been initialized and is not empty. listOne and listTwo are
// 	 initialized but not empty
//
// Post: listOne contains all the items of list whose keys are less than
//       or equal to item’s key;
//       listTwo contains all the items of list whose keys are greater
//       than item’s key.
void UnsortedListByArray::SplitList(ItemType item, UnsortedListByArray& listOne, UnsortedListByArray& listTwo)
{
	ItemType listItem;
	ResetList();
	
	while (currentPos < length)
	{
		GetNextItem(listItem);
		if (listItem.ComparedTo( item) == GREATER)
			listTwo.InsertItem(listItem);
		else
			listOne.InsertItem(listItem);
	}
}

// Pre: List has been initialized but empty
// 	listOne and listTwo have been initialized
// Post: List contains all items from listOne and listTwo, even duplicates
void UnsortedListByArray::MergeList(UnsortedListByArray& listOne, UnsortedListByArray& listTwo)
{
	ItemType listItem;
	int length;

	listOne.ResetList();
	listTwo.ResetList();
	MakeEmpty();

	length = listOne.GetLength();
	for (int i = 0; i < length; i++)
	{
		listOne.GetNextItem(listItem);
		InsertItem(listItem);
	}

	length = listTwo.GetLength();
	for (int i = 0; i < length; i++)
	{
		listTwo.GetNextItem(listItem);
		InsertItem(listItem);
	}
}






