#include <iostream>
using namespace std;
class Transport //Батьківський клас
{
protected:
    string model_name;
    short year;
public:
    /*Transport()
    {
      model_name = "Default name";
      year = 0;
      cout << "I am ctor Transport\n";
    }*/
    Transport(string model_name, short year) :model_name{ model_name }, year{ year }
    {
        cout << "This is ctor Transport\n";
    }
    void move()
    {
        cout << "It moves\n";
    }
};
class Bus :public Transport //Клас-нащадок
{
    float engine_vol;
public:
    Bus(string model_name, short year, float engine_vol) :Transport(model_name, year)
    {
        this->engine_vol = engine_vol;
        cout << "This is ctor Bus\n";
    }
    void move()
    {
        cout << model_name << endl << year << endl << engine_vol << endl;
        cout << "It goes to Tallinn\n";
    }

};
int main()
{
    Bus bus{ "BMW", 2006, 2.8f };
    bus.move();
    return 0;
}
