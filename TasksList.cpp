/*Завдання 3
Створіть додаток «Список справ». Додаток має давати можливість:
Додавати справи. Справа має:
назву;
пріоритет;
опис;
дату та час виконання.
Видаляти справи.
Редагувати справи.
Пошук справ за:
назвою;
пріоритетом;
описом;
датою та часом виконання.
Відображати список справ:
на день;
на тиждень;
на місяць.
При відображенні має бути можливість сортування:
за пріоритетом;
за датою та часом виконання.
*/
#pragma once
const int N = 32;

struct Tm {
    int tm_min=0;
    int tm_hour=0;
    int tm_mday=0;
    int tm_mon=0; 
    int tm_year=0;
    int tm_sec=0;
};

struct Task
{
    char name[N]{};
    string priority{};
    string description{};
    Tm fulfillment_time_date;
};

void printValue(const Task& task);

void fillTm(Tm& time_date)
{
    cout << "  Enter year (e.g., 2025): ";
    cin >> time_date.tm_year;
    cout << "  Enter month (1-12): ";
    cin >> time_date.tm_mon;
    cout << "  Enter Day of month (1-31): ";
    cin >> time_date.tm_mday;

    cout << "  Enter hours (0-23): ";
    cin >> time_date.tm_hour;
    cout << "  Enter minutes (0-59): ";
    cin >> time_date.tm_min;
    time_date.tm_sec = 0;
}

void fillValue(Task& task)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter task name: ";
    cin.getline(task.name, N);

    cout << "Enter priority (e.g., high or low): ";
    cin >> task.priority;

    cout << "Enter task description: ";
    cin >> task.description;
    cout << "--- Enter Fulfillment Date/Time ---\n";
    fillTm(task.fulfillment_time_date);
}

void printValue(const Task& task)
{
    const Tm& time_date = task.fulfillment_time_date;

    cout << "\n----------------------------------\n";
    cout << "Task name: " << task.name << "\n";
    cout << "Priority: " << task.priority << "\n";
    cout << "Description: " << task.description << "\n";

    cout << "Fulfillment Date: "
        << time_date.tm_year
        << "-"
        << time_date.tm_mon
        << "-"
        << time_date.tm_mday
        << "\n";

    cout << "Fulfillment Time: "
        << time_date.tm_hour
        << ":"
        << time_date.tm_min
        << ":"
        << time_date.tm_sec
        << "\n";
    cout << "----------------------------------\n";
}


void addTask(Task*& tasks, int& n)
{
    Task newTask;
    cout << "\n--- Adding a New Task ---\n";
    fillValue(newTask);

    Task* newTasks = new Task[n + 1];

    for (int i = 0; i < n; ++i) {
        newTasks[i] = tasks[i];
    }

    newTasks[n] = newTask;

    delete[] tasks;
    tasks = newTasks;
    n++;

    cout << "Task added successfully. Total tasks: " << n << endl;
}

void editTask(Task* tasks, int n)
{
    if (n == 0) {
        cout << "The task list is empty.\n";
        return;
    }

    string nameToEdit;
    cout << "\n--- Editing a Task ---\n";
    cout << "Enter the NAME of the task to edit: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nameToEdit);

    int editIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (strcmp(tasks[i].name, nameToEdit.c_str()) == 0) {
            editIndex = i;
            break;
        }
    }

    if (editIndex == -1) {
        cout << "Task with name \"" << nameToEdit << "\" not found.\n";
        return;
    }

    cout << "\nFound Task: " << tasks[editIndex].name << ". Please enter new values:\n";
    fillValue(tasks[editIndex]);

    cout << "Task updated successfully.\n";
}

void deleteTask(Task*& tasks, int& n)
{
    if (n == 0) {
        cout << "The task list is empty. Nothing to delete.\n";
        return;
    }

    string nameToDelete;
    cout << "\n--- Deleting a Task ---\n";
    cout << "Enter the name of the task to delete: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nameToDelete);

    int deleteIndex = -1;
    for (int i = 0; i < n; ++i) {
        if (strcmp(tasks[i].name, nameToDelete.c_str()) == 0) {
            deleteIndex = i;
            break;
        }
    }

    if (deleteIndex == -1) {
        cout << "Task with name \"" << nameToDelete << "\" not found.\n";
        return;
    }

    Task* newTasks = new Task[n - 1];
    int newIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (i != deleteIndex) {
            newTasks[newIndex++] = tasks[i];
        }
    }

    delete[] tasks;
    tasks = newTasks;
    n--;
    cout << "Task \"" << nameToDelete << "\" deleted successfully. Total tasks: " << n << endl;
}

int findTaskIndexByName(const Task* tasks, int n, const string& searchName) {
    for (int i = 0; i < n; i++) {
        if (strcmp(tasks[i].name, searchName.c_str()) == 0) {
            return i;
        }
    }
    return -1;
}

void searchByName(const Task* tasks, int n)
{
    string searchName;
    cout << "\n--- Search By Name ---\n";
    cout << "Enter the task name: ";
    getline(cin, searchName);

    int index = findTaskIndexByName(tasks, n, searchName);

    if (index != -1) {
        cout << "\nFound Task:\n";
        printValue(tasks[index]);
    }
    else {
        cout << "We didn't find a task with the name: " << searchName << "\n";
    }
}

void searchByPriority(const Task* tasks, int n)
{
    string searchPriority;
    bool found = false;
    cout << "\n--- Search By Priority ---\n";
    cout << "Enter the task priority: ";
    cin >> searchPriority;

    for (int i = 0; i < n; i++) {
        if (tasks[i].priority == searchPriority) {
            cout << "\nFound Tasks by priority:\n";
            printValue(tasks[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "We didn't find a task with such priority: " << searchPriority << "\n";
    }
}

void searchByDescription(const Task* tasks, int n)
{
    string searchDescription;
    bool found = false;
    cout << "\n--- Search By Description ---\n";
    cout << "Enter the task description: ";
    cin >> searchDescription;

    for (int i = 0; i < n; i++) {
        if (tasks[i].description == searchDescription) {
            cout << "\nFound Tasks by description:\n";
            printValue(tasks[i]);
            found = true;
        }
    }
    if (!found) {
        cout << "We didn't find a task with such description: " << searchDescription << "\n";
    }
}

#include <iostream>
#include <string> 
#include <cstring> 
#include <algorithm> 
#include <limits>  

using namespace std;
#include "Header.h"


int main() 
{

    int n = 0;
    Task* tasks = new Task[0];

    cout << "Welcome to the Task Manager!\n";
    int initial_n;
    cout << "Enter the initial number of tasks (0 to start empty): ";
    if (!(cin >> initial_n) || initial_n < 0) 
    {
        initial_n = 0;
    }

    if (initial_n > 0) 
    {
        for (int i = 0; i < initial_n; i++) {
            cout << "\n --- Initial Task " << i + 1 << " Setup ---\n";
            addTask(tasks, n);
        }
    }


    int choice;
    do {
        cout << "\n--- TASK MANAGER MENU ---\n";
        cout << "1. View All Tasks (" << n << ")\n";
        cout << "2. Add New Task\n";
        cout << "3. Edit Task by Name\n";
        cout << "4. Delete Task by Name\n";
        cout << "5. Search Tasks\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1; // Force invalid choice
        }

        switch (choice) {
        case 1:
            cout << "\n --- Current Tasks List ---\n";
            if (n == 0) {
                cout << "List is empty.\n";
            }
            for (int i = 0; i < n; i++) {
                printValue(tasks[i]);
            }
            break;
        case 2:
            addTask(tasks, n);
            break;
        case 3:
            editTask(tasks, n);
            break;
        case 4:
            deleteTask(tasks, n);
            break;
        case 5:
            cout << "\n  -- SEARCH SUBMENU --\n";
            cout << "  a. Search by Name\n";
            cout << "  b. Search by Priority\n";
            cout << "  c. Search by Description\n";
            cout << "  Enter search choice: ";
            char search_choice;
            cin >> search_choice;

            if (n == 0) {
                cout << "Task list is empty.\n";
                break;
            }

            switch (tolower(search_choice)) {
            case 'a': searchByName(tasks, n); break;
            case 'b': searchByPriority(tasks, n); break;
            case 'c': searchByDescription(tasks, n); break;
            default: cout << "Invalid search choice.\n";
            }
            break;
        case 0:
            cout << "Exiting Task Manager. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);
    delete[] tasks;
    return 0;
}
