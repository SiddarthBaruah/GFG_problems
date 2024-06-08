/*
in this we learn about the different bit wise operators which are
Operator    Meaning
=====================
    $       AND
    |       OR
    ^       XOR
    <<      LEFT SHIFT
    >>      RIGHT SHIFT
    ~       NOT
====================
NOT operator in signed integer
int main(){
    int x=1;
    cout << (x~)<<endl;
    x=5;
    cout << (x~)<<endl;
    return 0;
}
Here the Output will be:
-2
-6
Why!?
because after complementing each digit in say 5 i.e
000....00101
111....11010

we get 2's compliment: 111..... 11011
the above number can also be written as: 2^32- x-1
now the term -(x+1) is the output we will get.
But this varies from compiler to compiler.
*/