#include<bits/stdc++.h>
using namespace std;

int comp(pair <int,int> a, pair <int,int> b){
    return a.second>b.second;
    
}

int max_profit(pair <int,int> job[], int n){
    sort(job, job+n, comp);
    int sum=0;
    int max=0;
    for(int i=0;i<n; i++){
        if(max< job[i].first){
            max=job[i].first;
        }
    }
    if(max<n){
        for(int i=0; i<max; i++){
            sum += job[i].second;
        }
    }
    else{
        for(int i=0; i<n; i++){
            sum += job[i].second;
        }
    }
    return sum;
}

int main(){
    pair <int,int> job[]= {make_pair(2,100),make_pair(1,50),make_pair(2,10),make_pair(1,20),make_pair(3,30)};
    int n= 5;
    cout<< max_profit(job,n);
    return 0;
}