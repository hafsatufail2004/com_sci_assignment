#include<iostream>
#include<string>

using namespace std;

class Employee
{
protected:
    /* data */
    int employeeId;
    string employeeName;
    double salary;
public:
    Employee(): employeeId(0), employeeName(""), salary(0.0){}
    
    virtual void calculateSalary() = 0;

    virtual void displaySalary(){
        cout << " Salary of " << employeeName << " is " << salary << endl;
    }
    virtual ~Employee() {}
};

class RegularEmployee : public Employee
{
private:
    /* data */
    double basicSalary;
    double allowance;
    double incomeTax;
public:
    RegularEmployee(int id, string name, double basicSalary, double allowance, double incomeTax){
        employeeId = id;
        employeeName = name;
        this->basicSalary = basicSalary;
        this->allowance = allowance;
        this->incomeTax = incomeTax;
    }

    void calculateSalary(){
        salary = basicSalary + allowance - incomeTax;
    }
    void displaySalary(){
        cout << " Salary of employee with basic income: " << basicSalary 
             << " allowance " << allowance   
             << " and income tax " << incomeTax << " is given below:\n"; 
        cout << salary << endl;  
    }       
};

class HourlyEmployee : public Employee
{
    private:
       int noOfHours;
       double hourlyRate;
    public:
       HourlyEmployee(int id, string name,int noOfHours,double hourlyRate){
           employeeId = id;
           employeeName = name;
           this->noOfHours = noOfHours;
           this->hourlyRate = hourlyRate;
       }   

       void calculateSalary(){
           salary = noOfHours * hourlyRate;
       }
       void displaySalary(){
            cout << " Salary of hourly employee with hourly rate " << hourlyRate
                 <<" and no of hours: " << noOfHours << " is givn below:\n";
            cout << salary << endl;     
       }
};

int main(){
    RegularEmployee regularEmployee(1, "Regular Employee ", 75000, 25000,8000);
    HourlyEmployee hourlyEmployee(2," Hourly Employee ",2000,15);

    regularEmployee.calculateSalary();
    regularEmployee.displaySalary();
    cout << "------------------------------------" << endl;

    hourlyEmployee.calculateSalary();
    hourlyEmployee.displaySalary();

    return 0;

}










