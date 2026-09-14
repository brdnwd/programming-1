// WoodBGradeList.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Braden Wood
// 9/14/26
// GradeList V1: read in from a file, calculate average, then output to a file.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// declare constant variables
const int STUDENT = 20, TEST = 8, TEST_AVERAGE = 10;
const bool isDebug = false;

int main()
{
    // declare variables
    string name, gradesFile = "woodb_testscores.txt", results = "results.txt";
    double test1, test2, test3, average;

    // declare file stream variables
    ifstream fin;
    ofstream fout;

    // open streams
    fin.open(gradesFile);    
    fout.open(results);

    // title & description
    cout << "Grade List Program" << endl;
    cout << "Created by: Braden Wood" << endl;
    cout << "This program will read in student names and 3 test scores from a file" << endl;
    cout << "and then calculate each students average." << endl;
    cout << "The results will print to an external file named: \"" << results << "\"." << endl << endl;

    // output to file: column headings
    fout << setw(STUDENT) << left << "Name" << setw(TEST) << right << "Test 1" << setw(TEST) << "Test 2" << setw(TEST) << "Test 3" << setw(TEST_AVERAGE) << "Test Avg" << endl;

    // read the data
    if (isDebug) {
        while (getline(fin, name)) {
            fin >> test1 >> test2 >> test3;
            fin.ignore();

            // calculations
            average = (test1 + test2 + test3) / 3;

            // output to file
            fout << fixed << setprecision(2) << showpoint;

            // add data
            fout << setw(STUDENT) << left << name << setw(TEST) << right << test1 << setw(TEST) << test2 << setw(TEST) << test3 << setw(TEST_AVERAGE) << average << endl;
        }
    }
    else {
        //Student1
        getline(fin, name);
        fin >> test1 >> test2 >> test3;
        fin.ignore();

        // calculations
        average = (test1 + test2 + test3) / 3;

        // output to file
        fout << fixed << setprecision(2) << showpoint;

        // add data
        fout << setw(STUDENT) << left << name << setw(TEST) << right << test1 << setw(TEST) << test2 << setw(TEST) << test3 << setw(TEST_AVERAGE) << average << endl;
    
        //Student2
        getline(fin, name);
        fin >> test1 >> test2 >> test3;
        fin.ignore();

        // calculations
        average = (test1 + test2 + test3) / 3;

        // output to file
        fout << fixed << setprecision(2) << showpoint;

        // add data
        fout << setw(STUDENT) << left << name << setw(TEST) << right << test1 << setw(TEST) << test2 << setw(TEST) << test3 << setw(TEST_AVERAGE) << average << endl;

        //Student3
        getline(fin, name);
        fin >> test1 >> test2 >> test3;
        fin.ignore();

        // calculations
        average = (test1 + test2 + test3) / 3;

        // output to file
        fout << fixed << setprecision(2) << showpoint;

        // add data
        fout << setw(STUDENT) << left << name << setw(TEST) << right << test1 << setw(TEST) << test2 << setw(TEST) << test3 << setw(TEST_AVERAGE) << average << endl;
    }

    cout << "The program ran succesfully. Check the output file: \"" << results << "\" for results." << endl;

    // close streams
    fin.close();
    fout.close();

    return 0;
}