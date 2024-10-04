#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool isCompleted;
};

vector<Task> taskList;

void addTask(string taskDescription) {
    Task newTask;
    newTask.description = taskDescription;
    newTask.isCompleted = false;
    taskList.push_back(newTask);
}

void viewTasks() {
    cout << "To-Do List:" << endl;
    for (int i = 0; i < taskList.size(); i++) {
        cout << "[" << (taskList[i].isCompleted ? "X" : " ") << "] " << taskList[i].description << endl;
    }
}

void markTaskAsCompleted(int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        taskList[taskIndex].isCompleted = true;
    }
}

void removeTask(int taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        taskList.erase(taskList.begin() + taskIndex);
    }
}

int main() {
    int choice;
    string taskDescription;
    int taskIndex;

    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                addTask(taskDescription);
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                cout << "Enter task index to mark as completed: ";
                cin >> taskIndex;
                markTaskAsCompleted(taskIndex - 1);
                break;
            case 4:
                cout << "Enter task index to remove: ";
                cin >> taskIndex;
                removeTask(taskIndex - 1);
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}