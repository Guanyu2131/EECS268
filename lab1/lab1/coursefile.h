#ifndef COURSEFILE_H
#define COURSEFILE_H
#include <string>
using namespace std;

class coursefile
{
private:
  string depart;
  int coursenumber;
  int studentnumber;
  int* studentID;

public:
  string getDepart();
  int getCourseNumber();
  int* getStudentID();
  int getNumberofStudent();
  void setDepart(string D);
  void setCourseNumber(int CN);
  void setStudentID(int* SI);
  void setNumberofStudent(int SN);
};
#endif
