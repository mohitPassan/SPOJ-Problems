#include <iostream>
 
using namespace std;
 
bool isPalindrome(string n)
{
    long int size = n.size(),i;
    //cout << size;
    for(i=0;i<size/2;i++)
    {
        if(n[i] != n[size-1-i])
            return 0;
    }
    return 1;
}
 
void update(string &n)
{
    long int i,size = n.size(),count=0;
    for(i=size-1;i>=0;i--)
    {
        if(n[i] != '9')
        {
            n[i]++;
            break;
        }
        else
        {
            count++;
            n[i] = '0';
        }
    }
    //cout << size;
    if(count == size)
    {
        n.resize(size+1,'0');
        n[0] = '1';
    }
    //cout << size;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string n;
        cin >> n;
        update(n);
        while(1)
        {
            if(isPalindrome(n))
            {
                cout << n << endl;
                break;
            }
            else
            {
                update(n);
            }
        }
    }
    return 0;
}