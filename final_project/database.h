#include <string>
#include <vector>
using namespace std;



class Schedule{
    private:
        int credits;
        vector<string> courses;
        int num_courses;

    public:
        Schedule();
        Schedule(int credits, vector<string> courses,int num_courses);
        void printSchedule();
        string Schedule_to_string();

};


class Student{
    private:
        string first_name;
        string last_name;
        int age;
        string year;
        Schedule sched;

    public:
        Student(); 
        Student(string first_name,string last_name,int age, string grade_level, Schedule sched);
        void printStudent();
        string Student_to_string();
};


class Database{
    public:
        vector<Student> student_list;
        void print_database();
        string database_to_string();

};