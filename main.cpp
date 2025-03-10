#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;
public:
    void addTask(const string& desc) {
        tasks.push_back({desc, false});
        cout << "Task added: " << desc << endl;
    }

    void markCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed: " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void viewTasks() const {
        cout << "\nTo-Do List:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].description
                 << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    string taskDesc;
    int taskIndex;

    do {
        cout << "\n1. Add Task";
        cout << "\n2. Mark Task as Completed";
        cout << "\n3. View Tasks";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, taskDesc);
                todo.addTask(taskDesc);
                break;
            case 2:
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                todo.markCompleted(taskIndex - 1);
                break;
            case 3:
                todo.viewTasks();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
