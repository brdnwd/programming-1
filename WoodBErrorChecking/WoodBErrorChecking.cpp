// WoodBErrorChecking.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Braden Wood
// 9/21/26
// Error Checking V1: error check for input file and user input

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    int num1;

    ifstream fin;

    fin.open("test.txt");

    cout << "Error checking program" << endl;
    cout << "Created by: Braden Wood" << endl << endl;
    cout << "This program is an example of how to use if/else statements to check if" << endl;
    cout << "an input file is found and to error check user input." << endl;

    // if file is not found, report to user
    //if (!fin) {
    //    cout << endl << "Could not find \"test.txt\"! Please create \"test.txt\" or ensure the path is correct.";
    //    return 1;
    //}

    // check user input for num1 for invalid data
    //cout << "Enter an integer between 1 and 5: ";
    //cin >> num1;
    //if (!cin) {
    //    cout << "Invalid data was provided to \"num1\" please read instructions carefully.";
    //    return 1;
    //}
    //else if (num1 > 5 || num1 < 1) {
    //    cout << "You failed to choose a number between 1 and 5.";
    //    return 1;
    //}
    //else {
    //    cout << "Yay you chose a number between 1 and 5!";
    //}



    fin.close();

    return 0;
}
