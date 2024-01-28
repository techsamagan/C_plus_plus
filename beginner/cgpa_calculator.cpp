#include <iostream>
#include <iomanip>

using namespace std;

// Function to convert letter grade to grade points
double getGradePoints(char grade) {
    switch (grade) {
        case 'A':
        case 'a':
            return 4.0;
        case 'B':
        case 'b':
            return 3.0;
        case 'C':
        case 'c':
            return 2.0;
        case 'D':
        case 'd':
            return 1.0;
        case 'F':
        case 'f':
            return 0.0;
        default:
            return -1.0; // Invalid grade
    }
}

int main() {
    int numSubjects;
    
    // Get the number of subjects
    cout << "Enter the number of subjects: ";
    cin >> numSubjects;

    if (numSubjects <= 0) {
        cout << "Invalid number of subjects. Exiting." << endl;
        return 1;
    }

    double totalCreditHours = 0.0;
    double totalGradePoints = 0.0;

    for (int i = 1; i <= numSubjects; ++i) {
        double creditHours;
        char grade;

        // Get credit hours for the subject
        cout << "Enter credit hours for subject " << i << ": ";
        cin >> creditHours;

        // Get grade for the subject
        cout << "Enter grade for subject " << i << " (A/B/C/D/F): ";
        cin >> grade;

        // Validate the grade
        double gradePoints = getGradePoints(grade);

        if (gradePoints == -1.0) {
            cout << "Invalid grade. Exiting." << endl;
            return 1;
        }

        // Update total credit hours and total grade points
        totalCreditHours += creditHours;
        totalGradePoints += (creditHours * gradePoints);
    }

    // Calculate CGPA
    double cgpa = totalGradePoints / totalCreditHours;

    // Display the result
    cout << fixed << setprecision(2);
    cout << "CGPA: " << cgpa << endl;

    return 0;
}
