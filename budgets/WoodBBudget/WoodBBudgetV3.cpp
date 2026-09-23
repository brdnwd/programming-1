// WoodBBudgetV2.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Braden Wood
// 8/31/26
// Budgets V1: ask user for payrate and hours worked, then calculate budget, and print all info to the console.
// Budgets V2: prompt the user for percentages, add columns, add two new categories.
// Budgets V3: add menu and error checks

// libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// declare constant variables
const double TAX_RATE = .10;
const int COLUMN_ONE = 27, DOLLAR_SIGN = 2, MONEY = 8, NAME = 40;
const bool isDebug = false;

int main()
{
    // declare variables
    string name, payPeriod;
    int outputChoice, multiplier;
    char periodChoice;
    double payRate, hoursWorked, gross, taxes, mortgage, utilities, food, net, savings, leftOver,
        mortgageRate, utilitiesRate, foodRate, savingsRate, games, gamesRate, books, booksRate;

    // debug
    if (isDebug == true) {
        name = "Braden Wood";
        payRate = 20, hoursWorked = 18.2, gross, taxes, mortgage, utilities, food, net, savings, leftOver,
            mortgageRate = .1, utilitiesRate = .1, foodRate = .1, savingsRate = .1, games, gamesRate = .1, books, booksRate = .1,
            outputChoice = 3, multiplier = 4, periodChoice = 'w';
    }

    ofstream fout;

    fout.open("budget.txt");

    if (isDebug == false) {
        // program title & description
        cout << "Budget Program" << endl;
        cout << "Created by: Braden Wood" << endl;
        cout << "---------------------------------------------------------------------------------------------------" << endl;
        cout << "This program will create a budget for the user based on " << endl;
        cout << "total hours worked, payrate and tax rate of 10%, then calculate a budget based on the percentages " << endl;
        cout << "provided by the user for: food, mortgage, untilities, savings, games, and books." << endl;
        cout << "Then print gross, net, leftover, and budget info to the screen." << endl;
        cout << "---------------------------------------------------------------------------------------------------" << endl << endl;

        //user menu
        cout << "Configuration Menu" << endl;
        cout << "---------------" << endl;
        cout << "Time Period Options" << endl;
        cout << "W) Weekly" << endl;
        cout << "B) Biweekly" << endl;
        cout << "M) Monthly" << endl;
        cout << "---------------" << endl;
        cout << "1) Print to console" << endl;
        cout << "2) Print to file" << endl;
        cout << "3) Print to both" << endl << endl;
        cout << "Please enter your time perioid choice (w,b,m): ";
        cin >> periodChoice;
          
        if (!cin) {
            cout << "Invalid value given. Terminating Program." << endl;
            return 1;
        }
        else {
            // For time period
            switch (periodChoice) {
            case 'W':
            case 'w':
            case 'B':
            case 'b':
            case 'M':
            case 'm':
                // valid options
                break;
            default:
                cout << "You chose an invalid option. Terminating Program." << endl;
                return 1;
            }
        }
        
        cout << "Please enter your preferred output choice (1,2,3): ";
        cin >> outputChoice;

        if (!cin) {
            cout << "Invalid value given. Terminating Program." << endl;
            return 1;
        }
        else {
            switch (outputChoice) {
            case 1:
            case 2:
            case 3:
                // valid options
                break;
            default:
                cout << "You chose an invalid option. Terminating Program." << endl;
                return 1;
            }
        }

        // collect user input
        cin.ignore();
        cout << "Enter your first and last name: ";
        getline(cin, name);
        cout << "Enter your hourly wage (28.02): ";
        cin >> payRate;
        cout << "Enter your hours worked this pay period (18.29): ";
        cin >> hoursWorked;
        cout << endl << endl;
        cout << "Please note that all percentages must sum to 100% or less" << endl;
        cout << "Enter the amount of money you want to allocate for food as a decimal: ";
        cin >> foodRate;
        cout << "Enter the amount of money you want to allocate for mortgage as a decimal: ";
        cin >> mortgageRate;
        cout << "Enter the amount of money you want to allocate for savings as a decimal: ";
        cin >> savingsRate;
        cout << "Enter the amount of money you want to allocate for utilities as a decimal: ";
        cin >> utilitiesRate;
        cout << "Enter the amount of money you want to allocate for games as a decimal: ";
        cin >> gamesRate;
        cout << "Enter the amount of money you want to allocate for books as a decimal: ";
        cin >> booksRate;
    }
    
    // calculations
    switch (periodChoice) {
    case 'W':
    case 'w':
        payPeriod = "Weekly";
        multiplier = 4;
        break;
    case 'B':
    case 'b':
        payPeriod = "Biweekly";
        multiplier = 2;
        break;
    case 'M':
    case 'm':
        payPeriod = "Monthly";
        multiplier = 1;
        break;
    }
    gross = (payRate * hoursWorked) * multiplier;
    taxes = gross * TAX_RATE;
    net = gross - taxes;
    mortgage = net * mortgageRate;
    utilities = net * utilitiesRate;
    food = net * foodRate;
    savings = net * savingsRate;
    games = net * gamesRate;
    books = net * booksRate;
    leftOver = net - (mortgage + utilities + food + savings + games + books);

    // clear console
    system("cls");

    // format money
    cout << fixed << setprecision(2) << showpoint;
    fout << fixed << setprecision(2) << showpoint;

    switch (outputChoice) {
    case 3:
    case 1: // Console
        cout << setw(COLUMN_ONE) << left << "Name: " << setw(NAME) << name << endl;
        cout << setw(COLUMN_ONE) << left << "Wages: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << gross << endl;
        cout << setw(COLUMN_ONE) << left << "Taxes: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << taxes << endl;
        cout << setw(COLUMN_ONE) << left << "Net: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << net << endl;
        cout << setw(COLUMN_ONE) << left << "Mortgage: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << mortgage << endl;
        cout << setw(COLUMN_ONE) << left << "Savings: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << savings << endl;
        cout << setw(COLUMN_ONE) << left << "Food: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << food << endl;
        cout << setw(COLUMN_ONE) << left << "Utilities: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << utilities << endl;
        cout << setw(COLUMN_ONE) << left << "Games: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << games << endl;
        cout << setw(COLUMN_ONE) << left << "Books: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << books << endl;
        cout << "-------------------------------------" << endl;
        cout << "You have $" << leftOver << " left over this month" << endl;
        if (outputChoice != 3)
            break;
    case 2: // File
        fout << setw(COLUMN_ONE) << left << "Name: " << setw(NAME) << name << endl;
        fout << setw(COLUMN_ONE) << left << "Wages: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << gross << endl;
        fout << setw(COLUMN_ONE) << left << "Taxes: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << taxes << endl;
        fout << setw(COLUMN_ONE) << left << "Net: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << net << endl;
        fout << setw(COLUMN_ONE) << left << "Mortgage: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << mortgage << endl;
        fout << setw(COLUMN_ONE) << left << "Savings: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << savings << endl;
        fout << setw(COLUMN_ONE) << left << "Food: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << food << endl;
        fout << setw(COLUMN_ONE) << left << "Utilities: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << utilities << endl;
        fout << setw(COLUMN_ONE) << left << "Games: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << games << endl;
        fout << setw(COLUMN_ONE) << left << "Books: " << setw(DOLLAR_SIGN) << "$ " << setw(MONEY) << right << books << endl;
        fout << "-------------------------------------" << endl;
        fout << "You have $" << leftOver << " left over this month" << endl;
        if (outputChoice == 2)
            cout << "Please check output file \"budget.txt\" for your results." << endl;
        else
            cout << "Please check output file \"budget.txt\" for a copy of your results." << endl;
        break;
    }

    fout.close();

    // end process
    return 0;
}