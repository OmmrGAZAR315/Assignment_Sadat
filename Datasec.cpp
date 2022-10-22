#include <iostream>

using namespace std;
struct employee {
    int ID;//4
    string name;//22
    string job;//22
    double bonus;//18
    double salary;//10
};

int main() {
    employee employees[5];
    for (int i = 0; i < 2; ++i) {
        cout << "ID : ";
        cin >> employees[i].ID;
        cout << "Name : ";
        cin >> employees[i].name;
        cout << "Job : ";
        cin >> employees[i].job;
        employees[i].bonus = 0.23;
        if (employees[i].job == "manager") {
            employees[i].salary = 5000;
        } else if (employees[i].job == "engineer") {
            employees[i].salary = 3000;
        } else if (employees[i].job == "clerk") {
            employees[i].salary = 2000;
        } else employees[i].salary = 1000;
        employees[i].salary += employees[i].bonus * employees[i].salary;

        cout << "This Employee " << i + 1 << endl;
        cout << "Name: " << employees[i].name << endl;
        cout << "Job: " << employees[i].job << endl;
        cout << "Salary: " << employees[i].salary << endl;
        cout << "Bonus: " << employees[i].bonus << endl << endl;
    }
}