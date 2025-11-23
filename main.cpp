// ------------- FILE HEADER -------------
// Author ✅: phoenix morgan
// Assignment ✅: 7
// Date ✅: 11/23
// Citations: zybooks chapter 7


// ------------- ZYBOOKS SCORES -------------
// Chapter ✅: 7
// Participation ✅: 
// Challenge ✅:
// Labs ✅:100%


// ------------- DISCORD POSTS -------------
// https://discord.com/invite/URYKKf8YHm
// Count ✅: 1
// Links (Optional): 


// ------------- TESTING -------------
// PASS ALL GIVEN SAMPLE RUN TESTS ✅: yes
// (Optional) Additional tests count:   


// ------------- CODE -------------
#include <iostream>

using namespace std;

// Function prototypes (if any)
void welcome();
int readInt(string prompt);
double readScore(string prompt);
double assignAverage(int numAssigns);
double calcFinalScore(double assignAvg, double midterm, double finalExam);
char calcLetterGrade(double finalScore);

// Main function
// https://en.cppreference.com/w/cpp/language/main_function.html
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

const double ASSIGN_WEIGHT = 0.6;
const double MIDTERM_WEIGHT = 0.2;
const double FINAL_WEIGHT = 0.2;

int main() {
 // Function implementations (if any)

    welcome();

    int numAssignments = readInt("Enter the number of assignments (0 to 10): ");

    double assignAvg = assignAverage(numAssignments);

    double midtermScore = readScore("Enter your midterm exam score: ");
    double finalExamScore = readScore("Enter your final exam score: ");

    double finalScore = calcFinalScore(assignAvg, midtermScore, finalExamScore);
    char letter = calcLetterGrade(finalScore);

    cout << fixed << setprecision(1);
    cout << "Your Final Numeric score is " << finalScore << endl;
    cout << "Your Final Grade is " << letter << endl;
    cout << "Thank you for using my Grade Calculator!" << endl;

    return 0;
}

// Function Definitions 

void welcome() {
    cout << "Welcome to my Final Grade Calculator!" << endl;
    cout << "Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!" << endl;
    cout << "The number of assignments must be between 0 and 10." << endl;
    cout << "All scores entered must be between 0 and 4." << endl;
}

int readInt(string prompt) {
    int value;
    bool valid;

    do {
        cout << prompt;
        cin >> value;

        valid = true;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valid = false;
        }

        if (valid && (value < 0 || value > 10)) {
            valid = false;
        }

        if (!valid) {
            cout << "Illegal Value! Please try again!!" << endl;
        }

    } while (!valid);

    return value;
}

double readScore(string prompt) {
    double score;
    bool valid;

    do {
        cout << prompt;
        cin >> score;

        valid = true;

        if (!cin) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            valid = false;
        }

        if (valid && (score < 0.0 || score > 4.0)) {
            valid = false;
        }

        if (!valid) {
            cout << "Illegal Score! Please try again!" << endl;
        }

    } while (!valid);

    return score;
}

double assignAverage(int numAssigns) {
    if (numAssigns == 0) {
        return 0.0;
    }

    double sum = 0.0;

    for (int i = 1; i <= numAssigns; i++) {
        string prompt = "Enter score " + to_string(i) + ": ";
        double val = readScore(prompt);
        sum += val;
    }

    return sum / numAssigns;
}

double calcFinalScore(double assignAvg, double midterm, double finalExam) {
    return assignAvg * ASSIGN_WEIGHT +
           midterm * MIDTERM_WEIGHT +
           finalExam * FINAL_WEIGHT;
}

char calcLetterGrade(double finalScore) {
    if (finalScore >= 3.3 && finalScore <= 4.0) {
        return 'A';
    }
    else if (finalScore >= 2.8 && finalScore < 3.3) {
        return 'B';
    }
    else if (finalScore >= 2.0 && finalScore < 2.8) {
        return 'C';
    }
    else if (finalScore >= 1.2 && finalScore < 2.0) {
        return 'D';
    }
    else {
        return 'F';
    }
}



// ------------- DESIGN -------------
/* 
Program Name: Grade calculations

Program Description: a program to calculate 
the Final Calculated Score and the Letter Grade for a student in a course.

Design:
A. INPUT
Define the input variables including name data type. 
int numAssignments
double assignAverage()
double midtermScore
double finalExamScore

B. OUTPUT
Define the output variables including data types. 
double assignAvg
double finalScore
char letter

C. CALCULATIONS
Describe calculations used by algorithms in step D.  
List all formulas. 
If there are no calculations needed, state there are no calculations.

assignAvg * ASSIGN_WEIGHT +
midterm * MIDTERM_WEIGHT +
finalExam * FINAL_WEIGHT

D. LOGIC and ALGORITHMS
Design the logic of your program using pseudocode or flowcharts. 
Use conditionals, loops, functions or array constructs.
List the steps in transforming inputs into outputs. 
https://github.com/Glen-Sasek-PCC-Instructor/2025-06-22/blob/main/Pseudocode-Reference.txt

DECLARE constant ASSIGN_WEIGHT = 0.6
DECLARE constant MIDTERM_WEIGHT = 0.2
DECLARE constant FINAL_WEIGHT = 0.2

DECLARE integer numAssignments
DECLARE double assignAvg
DECLARE double midtermScore
DECLARE double finalExamScore
DECLARE double finalScore
DECLARE character letterGrade

CALL welcome

SET numAssignments = readInt("Enter the number of assignments (0 to 10): ")

SET assignAvg = assignAverage(numAssignments)

SET midtermScore = readScore("Enter your midterm exam score: ")

SET finalExamScore = readScore("Enter your final exam score: ")

SET finalScore = calcFinalScore(assignAvg, midtermScore, finalExamScore)

SET letterGrade = calcLetterGrade(finalScore)

DISPLAY "Your Final Numeric score is " + finalScore
DISPLAY "Your Final Grade is " + letterGrade
DISPLAY "Thank you for using my Grade Calculator!"

END PROGRAM

Function welcome

DISPLAY "Welcome to my Final Grade Calculator!"
DISPLAY "Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!"
DISPLAY "The number of assignments must be between 0 and 10."
DISPLAY "All scores entered must be between 0 and 4."
RETURN

Function readInt(prompt)

DECLARE integer value
DECLARE boolean valid = false

WHILE valid is false
DISPLAY prompt
INPUT value


SAMPLE RUNS
Copy from assignment document.
Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 6
Enter score 1: 3.4 
Enter score 2: 4 
Enter score 3: 2.5 
Enter score 4: 3.3
Enter score 5: 3.1
Enter score 6: 2.5
Enter your midterm exam score: 3.5
Enter your final exam score: 4
Your Final Numeric score is 3.4
Your Final Grade is A
Thank you for using my Grade Calculator!


Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 3
Enter score 1: 3 
Enter score 2: 4 
Enter score 3: 2.5 
Enter your midterm exam score: 2.5
Enter your final exam score: 2
Your Final Numeric score is 2.8
Your Final Grade is B
Thank you for using my Grade Calculator!


Welcome to my Final Grade Calculator!
Please enter the following information and I will calculate your Final Numerical Grade and Letter Grade for you!
The number of assignments must be between 0 and 10.
All scores entered must be between 0 and 4.
Enter the number of assignments (0 to 10): 12
Illegal Value! Please try again!!
Enter the number of assignments (0 to 10): 5
Enter score 1: 3.4 
Enter score 2: 4 
Enter score 3: 2.5 
Enter score 4: 5.5
Illegal Score! Please try again!
Enter score 4: 3.5
Enter score 5: 3.1
Enter your midterm exam score: 3.5
Enter your final exam score: 4
Your Final Numeric score is 3.5
Your Final Grade is A
Thank you for using my Grade Calculator!

*/