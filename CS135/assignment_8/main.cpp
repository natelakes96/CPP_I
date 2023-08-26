/*
 * Name:Nathaniel Stone, 8000617279, CS 135, assignment8
 * Description: Creates a struct and fills it in with
 *              information and then prints the info
 *              in the terminal
 * Input: user input on the terminal
 * Output: output to the terminal
 */
#include <iostream>
#include <iomanip>

using namespace std;

// initalizes the student struct
struct studentType
{
    string firstName, lastName;
    int grade;
    char letterGrade;
};

// prototyping all of the functs
studentType getStudentData();
void addLetterGrade(studentType &);
void printStudent(studentType);

int main()
{
    // gets first and last name of student
    studentType student = getStudentData();

    // fills in the letter grade
    addLetterGrade(student);

    // prints the student
    printStudent(student);
}

studentType getStudentData()
{
    // initalize student
    studentType student;

    // asks and gets first name
    cout << "Enter a first name: ";
    getline(cin, student.firstName);
    cout << endl;

    // asks and gets last name
    cout << "Enter a last name: ";
    getline(cin, student.lastName);
    cout << endl;

    // loop to get grade
    // make int data type
    int studentGRADE = 0;
    do
    {
        // checks for failure
        if (!cin)
        {
            // failure output
            cin.clear();
            cin.ignore(256, '\n');
            cout << "Error: Invalid grade" << endl
                 << endl;
        }
        else if (studentGRADE < 0 || studentGRADE > 4)
        {
            // failure output
            cout << "Error: Invalid grade" << endl
                 << endl;
        }
        // asks for grade
        cout << "Enter a grade: ";
        cin >> studentGRADE;

    } while (!cin || studentGRADE < 0 || studentGRADE > 4);
    cout << endl;

    // assigns the variable
    student.grade = studentGRADE;

    // returns new student
    return student;
}

void addLetterGrade(studentType &student)
{

    // switch to assign letter grade
    switch (student.grade)
    {
        // for f
    case 0:
        student.letterGrade = 'F';
        break;
        // for d
    case 1:
        student.letterGrade = 'D';
        break;
        // for c
    case 2:
        student.letterGrade = 'C';
        break;
        // for b
    case 3:
        student.letterGrade = 'B';
        break;
        // for a
    default:
        student.letterGrade = 'A';
    }
}

// does all of the output for printing
void printStudent(const studentType student)
{
    cout << "Data Entered" << endl
         << setw(22)
         << left << "  student.firstname"
         << right << "= " << student.firstName << endl
         //
         << setw(22)
         << left << "  student.lastName"
         << right << "= " << student.lastName << endl
         //
         << setw(22)
         << left << "  student.grade"
         << right << "= " << student.grade << endl
         //
         << setw(22)
         << left << "  student.letterGrade"
         << right << "= " << student.letterGrade;
}
