////////////////////// Test 2, 2023/2024 (Sem 1) //////////////////////
//// QUESTION 1
//// Name: Nurul Adriana Binti Kamal Jefri
//// Matric No: A23CS0258
//// Date / Day: 4 January 2024 / Thursday
///////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

// function prototypes
float price_original();
char choose_Option();
float price_afterTax(float, char); //this is a returning function

// start main function
int main() 
{
    float price = 0; // should > 0
    char option; // A -> Encyclopedia
                  // B -> Textbook
                  // C -> Novel
                  // D -> Magazine
	option = choose_Option(); 
    price = price_original();
    cout << "Original book price before tax = RM " << price << "\n\n";
    price = price_afterTax(price, option); //new price
    cout << "Total book price after tax = RM " << price << '\n';
    return 0;
}

// start new user-defined functions
float price_original() //different function prototype
{ 
    float bookPrice = 0;
    while (bookPrice <= 0) //book=rm0 is invalid
	{ 
        cout << "Please insert the book price (RM): ";
        cin >> bookPrice;
    }
    return bookPrice;
}

char choose_Option() //choose option is a character
{ 
    char category; 
    do 
	{
        cout << "Please choose the book category: \n";
        cout << "A -> Encyclopedia\n";
        cout << "B -> Textbook\n";
        cout << "C -> Novel\n";
        cout << "D -> Magazine\n";
        cout << "Book category (A,B,C,D): ";
        cin >> category;
        cout << "\n";
    } while (category != 'A' && category != 'B' && category != 'C' && category != 'D'); //these are not an integer, can't use <, >. also, B and C are missing
    return category;
}

// tax is based on book categories as follows:
// A -> Encyclopedia => 3%
// B -> Textbook => 2%
// C -> Novel => 1%
// D -> Magazine => 0.5%
float price_afterTax(float bookPrice, char category) //follow function prototype
{ 
    float tax = 0;
    switch (category) 
	{
        case 'A': tax = bookPrice *  3 / 100; break; 
        case 'B': tax = bookPrice * 2 / 100; break; 
        case 'C': tax = bookPrice * 1 / 100; break;
		case 'D': tax = bookPrice * 0.5 / 100;
    }
    cout << "Tax price = RM " << tax << "\n";
    bookPrice += tax;
    return bookPrice;
}
