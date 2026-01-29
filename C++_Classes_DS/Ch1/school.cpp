#include <iostream>


struct Course
{
    std::string courseCode;
    std::string days = "MWF";
    std::string time;
    int numCredits;
};

struct Student
{
    int age;
    Course c[6];
    int credits;
    float gpa;
};


int main()
{
    Student jane;
    jane.age = 24;
    jane.gpa = 3.4;
    std::cout << "Jane's age: " << jane.age << std::endl;
    jane.c[2].time = "11:00AM";
    int quality = 4 * jane.c[1].numCredits;
    std::cout << "Third class Time: " << jane.c[2].time << std::endl;
    Student students[25];
    students[9].c[1].days[1] = 'T';
    std::cout << "Student 10 days: " << students[9].c[1].days << std::endl;
    return 0;
}