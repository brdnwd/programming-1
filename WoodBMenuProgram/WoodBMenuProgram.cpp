// WoodBErrorChecking.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Braden Wood
// 9/21/26
// Menu Program V1: create a menu and error check
// Program note: I'm allowed to use switch cases instead of if statments for choices.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
    int wizardChoice;
    string wizardName, patronusName;
    char patronusChoice;

    cout << "Menu Program" << endl;
    cout << "Created by: Braden Wood" << endl;
    cout << "This example will ask the user to make 2 menu selections" << endl;
    cout << "by choosing a wizard and their patronus and then error check" << endl << endl;
    
    cout << "Wizard Choices: " << endl;
    cout << "1: Harry Potter" << endl;
    cout << "2: Hermione Granger" << endl;
    cout << "3: Ron Weasley" << endl;
    cout << "Enter the number for your wizard choice (1, 2, 3): ";
    cin >> wizardChoice;

    if (!cin) {
        cout << "Invalid data. Terminating...";
        return 1;
    }
    else {
        switch (wizardChoice) {
        case 1:
            wizardName = "Harry Potter";
            break;
        case 2:
            wizardName = "Hermione Granger";
            break;
        case 3:
            wizardName = "Ron Weasley";
            break;
        default:
            cout << "Not a correct option. Terminating...";
            return 1;
        }
    }
    
    cout << "Patronus Choices: " << endl;
    cout << "A: Stag" << endl;
    cout << "B: Otter" << endl;
    cout << "C: Dog" << endl;
    cout << "Enter the letter for your patronus choice (A, B, C): ";
    cin >> patronusChoice;

    if (!cin) {
        cout << "invalid data. Terminating...";
        return 1;
    }
    else {
        switch (patronusChoice) {
        case 'a':
        case 'A':
            patronusName = "Stag";
            break;
        case 'b':
        case 'B':
            patronusName = "Otter";
            break;
        case 'c':
        case 'C':
            patronusName = "Dog";
            break;
        default:
            cout << "Not a correct choice. Terminating...";
            return 1;
        }
    }

    cout << endl;
    cout << "Your wizard is " << wizardName << ", and your patronus is " << patronusName << "." << endl;

    return 0;
}
