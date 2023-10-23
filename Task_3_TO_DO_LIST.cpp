#include <iostream>

#include <string>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task> &tasks, const string &description) {
    Task task;
    task.description = description;
    task.completed = false;
    tasks.push_back(task);
}

void viewTasks(const vector<Task> &tasks) {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << (i + 1) << ". " << tasks[i].description;
        if (tasks[i].completed) {
            cout << " (Completed)";
        }
        cout << endl;
    }
}

void markAsCompleted(vector<Task> &tasks, size_t taskIndex) {
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks[taskIndex].completed = true;
        cout << "Task marked as completed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(vector<Task> &tasks, size_t taskIndex) {
    if (taskIndex >= 0 && taskIndex < tasks.size()) {
        tasks.erase(tasks.begin() + taskIndex);
        cout << "Task removed." << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;

    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cin.ignore(); // Clear newline character
                string taskDescription;
                cout << "Enter the task description: ";
                getline(cin, taskDescription);
                addTask(tasks, taskDescription);
                cout << "Task added." << endl;
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                size_t taskIndex;
                cout << "Enter the task number to mark as completed: ";
                cin >> taskIndex;
                markAsCompleted(tasks, taskIndex - 1);
                break;
            }
            case 4: {
                size_t taskIndex;
                cout << "Enter the task number to remove: ";
                cin >> taskIndex;
                removeTask(tasks, taskIndex - 1);
                break;
            }
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
cout<<"******This the Third Task3******"<<endl;
    return 0;
}
