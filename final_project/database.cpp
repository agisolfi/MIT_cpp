#include <iostream>
#include <fstream>
#include "database.h"


Student::Student(){
    first_name="NA";
    last_name="NA";
    age=0;
    year="NA";

    Schedule empty_sched=Schedule();
    sched = empty_sched;
}

Student::Student(string first_name,string last_name,int age, string year,Schedule sched) {
    this->first_name = first_name;  
    this->last_name = last_name;
    this->age = age;
    this->year = year;
    this->sched = sched;
}


string Student::Student_to_string()
{
    string sched_output = sched.Schedule_to_string();
    string output = "Name: "+first_name+ " " + last_name+ " Age: " + to_string(age)+" Year: "+ year + " \nSchedule: \n"+sched_output;
    return output;
}

void Student::printStudent(){
    string output = Student_to_string();
    cout<<output;
}

Schedule::Schedule() {
    int credits = 0;
    vector<string> courses;
    int num_credits = 0;
}


Schedule::Schedule(int credits, vector<string> courses,int num_courses){
    this->credits=credits;
    this->courses=courses;
    this->num_courses=num_courses;
}

void Schedule::printSchedule(){
    cout<<Schedule_to_string();
}

string Schedule::Schedule_to_string(){
    string output = "Number of Credits: "+ to_string(credits)+"\n";
    output.append("Courses: ");
    for(int i =0;i<num_courses;i++){
        output.append(courses.at(i)+" ");
    } 
    output.append("\n");
    return output;
}

void Database::print_database(){
    for (int i=0;i<student_list.size();i++){
        cout<<"Student " + to_string(i+1) +": \n";
        student_list[i].printStudent();
        cout<<"----------------------------------";
    }
}

string Database::database_to_string(){
    string output;
    for (int i=0;i<student_list.size();i++){
        output.append("Student " + to_string(i+1) +": \n");
        output.append(student_list[i].Student_to_string());
        output.append("----------------------------------");
    }
    return output;
}

Student add_student(){
    
    string first_name;
    string last_name;
    int age;
    string year;

    cout<<"First Name: \n";
    cin>>first_name;

    cout<<"Last Name: \n";
    cin>>last_name;

    cout<<"Age: \n";
    cin>>age;

    cout<<"Year: \n";
    cin>>year;

    int credits;
    vector<string> courses;
    int num_courses;

    cout<<"Num of credits: \n";
    cin>>credits;

    cout<<"Num of courses: \n";
    cin>>num_courses;

    for(int i=0;i<num_courses;i++) {
        string ui;
        cout<<"Course "<<i+1<<": \n";
        cin>>ui;
        courses.push_back(ui);
    }

    Schedule sched = Schedule(credits,courses,num_courses);
    Student s = Student(first_name,last_name,age,year,sched);
    return s;
}

void print_db(Database db)
{
    ofstream file("database.txt");
    file << db.database_to_string();
    file.close();

}

int main(){
    bool active = true;
    Database db= Database();
    while(active==true){
        int ui;
        cout<<"What would you like to do? (Please enter an integer value) \n"<<
        "0: Add a student to the database\n" <<
        "1: Remove a student from the database \n" <<
        "2: Print out the database \n"<<
        "3: Write the database to a file \n"<<
        "4: Quit \n";


        cin>>ui;
        if(ui>4||ui<0)
            throw invalid_argument("Please input an integer value betwwen 0 and 4");
            cin>>ui;


        switch (ui)
        {
        case 0:{
            //add a student
            Student s = add_student();
            db.student_list.push_back(s);
            break;
        }
        
        case 1: {
            //remove a student
            int index;
            cout<<"Which student would you like to remove? (Integer)";
            cin>>index;
            if (index >= 0 && index < db.student_list.size())
                db.student_list.erase(db.student_list.begin()+index);
            else
                throw invalid_argument("Index out of scope");
                cin>>index;
            break;
        }
        case 2:
            {
            //print out database
            for(int i =0;i<db.student_list.size();i++){
                db.student_list.at(i).printStudent();
            }
            break;
            }

        case 3:
            //print to file
            print_db(db);
            break;

        case 4:
            //quit
            active=false;
            break;

        default:
            break;
        }
    }
}