#include <iostream>
#include <fstream>
using namespace std;
int main () {
	
	int num;
	ifstream inp("input.txt");
	ofstream out("output.txt");
	if (!inp.is_open()) {
		cout<<"Input file could not be opened! Terminating!\n";
		return 0;
	} while (inp>>num)
	  out<< num*2 <<endl;
	
	inp.close();
	out.close();
	cout<<"Done!"<<endl;
	return 0;
}
