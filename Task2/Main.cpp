/* Function to test Task2 class and methods
* Author: Rushith Karunaratne
* compiled on Mac with: g++ -Wall -std=c++11 Main.cpp -o Main.a
*/

#include "Task2.cpp"
#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
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
