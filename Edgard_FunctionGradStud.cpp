/*this file contains the definition of our function for 
 grade project*/
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include"Edgard_GradStudHeadFile.h"
//i am update this files
/*This function takes in parameter an array of structure and displays its content*/
void display(StoreStud tab[], int &size) {
    cout << "Student's name         Id's Student       Average          Grade" << endl;
    cout << "--------------         ------------       -------          -----" << endl;
    for (int i = 0; i < size; i++) {
        cout << right << setw(6) << tab[i].StudName.firstName;
        cout << "  " << tab[i].StudName.lastName;
        cout << "             " << tab[i].idNum;
        cout << setw(3) << "                 " << tab[i].average;
        cout << setw(3) << "                 " << tab[i].grade << endl;

    }


}

/*This function allows to write a structure of student in the text file */
void writeFile(fstream &f, StoreStud *student, int &size) {
    if (f.is_open()) {
        for (int i = 0; i < size; i++) {// we start writing in our file with some delimiter for reading the data easier
            f << student[i].StudName.firstName << "$";
            f << "  " << student[i].StudName.lastName << "$";
            f << "               " << student[i].idNum << "$";
            f << "           " << student[i].average << "$";
            f << "                 " << student[i].grade << "$" << endl;


        }
        f.close();
    } else
        cout << "Trouble to open the file";

}

/*This function initializes the a structure of student with the data from the file */
void getDataFromFile(fstream &file, StoreStud &student, string c, vector<StoreStud> &st) {
    long size;
    file.seekg(0L, ios::end);
    size = file.tellg(); //we compute the size of file to see if it has some data

    if (size > 0) {// we check if the file has some data
        file.seekp(0L, ios::beg);
        if (file.is_open()) {
            int i = 0;
            while (!file.eof()) {// we start reading the file and initializer our structure
                getline(file, c, '$');
                student.StudName.firstName = c;
                getline(file, c, '$');
                student.StudName.lastName = c;
                getline(file, c, '$');
                student.idNum = atoi(c.c_str());
                getline(file, c, '$');
                student.average = atoi(c.c_str());
                getline(file, c, '$');
                student.grade = c[17];
                st.push_back(student); // we store each student in the vector
                i++;
            }
            cout << "the date from file have been stored in structures\n";
            file.close();
            system("PAUSES");

        }
    } else {
        cout << "no data in the file\n";
        system("PAUSE");
    }

}

/*This function displays read  a vector of structure of data from file and displays its contents*/
void DisplayFileData(vector<StoreStud> &data) {
    cout << "Student's name         Id's Student       Average          Grade" << endl;
    cout << "--------------         ------------       -------          -----" << endl;
    for (int i = 0; i < data.size(); i++) {
        cout << left << setw(6) << data[i].StudName.firstName;
        cout << left;
        cout << "  " << data[i].StudName.lastName;
        cout << setw(6) << "               " << data[i].idNum;
        cout << setw(2) << "           " << data[i].average;
        cout << right << setw(6) << "          " << right << setw(6) << data[i].grade << endl;

    }


}

/*this function compute the score for get the score for each student
 from user and return the total that will be used to calculate the average*/
int calScore(int &size, int &t, StoreStud *sc, int &k) {
    sc->testArrayPtr = new int[size]; // we allocated dynamically an array the will contain the tests score for each student
    int testScore; // this variable contains the score for each student
    for (int j = 0; j < size; j++) {

        do {
            system("CLS");
            cout << "the score " << j + 1 << " is  for student " << k + 1 << " :";
            cin>> testScore;
        } while (testScore < 0);
        sc->testArrayPtr[j] = testScore; //we save each score in our pointer
        t += sc->testArrayPtr[j];

    }
    return t;
}

/*this function return the grade of the student based on the average*/
char calAverage(StoreStud &st) {
    if (st.average >= 91 && st.average <= 100)
        return 'A';
    if (st.average >= 81 && st.average <= 90)
        return 'B';
    if (st.average >= 71 && st.average <= 80)
        return 'C';
    if (st.average >= 61 && st.average <= 70)
        return 'D';
    if (st.average <= 60)
        return 'F';
    else
        return'0';

}

/*this function checks if the user capitalize the first name*/
string CheckFrstName(int &i) {
    string frsName;
    char c;
    do {
        system("CLS");
        cout << "Please enter the first Name of the student with first capitalized letter " << i + 1 << ":";
        cin>>frsName;
        c = frsName[0];
    } while (!isupper(c)); // we loop the request of first until the user type the last name with first capitalized letter
    return frsName;
}

/*This function check if the user capitalize the last name*/
string CheckLastName(int &i) {
    string lstName;
    char d;
    do {
        system("CLS");
        cout << "\nPlease enter the Last Name of the student with first capitalized letter" << i + 1 << ":";
        cin>>lstName;
        d = lstName[0];
    } while (!isupper(d));
    return lstName;
}
