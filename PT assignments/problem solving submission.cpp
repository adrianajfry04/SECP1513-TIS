#include <iostream>
using namespace std;
void displayMenu();
void displayLibraryInfo();
void getUserInput(int &);
int calculateLateFees(int);

int main() {
    int choice, days = 0;

    do {
        cout << "************ Library Book Checkout System **********\n";
        displayMenu();
        cout << "Please enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                getUserInput(days);
                cout << "Late fees: RM" << calculateLateFees(days) << endl;
                break;
            case 2:
                displayLibraryInfo();
                break;
            case 3:
                cout << "Exiting the program. Thank You!";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 3." << endl;
        }
    } while (choice != 3);

    return 0;
}

int calculateLateFees(int days) {
    int lateFees = 0;

    if (days <= 7) {
        lateFees = days * 0.50;
    } else if (days <= 14) {
        lateFees = 3.5 + ((days - 7) * 1);
    } else {
        lateFees = 3.5 + 7 + ((days - 14) * 2.00);
    }
    return lateFees;
}

void displayMenu() {
    cout << "1. Calculate Late Fees" << endl;
    cout << "2. Display Library Information" << endl;
    cout << "3. Quit" << endl;
}

void displayLibraryInfo() {
    cout << "************ Library Information ************" << endl;
    cout << "Library Name: UTM Library" << endl;
    cout << "Address: Skudai, Johor" << endl;
    cout << "Contact: (123) 456 7890" << endl;
}

void getUserInput(int &days) {
    cout << "Enter the number of days the book is overdue: ";
    cin >> days;
}










