// TestOut_8-13-26.cpp : This file contains the 'main' function.
// Your Name: Braden Wood

/****************************************************
  Programming I (C++) Test-Out Exam — Start File
  INSTRUCTIONS:
  - Complete each TASK exactly as written.
  - Tasks are independent of one another.
  - Do NOT remove task comments.
  - Each task has its own required output label.
  - Reference sheet is allowed. No other resources.
****************************************************/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/****************************************************
  TASK 4: Value-Returning Function
  - See function requirements at bottom of file.
****************************************************/
// TASK 4 - TODO: Function prototype goes here

const int MAX_HOURS = 40;
const int SIZE = 4;

// Returns a string from integer
string getCategory(int age) {
    string age_name;

    if (age < 13) {
        age_name = "Child";
    }
    else if (age >= 13 && age <= 19) {
        age_name = "Teen";
    }
    else {
        age_name = "Adult";
    }

    return age_name;
}

int main()
{
    // IMPORTANT:
    // Declare variables as needed inside each TASK section.
    // Do not reuse variables across tasks.


    /************************************************
      TASK 1: Variables, Constants, Strings, I/O
      - Declare a named integer constant MAX_HOURS = 40
      - Prompt for the user's first name
      - Prompt for ONE number of hours worked (double)
      - Display exactly:
          TASK 1 OUTPUT: <name> worked <hours> out of <MAX_HOURS> hours
    ************************************************/

    // TODO: Task 1 code here
    string name = "";
    double hours;

    cout << "Enter your full name (ex: Braden Wood): ";
        
    if (!cin) {
        cout << "[ERROR] Invalid Data";
        return 1;
    }

    getline(cin, name);

    cout << "Enter your hours worked (ex: 18.27): ";
    cin >> hours;

    if (!cin) {
        cout << "[ERROR] Invalid Data";
        return 1;
    }

    cout << "TASK 1 OUTPUT: " << name << " worked " << hours << " out of " << MAX_HOURS << " hours" << endl << endl;

    /************************************************
      TASK 2: If / Else (Conditionals)
      - Prompt for ONE integer speed value
      - Display exactly ONE of the following:
          TASK 2 OUTPUT: Slow
          TASK 2 OUTPUT: Normal
          TASK 2 OUTPUT: Fast

      Rules:
        speed < 30              -> Slow
        30 through 60           -> Normal
        above 60                -> Fast
    ************************************************/

    // TODO: Task 2 code here
    int speed_value;
    string speed;
    
    cout << "Enter a speed value (0-100+): ";
    cin >> speed_value;

    if (!cin || speed_value < 0) {
        cout << "[ERROR] Invalid Data";
        return 1;
    }

    if (speed_value <= 30) {
        speed = "Slow";
    }
    else if (speed_value >= 30 && speed_value <= 60) {
        speed = "Normal";
    }
    else {
        speed = "Fast";
    }

    cout << "TASK 2 OUTPUT: " << speed << endl << endl;

    /************************************************
      TASK 3: Arrays + Loops (Total and Average)
      - Declare a const int SIZE = 4
      - Declare a 1-D array of doubles with size SIZE
      - Prompt the user to enter 4 numeric expenses
      - Use a loop to store the values in the array
      - Use a loop to compute the TOTAL of the values
      - Calculate the AVERAGE of the 4 values
      - Display exactly:
          TASK 3 OUTPUT: Total Expenses = <value>
          TASK 3 OUTPUT: Average Expense = <value>

      NOTES:
      - Use loops (do not write 4 separate input statements)
    ************************************************/

    // TODO: Task 3 code here
    double expenses[SIZE], total = 0, average;

    for (int i = 0; i < SIZE; i++) {
        cout << "Enter expense " << i + 1 << " (" << rand() << "): "; // produces a random value for examples
        cin >> expenses[i];

        if (!cin) {
            cout << "[ERROR] Invalid Data";
            return 1;
        }
    }

    for (int i = 0; i < SIZE; i++) {
        total += expenses[i];
    }

    average = total / SIZE;

    cout << "TASK 3 OUTPUT: Total Expenses = $" << total << endl;
    cout << "TASK 3 OUTPUT: Average Expense = $" << average << endl << endl;

    /************************************************
      TASK 4: Function Use
      - Prompt for ONE numeric age (int)
      - Call getCategory using the entered age
      - Display exactly:
          TASK 4 OUTPUT: Category = <word>

      NOTE:
      - This task only tests the function.
      - It does NOT depend on Tasks 1–3.
    ************************************************/

    // TODO: Task 4 code here
    int age;

    cout << "Please enter an age (1,20,80): ";
    cin >> age;

    if (!cin || age < 1) {
        cout << "[ERROR] Invalid Data";
        return 1;
    }

    string category = getCategory(age);

    cout << "TASK 4 OUTPUT: Category = " << category << endl << endl;

    /************************************************
      TASK 5: File Output Only
      - Create a file named "report.txt"
      - Write the following three lines to the file:
          Programming I Review
          File Writing Complete
          Goodbye

      - Close the file

      - Display exactly:
          TASK 5 OUTPUT: File created successfully

      NOTES:
      - No file input required
      - Content is fixed (not computed)
    ************************************************/

    // TODO: Task 5 code here
    ofstream fout;

    fout.open("report.txt");

    fout << "Programming I Review" << endl;
    fout << "File Writing Complete" << endl;
    fout << "Goodbye" << endl;

    fout.close();

    cout << "TASK 5 OUTPUT: File created successfully" << endl << endl;

    return 0;
}