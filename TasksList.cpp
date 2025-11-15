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
const int N= 3;
struct Task
{
    char name[N];
    char priority;
    char description;
}
struct Tm {
  int tm_min;   /* Minutes: 0-59 */
  int tm_hour;  /* Hours:   0-23 */
  int tm_mday;  /* Day of month: 1-31 */
  int tm_mon;   /* Month: 0-11 */
  int tm_year;  /* Years since 1900 */
}

void fillValue(Task& task)
{
    cin.ignore();
    cout << "Enter task name: ";
    cin.getline(task.name, N);
    cout << "Enter priority (high or low): ";
    cin >> task.priority;
    cout << "Enter task description: ";
    cin >> task.description;
    cout << "Enter the date of fulfillment: ";
    cin >> task.fulfillment_date;
    cout << "Enter fulfillment time: ";
    cin >> task.fulfillment_time;
}
void fillTm(Tm& time_date)
{ 
    cout << "Enter hours: ";
    cin >> time_date.tm_hour;
    cout << "Enter minutes: ";
    cin >> time_date.tm_min;
    cout << "Enter Day of month: ";
    cin >> time_date.tm_mday;
    cout << "Enter month: ";
    cin >> time_date.tm_mon;
    cout << "Enter year: ";
    cin >> time_date.tm_year;
}
void printValue(const Task& task, const Tm& time_date)
{
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
}
void searchByName(const Task* tasks, int n)
{
    string searchName;
    bool found = false;
    cout << "Enter the task name: ";
    cin >> searchName;

    for (int i = 0; i < n; i++)
    {
        if (tasks[i].name == searchName)
        {
            cout << "\nFound Task:\n";
            printValue(tasks[i]);
            found = true;
        }
    }
    if (!found)
    {
        cout << "We didn't find a task with the name: " << searchName << "\n";
    }
    cout << "\n";
}
void searchByPriority(const Task* tasks, int n)
{
    string searchPriority;
    bool found = false;
    cout << "Enter the task priority: ";
    cin >> searchPriority;

    for (int i = 0; i < n; i++)
    {
        if (tasks[i].priority == searchPriority)
        {
            cout << "\nFound Tasks by priority:\n";
            printValue(tasks[i]);
            found = true;
        }
    }
    if (!found)
    {
        cout << "We didn't find a task with such priority: " << searchPriority << "\n";
    }
    cout << "\n";
}

void searchByDescription(const Task* tasks, int n)
{
    string searchDescription;
    bool found = false;
    cout << "Enter the task description: ";
    cin >> searchDescription;

    for (int i = 0; i < n; i++)
    {
        if (tasks[i].description == searchDescription)
        {
            cout << "\nFound Tasks by description:\n";
            printValue(tasks[i]);
            found = true;
        }
    }
    if (!found)
    {
        cout << "We didn't find a task with such description: " << searchDescription<< "\n";
    }
    cout << "\n";
}

void sortingByPriority(Task* task, unsigned int n)
{
  for (size_t i = 0; i < n - 1; i++)
  {
    for (size_t j = 0; j < n - 1 - i; j++)
    {
      if (strcmp(task[j].priority, task[j + 1].priority)==1)
      {
        swap(task[j], task[j + 1]);
      }
    
    }
  }
}

void sortingByDateAsc(Task* task, unsigned int n)
{
  for(size_t i = 0; i < n - 1; i++)
  {
    for (size_t j = 0; j < n - 1 - i; j++)
    {
      if (task[j].fulfillment_date > user[j + 1].fulfillment_date)
      {
        Task temp = task[j];
        task[j] = task[j + 1];
        task[j + 1] = task;
      }
    }
  }
}

void sortingByTimeAsc(Task* task, unsigned int n)
{
  for(size_t i = 0; i < n - 1; i++)
  {
    for (size_t j = 0; j < n - 1 - i; j++)
    {
      if (task[j].fulfillment_time > user[j + 1].fulfillment_time)
      {
        Task temp = task[j];
        task[j] = task[j + 1];
        task[j + 1] = task;
      }
    }
  }
}

#include <iostream>
#include <ctime>  // Import the ctime library
using namespace std;
 
int main () {
char task;
int time_date;
int n;
Task* task = new Task[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\n Enter task " << i + 1 << "\n";
        fillValue(task[i]);
    }
    cout << "\n Initial Tasks List \n";
    for (int i = 0; i < n; i++)
    {
        printValue(tasks[i]);
    }
  
    sortingByName (tasks, n);
    cout << endl;
    sortingByPriority(tasks, n);
    cout << endl;
    sortingByTimeAsc(tasks, n);
    cout << endl;
    sortingByDateAsc(tasks, n);
    cout << endl;
    searchByDescription(tasks, n);
    searchByName(tasks, n);
    searchByPriority(tasks, priority);
    for (int i = 0; i < n; i++)
    {
        cout << endl;
    }

    delete[] tasks;

    return 0;
}

  return 0;
}

