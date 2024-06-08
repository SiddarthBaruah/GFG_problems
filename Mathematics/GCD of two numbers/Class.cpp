#include<bits/stdc++.h>

using namespace std;


/*Eucledean algorithm

so the algorithm is;

gcd(a,b)= gcd(a-b,b) where a>b

proof:
    let's say:
        a= gx
        b= gy
    such that gcd(x,y)=1 and g is the gcd of a and b
    a-b= g(x-y)
    so gcd(a-b,b) also gives g as gcd of a and b
        now why (x-y) is not in gcd because if it is then it should have been in the previos a, b as well
    Hence proved!

so the naive implementation goes as

---------code----------
int gcd(int a, int b)
{
    while(a!=b)
    {
        if(a>b)
        {
            a=a-b;
        }
        else
        {
            b=b-a;
        }
    }
    return a;
}
----------------------------
advance Eucledean implimentation is given below;
which uses more auxially space but is much faster
*/
int gcd(int m,int n)
{
    if(n==0)
    {
        return m;
    }
    else
    {
        return gcd(n, m%n);
    }
}


int main()
{
    int m,n;
    cin >> m >>n;
    cout <<gcd(m,n);
    return 0;
}   