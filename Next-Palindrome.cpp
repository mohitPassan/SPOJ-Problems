#include <iostream>
 
using namespace std;
 
string mirror(string n, int mid,bool odev)
{
    int i = odev?mid:mid-1;         //i starts from a different value which depends upon length of n
    for(;i>=0;i--)
    {
        if(n[i] == n[n.size()-i-1])         //If two characters are same, continue
            continue;
        else
        {
            n[n.size()-i-1] = n[i];         //Otherwise, pass the left half's value to right
        }
    }
    return n;           //Return the mirrored string
}

bool areAll9(string n)          //Just checks if all the characters are '9' or not.
{
    for(int i=0;i<n.size();i++)
    {
        if(n[i]!='9')
            return 0;
    }
    return 1;
}

int main()
{
    int t;          //Number of test cases
    cin >> t;
    string temp;            //A temp string which stores the answer
    while(t--)
    {
        string n;           //String in which input will be taken
        cin >> n;
        bool flag=0;            //A flag variable to check if the middle element is 9, so different type of changes are done and mirror is called again
        if(areAll9(n))          //To check if all the characters are 9, for eg. 9999. The answer for this will be 10001
        {
            cout << 1;
            for(int i=0;i<n.size()-1;i++)
                cout << 0;
            cout << 1 << endl;
        }
        else if((n.size()%2) != 0)          //For odd length
        {
            int mid = n.size()/2;           
            temp = mirror(n,mid,0);         //To mirror the string. n is the string, mid is the middle value, and 0 to tell that length is odd
            if(temp<=n)         //If temp comes out to be smaller than n
            {
                temp[mid]++;            //Increment the middle value
                while(temp[mid] > '9')          //If the previous value was 9, incementing will set it to ':', which is wrong
                {
                    flag=1;         //To tell that mirror should be called again
                    temp[mid] = '0';     //Basically adding 1 to mid and adding the carry to previous character.
                    temp[mid-1]++;          
                    mid--;          //Now mid will point to previous position, and the process wil go on, until all 9s are added with 1
                }
                if(flag)
                {
                    int mid = n.size()/2;           //mid is calculated again because in the previous loop it was changed
                    temp = mirror(temp,mid,0);          //mirror called again
                }
            }
            cout << temp << endl;           //print final string
        }
        else            //for even length.
        {
            int mid = n.size()/2-1;             //There are two middle values, we choose the first one.
            temp = mirror(n,mid,1);
            if(temp<=n)
            {
                temp[mid]++;            //Incrementing both the middle values
                temp[mid+1]++;
                while(temp[mid] > '9')      //Same as in case for odd length
                {
                    flag=1;
                    temp[mid] = '0';
                    temp[mid-1]++;
                    mid--;
                }
                if(flag)
                {
                    int mid = n.size()/2;
                    temp = mirror(temp,mid,0);
                }
            }
            cout << temp << endl;
        }
    }
    return 0;
}