#include <iostream>
#include <iomanip>

using namespace std;

struct employee {
    int ID;//4
    string name;//22
    string job;//22
    double salary;//10
    double bonus;//18
    //
};

void callFunctions(void(*func)(employee *), void(*func2)(employee *), employee *e) {
    func(e);
    func2(e);
}

void callSalary(employee *);

void CalBonus(employee *);

void displayEmployees(employee *, int, bool *);

void implementingData(bool *b, employee pEmployee[5], bool *b1);

#define  arraySize  5

int getArraySize(employee *e) {
    int counter = 0;
    for (int k = 0; k < arraySize; k++) {
        counter += !e[k].name.empty();
    }
    return counter;
}

void addEmployee(employee *e, int index) {
    printf("Please, enter the following: \n");
    printf("ID : ");
    cin >> e[index].ID;
    printf("Name : ");
    cin >> e[index].name;
    printf("job position: Manager, Engineer, Clerk\n");
    printf("Job : ");
    cin >> e[index].job;
}

int main() {
    int option, chosen;
    bool executor = true, ex = true, oneTime = false;
    struct employee employees[arraySize] = {NULL};
    employees[0] = {11, "Example", "Manager"};
    employees[1] = {26, "Example2", "Clerk"};//bonus  2.5%
//    employees[2] = {35, "Fawzy", "Engineer"};
//    employees[3] = {44, "Yasser", "Engineer"};
//    employees[4] = {53, "Medo", "Clerk"};//bonus 5%
    printf("Welcome HR employee\n");
    while (executor) {
        printf("please, Choose an option and don't exceed 5 employees\n");
        printf("1 - Add Employee\n");
        printf("2 - Display Employees\n");
        printf("3 - Replace\n");
        printf("4 - Exit\n");
        cin >> option;
        switch (option) {
            case 1: {
                if (5 > getArraySize(employees))
                    addEmployee(employees, getArraySize(employees));
                else cout << "ERROR 404, \nI Told YOU";
            }
                break;
            case 2:
                implementingData(&oneTime, employees, &ex);

                break;
            case 3: {
                cout << "Choose one from the following respectively \n";
                implementingData(&oneTime, employees, &ex);
                cout << "Replaceable :";
                cin >> chosen;
                if (--chosen < getArraySize(employees))
                    addEmployee(employees, chosen);
                else cout << "Index out of bounce\n\n";
            }
                break;
            case 4:
                executor = false;
        }
    }

    return 0;
}

void implementingData(bool *oneTime, employee employees[], bool *ex) {
    *oneTime = true;
    for (int j = 0; j < arraySize; j++) {
        if (!employees[j].name.empty()) {
            callFunctions(callSalary, CalBonus, &employees[j]);
            displayEmployees(employees, j, oneTime);
            *ex = false;
        }
    }
    cout << endl;
    if (*ex) printf("Error: 404, not found \n\n\n");
}

void tableForm() {
    cout << "|";
    for (int x = 0; x < 48; x++) {
        cout << "-";
    }
    cout << "|" << endl;
}


void displayEmployees(employee *arrayEmployees, int j, bool *oneTime) {
    if (*oneTime) {
        *oneTime = false;
        tableForm();
        cout << "| ID" << setw(10) << "Name" << setw(10) << "Job" << setw(14) << "Salary" << setw(13) << "Bonus |\n";
        tableForm();
    }
    cout << "| " << arrayEmployees[j].ID
         << setw(10) << arrayEmployees[j].name
         << setw(13) << arrayEmployees[j].job
         << setw(10) << arrayEmployees[j].salary
         << setw(11) << arrayEmployees[j].bonus << " |" << endl;
    tableForm();

}

void CalBonus(employee *e) {
    e[1].bonus = 0.025;
    e[4].bonus = 0.05;
    e->bonus = e->bonus * e->salary;
    e->salary += e->bonus;
}

void callSalary(employee *e) {
    if (e->job == "Manager") {
        e->salary = 5000;
    } else if (e->job == "Engineer") {
        e->salary = 3000;
    } else if (e->job == "Clerk") {
        e->salary = 2000;
    } else e->salary = 1000;
}