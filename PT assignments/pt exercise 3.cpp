/*pt exercise 3
name : Nurul Adriana Binti Kamal Jefri
matrics number : A23CS0258
date : 17/12/2023*/
#include <iostream>
#include <string>
using namespace std;
void dispStatus (int); 
void getInput (int&, int&, int&, int&);
void dispOutput (int);
int calcAverage (int, int);
    
int main(){
    int n, x=0, y=0, totalCase, newCase, totalDeath, totalRecovered, highest=-999;
    string state, temp, higheststate;
    char result;
    
    do {
        cout<<"\n<<<<<<<<<<<<<<DATA>>>>>>>>>>>>>>\n";
        cout<<"Enter state : ";
        getline(cin, state);
        getInput (totalCase, newCase, totalDeath, totalRecovered);
        n = totalCase + newCase - totalDeath - totalRecovered;
        if (n > highest) {
            highest=n;
            higheststate=state;
        } 
        cout<<"\n<<<<<<<<<<<<<<SUMMARY>>>>>>>>>>>>>>\n";
        cout<<"Active cases : " <<n<< "\n";
        dispOutput (n); 
        x = x+n;
        y = y+1;
        cin.ignore();
        cout<<"\nPRESS <ENTER> TO CONTINUE...";
    } while (cin.get() == '\n');
    calcAverage (x,y);
    cout<<"<<<<<<<<<<ACTIVE CASES>>>>>>>>>>";
    cout<<"\nTotal : "<<x;
    cout<<"Highest : "<<highest<<"("<<higheststate<<")";
    cout<<"\nAverage for "<<y<<" state(s)"<<calcAverage (x,y);
    return 0;
}

void getInput (int &a, int &b, int &c, int &d) {
    cout<<"Enter total case : ";
    cin>>a;
    cout<<"Enter new cases : ";
    cin>>b;
    cout<<"Enter total death : ";
    cin>>c;
    cout<<"Enter total recovered : ";
    cin>>d;
}

void dispOutput (int n) {
    dispStatus (n);
}


void dispStatus (int n) { 
    if (n > 40) {
        cout<<"Status of zone : RED.";     
    } else if (n >= 21 && n <= 40) {
        cout<<"Status of zone : ORANGE.";
    } else if (n >= 1 && n <= 20) {
        cout<<"Status of zone : YELLOW.";
    } else if (n == 0) {
        cout<<"Status of zone : GREEN.";
    } else {
        cout<<"Status of zone : GREEN.";
    }
}

int calcAverage (int x, int y) {
    int average = x/y;
    return average;
}


