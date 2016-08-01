/* 
 * File:   main.cpp
 * Author: Edgard Paulin zafack
 *
 * Created on October 1, 2015, 9:13 PM
 */
using namespace std;
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
#include<iomanip>
#include"Edgard_GradStudHeadFile.h"
int main(int argc, char** argv) {
    int sizeScore = 0;//this variable contains the number of test we want to register for each student
    string c;// this variable string will contain each string of data we read in the file
    int sizeStudent = 0;// this variable contain the number of student we want to grade
    vector<StoreStud>recupStud;// this variable vector contains the information from file about the student. 
    StoreStud *stud = 0,t;// we declare a pointer of type StoreStud that will point a array of StoreStud
    fstream inputFile;// we declare a variable for our file
    int total = 0;// this variable will contain the total of our score
    inputFile.open("CIT237StudentGrades.txt", ios::in);// we try to read our file to check if there are some data
    getDataFromFile(inputFile,t,c,recupStud);// this function read the data form our file and save in the variable recupStud
    do{
        system("CLS");
    cout << "\nhow many score you want to register for each student?:";
    cin>>sizeScore;// we get the number of score from user
    }while(sizeScore<0);
    do{
        system("CLS");
        cout << "\nplease how many students you want to register:";
        cin>>sizeStudent;// we get the number of student from user
    }while(sizeStudent<0);
    stud = new StoreStud[sizeStudent];// we allocated dynamically the pointer stud at the array of type StoreStud
    for (int i = 0; i < sizeStudent; i++) {
        system("CLS");
        stud[i].StudName.firstName=CheckFrstName(i);// we check if the user type the first letter of first name with capitalized letter
         stud[i].StudName.lastName=CheckLastName(i);// we check if the user type the first letter of last name with capitalized letter
        cout << "\nPlease enter the id number of the student " << i + 1 << ":";
        cin >> stud[i].idNum;
        // we use the function calScore to compute the average for each student
        stud[i].average = calScore(sizeScore, total, &stud[i], i) / sizeScore;
        stud[i].grade = calAverage(stud[i]);// we register the average grade of each student in the pointer of array
    }
    inputFile.open("CIT237StudentGrades.txt", ios::out|ios::app);//we open the file for writing
    writeFile(inputFile,stud,sizeStudent);// we write the pointer of array in the file
    
    system("CLS");
   cout<<"          The data from the file:\n";
   cout<<"          --------------------------\n";
   DisplayFileData(recupStud);// we display the content of file
    cout<<"          The new data you have just added:\n";
    cout<<"          ------------------------------------\n";
    display(stud, sizeStudent);//we display the content of our pointer of array
    delete[]stud;// we free the memory the pointer was pointed to.
    return 0;
}



