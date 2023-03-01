/*
@Authors: Ethan Tecson and Daniel Chu
@DNAsearch Program
@created 2023-03-1
@updated 2023-
*/

// Header files
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string donor_string;
    string fragment;

    cout << "Enter DNA String: ";
    cin >> donor_string;

    do
    {
        cout << "Enter DNA Fragemnt to be searched (Enter 'exit' to quit): ";
        cin >> fragment;
    } while (fragment != "exit");

    return 0;
}