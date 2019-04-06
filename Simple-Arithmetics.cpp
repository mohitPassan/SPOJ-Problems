#include <iostream>
#include <cstring>
#include <iomanip>
#include <stack>
using namespace std;

void seperateString(string input, char a[], char b[],char &op)
{
	int i=0,j=0;
	while(input[i] != '+' && input[i] != '-' && input[i] != '*')
	{
		a[j++] = input[i++];
	}
	a[j] = '\0';
	op = input[i++];
	j=0;
	while(input[i] != '\0')
	{
		b[j++] = input[i++];
	}
	b[j] = '\0';
}

void addition(char a[], char b[], char op)
{
	int i,length = (strlen(a)>strlen(b)?strlen(a):strlen(b)+1);
	char *c = new char[strlen(b) + 1];
	c[0] = op;
	for(i=1;i<=strlen(b);i++)
	{
		c[i] = b[i-1];
	}
	c[i]='\0';
	cout << setw(length) << a << endl;
	cout << setw(length) << c << endl;
	for(i=0;i<length;i++)
	{
		cout << "-";
	}
	cout << endl;
	stack<int> first,second,result;
	int carry=0;
	for(i=0;i<strlen(a);i++)
	{
		first.push(a[i] - '0');
	}
	for(i=0;i<strlen(b);i++)
	{
		second.push(b[i] - '0');
	}
	int size = (first.size()<second.size()?first.size():second.size());
	while(!first.empty() && !second.empty())
	{
		int element = first.top() + second.top();
		if(carry)
		{
			element++;
			carry = 0;
		}
		if(element>=10)
		{
			element %= 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		result.push(element);
		first.pop();
		second.pop();
	}
	while(!first.empty())
	{
		if(carry)
		{
			result.push(first.top() + 1);
			carry=0;
		}
		else
		{
			result.push(first.top());
		}
		first.pop();
	}
	while(!second.empty())
	{
		if(carry)
		{
			result.push(second.top() + 1);
			carry=0;
		}
		else
		{
			result.push(second.top());
		}
		second.pop();
	}
	char *answer = new char[length];
	i=0;
	while(!result.empty())
	{
		answer[i] = result.top() + '0';
		result.pop();
		i++;
	}
	answer[i]='\0';
	cout << setw(length) << answer;
}

void multiplication(char a[], char b[], char op)
{
	cout << a << endl << op << b;
}

void subtraction(char a[], char b[], char op)
{
	cout << a << endl << op << b;
}

int main()
{
	string input;
	char op,a[500],b[500];
	cin >> input;
	seperateString(input,a,b,op);
	switch(op)
	{
		case '+':
			addition(a,b,op);
			break;
		case '-':
			multiplication(a,b,op);
			break;
		case '*':
			subtraction(a,b,op);
			break;
	}
}