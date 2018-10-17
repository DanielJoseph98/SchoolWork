#include "SortedListByArray.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

SortedListByArray::SortedListByArray()
{
  length = 0;
}


bool SortedListByArray::IsFull() const
{
  return (length == MAX_ITEM);
}

int SortedListByArray::GetLength( ) const
{
  return length;
}


bool SortedListByArray::IsEmpty() const
{
  return (length == 0);
}

void SortedListByArray::InsertItem(ItemType item) 
{
   bool moreToSearch; 
   int location = 0;
   moreToSearch = (location < length);
   while (moreToSearch)
   {
      switch(item.ComparedTo(info[location]))
      {
         case LESS : moreToSearch = false; break;
         case GREATER : location++;
                        moreToSearch = (location < length);
                        break;
      }
   }

   for ( int index = length; index > location; index--)
        info[index] = info[index-1];

   info[location] = item;
   length++;
}


void SortedListByArray::RetrieveItem(ItemType& item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged. 
{
  int midPoint;
  int first =0;
  int last = length -1;
  
  bool moreToSearch = (first <= last);
  found = false;
  while (moreToSearch && !found) 
  {
    midPoint = (first+last)/2;
    switch (item.ComparedTo(info[midPoint]))
    { 
      case LESS    : last = midPoint -1;
                     moreToSearch = (first <= last);
                     break;
      case GREATER : first = midPoint +1;
                     moreToSearch = (first <= last);
                     break;
      case EQUAL   : found = true;
                     item = info[midPoint];
                     break;
    }
  }
}


void SortedListByArray::DeleteItem(ItemType item) 
// Pre: item�s key has been inititalized.
//	One and only one element in the list has a key that matches item�s.
// Post: No element in the list has a key that matches item�s.
{
   int location = 0;
   while(item.ComparedTo(info[location])!= EQUAL)
       location++;

   for ( int index = location +1; index < length; index++)
        info[index-1] = info[index];
   info[location] = item;
   length--;
}


void SortedListByArray::MakeEmpty()
// Pre:  N/A   
// Post: the list is empty
{
   length = 0;
}



void SortedListByArray::ResetList ( )  
// Pre:  List has been inititalized.
// Post: Current position is prior to first element.
{    
  currentPos  =  -1 ;
}


void SortedListByArray::GetNextItem ( ItemType&  item )  
// Pre:  List has been initialized. Current position is 
//       defined. 
//       Element at current position is not last in list.
// Post: Current position is updated to next position.
// 	  item is a copy of element at current position.
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
void SortedListByArray::SplitList(ItemType item, SortedListByArray& listOne, SortedListByArray& listTwo)
{
	SortedListByArray toAdd;
	for (int i = 0; i < length; i ++)
	{
		if(item.ComparedTo(info[i]) == GREATER)
			listOne.InsertItem(info[i]);
		else
			listTwo.InsertItem(info[i]);
	
		toAdd.InsertItem(info[i]);				
	}
}

// Pre: List has been initialized but empty
// 	listOne and listTwo have been initialized
// Post: List contains all items from listOne and listTwo, even duplicates
void SortedListByArray::MergeList(SortedListByArray& listOne, SortedListByArray& listTwo)
{
	ItemType listItem;
	bool moreToSearch;
	int location;
	int j = 0;
	SortedListByArray* list;	

	listOne.ResetList();
	listTwo.ResetList();
	length = 0;
	currentPos = -1;
	location = 0;

	list = &listOne;
	do
	{
		j++;
		for(int i = 0; i < list->GetLength(); i++)
		{
			location = 0;
			list->GetNextItem(listItem);
			moreToSearch = (location < length);

			while(moreToSearch)
			{
				switch(listItem.ComparedTo(info[location]))
				{
					case LESS: moreToSearch = false;
						   break;
					case EQUAL:
					case GREATER:
						location++;
						moreToSearch = (location < length);
						break;
				}
			}
			for (int j = length; j > location; j--)
				info[j] = info[j-1];
			info[location] = listItem;
			length++;
		}
	list = &listTwo;
	}while(j< 2);


}
