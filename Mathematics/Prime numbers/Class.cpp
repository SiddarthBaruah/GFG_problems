#include <bits/stdc++.h>

using namespace std;

/*Efficeient idea;
All the divisors of a number always come in pairs.
therefore:
30 has :=  (1,30), (2,15), (3,10)
thus
if
    x*y=n
    x*x<n
    x<root(n)
therefore we only need to check till root of n

now,

the number needed to check are,

2,3,4,5,6,..... root(n)

if we already check for a%2 and a%3 then only numbers left are

5<-->7<---->11<-->13<---->17<-->19

thus we will check for i=5 i=i+6 and a%i==0 || a%(i+2)==0
*/

/*
bool isPrime(int a)
{
    for(int i=2;i*i<= a;i++)
    {
        if(a%i==0){return false;}
    }
    return true;
}
*/

bool isPrime(int a)
{
    if (a == 1)
        return false;
    if (a == 2 || a == 3)
        return true;

    if (a % 2 == 0 || a % 3 == 0)
        return false;

    for (int i = 5; i * i <= a; i = i + 6)
    {
        if (a % i == 0 || a % (i + 2) == 0)
            return false;
    }
    return true;
}

int main()
{
    int a;
    cin >> a;
    if (isPrime(a))
        cout << "True";
    else
        cout << "False";
    return 0;
}