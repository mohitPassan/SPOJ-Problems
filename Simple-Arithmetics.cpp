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
	char **ans = new char*[strlen(b)-1];
	int i,j,carry;
	for(i=0;i<strlen(b);i++)
	{
		ans[i] = new char[strlen(a)+2];
	}
	for(i=0;i<strlen(b);i++)
	{
		ans[i][strlen(a)+1] = '\0';
	}
	for(i=strlen(b)-1;i>=0;i--)
	{
		carry=0;
		if(b[i] == '0')
		{
			ans[i][0] = '0';
			ans[i][1] = '\0';
		}
		else
		{
			for(j=strlen(a)-1;j>=0;j--)
			{
				int temp;
				temp = (a[j] - '0') * (b[i] - '0');
				if(carry != 0)
				{
					temp += carry;
					carry = 0;
				}
				if(temp >= 10)
				{
					carry = temp / 10;
					temp = temp % 10;
				}
				else
				{
					carry = 0;
				}
				ans[i][j+1] = temp + '0';
			}
			if(carry!=0)
				ans[i][j+1] = carry + '0';
			else
			{
				ans[i][j+1] = ' ';
			}
		}
		//cout << ans[i] << endl;
	}
	for(i=strlen(b)-1,j=strlen(a);i>=0,j>=0;)		
	{
		cout << i << " " << j << endl;
		int temp = j;
		if(j+1 > strlen(a))
		{
			i = strlen(a);
			j = --temp;
		}
		else
		{
			i--;
			j++;
		}
	}
	// char *result = new char[strlen(a)+3];
	// result[strlen(a)+2] = '\0';
	// carry = 0;
	// for(i=strlen(a);i>=0;i--)
	// {
	// 	int temp = 0;
	// 	for(j=strlen(b)-1;j>=0;j--)
	// 	{
	// 		if(ans[j][i] == ' ')
	// 		{
	// 			temp += 0;
	// 		}
	// 		else
	// 		{
	// 			temp += ans[j][i] - '0';
	// 		}
	// 	}
	// 	if(carry)
	// 	{
	// 		temp++;
	// 		carry=0;
	// 	}
	// 	if(temp >= 10)
	// 	{
	// 		carry = temp / 10;
	// 		temp %= 10;
	// 	}
	// 	else
	// 	{
	// 		carry = 0;
	// 	}
	// 	result[i+1] = temp + '0';
	// }
	// result[i+1] = carry + '0';
	// for(i=0;i<2;i++)
	// {
	// 	if(result[i] == '0')
	// 	{
	// 		for(j=0;result[j]!='\0';j++)
	// 		{
	// 			result[j] = result[j+1];
	// 		}
	// 		i=-1;
	// 	}
	// 	else
	// 	{
	// 		break;
	// 	}
	// }
	// cout << result;
}

void subtraction(char a[], char b[], char op)
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
	int borrow=0;
	for(i=0;i<strlen(a);i++)
	{
		first.push(a[i] - '0');
	}
	for(i=0;i<strlen(b);i++)
	{
		second.push(b[i] - '0');
	}
	while(!first.empty() && !second.empty())
	{
		int element = first.top() - second.top();
		if(borrow)
		{
			element--;
			borrow = 0;
		}
		if(element<0)
		{
			element += 10;
			borrow = 1;
		}
		else
		{
			borrow = 0;
		}
		result.push(element);
		first.pop();
		second.pop();
	}
	while(!first.empty())
	{
		if(borrow)
		{
			result.push(first.top() - 1);
			borrow=0;
		}
		else
		{
			result.push(first.top());
		}
		first.pop();
	}
	while(!second.empty())
	{
		if(borrow)
		{
			result.push(second.top() + 1);
			borrow=0;
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
			subtraction(a,b,op);
			break;
		case '*':
			multiplication(a,b,op);
			break;
	}
}