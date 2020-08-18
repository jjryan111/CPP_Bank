#include <string>
#include "ValidNum.h"

ValidNum::ValidNum() {}
ValidNum::~ValidNum() {}
bool ValidNum::validNumber(string user_string_num)
{
    int is_num = 0,
        decimal_count = 0;

    bool is_num_bool = 0;
    /*
    if (user_string_num[0] == '-')
        is_num++;
        */
    if (user_string_num[0] == '0' &&
        isdigit(user_string_num[1]))
        is_num = 0;
    else
    {
        for (int i = 0; i < user_string_num.size(); i++)
        {
            if (isdigit(user_string_num[i]))
                is_num++;
            if (user_string_num[i] == '.') {
                decimal_count++;
                is_num++;
            }
        }
    }

    if (decimal_count > 1) {
        is_num = 0;
    }

    if (is_num == user_string_num.size())
    {
        is_num_bool = 1;
    }
    /*
    else {
    //Put this in to clear the buffer when the code returns
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');}*/
    return is_num_bool;
}

void ValidNum::clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int ValidNum::validateEntry(string msg) {
    string entry;
    cout << msg;
    cin >> entry;
    if (validNumber(entry)) {
        return stoi(entry);
    }
    else {
        clearInput();
        cout << "Invalid entry.\n";
        system("pause");
        return -1;
    }
}
double ValidNum::validateEntry(string msg, double transaction) {
    string entry;
    cout << msg;
    cin >> entry;
    if (validNumber(entry)) {
        transaction = stod(entry);
        return transaction;
    }
    else {
        clearInput();
        cout << "Invalid entry.\n";
        system("pause");
        return -1;
    }
}

