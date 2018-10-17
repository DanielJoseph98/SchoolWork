/*Daniel Joseph
 * Final Project
 * CISC2200 - Fall 2017
 *
 * Take in an expression, convert to postfix, and calculate answer
 * (6+13)*2-(5+1)/3 
 * -> 6 13 + 2 * 5 1 + 3 / - 
 *  -= 36
 *
 * Bugs
 * 	Exception classes: an extra parenthesis at end does not trigger exception
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;


int precedence(char op)
{
	if(op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
	else return 0;
}

double calcOp(double op1, double op2, char op)
{
	switch(op)
	{
		case('+'): return (op1 + op2);
			   break;
		case('-'): return (op1 - op2);
			   break;
		case('*'): return (op1 * op2);
			   break;
		case('/'): if (op2 == 0)
				   //Divide by 0 exception
				   throw std::overflow_error("Divide by zero exception - result is nullified\n");
			   else
				   return (op1 / op2);
			   break;
		default: return 0;
	}
}

string prefixConvert(string input)
{
	stack<char> equation;
	string postfix;
	int index = 0, openParen = 0, closedParen = 0;
	bool cont = false;

	while(index < input.length())
	{
		//if operand, output
		if(isdigit(input[index]))
		{
			int j = 1;
			postfix += input[index];
			while(isdigit(input[index+j]))
			{
				postfix += input[index+j];
				j++;
			}
			postfix += " ";
			if (j > 1)
				index += (j-1);	
		}
		//if open parenthesis, push to stack
		else if(input[index] == '(')
		{
			equation.push(input[index]);
			openParen++;
		}
		//if operator,
		else if(input[index] == '+' || input[index] == '-' || 
				input[index] == '/' || input[index] == '*')
		{
			//exception handling, bad operator placement
			if((!isdigit(input[index+1]) && input[index+1] != '(')  || index == input.length())
			{
				throw std::overflow_error("Input error: Extra operator \n");
			}

			if(equation.empty() || equation.top() == '(' || 
			precedence(input[index]) > precedence(equation.top()))
			{
				equation.push(input[index]);

			}
			//part 4d
			else 
			{
				postfix += equation.top();
				postfix += " ";
				equation.pop();	
				equation.push(input[index]);	
			}
		}
		else if(input[index] == ')')
		{
			closedParen++;
			while(equation.top() != '(')
			{
				postfix += equation.top();
				postfix += " ";	
				equation.pop();
			}
			//final pop to discard opening parenthesis '('
			equation.pop();
		}
		index++;
	}
	//unstack remaining operators
	while(!equation.empty())
	{
		if(equation.top() != ')')
		{
			postfix += equation.top();
			postfix += " ";			
		}
	
		equation.pop();

	}
	//exception for misplaced/extra parenthesis
	if (openParen != closedParen)
	{
		throw std::overflow_error("Input error: Misplaced parenthesis \n");
	}
	return postfix;
}

double calcPost(string post)
{
	stack<double> results;
	string temp;
	int index = 0;
	double op1, op2, result;
	while(index < post.length())
	{
		if(isdigit(post[index]))
		{
			temp = "";
			int j = 1;
			temp += post[index];
			while(isdigit(post[index+j]))
			{
				temp += post[index+j];
				j++;
			}
			if (j > 1)
				index += (j-1);	
			//string to double function
			results.push(std::stod(temp, NULL));
 		}

		else if(post[index] == '+' || post[index] == '-' || 
				post[index] == '/' || post[index] == '*')
		{
			op2 = results.top();
			results.pop();
			op1 = results.top();
			results.pop();
			try {
				result = calcOp(op1, op2, post[index]);
			} catch (overflow_error e) {
			//	cout << e.what();
				cout << "Cannot divide " << op1 << " by " << op2 << endl;
				throw std::overflow_error("Divide by zero exception\n");

			}
			results.push(result); 
		}
		index ++; 
	}

	return results.top();
}



int main()
{
	string preInput, postInput, again;
	double result;

	try{
		cout << "\nEnter calculation: ";
		getline(cin, preInput);
		postInput = prefixConvert(preInput);
		cout << "Postfix conversion: " << postInput << endl;
		result = calcPost(postInput);
		cout << "The result is = " << result << endl;

	} catch (overflow_error e){
		cout << e.what();
	}
}


