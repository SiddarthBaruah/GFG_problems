#include <bits\stdc++.h>

using namespace std;

// bool isPrime(int a){if(a==1) return false;if(a==2 || a==3) return true;if(a%2==0 || a%3==0) return false;for(int i=5;i*i<=a; i=i+6){if(a%i==0 || a%(i+2)==0) return false;}return true;}
/*
Seive of Eratosthenes
Here we remove all the numbers which as a divisor other than itself. We make an bool array like of n+1 lenght
and inside every box we put True.

|T|T|T|T|T|T|T|T|T|T|T|T|T|T|T|T|T|
 0 1 2 3 4 5 6 7 8 9 .....       n

then we start a for loop in the following way,

it will first remove all the multiplication numbers of 2 i,e 4th, 6th... 2nth places will become false
then it will make all the multiplication of the number of 3 as false and so on it will continue to proceed for prime numbers
. i,e it will do it for 5,7,11 and so on;

now the array that will be left will be collection of prime numbers
*/

void seive(int n)
{
    vector<bool> isPrime(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            if (isPrime[i])
            {
                cout << i << " ";
                for (int j = i * i; j <= n; j = j + i)
                {
                    isPrime[j] = false;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    seive(n);
    return 0;
}