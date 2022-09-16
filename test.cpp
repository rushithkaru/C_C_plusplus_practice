#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

#define MAX 100000

int multiply(int x, int res[], int res_size) {
    // Initialize carry
    int carry = 0;

    // One by one multiply n with
    // individual digits of res[]
    for (int i = 0; i < res_size; i++) {
        int prod = res[i] * x + carry;

        // Store last digit of
        // 'prod' in res[]
        res[i] = prod % 10;

        // Put rest in carry
        carry = prod / 10;
    }

    // Put carry in res and
    // increase result size
    while (carry) {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

/** This function finds power of a number x and print \f$x^n\f$
 * @param x base
 * @param n exponent
 */
void power(int x, int n) {
    // printing value "1" for power = 0
    if (n == 0) {
        std::cout << "1";
        return;
    }

    int res[MAX];
    int res_size = 0;
    int temp = x;

    // Initialize result
    while (temp != 0) {
        res[res_size++] = temp % 10;
        temp = temp / 10;
    }

    // Multiply x n times
    // (x^n = x*x*x....n times)
    for (int i = 2; i <= n; i++) res_size = multiply(x, res, res_size);

    std::cout << x << "^" << n << " = ";
    for (int i = res_size - 1; i >= 0; i--) std::cout << res[i];
}


int main(int argc, char const *argv[])
{
    int exponent, base;
    std::cout << "Enter base ";
    std::cin >> base;
    std::cout << "Enter exponent ";
    std::cin >> exponent;
    power(base, exponent);
    return 0;
}
