#include<bits/stdc++.h>
using namespace std;

/*
Brian Kerningum's Algorithm

code:
=========
while(n>0)
{
    n=n&(n-1);
    res++;
}
==========
so here the algo happens like this

n=40:   101000
n-1=39: 100111
________________
n&(n-1):100000

thus we can see that we have to travese through only once, per bit intead of checking every bit
Time complexity= theta(number of kth bit)
code:
int count_set_bit(int x)
{
    int num;
    num=0;
    while(x>=1)
    {
        num= num+ (x&1);
        x=x>>1;
    }
    return num;
}
=============================================================
Look up table solution:
-------------------------
based on preprocessing
Assumption: If we have only 32 bit.
good when we need to repeat this count a lot of time

so here firstly we make a precomputed table of numbers with number of set bit from 0-255. i.e

for(int i=0;i<256;i++)
{
    tbl[i]= tbl[i&(i-1)]+ 1
}

*/

///////////////////////////////
/*Preprocession  */
int TBL[256];

////////////////////////////////


int count_set_bit(int x)
{
    int num;
    num= TBL[(x&(0xff))]+TBL[((x>>8)&(0xff))]+TBL[((x>>16)&(0xff))]+TBL[((x>>24)&(0xff))];
    return num;
}
int preprocessing(){
    for(int i=1;i<256;i++)
    {
        TBL[i]= TBL[i&(i-1)]+ 1;
    }
    return 0;
}
int main()
{
    int x;
    TBL[0]=0;
    cin >> x;
    preprocessing();
    cout << count_set_bit(x)<<endl;
    return 0;    
}