#include<bits\stdc++.h>

using namespace std;

int pow(int x, int y)
{
    if(y==0) return 1;
    int temp;

    temp= pow(x, y/2);
    temp= temp*temp;
    
    if(y%2==0) return temp;
    else return temp*x;
}

int main()
{
    int x,y;
    cin >> x>>y;
    cout << pow(x,y);
    return 0;
}