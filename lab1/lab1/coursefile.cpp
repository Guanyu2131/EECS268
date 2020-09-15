#include "coursefile.h"
#include <string>
#include <iostream>
using namespace std;

string coursefile::getDepart()
{
  return(depart);
}

int coursefile::getCourseNumber()
{
  return(coursenumber);
}

int* coursefile::getStudentID()
{
  return(studentID);
}

int coursefile::getNumberofStudent()
{
  return(studentnumber);
}

void coursefile::setDepart(string D)
{
  depart=D;
}

void coursefile::setCourseNumber(int CN)
{
  coursenumber=CN;
}

void coursefile::setStudentID(int* student)
{
  studentID=student;
}

void coursefile::setNumberofStudent(int SN)
{
  studentnumber=SN;
}
