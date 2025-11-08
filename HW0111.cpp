/*Реалізувати структуру «Автомобіль» (довжина, кліренс (висота посадки), об’єм двигуна, потужність
двигуна, діаметр коліс, колір, тип коробки передач). 
Створіть функції для задання значень, відображення значень,
пошуку значень.
Створити масив Автомобілів у купі.
Написати функції:
1) Пошук автомобіля по коліру
2) Сортування автомобіля по кольору

Відправити проект через github*/

const int N = 5;
struct Car
{
    char model[N];
    float weight;
    float engine_volume;
    int engine_power;
    float ground_clearance;
    int wheel_diameter;
    char gearbox_type;
    int length;
    char colour[N];
};

void fillValue(Car& car)
{
    cin.ignore();
    cout << "Enter car name/model: ";
    cin.getline(car.model, N);
    cout << "Enter length: ";
    cin >> car.length;
    cout << "Enter wheel diameter: ";
    cin >> car.wheel_diameter;
    cout << "Enter ground clearance: ";
    cin >> car.ground_clearance;
    cout << "Enter engine volume: ";
    cin >> car.engine_volume;
    cout << "Enter engine power: ";
    cin >> car.engine_power;
    cout << "Enter gearbox type: ";
    cin >> car.gearbox_type;
    cin.ignore();
    cout << "Enter car colour: ";
    cin >> car.colour;
   
}

void printValue(const Car& car)
{
    cout << "Car model: " << car.model << "\n";
    cout << "Length: " << car.length << "\n";
    cout << "Wheel diameter: " << car.wheel_diameter << "\n";
    cout << "Ground clearance: " << car.ground_clearance << "\n";
    cout << "Engine volume: " << car.engine_volume << "\n";
    cout << "Engine power: " << car.engine_power << "\n";
    cout << "Ground colour: " << car.colour << "\n";
    cout << "Gearbox type: " << car.gearbox_type << "\n";
}

void sortingByColour(Car* cars, unsigned int n)
{
    for (size_t i = 0; i < static_cast<unsigned long long>(n) - 1; i++)
    {
        for (size_t j = 0; j < static_cast<unsigned long long>(n) - 1 - i; j++)
        {
            if (strcmp(cars[j].colour, cars[j + 1].colour))
            {
                Car temp = cars[j];
                cars[j] = cars[j + 1];
                cars[j + 1] = temp;
            }
        }
    }
}

void searchByColour(const Car* cars, int n, const char* search_colour)
{
    bool found = false;
    cout << "\n--- Search results for colour: " << search_colour << " ---\n";

    for (int i = 0; i < n; i++)
    {
        if (strcmp(cars[i].colour, search_colour) == 0)
        {
            cout << "\nFound Car:\n";
            printValue(cars[i]);
            found = true;
        }
    }

    if (!found)
    {
        cout << "We didn't find a car with the colour: " << search_colour << "\n";
    }
    cout << "\n";
}

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
#include "Header.h"


int main()
{
    int n;
    cout << "Enter the number of cars (n): ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid number of cars entered or n <= 0.\n";
        return 1;
    }
    Car* cars = new Car[n];
    for (int i = 0; i < n; i++)
    {
        cout << "\n Enter data for Car " << i + 1 << "\n";
        fillValue(cars[i]);
    }
    cout << "\n Initial Car List \n";
    for (int i = 0; i < n; i++)
    {
        printValue(cars[i]);
    }
    
    cout << "\n After Sorting by Colour \n" << endl;
    sortingByColour (cars, n);
    cout << endl;

    char search_colour[N];

    cout << "Enter the colour for search: ";
    cin.getline(search_colour, N);

    searchByColour(cars, n, search_colour);
    searchByColour(cars, n, search_colour);

    for (int i = 0; i < n; i++)
    {
        printValue(cars[i]);
        cout << endl;
    }

    delete[] cars;

    return 0;
}
