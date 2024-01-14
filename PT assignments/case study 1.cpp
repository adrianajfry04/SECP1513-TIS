/* Group member :
1. 
2. NURUL ADRIANA BINTI KAMAL JEFRI (A23CS0258)
3. LUBNA AL HAANI BINTI RADZUAN (A23CS0107)

Date :
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

//Function prototype list
void displayMenu();
void readFile(ifstream&, string[], const char*, float[], float[], float[]);
float calConvert (float[], float[], float[]);
string categoryAVG (float);

int main () {
	ifstream input("inputcereal.txt");
	ofstream output("outputcereal.txt");
	float C[10];
	float P[10];
	float F[10];
	char X[10];
	string Z[10];
	readFile (input, Z, X, C, P, F);
	void calConvert (C, P, F);
	int choice;
	
	do {
	displayMenu(); 
	cout<<"Please enter your choice >> ";
	cin>>choice;

	} while (choice == 'Y' || choice == 'y');
}

void displayMenu () {
	cout<<"1. Carbohydrate"<<endl;
	cout<<"2. Protein"<<endl;
	cout<<"3. Fat"<<endl;
}

void readFile (ifstream& input, string Z[], char X[], float C[], float P[], float F[]) {
	if (!inputFile.is_open()) {
        cout << "Error opening the file." << endl;
        return;
    } 
	
	for (int i = 0; i < 10; ++i) {
        input >> Z[i] >> X[i] >> C[i] >> P[i] >> F[i];
    }

    inputFile.close();
}

void calConvert (float C[], float P[], float F[]) {
	for (int i = 0; i<8; i++) {
		C[i] = C[i] * 28.35;
		P[i] = P[i] * 28.35;
		F[i] = F[i] * 28.35;
	}
}

string categoryAVG (float avg) {
	string level;
	
	if (avg <= 5) {
		level = "LOW";
	} else if ((avg > 5) && (avg < 20)) {
		level = "MODERATE";
	} else {
		level = "HIGH";
	} return level;
}
