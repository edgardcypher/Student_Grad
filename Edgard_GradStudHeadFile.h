/* 
 * File:   Edgard_GradStudHeadFile.h
 * Author: Edgard Paulin zafack
 * this file contains the prototypes of our functions and also the definition 'of our structure
 * Created on October 1, 2015, 9:14 PM
 */
using namespace std;
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include<fstream>
// definition of our structure name
struct Name {
    string lastName;
    string firstName;
};
//definition of our StoreStud
struct StoreStud {
    Name StudName;// we declare the variable of type Name that is a structure
    int idNum;// we declare the variable idnum that contains the id of student
    int* testArrayPtr;// we declare a pointer that allocated dynamically an array that contains the test score for each student
    int average;// we declare a variable that contains the average of test score for each student
    char grade;// this variable contain the grade for each student

};

#ifndef EDGARD_GRADSTUDHEADFILE_H
#define	EDGARD_GRADSTUDHEADFILE_H
//prototype of our functions
char calAverage(StoreStud &);
void display(StoreStud[], int &);
int calScore(int &, int &, StoreStud *, int &);
string CheckFrstName(int &);
string CheckLastName(int &);
void writeFile(fstream &,StoreStud *,int & );
void DisplayFileData(vector<StoreStud> &);
void getDataFromFile(fstream &file,StoreStud &student,string $c,vector<StoreStud> &st);
#endif	/* EDGARD_GRADSTUDHEADFILE_H */

