#include <iostream>
#include <limits>
using namespace std;

bool isValidDate(int day, int month, int year) {
    if (day < 1 || day > 31) return false;
    if (month < 1 || month > 12) return false;
    if (year < 1900 || year > 2025) return false;
    return true;
}

int calculateAge(int birthMonth, int birthDay, int birthYear,
    int currentMonth, int currentDay, int currentYear) {
    int age = currentYear - birthYear;
    if (currentMonth < birthMonth ||
        (currentMonth == birthMonth && currentDay < birthDay)) {
        age--;
    }
    return age;
}

// Reads one integer; returns false only if input has ended
bool readInt(const char* prompt, int& value) {
    while (true) {
        cout << prompt;
        if (cin >> value) return true;
        if (cin.eof()) return false;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please enter a number." << endl;
    }
}

int main() {
    while (true) {
        int bm, bd, by, cm, cd, cy;

        do {
            if (!readInt("Enter your birth month: ", bm)) return 0;
            if (!readInt("Enter your birth day: ", bd)) return 0;
            if (!readInt("Enter your birth year: ", by)) return 0;
            if (!isValidDate(bd, bm, by)) cout << "Invalid date. Please try again." << endl;
        } while (!isValidDate(bd, bm, by));

        do {
            if (!readInt("Enter the current month: ", cm)) return 0;
            if (!readInt("Enter the current day: ", cd)) return 0;
            if (!readInt("Enter the current year: ", cy)) return 0;
            if (!isValidDate(cd, cm, cy)) cout << "Invalid date. Please try again." << endl;
        } while (!isValidDate(cd, cm, cy));

        cout << "Your age is " << calculateAge(bm, bd, by, cm, cd, cy)
            << " years old." << endl << endl;
    }
}}