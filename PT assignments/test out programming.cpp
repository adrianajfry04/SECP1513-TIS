#include <iostream>
#include <iomanip>
using namespace std;
void readQty (int&, int&, int&);
void displayHighProd (double, double, double);
double calcAvrg (int, double);
void summaryCom (double, double, double, double);

int main (){
	string name, lowestagent, highestagent, highestagentA, highestagentB, highestagentC;
	int agents=0, A, B, C, sumTotal=0, lowest=99999, highest=0, highestA=0, highestB=0, highestC=0;
	
	do {
	cout<<"----------------------AGENT------------------------";
	cout<<"\nAgent Name : ";
	getline(cin, name);
	if (name.empty()) break;
	readQty (A, B, C);
	double commissionA = A*(150*0.025);
	double commissionB = B*(300*0.05);
	double commissionC = C*(450*0.1); 
	double total = commissionA + commissionB + commissionC;
	summaryCom (commissionA, commissionB, commissionC, total);
	
	if (total < lowest) {
		lowest = total;
		lowestagent = name;
	}
	
	if (total > highest) {
		highest = total;
		highestagent = name;
	}
	
	if (commissionA > highestA) {
		highestA = commissionA;
		highestagentA = name;
	}
	
	if (commissionB > highestB) {
		highestB = commissionB;
		highestagentB = name;
	}
	
	if (commissionC > highestC) {
		highestC = commissionC;
		highestagentC = name;
	}
	
	sumTotal += total;
	agents = agents + 1;
    } while (cin.get() == '\n');
    double Ave = calcAvrg (agents, sumTotal);
	cout<<"------------------SALES ANALYSIS-------------------";
   	cout<<"Lowest commission for three products: RM" << lowest << " (" << lowestagent << ")." <<endl;
   	cout<<"Highest commission for three products: RM" << highest << " (" << highestagent << ")." <<endl;
   	cout<<"Highest commission for Product A: RM" << highestA << " (" << highestagentA << ")." <<endl;
   	cout<<"Highest commission for Product B: RM" << highestB << " (" << highestagentB << ")." <<endl;
   	cout<<"Highest commission for Product C: RM" << highestC << " (" << highestagentC << ")." <<endl;
   	cout<<"Total of commission for 4 agents: RM" << sumTotal <<endl;
   	cout<<"Average commission for 4 agents: RM" << Ave << endl; 
}


void readQty (int &A, int &B, int &C) {
	do {
		cout<<"Product A: ";
		cin>>A;
		if (A<0 || A>100) {
			cout<<"The input is invalid!";
		}
	} while (A>0 || A<100);
	
	do {
		cout<<"Product B: ";
		cin>>B;
		if (B<0 || B>100) {
			cout<<"The input is invalid!";
		}
	} while (B>0 || B<100);
	
	do {
		cout<<"Product C: ";
		cin>>C;
		if (C<0 || C>100) {
			cout<<"The input is invalid!";
		}
	} while (C>0 || C<100);
}

void displayHighProd (double commissionA, double commissionB, double commissionC) {
	if (commissionA>commissionB && commissionA>commissionC ) {
		cout<<"A" << ": RM" << commissionA;
	} else if (commissionB>commissionA && commissionB>commissionC) {
		cout<<"B" << ": RM" << commissionB;
	} else {
		cout<<"C" << ": RM" << commissionC;
	}
}

void summaryCom (double summaryA, double summaryB, double summaryC, double total) {
	cout<<"-------------------SALES SUMMARY-------------------";
	cout<<"Total of commission for three products : RM" << total <<endl;
	cout<<"Highest commission - Product ";
	displayHighProd (summaryA, summaryB, summaryC);
}

double calcAvrg (int agents, double sumTotal) {
	double average = sumTotal/agents;
	return average;
}


