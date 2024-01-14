#include <iostream> //copy 10 numbers between files
#include <fstream>
using namespace std;
int main() {
	fstream infile("input.txt", ios::in); // open the files
	fstream outfile("output.txt", ios::out);
	int num;
	for (int i = 1; i <= 10; i++) {
		infile >> num; // use the files
	    outfile << num; 
	}
	infile.close(); // close the files
	outfile.close();
}
