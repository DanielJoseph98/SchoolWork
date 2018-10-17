/* Daniel Joseph
 * October 18, 2017
 * CS2200, Lab 3
 *
 */

#include <stack>
#include <iostream>

using namespace std;

//Pushes a string into a stack one char at a time
//Post:: A stack containing all chars of an individual string
void pushToStack(const string s, stack<char> & letters)
{
	for (int i = 0; i < s.length(); i++)
	{
		letters.push(s[i]);
	}
}

//Filters a particular string to keep only alphanumeric chars, converting all letters to lowercase
//Post:: A filtered string cotaining only numbers and lowercase letters
void filterInput(string & s)
{
	string filtered;
	
	for (int i = 0; i < s.length(); i++)
	{
		if((s[i] >= '0' && s[i] <= '9') 
			|| (s[i] >='a' && s[i] <= 'z') 
			|| (s[i] >= 'A' && s[i] <= 'Z'))
		{
			//convert any uppercase to lowercase
			filtered += tolower(s[i]);
		}
	}
	s = filtered;	
}

//Compares a particular string to a stack of chars, checking for equality
//Post:: Returns true if string is equal to output of stack
bool compareString(const string s, stack<char> &letters)
{
	string fromStack;
	while (!(letters.empty()))
	{
		fromStack += letters.top();
		letters.pop();
	}
	
	return (s == fromStack);

}

//Test function to test test implementation of stack and filter
void showstack(stack <char> gq)
{
    stack <char> g = gq;
    while (!g.empty())
    {
        cout << g.top();
        g.pop();
    }
    cout << '\n';
}

//Function to test whether a given user input is a palindrome, meaning the same forwards and backwards
//Function asks whether user would like to repeat
int main()
{
	string input, toTest, response;
	stack <char> letters;
	bool repeat;
	do
	{	
		input.clear();	
		cout << "Enter your string to check whether or not it's a palindrome: ";
		if (repeat)
			cin.ignore();
		getline(cin, input);
		toTest = input;
	
		filterInput(toTest);
	
		pushToStack(toTest, letters);
		showstack(letters);

		if (compareString(toTest, letters))
			cout << endl << "Your string is a palindrome" << endl;
		else
			cout << endl <<  "Your string is not a palindrome" << endl;
		
		cout << endl << "Would you like to try another word? (y/n): " ;
		cin >> response;
		
		//for use on line 74-75. This is the only way I could find to clear cin without disturbing with the first input
		//Without this, the first input skips the first character 
		repeat = true;
	
	}while (response == "y" || response == "Y");

	return 0;
}
