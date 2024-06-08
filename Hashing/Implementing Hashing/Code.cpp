#include<bits/stdc++.h>
using namespace std;

struct MyHash
{
    int BUCKET;
    list <int> *table;
    MyHash(int b)
    {
        BUCKET=b;
        table= new list<int> [b];
    }
    void insert(int key){
        int i= key%BUCKET;
        table[i].push_back(key);
    }
    bool search(int key){
        int i =key%BUCKET;
        for( auto x: table[i])
        {
            if(x==key) return true;
        }
        return false;
    }
    void remove(int key){
        int i = key%BUCKET;
        table[i].remove(key);
    }
};


int main()
{
    MyHash first(7);
    first.insert(73);
    first.insert(34);
    if(first.search(73)) cout << "Found"<< endl;
    if(first.search(35)) cout << "Found" << endl;
    return 0;
}