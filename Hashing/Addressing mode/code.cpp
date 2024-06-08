#include<bits/stdc++.h>
using namespace std;

struct MyHash //open Adressing
{
    int Bucket;
    int *arr;
    int elements=0;
    MyHash(int size)
    {
        Bucket=size;
        for(int i=0; i<size; i++)
        {
            arr[i]=-1;
        }
    }

    bool insert(int key){
        if(elements==Bucket) return false;
        elements++;
        int h_key=0;
        for(int j=0;j<Bucket;j++)
        {
            h_key= (key%Bucket + j );
            if(arr[h_key]!=-1 || arr[h_key]!=-2)
            {
                arr[h_key]= key;
                return true;
            }
        }
        return false;
    }
    bool search(int key){
        for(int i=0;i<Bucket;i++)
        {
            if(arr[key%Bucket+i]==key) return true;
            else if ( arr[key%Bucket+i]==-1 )
            {
                return false;
            }
            
        }
        return false;
    }
    bool remove(int key){
        if(elements==0) return false;
        elements--;
        for(int i=0; i<Bucket; i++)
        {
            if(arr[key%Bucket+i]==key)
            {
                arr[key%Bucket+i]=-2;
                return true;
            }
            else if (arr[key%Bucket+i]==-1){
                return false;
            }
        }
        return false;
    }
    void print_(){
        for(int i=0; i<Bucket;i++)
        {
            cout<< arr[i]<< endl;
        }
    }
};


int main()
{
    MyHash open_address(7);
    open_address.insert(7);
    open_address.insert(3);
    open_address.insert(10);
    open_address.print_();
}