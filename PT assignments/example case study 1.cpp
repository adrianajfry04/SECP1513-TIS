#include <iostream>
#include <fstream>
#include <iomanip>

const double OZ_TO_GRAMS = 28.35;
const double CARB_DV = 300.0;
const double PROTEIN_DV = 50.0;
const double FAT_DV = 65.0;
const int NUM_CEREALS = 10;
double calAverage(const double* values);

struct Cereal {
    std::string name;
    double carb_oz;
    double protein_oz;
    double fat_oz;
};

void calconvert(Cereal& cereal) {
    cereal.carb_oz *= OZ_TO_GRAMS;
    cereal.protein_oz *= OZ_TO_GRAMS;
    cereal.fat_oz *= OZ_TO_GRAMS;
}

double calDV(double nutrient, double dv) {
    return (nutrient / dv) * 100.0;
}

std::string category(double percentage) {
    if (percentage <= 5.0) {
        return "low";
    } else if (percentage > 5.0 && percentage < 20.0) {
        return "moderate";
    } else {
        return "high";
    }
}

void printMenu() {
    std::cout << "1. Carbohydrate\n2. Protein\n3. Fat\nPlease enter your choice>> ";
}

void printLevelMenu() {
    std::cout << "1. Low\n2. Moderate\n3. High\nPlease enter your choice>> ";
}

void processCategory(std::ofstream& outFile, const std::string& nutrient, const double* percentages, const Cereal* Cereals) {
    outFile << nutrient << std::endl;
    for (int i = 0; i < NUM_CEREALS; ++i) {
        outFile << std::setw(10) << std::left << Cereals[i].name;
        outFile << std::setw(7) << std::right << std::fixed << std::setprecision(1) << percentages[i] << "%("
                << category(percentages[i]) << ") ";
        outFile << std::endl;
    }
}


void displayCerealCategory(const std::string& nutrient, int level, const double* percentages) {
    std::cout << "List of cereal(s) with " << category(level) << " amount of " << nutrient << ":\n";
    for (int i = 0; i < NUM_CEREALS; ++i) {
        if (category(percentages[i]) == category(level)) {
            std::cout << i + 1 << ". " << Cereals[i].name << "\n";
        }
    }
}

void writeOutputFile(std::ofstream& outFile, double carbPercentages[], double proteinPercentages[], double fatPercentages[]) {
    outFile << "Type\n========\n";
    outFile << "Carbohydrate\n============= \nProtein\n======= \nFat\n===\n";
    for (int i = 0; i < NUM_CEREALS; ++i) {
        outFile << std::setw(10) << std::left << Cereals[i].name;
        outFile << std::setw(7) << std::right << std::fixed << std::setprecision(1) << carbPercentages[i] << "%("
                << category(carbPercentages[i]) << ") ";
        outFile << std::setw(7) << std::right << std::fixed << std::setprecision(1) << proteinPercentages[i] << "%("
                << category(proteinPercentages[i]) << ") ";
        outFile << std::setw(7) << std::right << std::fixed << std::setprecision(1) << fatPercentages[i] << "%("
                << category(fatPercentages[i]) << ") ";
        outFile << std::endl;
    }

    outFile << "\nThe four cereal types produce an average %DV of:\n";
    outFile << "Carbohydrate : " << std::fixed << std::setprecision(1) << std::setw(3) << calAverage(carbPercentages) << "%("
            << category(calAverage(carbPercentages)) << ")\n";
    outFile << "Protein : " << std::fixed << std::setprecision(1) << std::setw(3) << calAverage(proteinPercentages) << "%("
            << category(calAverage(proteinPercentages)) << ")\n";
    outFile << "Fat : " << std::fixed << std::setprecision(1) << std::setw(3) << calAverage(fatPercentages) << "%("
            << category(calAverage(fatPercentages)) << ")\n";
}

double calAverage(const double* values) {
    double sum = 0.0;
    for (int i = 0; i < NUM_CEREALS; ++i) {
        sum += values[i];
    }
    return sum / NUM_CEREALS;
}

int main() {
    // ...

    // Ask the user to enter nutrient and level, then display the food listed under that category
    char chooseAgain;
    do {
        printMenu();
        int nutrientChoice;
        std::cin >> nutrientChoice;

        printLevelMenu();
        int levelChoice;
        std::cin >> levelChoice;

        switch (nutrientChoice) {
            case 1:
                displayCerealCategory("Carbohydrate", levelChoice, carbPercentages);
                break;
            case 2:
                displayCerealCategory("Protein", levelChoice, proteinPercentages);
                break;
            case 3:
                displayCerealCategory("Fat", levelChoice, fatPercentages);
                break;
            default:
                std::cout << "Invalid choice\n";
        }

        std::cout << "Choose again? Y/N >> ";
        std::cin >> chooseAgain;

    } while (chooseAgain == 'Y' || chooseAgain == 'y');

    outFile.close();

    return 0;
}
