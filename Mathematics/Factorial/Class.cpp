#include<bits/stdc++.h>

using namespace std;

int factorial(int n)
{
    int res=1;
    for( int i=2; i <=n ; i++)
    {
            res= res*i;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    cout << factorial(n);
    return 0;
}   