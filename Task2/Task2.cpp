/*
* Author: Rushith Karunaratne
* Task2 class
* 
*/

#include <iostream>
using namespace std;

#define MAX_LEN 1000000

/*Class to find C=A^B where B is the reverse of the digits of A.
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
    int reverseA();
    int getB();
    int getA();
    string AtoThePowerB();
    int multiply(int result[], int result_size);
    string display();
 

};
//Constructor
Task2::Task2(int A)
{
    this->A = A;
    B = reverseA();  
}
//Setter for B based on the value of A
int Task2::reverseA(){
    int n = A;
    int reverse = 0;
    int remainder;

    //Iterating one digit at a time and store in reverse.
    while (n != 0) {
        remainder = n % 10;
        reverse = reverse * 10 + remainder;
        n /= 10;
    }
    //return reverse of A
    return reverse;
}

int Task2::getB(){
    return this->B;
}

int Task2::getA(){
    return this->A;
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
string Task2::AtoThePowerB(){
    if (A <= 0 || A >= 99999) {
        throw std::invalid_argument( "received invalid input" );
    }

    int result[MAX_LEN];
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

    //Get values in result array and create string.
    string C = "";
    cout << "Result: " << A << "^" << B << " is \n";
    for (int i = result_size - 1; i >= 0; i--)
    {   
        C.append(to_string(result[i]));
        cout << result[i];
    }
    cout << endl;
    return C;
}



