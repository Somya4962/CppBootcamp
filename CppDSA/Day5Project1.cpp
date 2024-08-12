#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Employee {
private:
    int empid;                   
    string empname;              
    string emposition;           
    double salary;              
    double benefits;             
    double deduction;            
    double Workinghrs;           

public:

    Employee(int empid, string empname, string emposition, double salary, double benefits = 0, 
    double deduction = 0, double Workinghrs = 0) {
        this->empid = empid;
        this->empname = empname;
        this->emposition = emposition;
        this->salary = salary;
        this->benefits = benefits;
        this->deduction = deduction;
        this->Workinghrs = Workinghrs;
    }

    
    void setBenefits(double health, double retirement) {
        benefits = health + retirement;
    }

    void setDeduction(double tax, double insurance) {
        deduction = tax + insurance;
    }

    void addWorking(double hrs) {
        Workinghrs += hrs;
    }

    double getGrossSalary() {
        return salary + benefits;
    }

    double getNetSalary() {
        return getGrossSalary() - deduction;
    }

    void printEmpDetails() {
        cout << "Employee ID: " << empid << endl;
        cout << "Employee Name: " << empname << endl;
        cout << "Employee Position: " << emposition << endl;
        cout << "Employee Gross Salary: " << getGrossSalary() << endl;
        cout << "Employee Net Salary: " << getNetSalary() << endl;
    }

    int getId() {
        return empid;
    }
};

class SalaryCalculator {
public:

    double calculateGrossSalary(Employee emp) {
        return emp.getGrossSalary();
    }

    double calculateNetSalary(Employee emp) {
        return emp.getNetSalary();
    }
};

class UserInterface {
public:
    // Method to display the main menu options
    void displayMenu() {
        cout << "1 -> Add Employee" << endl;
        cout << "2 -> Update Employee" << endl;
        cout << "3 -> Delete Employee" << endl;
        cout << "4 -> Calculate Employee Salary" << endl;
        cout << "5 -> Generate Employee Report" << endl;
        cout << "6 -> Mark Employee Attendance" << endl;
        cout << "7 -> Calculate Attendance Percentage" << endl;
        cout << "8 -> Exit" << endl;
    }

    int getInput() {
        int choice;
        cin >> choice;
        return choice;
    }

    void displayOutput(string &output) {
        cout << output << endl;
    }
};

class AttendanceSystem {
private:
    unordered_map<int, vector<string>> attendanceRecord;  // Map to store attendance records

public:
    // Method to mark attendance for an employee
    void markAttendance(int empId, string date) {
        attendanceRecord[empId].push_back(date);
        cout<<"Attendance marked for Employee ID"<< empId << " on " << date << endl;
    }

    // Method to calculate attendance percentage
    double calculateAttendancePercentage(int empId) {
        int totalDays = 30; // Assume a 30-day month for simplicity
        int presentDays = attendanceRecord[empId].size();

        if (totalDays == 0) return 0;
        double attendancePercentage = (presentDays / (double)totalDays) * 100;
        return attendancePercentage;
    }

    // Method to print attendance percentage
    void printAttendancePercentage(int empId) {
        double percentage = calculateAttendancePercentage(empId);
        cout << "Employee ID: " << empId << " has an attendance percentage of: " << percentage << "%" << endl;
    }
};

class PayRollSystem {
private:
    vector<Employee> emp;  
    AttendanceSystem attendanceSystem;  

public:
   
    void addEmp() {
        int empid;
        string name, position;
        double salary;

        cout << "Employee ID: " << endl;
        cin >> empid;
        cin.ignore(); 

        cout << "Enter Employee Name: " << endl;
        getline(cin, name);

        cout << "Enter Employee Position: " << endl;
        getline(cin, position);

        cout << "Employee Salary: " << endl;
        cin >> salary;

        emp.push_back(Employee(empid, name, position, salary));
        cout << "Employee added successfully!" << endl;
    }

    // Method to update an existing employee's details
    void updateEmp() {
        int empid;
        cout << "Enter the Employee ID to update: " << endl;
        cin >> empid;

        for (auto &i : emp) {
            if (i.getId() == empid) {
                double health, retirement, tax, insurance;
                cout << "Enter Health Benefits: " << endl;
                cin >> health;
                cout << "Enter Retirement Benefits: " << endl;
                cin >> retirement;
                cout << "Enter Tax Deduction: " << endl;
                cin >> tax;
                cout << "Enter Insurance Deduction: " << endl;
                cin >> insurance;

                i.setBenefits(health, retirement);
                i.setDeduction(tax, insurance);

                cout << "Employee updated successfully!" << endl;
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }

    void deleteEmp() {
        int empid;
        cout << "Enter the Employee ID to delete: " << endl;
        cin >> empid;

        for (auto it = emp.begin(); it != emp.end(); ++it) {
            if (it->getId() == empid) {
                emp.erase(it);
                cout << "Employee deleted successfully!" << endl;
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }

    void calculateSalary() {
        int id;
        cout << "Enter Employee ID to calculate Salary: " << endl;
        cin >> id;

        for (auto &i : emp) {
            if (i.getId() == id) {
                SalaryCalculator sc;
                double grossSalary = sc.calculateGrossSalary(i);
                double netSalary = sc.calculateNetSalary(i);

                cout << "Gross Salary: " << grossSalary << endl;
                cout << "Net Salary: " << netSalary << endl;
                return;
            }
        }
        cout << "Employee not found!" << endl;
    }

    void generateReport() {
        for (auto &i : emp) {
            i.printEmpDetails();
            cout << "-----------------------------------" << endl;
        }
    }

    // Method to mark attendance for an employee
    void markEmployeeAttendance() {
        int empId;
        string date;
        cout << "Enter Employee ID: " << endl;
        cin >> empId;
        cout << "Enter Date (YYYY-MM-DD): " << endl;
        cin >> date;

        attendanceSystem.markAttendance(empId, date);
    }

    // Method to calculate and display attendance percentage
    void calculateAttendancePercentage() {
        int empId;
        cout << "Enter Employee ID to calculate attendance percentage: " << endl;
        cin >> empId;

        attendanceSystem.printAttendancePercentage(empId);
    }
};

int main() {
    UserInterface ui;
    PayRollSystem ps;

    while (true) {
        ui.displayMenu();
        int choice = ui.getInput();

        switch (choice) {
            case 1:
                ps.addEmp();
                break;
            case 2:
                ps.updateEmp();
                break;
            case 3:
                ps.deleteEmp();
                break;
            case 4:
                ps.calculateSalary();
                break;
            case 5:
                ps.generateReport();
                break;
            case 6:
                ps.markEmployeeAttendance();
                break;
            case 7:
                ps.calculateAttendancePercentage();
                break;
            case 8:
                return 0;
            default:
                cout <<"Invalid choice. Please try again."<< endl;
        }
    }

    return 0;
}
