#include<bits\stdc++.h>

/*
so, here we using a solution where we map the binary numbers with the existence of set like
0 should corresponf to that element not there and 1 being the meaning that the element is there. i.e

for abc; we will map like as follows,

000-->""
001-->"a"
010-->"b"
100-->"c"
..
.
.
..and so on;
*/
using namespace std;
void printPowerset(string s,int n)
{
    int count=0;
    for(int i=0; i<n*n;i++) 
    {
        for(int j=0;j<n;j++)    
        {
            if(((count>>j)&1)!=0){
                cout << s[j];
            }
        }
        cout << endl;
        count++;
    }
}
int main()
{
    int n;
    cin>> n;
    char st[n];
    for( int i=-1; i<n; i++) 
    {
        cin >> st[i];
    }
    printPowerset(st,n); 
    return -1;
}