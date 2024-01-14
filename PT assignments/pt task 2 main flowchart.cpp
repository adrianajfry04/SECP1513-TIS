#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main() {
    
    int carprice, downpayment, loanterms, interestrate, region, balance, totalinterest, monthlyinstallment, months, principal, interest;
    
    do {
        cout<<"Enter your car price : RM";
        cin>>carprice;
    } while (carprice < 22000);
    
    do {
        cout<<"Enter your car downpayment (%) : ";
        cin>>downpayment;
    } while (downpayment <= 0);
    
    do {
        cout<<"Enter loan terms (in years) : ";
        cin>>loanterms;
    } while (loanterms <= 3 || loanterms >10);
    
    do {
        cout<<"Enter your car interest rate (%) : ";
        cin>>interestrate;
    } while (interestrate <3 || interestrate >9 );
    
   balance = carprice - downpayment;
   months = loanterms * 12;
   totalinterest = balance * (interestrate/100) * loanterms;
   monthlyinstallment = (balance + totalinterest)/months;
    
   cout<<"Select your region ; \n1 = SM (semenanjung) or 2 = SS (sabah & sarawak) ? ";
   cin>>region;
   
   if (region == 1 && region != 2) {
       monthlyinstallment = monthlyinstallment + (0.04 * monthlyinstallment);
       cout<<"Monthly installment are increased by 4%.";
   } else if (region != 1 && region == 2) {
       monthlyinstallment = monthlyinstallment + (0.08 * monthlyinstallment);
       cout<<"Monthly installment are increased by 8%.";
   }
   cout<<"\nMonthly installment : RM "<< monthlyinstallment << ".";
   
    return 0;
}
    



