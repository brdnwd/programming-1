// WoodBBudget.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Braden Wood
// 8/31/26
// Budgets V2: ask user for payrate and hours worked, then calculate budget, and print all info to the console.

// libraries
#include <iostream>
#include <string>

using namespace std;

// declare constant variables
const double TAX_RATE = .10, MORTGAGE_RATE = .20, UTILITY_RATE = .20, FOOD_RATE = .25, SAVINGS_RATE = .15;

int main()
{
    // declare variables
    string fName, lName;
    double payRate, hoursWorked, gross, taxes, mortgage, utilities, food, net, savings, leftOver;

    // program title & description
    cout << "Budget Program" << endl;
    cout << "Created by: Braden Wood" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "This program will create a budget for the user based on " << endl;
    cout << "total hours worked and payrate then calculate a budget based on the following: " << endl;
    cout << "10% for taxes, " << endl;
    cout << "20% for mortgage, " << endl;
    cout << "20% for utilities, " << endl;
    cout << "25% for food, and " << endl;
    cout << "15% for savings. " << endl;
    cout << "Then print gross, net, leftover, and budget info to the screen." << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    // collect user input
    cout << "Enter your first name: ";
    cin >> fName;
    cout << "Enter your last name: ";
    cin >> lName;
    cout << "Enter your hourly wage (28.02): ";
    cin >> payRate;
    cout << "Enter your hours worked this month (18.29): ";
    cin >> hoursWorked;
    
    // calculations
    gross = payRate * hoursWorked;
    taxes = gross * TAX_RATE;
    net = gross - taxes;
    mortgage = net * MORTGAGE_RATE;
    utilities = net * UTILITY_RATE;
    food = net * FOOD_RATE;
    savings = net * SAVINGS_RATE;
    leftOver = net - (mortgage + utilities + food + savings);

    // output to console;
    cout << endl << endl;
    cout << "Your name is: " << fName << " " << lName << endl;
    cout << "Your hourly wage is: $" << payRate << endl;
    cout << "You've worked " << hoursWorked << " hours this month" << endl;
    cout << "Your gross earning this month are: $" << gross << endl;
    cout << "Your taxes on your gross earnings are: $" << taxes << endl;
    cout << "Your net earnings this month are: $" << net << endl;
    cout << "Your mortgage is: $" << mortgage << endl;
    cout << "Your utilities is: $" << utilities << endl;
    cout << "Your food is: $" << food << endl;
    cout << "Your savings is: $" << savings << endl;
    cout << "You have $" << leftOver << " left over this month" << endl;

    // end process
    return 0;
}