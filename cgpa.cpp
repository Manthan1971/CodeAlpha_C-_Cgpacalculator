#include <iostream>
#include <iomanip>
using namespace std;

// Function to convert grade to point
float getGradePoint(string grade) {
    if (grade == "A" || grade == "A+") return 4.0;
    else if (grade == "A-") return 3.7;
    else if (grade == "B+") return 3.3;
    else if (grade == "B") return 3.0;
    else if (grade == "B-") return 2.7;
    else if (grade == "C+") return 2.3;
    else if (grade == "C") return 2.0;
    else if (grade == "C-") return 1.7;
    else if (grade == "D+") return 1.3;
    else if (grade == "D") return 1.0;
    else return 0.0; // F
}

int main() {
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    string courseNames[50];
    string grades[50];
    float credits[50];
    float gradePoints[50];

    float totalCredits = 0, totalPoints = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nCourse #" << i + 1 << "\n";

        cout << "Course name: ";
        cin.ignore(); // flush newline
        getline(cin, courseNames[i]);

        cout << "Credit hours: ";
        cin >> credits[i];

        cout << "Grade (A, B+, C, etc.): ";
        cin >> grades[i];

        gradePoints[i] = getGradePoint(grades[i]) * credits[i];

        totalCredits += credits[i];
        totalPoints += gradePoints[i];
    }

    float cgpa = (totalCredits > 0) ? totalPoints / totalCredits : 0;

    cout << "\n--- CGPA Report ---\n";
    cout << fixed << setprecision(2);
    for (int i = 0; i < n; i++) {
        cout << courseNames[i] << ": Grade = " << grades[i]
             << ", Credits = " << credits[i]
             << ", Grade Points = " << gradePoints[i] << endl;
    }

    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nTotal Grade Points: " << totalPoints;
    cout << "\nCGPA: " << cgpa << endl;

    return 0;
}
