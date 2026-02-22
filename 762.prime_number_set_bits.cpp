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

/*
 * Better solution.
 * As we know the max size of number is max of INT.
 * i.e. 32 bits. So prime number should be less than 32
 * i.e. valid prime numbers are only
 * 2,3,5,7,11,13,17,19,23,27,31
 */
/*
int countPrimeSetBits(int left, int right) {
        int res = 0;
        for(left; left <= right; left++) {
            int num = __builtin_popcount(left);
            if((num == 2) || (num == 3) || (num==5) || (num == 7) || (num == 11) || (num == 13)
            || (num == 17) || (num == 19) || (num == 23) ||(num==29) || (num == 31)) res++;
        }
        return res;
}
*/
