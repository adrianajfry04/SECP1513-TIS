/*exercise 1 set 3 : pre-test loop*/
#include <iostream>
using namespace std;
int main()
{
    int num1, num2, remainder, product = 1, i;
    cout << "Enter a positive number: ";
    cin >> num1;
    num2 = num1;
    
    for(i=num1;i>0;i=i/10) {
        remainder = i % 10;
        product = product *remainder;
    }
    
    if (product % 4 == 0 && product % 5 == 0 && product % 7 == 0) {
        cout<<"Product of digits is "<<product<<" and divisible by 4, 5 & 7.";
    }
    else if (product % 4 == 0 && product % 5 != 0 && product % 7 != 0) {
        cout<<"Product of digits is "<<product<<" and divisible by 4.";
    }
    else if (product % 4 != 0 && product % 5 == 0 && product % 7 != 0) {
        cout<<"Product of digits is "<<product<<" and divisible by 5.";
    }
    else if (product % 4 != 0 && product % 5 != 0 && product % 7 == 0) {
        cout<<"Product of digits is "<<product<<" and divisible by 7.";
    }
    else if (product % 4 == 0 && product % 5 == 0 && product % 7 != 0) {
        cout<<"Product of digits is "<<product<<" and divisible by 4 & 5.";
    }
    else if (product % 4 == 0 && product % 5 != 0 && product % 7 == 0) {
        cout<<"Product of digits is "<<product<<" and divisible by 4 & 7.";
    }
    else if (product % 4 != 0 && product % 5 == 0 && product % 7 == 0) {
        cout<<"Product of digits is "<<product<<" and divisible by 5 & 7.";
    }
    else {
        cout<<"Product of digits is "<<product<<" and not divisible by 4, 5 & 7.";
    }
    return 0;
}
