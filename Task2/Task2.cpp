#include <iostream>
using namespace std;

#define MAX 1000000

class Task2
{
private:

    unsigned  int A;
    unsigned  int B;

public:

    Task2(int A);
    void setB();
    void AtoThePowerB();
    int multiply(int result[], int result_size);
    ~Task2();

};

Task2::Task2(int A)
{
    this->A = A;
    setB();
    
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

int Task2::multiply(int result[], int result_size){
    int carrier = 0;
    
    for (int i = 0; i < result_size ; i++){
        int product = result[i]*A + carrier;
        result[i] = product%10;
        carrier = product/10;
    }

    while (carrier) {
        result[result_size] = carrier % 10;
        carrier = carrier / 10;
        result_size++;
    }

    return result_size;
}

void Task2::AtoThePowerB(){
    int result[MAX];
    int result_size = 0;
    int temp_val = A;

    while (temp_val != 0){
        result[result_size++] = temp_val%10;
        temp_val = temp_val / 10;
    }

    for (int i = 2; i <= B; i++){
        result_size = multiply(result,result_size);
    }
    cout << "Result: " << A << "^" << B << " is \n";
    for (int i = result_size - 1; i >= 0; i--)
    {
        cout << result[i];
    }
}

Task2::~Task2()
{
}

int main(int argc, char const *argv[])
{
    int A;
    cout << "Enter a number (0-99999): ";
    cin >> A;
    Task2 task2(A);
    task2.AtoThePowerB();
    return 0;
}
