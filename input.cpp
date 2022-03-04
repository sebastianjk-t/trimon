    #include <iostream>
#include <string>
#include <limits>

using namespace std;

// takes in prompt to display user, plus lower and upper bound, then returns entered integer
int getInt(string prompt, int lower, int upper)
{
    int myInt;

    // repeat prompt and input until valid integer is entered
    for (;;)
    {
        cout << prompt;
        cin >> myInt;

        // leave for-loop if within range
        if (myInt >= lower && myInt <= upper)
        {
            break;
        }
        else // display error message and clear input stream
        {
            cout << "\nInput must be an integer between " << lower << " and " << upper << ".\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize> :: max(), '\n');
        }
    }

    return myInt;
}

// takes in prompt to display user, then returns entered string
string getString(string prompt)
{
    string myString;

    // repeat prompt and input until valid string is entered
    for (;;)
    {
        cout << prompt;

        // leave for-loop if input doesn't produce error
        if (cin >> myString)
        {
            break;
        }
        else // display error message and clear input stream
        {
            cout << "\nInput must be a string.\n\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize> :: max(), '\n');
        }
    }

    return myString;
}
