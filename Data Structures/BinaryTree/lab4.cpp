#include "ItemType.h"
#include "TreeType.h"



int main(){

	cout << endl;
	
    TreeType firstTree;

    ItemType x;
    x.Initialize('F');
    firstTree.InsertItem(x);

 
    
    if (firstTree.IsEmpty() == false)
       cout<<"the first item is inserted"<<endl;

    cout<<"After inserting the first item "<<x<<" into the tree"<<endl;
    firstTree.Print();

   x.Initialize('D');
   firstTree.InsertItem(x);
    x.Initialize('E');
    firstTree.InsertItem(x);

    x.Initialize('G');
    firstTree.InsertItem(x);
    x.Initialize('A');
    firstTree.InsertItem(x);
    x.Initialize('M');
    firstTree.InsertItem(x);
    x.Initialize('C');
    firstTree.InsertItem(x);

/*
         x.Initialize('A');
    firstTree.InsertItem(x);
    x.Initialize('B');
    firstTree.InsertItem(x);
    x.Initialize('C');
    firstTree.InsertItem(x);
    x.Initialize('D');
    firstTree.InsertItem(x);
    x.Initialize('E');
    firstTree.InsertItem(x);    
    x.Initialize('F');
    firstTree.InsertItem(x);
    x.Initialize('G');
    firstTree.InsertItem(x);
    x.Initialize('H');
    firstTree.InsertItem(x);
    x.Initialize('I');
    firstTree.InsertItem(x);
    x.Initialize('J');
    firstTree.InsertItem(x);

*/

    //CURRENT TREE
    //		F
    //	       / \
    //	      D   G
    //	     / \   \
    //	    A   E   M
    //	     \
    //	      C

    cout<<"After inserting five items into the tree"<<endl;
    firstTree.Print();
    firstTree.treePrint();


    int count = firstTree.GetLength();
    cout<<"The tree has "<<count<<"  elements"<<endl;
  
    //LEAF TEST 
    int leaves = firstTree.LeafCount();
    //Should return 3
    cout<<"The tree has "<<leaves<<" leaves"<<endl;

   //ANCESTOR TEST
   ItemType M;
   M.Initialize('M');
   cout << "Ancestors: ";
   firstTree.Ancestors(M);
   //should return G F
   cout << endl;


    //DELETE TEST
    ItemType D;
    D.Initialize('D');
    firstTree.DeleteItem(D);

    cout << "After deleting 'D'" << endl;
        firstTree.Print();
        firstTree.treePrint();

    //CURRENT TREE
    //		F
    //	       / \
    //	      E   G
    //	     /    \
    //	    A      M
    //	   /
    //	  C
    //
    //	  Old delete would have replaced D with C, not E

    ItemType C;
    C.Initialize('C');
    cout << "Ancestors of 'C': " << endl;
    firstTree.Ancestors(C);
    //Should return A E F, if D was replaced with E
    cout << endl;



    //SWAP TEST

	TreeType swapped;
	firstTree.pubSwap(swapped);
	cout << endl << "Swapped tree: " << endl;
	swapped.Print();
	swapped.treePrint();
	//Should return F G M E A C(in reverse order -- larger letters go firsti)
	//
	leaves = swapped.LeafCount();
         cout<<"The swapped tree has "<<leaves<<" leaves"<<endl;

		
    return 0;
}


