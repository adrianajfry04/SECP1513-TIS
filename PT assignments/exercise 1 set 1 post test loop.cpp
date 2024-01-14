/*exercise 1 : post-test loop*/
#include <iostream>
using namespace std;
int main()
{
    int number, sum = 0, remainder;
    cout<<"Enter a positive number : ";
    cin>>number;
    
    do {
        remainder = number % 10;
        sum = sum + remainder;
        number = number / 10;
        
    }while (number>0) ;
    
    if (sum % 3 == 0 && sum % 4 == 0 && sum % 5 == 0) {
        cout<<"Sum of digits is "<<sum<<" and divisible by 3, 4 & 5.";
    }
    else if (sum % 3 == 0 && sum % 4 != 0 && sum % 5 != 0) {
        cout<<"Sum of digits is "<<sum<<" and divisible by 3.";
    }
    else if (sum % 3 != 0 && sum % 4 == 0 && sum % 5 != 0) {
        cout<<"Sum of digits is "<<sum<<" and divisible by 4.";
    }
    else if (sum % 3 != 0 && sum % 4 != 0 && sum % 5 == 0) {
        cout<<"Sum of digits is "<<sum<<" and divisible by 5.";
    }
    else if (sum % 3 == 0 && sum % 4 == 0 && sum % 5 != 0) {
        cout<<"Sum of digits is "<<sum<<" and divisible by 3 & 4.";
    }
    else if (sum % 3 == 0 && sum % 4 != 0 && sum % 5 == 0) {
        cout<<"Sum of digits is "<<sum<<" and divisible by 3 & 5.";
    }
    else if (sum % 3 != 0 && sum % 4 == 0 && sum % 5 == 0) {
        cout<<"Sum of digits is "<<sum<<" and divisible by 4 & 5.";
    }
    else {
        cout<<"Sum of digits is "<<sum<<" and not divisible by 3, 4 & 5.";
    }
    
    return 0;
}




