#include<bits\stdc++.h>

using namespace std;
 
int powiter(int x, int y)
{
    int res=1;
    while(y>0)
    {
        if(y&1)
        {
            res= res*x;
        }
        x=x*x;
        y=y>>1;
    }
    return res;
}

int main()
{
    int x,y;
    cin >>x >>y;
    cout << powiter(x,y);
    return 0;
}