/*
Create class Student which contains:
- avg (int)
- name (string)
- Default & parameterized constructors
- Create a Custom Exception Class called AvgException which checks in the Student Constructor the value of the avg
o will throw an exception if avg is <= -1
- Create another Custom Exception Class called NameException which checks in the Student Constructor the value of the name 
o will throw an exception if name length > 15
- in main try to create object of class Student , your code should catch any exceptions and print exception message .
*/
#include <iostream>
#include <exception>
using namespace std;

class Student {
private:
    int avg;
    string name;
public:
    Student() {
        avg = 0;
        name = " ";
    }
    Student(int avg,string name) {
        this->avg=avg;
        this->name=name;
    }
    string get_name() { return name; }
    int get_avg() { return avg; }
};

class AvgException : public exception{
    const char* what() const throw() {
        return "The avg less than or equal -1";
    }
};
class NameException : public exception {
    const char* what() const throw() {
        return "The name length long than 15";
    }
};
void checks(Student &s) {
    if (s.get_avg() <= -1) throw new AvgException(); 
    if (size(s.get_name()) > 15) throw new NameException();
    else cout << "all right" << endl;
}
int main()
{
    Student s(85, "ameenajadallah");
    try
    {
        checks(s);
    }
    catch (exception *e)
    {
        cout << e->what() << endl;
    }
}