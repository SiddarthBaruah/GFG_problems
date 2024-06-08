#include<bits\stdc++.h>

using namespace std;

/*
Here the question is only one of the number in a vector is repeating odd times
and all the other are repeating for even number of times

now we have to find which number is such a number;

so basically, we are doing XOR operations here which works like,

x^x=0
x^0=x
x^y=y^x
x^(y^z)=(x^y)^z

now, 4^4=0 and 4^4^4=4

therefore, for the given array like {1,2,2,3,2,3,4,4,2}
we will XOR all of them to get;
1^2^2^3^2^3^4^4^2= 1^(2^2^2^2)^(3^3)^(4^4)= 1^0^0^0= 1

*/

int main()
{
    int n,res;
    res=0;
    cin >> n;
    vector<int> in(n);
    for(int i=0;i<n;i++)
    {
        cin>> in[i];
    }

    for(int i=0; i<n; i++)
    {
        res=res^in[i];
    }
    cout<< res<<endl ;
    return 0;
}