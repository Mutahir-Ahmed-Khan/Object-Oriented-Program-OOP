#include <iostream>
#include <string>
using namespace std;

class Calendar {
private:
    string months[12][31]; 
    int year;

public:
    // Constructor
    Calendar(int y) : year(y) {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 31; j++) {
                months[i][j] = "No Task"; 
            }
        }
    }

    void addTask(const std::string& task, int date, int month) {
        if (month >= 1 && month <= 12 && date >= 1 && date <= 31) {
            months[month - 1][date - 1] = task;
        } else {
            cout << "Invalid date or month.\n";
        }
    }

    void removeTask(int date, int month) {
        if (month >= 1 && month <= 12 && date >= 1 && date <= 31) {
            months[month - 1][date - 1] = "No Task";
        } else {
            cout << "Invalid date or month.\n";
        }
    }

    // Show all tasks in the calendar
    void showTasks() const {
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 31; j++) {
                if (months[i][j] != "No Task") {
                    cout << "Date: " << (j + 1) << "/" << (i + 1) << " - Task: " << months[i][j] << "\n";
                }
            }
        }
    }
};

int main() {
    Calendar myCalendar(2025);
    
    // Adding some tasks
    myCalendar.addTask("Doctor Appointment", 5, 2);
    myCalendar.addTask("Meeting with client", 10, 3);
    myCalendar.addTask("Project deadline", 15, 4);
    myCalendar.addTask("Birthday Party", 22, 6);
    myCalendar.addTask("Grocery Shopping", 12, 8);
    myCalendar.addTask("Gym Session", 30, 11);

    // Display tasks
    cout << "Tasks before removing:\n";
    myCalendar.showTasks();
    
    // Remove a task
    myCalendar.removeTask(15, 4);
    
    // Display updated tasks
    cout << "\nTasks after removing task on 15/4:\n";
    myCalendar.showTasks();
    
    return 0;
}
