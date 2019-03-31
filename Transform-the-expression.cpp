/*
Transform the algebraic expression with brackets into RPN form (Reverse Polish Notation). Two-argument operators: +, -, *, /, ^ (priority from the lowest to the highest), brackets ( ). Operands: only letters: a,b,...,z. Assume that there is only one RPN form (no expressions like a*b*c).

Input
t [the number of expressions <= 100]
expression [length <= 400]
[other expressions]
Text grouped in [ ] does not appear in the input file.

Output
The expressions in RPN form, one per line.
Example
Input:
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*
*/

#include <iostream>
#include <stack>								//Including for stack STL.
using namespace std;
int main()
{
	int t;										//No of test cases.
	cin >> t;
	stack <char> st;							//Declaring a stack 'st'.
	while(t--)
	{
		string s;								//Storing infix expression in 's'.
		cin >> s;
		for(int i=0;i<s.length();i++)			//Traversing each character.
		{
			if(s[i] >= 'a' && s[i] <= 'z')		//If current character is an operand, simply print it.
			{
				cout << s[i];
			}
			else if(s[i] == '(')				//If it is an opening bracket, push it into the stack.
			{
				st.push(s[i]);
			}
			else if(s[i] == ')')				//If it is a closing bracket
			{
				while(st.top() != '(')			//Pop and print the elements till an opening bracket comes.
				{
					cout << st.top();
					st.pop();
				}
				st.pop();						//Pop the opening bracket.
			}
			else
			{
				/*
				If an operator of higher precedance is present int the stack print it and pop it till an operator with lower or same precedence is read.
				*/
				switch(s[i])
				{
					case '+':
						while(st.top() == '*' || st.top() == '/' || st.top() == '^')
						{																
							cout << st.top();											
							st.pop();													
						}																
						st.push(s[i]);												//Push the current character.
						break;
					case '-':
						while(st.top() == '*' || st.top() == '/' || st.top() == '^')
						{
							cout << st.top();
							st.pop();
						}
						st.push(s[i]);
						break;
					case '*':
						while(st.top() == '^')
						{
							cout << st.top();
							st.pop();
						}
						st.push(s[i]);
						break;
					case '/':
						while(st.top() == '^')
						{
							cout << st.top();
							st.pop();
						}
						st.push(s[i]);
						break;
					case '^':
						st.push(s[i]);
						break;
				}
			}
		}
		cout << endl;					//Next line after each test case.
	} 
}
