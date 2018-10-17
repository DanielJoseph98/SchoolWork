// SPECIFICATION FILE		( SortedType.h )
#ifndef SORTEDLISTBYARRAY_H
#define SORTEDLISTBYARRAY_H

#include "ItemType.h"

class  SortedListByArray		// declares a class data type
{				
public : 			

  SortedListByArray();

  void MakeEmpty( );        // 8 public member functions
  void InsertItem( ItemType  item ); 	
  void DeleteItem( ItemType  item ); 	

  bool IsFull( ) const;
  bool IsEmpty( ) const;              
  int  GetLength( ) const;  // returns length of list
  void RetrieveItem( ItemType &  item, bool&  found );

  void ResetList( );
  void GetNextItem( ItemType&  item ); 	

  void SplitList(ItemType item, SortedListByArray& listOne, SortedListByArray& listTwo);
  void MergeList(SortedListByArray& listOne, SortedListByArray& listTwo);

private :
   int length; 
   ItemType info[MAX_ITEM]; 
   int currentPos;
};


#endif
