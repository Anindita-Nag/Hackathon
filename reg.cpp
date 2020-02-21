#include<iostream>
#include<fstream>
 
using namespace std;
 

fstream storage; 
 
struct student_profile{
    char FName[100];
    char LName[100];
    char reg_year[100];
    char faculty[100];
    char id[100];
    int NumberOf_courses;
    char course_Name[100];
    char course_code[100];
    int credit_hour;
    int term_one;
    int term_two;
    int term_three;
    int term_four;
    int assignment;
    int lab;
    int final_exam;
    int choice;
};  
 

student_profile student; 
 
void function_to_register(){
 cout<<"Write First Name of student: ";
 cin>>student.FName;
 cout<<"Write Last Name of student: ";
 cin>>student.LName;
 cout<<"Enter student ID:";
 cin>>student.id;
 cout<<"Write Registration registration year: ";
 cin>>student.reg_year;
 cout<<"Write Faculty name of student: ";
 cin>>student.faculty;
 cout<<" Write number of courses that student learns in this semister and register them one by one\n";
 cout<<"Number of courses:-";
 cin>> student.NumberOf_courses;
  

 for(int a=1; a<=student.NumberOf_courses; a++) {
 cout<<"Write course Name: ";
 cin>>student.course_Name;
 if(student.course_Name=="PGPJS" or student.course_Name=="Python")
 {
 	cout<<"There is no required to give the term no"<<endl;
 }
 else
 {
 	cout<<"Please enter which term you want to give the student:";
 	cin>>student.choice;
 	switch(student.choice)
 		{
 			case 1:
 				cout<<"Enter term one: ";
 				cin>>student.term_one;
 			break;
			case 2:		
 				cout<<"Enter term two: ";
 				cin>>student.term_two;
 			break;
 			case 3:
 				cout<<"Enter term three: ";
 				cin>>student.term_three;
 			break;
 			case 4:
 				cout<<"Enter term four: ";
 				cin>>student.term_four;
 		}
}
cout<<" Enter assignment no: ";
 cin>>student.assignment;
 cout<<"Enter lab no which he was joined already: ";
 cin>>student.lab;
 cout<<"Enter final exam: ";
 cin>>student.final_exam;
 storage.open("marklist.txt",ios::app) ;
   storage.write((char*)&student,sizeof(student));
   storage.close(); 
 }
} 
 
 
void grade_calculator(int totalMark) { 
    if(totalMark>=90 && totalMark<=100)
        cout<<"A+";
    else if(totalMark>=80 && totalMark<90)
        cout<<"A";
    else if(totalMark>=70 && totalMark<80)
        cout<<"B";
    else if(totalMark>=60 && totalMark<70)
        cout<<"C+";
    else if(totalMark>=50 && totalMark<60)
        cout<<"D";
    else if(totalMark>=0 && totalMark<50)
        cout<<"F";
    else
        cout<<"NG";   
    }
     


 
void seeRegistered() {    
 storage.open("marklist.txt",ios::app) ;
 storage.close();
 
 storage.open("marklist.txt",ios::in);
 storage.read((char*)&student,sizeof(student));
 
 while (storage.eof()==0) { 
  cout<<"\n\n\n";
  cout<<"  Full Name: "<<student.FName<<"  "<<student.LName<<endl;
  cout<<"  Registration Year: "<<student.reg_year<<endl;
  cout<<"  Faculty: "<<student.faculty<<endl;
  cout<<"  ***************************************************************************\n";
  cout<<"  ****************************STUDENT MARK LIST******************************\n";
  cout<<"  ***************************************************************************\n";  
  cout<<"  Subject    Term1   Term2   Term3    Term4    assmenty    Final   Total   Grade\n";
  cout<<"  ___________________________________________________________________________\n";
   
   

     for(int t=1; t<=student.NumberOf_courses; t++) {     
     int totalMark;
     totalMark=student.term_one+student.term_two+student.term_three+student.assignment+student.final_exam; 
  cout<<"   "<<student.course_Name<<"\t       "<<student.term_one<<"      "<<student.term_two<<"       "<<student.term_three<<"       "<<student.term_four<<"       "<<student.assignment<<"         "<<student.final_exam<<"       "<<totalMark<<"      "; 
     grade_calculator(totalMark);
     cout<<endl;
     storage.read((char*)&student,sizeof(student)); 
     } 
  }
storage.close();
}

 
 int main() { 
 char select;
 

 while(1) { 
  cout<<endl; cout<<endl; cout<<endl;
  cout<<endl;
  cout<<"     **********************************************\n";
  cout<<"     *  STUDENT REGISTRATION SYSTEM *\n";
  cout<<"     **********************************************\n";
  cout<<"     *\n";
  cout<<"     1.Add student data \n";
  cout<<"     2.View all student \n";
  cout<<"     :- ";
  cin>>select;
 
  switch (select) {
         case '1':
     		function_to_register();
     		cout<<"Student Registered succsesfully \n";
         break;
         case '2':
     		seeRegistered();
         break; 
        default:
            cout<<"you entered a invalid input.Please enter the correct input.";
  }
 }
 
}
