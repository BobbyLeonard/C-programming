#include <stdio.h>

/*
https://en.wikipedia.org/wiki/Collatz_conjecture

The Collatz conjecture in mathematics asks whether repeating two simple arithmetic operations will eventually transform every positive integer into one. 
It concerns sequences of integers in which each term is obtained from the previous term as follows: 

if the previous term is even, the next term is one half of the previous term. 
If the previous term is odd, the next term is 3 times the previous term plus 1. 
The conjecture is that these sequences always reach 1, no matter which positive integer is chosen to start the sequence.
*/

int collatz(int n);
int steps;

int main(void)
{
    // set this as input
    int n = 27;

    // print final result
    printf("Steps taken to get from n=%i to 1: \n%i steps\n", n, collatz(n));
        
}

int collatz(int n)
{
    // recursion base case
    if (n == 1)
        return steps;

    // if even number
    else if (n % 2 == 0)
    {
        steps += 1;
        return collatz(n / 2);
    }
    // if odd number
    else
    {
        steps += 1;
        return collatz(3 * n + 1);
    }
}
