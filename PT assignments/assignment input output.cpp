#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void readFile(ifstream&, float[], int);
void computeC(float[], float[], int);
float average(float[]);
void grade(float[], char[], int &, int &, int &);
void writeFile(ofstream&, float[], float[], char []);

int main () {
	ifstream input("input.txt");
	ofstream output("output.txt");
	float F[8];
	float C[8];
	int m=0, countH=0, countM=0, countL=0;
	char G[8];
	readFile (input, F, m);
	computeC (F, C, m);
	cout << "Average of the temperature in Celcius : ";
	cout << fixed << showpoint << setprecision(1) << average (C) << endl;
	grade (C, G, countH, countM, countL);
	cout << "Number of high temperature :" << countH << endl;
	cout << "Number of medium temperature : " << countM << endl;
	cout << "Number of low temperature : " << countL << endl;
	writeFile (output, F, C, G);	
}

void readFile (ifstream& input, float F[], int m) {
	float f;
		if (!input.is_open()) {
		cout<<"Terminating!";
	} 	
	while (!input.eof()) {
		for (int i=0; i<8; i++) {
			input >> f;
			F[i]=f;
			m = m+1;
		}
	} 
}

void computeC (float F[], float C[], int m) {
	for (int i = 0; i<8; i++) {
		C[i] = (5.0/9.0) * (F[i] - 32);
	}
}

float average (float C[]) {
	float sum = 0.0;
	for (int i = 0; i<8; i++) {
		sum += C[i];
	} 
	float ave = sum / 8.00;
	return ave;
}

void grade (float C[], char G[], int &x, int &countM, int &countL) {
	for (int i = 0; i < 8; i++) {
		if (C[i]>= 35) {
			G[i] = 'H' ;
			x += 1;
		} else if (C[i]<35 && C[i]>=20) {
			G[i] = 'M' ;
			countM += 1;
		} else if (C[i]<20) {
			G[i] = 'L' ;
			countL += 1;
		}
	}	
  }

void writeFile (ofstream &output, float F[], float C[], char G[]) {
    if (output.is_open()) {
    	output << setw(15) << "C(Celcius)" << setw(15) << "F(Farenheit)"  << setw(15) <<  "Description" << endl;
    	output << setw(15) << "==========" << setw(15) << "============"  << setw(15) <<  "===========" << endl;
        for (int i = 0; i < 8; ++i) {
        	output << fixed << showpoint << setprecision(2);
            output << setw(15) << C[i];
            output << setw(15) << F[i];
            output << setw(15) << G[i] << endl;
        } output.close();
    } else {
        cout << "Unable to open file for writing." << endl;
    }
}
