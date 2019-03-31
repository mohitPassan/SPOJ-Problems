/*
Given two binary strings, A (of length 10) and B (of length 5), output 1 if B is a substring of A and 0 otherwise.

Please note, that the solution may only be submitted in the following languages: Brainf**k, Whitespace and Intercal.

Input
24 lines consisting of pairs of binary strings A and B separated by a single space.

Output
The logical value of: 'B is a substring of A'.

Example
First two lines of input:

1010110010 10110
1110111011 10011
First two lines of output:
1
0
*/

//The following code is in C++ instead of Brainf**k.
#include <iostream>
using namespace std;
int main()
{
	int t=1;					//No of test cases.
	while(t--)
	{
		string a,b;
		cin >> a >> b;			//Taking two strings from stdin
		int i=0,j,k=0;			//i,j and k are integers used for traversing the strings. i & k for a and j for b.
		for(j=0;j<5;)
		{
			if(a[k] == b[j])	//If the current characters are equal then go one step forward in both strings.
			{
				j++;			
				k++;
			}
			else				//Otherwise go at initial positin in string b and in string a go back to the (character from this particular comparison started, which is stored in i) + 1.
			{
				j=0;
				k=++i;
			}
			if(k>10)			//If at any time k becomes greater than 10, it means b is not a substring of a.
				break;
		}
		if(j==5)				//We went all the way through b, i.e it is a substring.
			cout << "1";
		else
			cout << "0";
	}
}