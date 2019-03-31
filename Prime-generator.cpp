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