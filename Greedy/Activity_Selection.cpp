#include<bits/stdc++.h>

using namespace std;

bool comp(pair <int,int> a,pair <int,int> b){
    return (a.second)<(b.second);
}

int maxAcc(pair <int,int> arr[], int n){
    sort(arr, arr+n, comp);
    int count=0;
    for(int i=1; i<n; i++){
        if(arr[i].first>= arr[i-1].second){
            count++;
        }
    }
    return count;
}

int main(){
    pair <int,int> arr[] = {make_pair(1,2),make_pair(4,5), make_pair(2,3) };
    int n = 3;
    cout<< maxAcc(arr,n);
    return 0;
    
}