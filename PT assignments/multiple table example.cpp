#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
int main () {
	int n, c=1, limit;
	cout<<"Enter number to print its table : ";
	cin>>n;
	cout<<"\nEnter limit : ";
	cin>>limit;
	
	while  (c <= limit) {
		cout << n << " * " << setw(2) << c << " = " << setw(2) << n * c << endl;
		c++;
	}
	getch();
}
