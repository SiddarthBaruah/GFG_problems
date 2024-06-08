#include<bits/stdc++.h>

using namespace std;

bool isPow2(int n)
{
    return n&&(n&(n-1))==0;    
}

int main(){
    int n;
    cin >> n;
    if(isPow2(n)) cout<< "TRUE";
    else cout<< "FALSE";
    return 0;
}