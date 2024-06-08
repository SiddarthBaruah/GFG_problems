#include<bits/stdc++.h>

int gcd(int m,int n){if(n==0){return m;}else{return gcd(n, m%n);}}

using namespace std;

int lcm(int a, int b)
{
    return (a*b/gcd(a,b));
}


int main()
{
    int a, b;
    cin >>a >>b;
    cout << lcm(a,b);
    return 0;
}