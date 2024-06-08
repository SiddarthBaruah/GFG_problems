#include<bits/stdc++.h>

using namespace std;

int main()
{
    int x,y;
    cin >> x >>y;
    x= x>>(y-1);
    if((x&1)==0) cout << "NO"<< endl;
    else cout << "YES"<< endl;
    return 0;
}   