#include<bits/stdc++.h>

using namespace std;

#define for(a,b,c) for(int i= a;i b;i=i c)

int counttrailing(int n)
{
    int rem=0;
    for(5,<=n,*5)
    {
        rem= rem+ n/i;
    }
    return rem;
}

int main()
{
    int n;
    cin >> n;
    cout <<counttrailing(n);
    return 0;
}   