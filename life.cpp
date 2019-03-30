#include <iostream>
using namespace std;
int main()
{
	int a=0;
	while(1)
	{
		cin >> a;
		if(a!=42)
			cout << a << endl;
		else
			break;
	}
	return 0;
}