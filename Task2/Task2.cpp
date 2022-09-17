#include <iostream>
using namespace std;

#define MAX 1000000

/*Class to C=A^B where B is the reverse of the digits of A.
* Since input range is 0-99999 the code needs to manage integer 
* overflow.
*/

class Task2
{
private:
    unsigned int A;
    unsigned int B;

public:
    //Public method definitions
    Task2(int A);
    void setB();
    void AtoThePowerB();
    int multiply(int result[], int result_size);
 

};
//Constructor
Task2::Task2(int A)
{
    this->A = A;
    setB();  
}
//Setter for B based on the value of A
void Task2::setB(){
    int n = A;
    int reverse = 0;
    int remainder;

    //Iterating one digit at a time and store in reverse.
    while (n != 0) {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }
    //set value of B
    B = reverse;
}

/* Custom multiplication method to deal with very large numbers.*/
int Task2::multiply(int result[], int result_size){
    int carrier = 0;
    
    //multiply the values in result with the base
    for (int i = 0; i < result_size ; i++){
        int product = result[i]*A + carrier;
        result[i] = product%10;
        //get the carry over value
        carrier = product/10;
    }
    //loop till carrier is included in result array
    while (carrier) {
        result[result_size] = carrier % 10;
        carrier = carrier / 10;
        result_size++;
    }

    return result_size;
}

//Function to perform A^B where B is the reverse of A
void Task2::AtoThePowerB(){
    int result[MAX];
    int result_size = 0;
    int temp_val = A;

    //initialise result array with 
    while (temp_val != 0){
        result[result_size++] = temp_val%10;
        temp_val = temp_val / 10;
    }

    //call custom multiply array and get size of array while setting
    for (int i = 2; i <= B; i++){
        result_size = multiply(result,result_size);
    }

    //print values in result array.
    cout << "Result: " << A << "^" << B << " is \n";
    for (int i = result_size - 1; i >= 0; i--)
    {
        cout << result[i];
    }
}


int main(int argc, char const *argv[])
{
    //Get user input and find C=A^B
    int A;
    cout << "Enter a number (0-99999): ";
    cin >> A;
    //Check input range
    if (A <= 0 || A >= 99999) {
        cout << "Invlalid input\n";
        return 0;
    }
    Task2 task2(A);
    task2.AtoThePowerB();
    return 0;
}
