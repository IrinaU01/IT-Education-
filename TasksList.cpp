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
const int N= 5;
struct TasksList
{
    char name[N];
    char priority;
    char description;
    date fulfillment_date;
    time fulfillment_time;
};
void fillValue(TasksList& task)
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

void printValue(const TaskList& task)
{
    cout << "Task name: " << task.name << "\n";
    cout << "Priority: " << task.priority << "\n";
    cout << "Description: " << task.description << "\n";
    cout << "Fulfillment Date: " << task.fulfillment_date << "\n";
    cout << "Fulfillment Time: " << task.fulfillment_time << "\n";
}

void searchByName(const TasksList* tasks, int n)
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
void searchByPriority(const TasksList* tasks, int n)
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

void searchByDescription(const TasksList* tasks, int n)
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

void sortingByPriority(TasksList* task, unsigned int n)
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

void sortingByDateAsc(TasksList* task, unsigned int n)
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
