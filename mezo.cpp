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


int main() {
string str = "toto";
  str[0]=  toupper(str[0]);
   cout<< str;
    return 0;
}
