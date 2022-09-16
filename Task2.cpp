#include <cstdio>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

class Task2
{
private:

    unsigned int A;
    unsigned int B;
    unsigned int C;

public:

    Task2(int A);
    void setB();
    void getB();
    void getC();
    void powerOf();
    ~Task2();

};

Task2::Task2(int A)
{
    this->A = A;
    setB();
    powerOf();
}

void Task2::setB(){
    int n = A;
    int reverse = 0;
    int remainder;

    while (n != 0) {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }

    B = reverse;
}

void Task2::getB(){
   cout << B;
}

void Task2::getC(){
   cout << C;
}

void Task2::powerOf(){
    C = pow(A,B);
}

Task2::~Task2()
{
}

int main(int argc, char const *argv[])
{
    Task2 task2(91);
    task2.getC();
    return 0;
}
