/*
Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

Input
The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output
For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

Example
Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
*/

#include <iostream>
#include <cmath>
using namespace std;
typedef long long int LI;

bool isPrime(LI n)
{
	if(n<2)							//0 and 1 are not prime numbers.
		return false;
	for(LI i=2;i<=sqrt(n);i++)		//Checking form 2 to square root of n because a larger factor of n must be a multiple of	
	{								//smaller factor that has been already checked.
		if(n%i == 0)				
		{
			return false;
		}
	}
	return true;
}
void printPrimes(LI start,LI end)
{
	for(LI i=start;i<=end;i++)
	{
		if(isPrime(i))				//Checking if prime by calling 'isPrime()'
		{
			cout << i << endl;		//Print if it is prime.
		}
	}	
}
int main()
{
	int t;
	cin >> t;						//No of test cases.
	while(t--)
	{
		LI a,b;						//To print from a to b.
		cin >> a >> b;
		printPrimes(a,b);			//Function for printing prime numbers from a to b.
		cout << endl;				//Empty line to ber printed after each test case.
	}
}