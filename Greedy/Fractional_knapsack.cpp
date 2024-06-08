#include<bits/stdc++.h>

using namespace std;

bool comp(pair <int,int> a, pair <int,int> b){
    return (float)(a.second)/(a.first) > (float)(b.second)/(b.first);
}

double max_value(pair <int,int> arr[], int n, int max_wt){
    sort(arr, arr+n, comp); //should arrange decendingly
    
    
    float sum=0;
    float frac;
    for(int i=0;i<n;i++){
        
        if(arr[i].first < max_wt){           //check if amount is less than space left
            max_wt= max_wt- arr[i].first;   //remove the space from there
            sum= sum+ arr[i].second;        //add the total weight
        }
        else if(arr[i].first== max_wt){
            sum+=arr[i].second;
            max_wt=0;
            break;
        }
        else{                                   //if amount is more than space left
            frac=(float) ( max_wt)/(arr[i].first);     
            sum+=frac* arr[i].second;      //amount of things going inside
            max_wt=0;
            break;
        }
    }


    return sum;
}

int main(){
    pair <int,int> items[]= {make_pair(50,600), make_pair(20,500), make_pair(30,400)};
    int max_wt= 70;
    int n=3;
    cout << max_value(items, n, max_wt);
    return 0;
}