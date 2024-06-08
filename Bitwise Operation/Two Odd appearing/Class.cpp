#include<Bits\stdc++.h>

using namespace std;

/*
So basically the algorithm is really nice and efficent, we can do it by Hashing(not learn in this date), but the given
algo is much faster

for example case say we take
{6,3,5,4,3,2,2}

so firtly we will XOR all the terms and we will get
x= 6^5 (110 & 101)
we can see that
x=3 = 010

*/
void oddAppearing(int arr[],int n)
{
    int k=0;
    int res=0, res1=0;
    for(int i=0; i<n; i++)
    {
        k=k^arr[i];
    }
    k=k&(~(k-1));
    for(int i=0;i<n;i++)
    {
        if((arr[i]&k)!=0) 
            res=res^arr[i];
        else 
            res1=res1^arr[i];
    }
    cout << res <<" "<< res1<< endl;
}

int main()
{
    int n, count;
    cin >> n;
    int in[n];
    for(int i=0; i<n; i++)
    {
        cin >> in[i];
    }
    oddAppearing(in ,n);
    return 0;

}