#include <iostream>

#define NUM_EMPLOYEES 4
#define WORK_DAYS 5
#define OT_RATE 1.5

struct Employee
{
    std::string last_name;
    double hourly_rate;
    double pay_stub;
    int hours_worked_per_day[WORK_DAYS];
};

void initialize(Employee* e_list){
    
    std::cout << "Initializing Employee records...\n" << std::endl;
    int empl_num = 0;

    for(int i = 0; i < 4; i++){
        std::cout << "Employee " << i+1 << std::endl;
        
        std::cout << "Please enter employee's\n" \
            << "Last name: ";
        std::cin >> e_list[i].last_name;
        

        std::cout << "Hourly rate: ";
        std::cin >> e_list[i].hourly_rate;
        
        std::cout << "Enter the hours worked each day" << std::endl;
        std::cout << "Monday: ";
        std::cin >> e_list[i].hours_worked_per_day[0];
        std::cout << "Tuesday: ";
        std::cin >> e_list[i].hours_worked_per_day[1];
        std::cout << "Wednesday: ";
        std::cin >> e_list[i].hours_worked_per_day[2];
        std::cout << "Thursday: ";
        std::cin >> e_list[i].hours_worked_per_day[3];
        std::cout << "Friday: ";
        std::cin >> e_list[i].hours_worked_per_day[4];

    }

    std::cout << "Finished initializing employee list" << std::endl;
}

void compute(Employee* empl)
{
    int total_hours_worked = 0;

    for(int i = 0; i < WORK_DAYS; i++){
        total_hours_worked += (*empl).hours_worked_per_day[i];
    }

    (*empl).pay_stub = (total_hours_worked > 40) ? \
        40*(*empl).hourly_rate + OT_RATE*(total_hours_worked-40)*(*empl).hourly_rate :  
        total_hours_worked*(*empl).hourly_rate;

}

void result(Employee* empl)
{
    std::cout << "Employee: " << (*empl).last_name << std::endl;
    std::cout << "Weekly pay stub: " << (*empl).pay_stub << std::endl;

}

int main()
{
    Employee empl_list[NUM_EMPLOYEES];
    initialize(empl_list);

    for(int i = 0; i < NUM_EMPLOYEES; i++){
        compute(&empl_list[i]);
    }

    for(int i = 0; i < NUM_EMPLOYEES; i++){
        result(&empl_list[i]);
    }

    return 0;
}