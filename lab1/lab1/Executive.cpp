#include "Executive.h"
#include "coursefile.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Executive::Executive(string file)
{
  string depart;
  int coursenumber=0;
  int studentID;
  int studentnumber=0;
  int size=0;
  ifstream inFile;
  inFile.open(file);
  inFile>>size;
  arrSize=size;
  arr = new coursefile*[size];
  for(int i=0;i<size;i++)
  {
    inFile >> depart;
    inFile >> coursenumber;
    inFile >> studentnumber;
    arr[i]= new coursefile();
    arr[i]-> setDepart(depart);
    arr[i]-> setCourseNumber(coursenumber);
    arr[i]-> setNumberofStudent(studentnumber);
    int *array = new int[studentnumber];
    for(int j=0; j< studentnumber; j++)
    {
      inFile >> studentID;
      array[j]=studentID;
    }
    arr[i]-> setStudentID(array);
  }
}

void Executive::menu()
{
  cout<<"\nSelect an option:\n";
	cout<<"1) Print all courses.\n";
	cout<<"2) Print all courses for a department.\n";
	cout<<"3) Print roster for a course.\n";
	cout<<"4) Print the largest class.\n";
  cout<<"5) Swap two classes.\n";
  cout<<"6) Print schedule for student.\n";
	cout<<"7) Exit the program.\n";
	cout<<"Enter your choice:";
}

void Executive::run()
{
  int choice = 0;
  int number = 0;
  int ugi = 0;
  int storeN = 0;
  int storeN2 = 0;
  int D1N = 0;
  int D2N = 0;
  string code = "";
  string c = "";
  string dep = "";
  string save = "";
  string keep = "y";
  string D1 = "";
  string D2 = "";
  menu();
  cin >> choice;
  while( choice != 7)
  {

    if(choice==1)
      for(int i=0; i<arrSize; i++)
      {
        c = arr[i]->getDepart() + " " + to_string(arr[i]->getCourseNumber())+'\n';
        cout << c;
      }


     if(choice==2)
     {
       do{
         cout<<"Which department are you looking for? ";
         cin>>code;
         for(int i=0; i<arrSize; i++)
         {
           if(code==arr[i]->getDepart())
           {
             dep = code + " " + to_string(arr[i]->getCourseNumber())+'\n';
             cout<<dep;
           }
         }
         cout<<"Do it again?(Y or N)";
         cin>>keep;
       }while(keep=="y"||keep=="Y");
     }

     if(choice==3)
     {
       do{
         cout<<"which course of student ID do you need?(ie:EECS 268) \n";
         cin>>code>>number;
         for(int i=0; i<arrSize; i++)
         {
           int* a = arr[i]->getStudentID();
           int s = arr[i]->getNumberofStudent();
           if(code==arr[i]->getDepart() && number== arr[i]->getCourseNumber())
           {
             for(int j=0; j<s; j++)
             {
               cout<<a[j]<<", ";
             }
             cout<<"\n";
           }
         }
         cout<<"Do it again?(Y or N)";
         cin>>keep;
       }while(keep=="y"||keep=="Y");
      }

     if(choice==4)
     {
       int roster = arr[1]->getNumberofStudent();
       for(int i=0; i<arrSize; i++)
       {
         if(arr[i]->getNumberofStudent() > roster )
         {
           roster = arr[i]->getNumberofStudent();
           save += arr[i]->getDepart()+" "+to_string(arr[i]->getCourseNumber())+" "+to_string(arr[i]->getNumberofStudent());
         }
       }
       cout<<"The largest class: "<<save<<"\n";
     }

     if(choice==5)
     {
       cout<<"Select a course:(ie:EECS 268) ";
       cin>>D1>>D1N;
       cout<<"Select another course:(ie:EECS 268) ";
       cin>>D2>>D2N;
       for(int i=0; i<arrSize; i++)
       {
         if(arr[i]->getDepart()==D1 && arr[i]->getCourseNumber()==D1N)
         {
           storeN = i;
         }
         if(arr[i]->getDepart()==D2 && arr[i]->getCourseNumber()==D2N)
         {
           storeN2 = i;
         }
       }
        arr[storeN]-> setDepart(D2);
        arr[storeN]-> setCourseNumber(D2N);
        arr[storeN2]-> setDepart(D1);
        arr[storeN2]-> setCourseNumber(D1N);
     }

    if(choice==6)
    {
      do{
        cout<<"Give me a studentID: ";
        cin>>ugi;
        for(int i=0; i<arrSize;i++)
        {
          int* b = arr[i]->getStudentID();
          for(int j=0; j<arr[i]->getNumberofStudent();j++)
          {
            if(b[j]==ugi)
            {
              cout<<arr[i]->getDepart()<<arr[i]->getCourseNumber()<<" ";
            }
          }
        }
        cout<<"\nDo it again?(Y or N)";
        cin>>keep;
      }while(keep=="y"||keep=="Y");
      cout<<"\n";
    }


    menu();
    cin>>choice;
  }
  cout<<"Goodbye!\n\n";
}

// void Executive::backup1()
// {
//   if()
// }
