#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    
    int carprice, downpayment, loanterms, interestrate, totalpayment, carbrand, monthlyinstallment;
    
    cout<<"Select your car brand : 1.local or 2.international = ";
    cin>>carbrand;
    
    do {
        cout<<"Enter your car price : RM ";
        cin>>carprice;
    } while (carprice < 22000);
    
    do {
        cout<<"Enter loan terms (in years) : ";
        cin>>loanterms;
    } while (loanterms <= 3 || loanterms >10);
    
    do {
        cout<<"Enter your car downpayment (%) : ";
        cin>>downpayment;
    } while (downpayment <= 0);
    
    do {
        cout<<"Enter your car interest rate (%) : ";
        cin>>interestrate;
    } while (interestrate <3 || interestrate >9 );
    
    monthlyinstallment = ((carprice - downpayment) *interestrate  + carprice * loanterms);
   
   if (carbrand == 1 && carbrand != 2) {
       totalpayment = monthlyinstallment + 500;
       cout<<"Monthly installment : RM"<<totalpayment;
   } else if (carbrand != 1 && carbrand == 2) {
       totalpayment = monthlyinstallment + 1000;
       cout<<"Monthly installment : RM"<<totalpayment;
   }
   
    return 0;
}
    




