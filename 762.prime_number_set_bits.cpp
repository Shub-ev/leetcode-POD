/*
Given two integers left and right, return the count of numbers in the inclusive range
[left, right] having a prime number of set bits in their binary representation.
Recall that the number of set bits an integer has is the number of 1's present when written in binary.
For example, 21 written in binary is 10101, which has 3 set bits. 

Example 1:
Input: left = 6, right = 10
Output: 4
Explanation:
6  -> 110 (2 set bits, 2 is prime)
7  -> 111 (3 set bits, 3 is prime)
8  -> 1000 (1 set bit, 1 is not prime)
9  -> 1001 (2 set bits, 2 is prime)
10 -> 1010 (2 set bits, 2 is prime)
4 numbers have a prime number of set bits.
*/

#include <iostream>
#include <math.h>

// Check the number if prime
bool isPrime(int num) {
    if(num < 2) return false;

    int n = sqrt(num);
    for(int i = 2; i <= n; i++) {
        if(n%i == 0) {
            return false;
        }
    }
    return true;
}

int countPrimeSetBits(int left, int right) {
    int res = 0;
    for (left; left <= right; left++) {
        if(isPrime(__builtin_popcount(left))) res++;
    }

    return res;
}

int main()
{
    int left = 10, right = 15;
    std::cout << countPrimeSetBits(left, right);
    return 0;
}
