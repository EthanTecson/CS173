/*
Author: Ethan Tecson
Description: Checks if flood light is on/off
Date: 2023/1/31
Updated: 2023/2/2
*/
#include <iostream>
#include <string>

using namespace std;

string floodLight();

int main()
{

    string output = floodLight();
    cout << output;

    return 0;
}

//*********************************************************************

string floodLight()
{
    int t1_on;
    cout << "Length of time FIRST security light stays ON: " << endl; // Prompt user for length of ON time for FIRST light
    cin >> t1_on;

    int t1_off;
    cout << "Length of time FIRST security light stays OFF: " << endl; // Prompt user for length of OFF time for FIRST light
    cin >> t1_off;

    int t2_on;
    cout << "Length of time SECOND security light stays ON: " << endl; // Prompt user for length of ON time for SECOND light
    cin >> t2_on;

    int t2_off;
    cout << "Length of time SECOND security light stays OFF: " << endl; // Prompt user for length of OFF time for SECOND light
    cin >> t2_off;

    int t_ups;
    cout << "Time in minutes after midnight when package arrives: " << endl; // Prompt user for arrival time of ups package
    cin >> t_ups;

    int t1_cycle = t1_on + t1_off;       // Creating full cycle of off and on for t1
    int t1_remainder = t_ups % t1_cycle; // Find remainder of t1_cycle to figure out when cycle ups driver will arrive

    int t2_cycle = t2_on + t2_off;       // Creating full cycle of off and on for t2
    int t2_remainder = t_ups % t2_cycle; // Find remainder of t2_cycle to figure out when cycle ups driver will arrive

    int count = 0; // Create counter that starts at 0

    if (t1_remainder < t1_on) // If remainder is less than t1_on cycle, add 1 to counter
        (count += 1);

    if (t2_remainder < t2_on) // If remainder is less than t2_on cycle, add 1 to counter
        (count += 1);

    if (count == 1)
    {
        return ("ONE"); // If count = 1, only one light is on
    }
    else if (count == 2)
    {
        return ("BOTH"); // If count = 12, two lights are on
    }
    else
    {
        return ("NONE"); // If count = 0, no lights are on
    }
}
//*********************************************************************