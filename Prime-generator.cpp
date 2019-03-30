#include <iostream>
#include <cmath>
using namespace std;
typedef long long int LI;

void mark(LI arr[],LI size)
{
	LI i,j;
	for(i=2;i<=sqrt(size);i++)
	{
		//cout << "i=" << i << endl;
		for(j=i*i;j<size;j+=i)
		{
			//cout << "j=" << j << endl;
			arr[j] = 1;
		}
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		LI a,b,*seive;
		cin >> a >> b;
		seive = new LI[b+1] ();
		seive[0] = 1;
		seive[1] = 1;
		mark(seive,b+1);
		for(LI i=a;i<b;i++)
		{
			if(seive[i] == 0)
				cout << i << endl;	
		}
		cout << endl;
	}
}