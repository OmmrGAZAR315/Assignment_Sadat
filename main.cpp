#include <iostream>
#include <iomanip>
#include <cstring>

#define  arraySize  5


using namespace std;

struct employee {
    int ID;//4
    string name;//22
    string job;//22
    double bonus;//18
    double salary;//10
};

string toLower(const string &charArr);

void callFunctions(void func(employee *), void func2(employee &, int), employee &e, int index);

void tableForm();

string up_LowWord(string word);

void displayEmployees(const employee &employee, bool &oneTime);

void callSalary(employee *e);

void CalBonus(employee &e, int index);

int getArraySize(employee e[]);

void implementingData(employee employees[]);

void addEmployee(employee *e, int index);

int main() {
    //bonus for second and fifth employees
    int option, chosen, i;
    bool executor = true, oneTime = true;
    struct employee employees[arraySize];
    employees[0] = {11, "ExSmAle", "maNaGeR", 0};
    employees[1] = {22, "ExAmPle2", "clErK", 0};//bonus  2.5%
    employees[2] = {33, "ExaMPlE3", "mAnAgEr", 0};//bonus  2.5%
    employees[3] = {44, "ExaMPLE4", "enGinEeR", 0};//bonus  2.5%
    employees[4] = {55, "ExAmPle5", "Clerk", 0};//bonus  2.5%
    printf("Welcome HR employee\n");
    while (executor) {
        implementingData(employees);
        printf("please, Choose an option and don't exceed 5 employees\n");
        printf("1 - Add Employee\n");
        printf("2 - Display Employees\n");
        printf("3 - Replace\n");
        printf("4 - Delete\n");
        printf("5 - Exit\n");
        cin >> option;
        switch (option) {
            case 1: {
                if (5 > getArraySize(employees))
                    addEmployee(employees, getArraySize(employees));
                else cout << "ERROR 404, \nI Told YOU\n";
            }
                break;
            case 2: {
                for (int x = 0; x < getArraySize(employees); x++)
                    displayEmployees(employees[x], oneTime);
                oneTime = true;
            }
                break;
            case 3: {
                cout << "Choose one from the following respectively \n";
                for (int x = 0; x < getArraySize(employees); x++)
                    displayEmployees(employees[x], oneTime);
                oneTime = true;
                cout << "Replaceable :";
                cin >> chosen;
                if (--chosen < getArraySize(employees))
                    addEmployee(employees, chosen);
                else cout << "Index out of bounce\n\n";
            }
                break;
            case 4: {
                for (int x = 0; x < getArraySize(employees); x++)
                    displayEmployees(employees[x], oneTime);
                oneTime = true;
                cin >> i;
                i--;
                for (; i < getArraySize(employees) - 1; ++i) {
                    employees[i].ID = employees[i + 1].ID;
                    employees[i].name = employees[i + 1].name;
                    employees[i].job = employees[i + 1].job;
                    employees[i].salary = employees[i + 1].salary;
                    employees[i].bonus = employees[i + 1].bonus;
                }
                employees[getArraySize(employees) - 1].name = "";
            }
                break;
            case 5:
                executor = false;
        }
    }
    return 0;
}

string toLower(const string &charArr) {
    string loweredWord;
    for (char eachLetter: charArr) loweredWord += tolower(eachLetter);
    return loweredWord;
}

void callFunctions(void func(employee *), void func2(employee &, int), employee &e, int index) {
    func(&e);
    func2(e, index);
}

void tableForm() {
    cout << "|";
    for (int x = 0; x < 48; x++) {
        cout << "-";
    }
    cout << "|" << endl;
}

string up_LowWord(string word) {
    word = toLower(word);
    word[0] = toupper(word[0]);
    return word;
}

void displayEmployees(const employee &employee, bool &oneTime) {
    if (oneTime) {
        oneTime = false;
        tableForm();
        cout << "| ID" << setw(10) << "Name" << setw(10) << "Job" << setw(14) << "Salary" << setw(13) << "Bonus |\n";
        tableForm();
    }
    cout << "| " << employee.ID
         << setw(10) << up_LowWord(employee.name)
         << setw(13) << up_LowWord(employee.job)
         << setw(10) << employee.salary
         << setw(11) << employee.bonus << " |" << endl;
    tableForm();

}

void CalBonus(employee &e, int index) {
    if (index == 1)
        e.bonus = 0.25;
    else if (index == 4)
        e.bonus = 0.5;
    else
        e.bonus = 0.12;

    if (e.bonus <= 0.5) {
        e.bonus = e.bonus * e.salary;
        e.salary += e.bonus;
    }
}

void callSalary(employee *e) {
    e->job = toLower(e->job);
    if (e->job == "manager") {
        e->salary = 5000;
    } else if (e->job == "engineer") {
        e->salary = 3000;
    } else if (e->job == "clerk") {
        e->salary = 2000;
    } else e->salary = 1000;
}

int getArraySize(employee e[]) {
    int counter = 0;
    for (int k = 0; k < arraySize; k++) {
        counter += !e[k].name.empty();
    }
    return counter;
}

void implementingData(employee employees[]) {
    bool ex = true;
    for (int j = 0; j < getArraySize(employees); j++) {
        if (!employees[j].name.empty()) {
            callFunctions(callSalary, CalBonus, employees[j], j);
            ex = false;
        }
    }
    cout << endl;
    if (ex) printf("Error: 404, not found \n\n\n");
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
    e[index].bonus = 0;
    e[index].salary = 0;
}