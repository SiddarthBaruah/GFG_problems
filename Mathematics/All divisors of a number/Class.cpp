#include<bits\stdc++.h>

using namespace std;

int divisors(int n)
{
    int i,m;
    for(i=1; i*i<= n;i++)
    {
        if(n%i==0)
        {
            cout << i <<" ";
        }
        m=i;
    }
    for( ; i>=1 ; i--)
    {
        if(n%i==0)
        {
            if(n!=i*i){
                cout << n/i<<" ";
            }
        }
    }
    return 0;
}

int main()
{
    int n;
    cin>> n;
    divisors(n);
    return 0;
}