#include<bits/stdc++.h>
using namespace std;
int getLargest(int arr[],int n)
{
    int temp=0;
    for(int i=0;i<n; i++)
    {
        if (arr[i]>arr[temp])
        {
            temp=i;
        }
        
    }
    return temp;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    cout<< getLargest(arr, n)<<endl;
    return 0;
}