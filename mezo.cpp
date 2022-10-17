#include <iostream>

using namespace std;

struct employee {

    int eno = 0;
    string ename;
    string job;
    double salary = 0;
    double bonus = 0;

};

int main() {

    int i;
    employee arr[5];
    for (i = 0; i < 5; i++) {
        cout << "Number" << endl;
        cin >> arr[i].eno;
        cout << "Name" << endl;
        cin >> arr[i].ename;
        cout << "Job" << endl;
        cin >> arr[i].job;

        if (arr[i].job == "Manager") {
            arr[i].salary = 5000;
            cout << "Salary is " << arr[i].salary;
        } else if (arr[i].job == "Engineer") {
            arr[i].salary = 3000;
            cout << "Salary is " << arr[i].salary;
        } else if (arr[i].job == "Clerck") {
            arr[i].salary = 2000;
            cout << "Salary is " << arr[i].salary;
        } else {
            arr[i].salary = 1000;
            cout << "Salary is " << arr[i].salary;
        }
        cout << endl;
        arr[i].bonus = arr[i].salary * 0.12;
        cout << "Bonus =" << arr[i].bonus << endl;
        cout << endl;
        cout << "Thats Employ Number  " << i + 1 << endl << endl;
    }
    return 0;
}