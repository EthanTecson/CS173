/*
@Authors: Ethan Tecson and Khanh Do
@Roman Numerals Program
@created 2023-02-23
@updated 2023-02-26
*/

// Header files
#include <iostream>
#include <string>
using namespace std;

string convert(int year);
/*
name of function
list and description/restriction of inputs
return value description
*/

int main()
{
    string answer;
    int value;
    do // Do while loop that prompts user to enter a year between 1 and 2023 forever until 0 is entered
    {
        cout << "Enter year 1 to 2023 (0 to quit): ";
        cin >> value;

        if (1 <= value && value <= 2023) // Checking to see if value is between 1 and 2023
        {
            // cout << value << endl; // Acting as function for now
            cout << convert(value) << endl;
        }
        else if (value != 0) // If value is not between 1 and 2030 and not 0, user will be given error and will be prompted again
        {
            cout << "Invalid Entry. Try Again." << endl;
        }
    } while (value != 0);

    return 0;
}

// arrays including main roman numeral symbols and its values
string symbol[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};

string convert(int year)
{
    string result = "";
    // do for loop to compare the year with its nearest smaller roman numeral value
    for (int i = 12; i >= 0; i--)
    {
        // compare the year for each numeral values
        while (year - num[i] >= 0)
        {
            result = result + symbol[i];
            year = year - num[i];
        }
    }
    return result;
}
//*****************************************************************************

/*
Test Cases:

    - Tested if 4's and 9's came out correctly

*/