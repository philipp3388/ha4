#include <bits/stdc++.h>
#include "Car.h";
#include "Order.h";
#include "Passenger.h";
#include "Driver.h";
#include "Date.h";

using namespace std;

int numberOfPassengers, numberOfDrivers;
vector <Passenger> passengerDataBase;
vector <Driver> driverDataBase;

void LoadingDataBaseOfPassengers()
{
    ifstream indbP("DataBaseOfPassengers.txt");

    int num;

    while(indbP >> num)
    {
        string name; indbP >> name;
        string password; indbP >> password;

        int n; indbP >> n;
        vector <double> marks;

        for (int i = 0; i < n; i++)
        {
            double tmpMark; indbP >> tmpMark;
            marks.push_back(tmpMark);
        }

        double rating; indbP >> rating;

        int m; indbP >> m;

        vector <Order> history;

        for (int i = 0; i < m; i++)
        {
            string from, to;
            int day, month, year, hour, minute, second;
            indbP >> from >> to >> day >> month >> year >> hour >> minute >> second;

            Date tmpTime(day, month, year, hour, minute, second);
            Order tmpOrder(from, to, tmpTime);

            history.push_back(tmpOrder);
        }

        Passenger tmpPassanger(name, password, marks, rating, history);
        passengerDataBase.push_back(tmpPassanger);
    }

    numberOfPassengers = passengerDataBase.size();
}

void LoadingDataBaseOfDrivers()
{
    ifstream indbD("DataBaseOfDrivers.txt");

    int num;

    while(indbD >> num)
    {
        string name; indbD >> name;
        string password; indbD >> password;

        int n; indbD >> n;
        vector <double> marks;

        for (int i = 0; i < n; i++)
        {
            double tmpMark; indbD >> tmpMark;
            marks.push_back(tmpMark);
        }

        double rating; indbD >> rating;

        string model; indbD >> model;
        int carType; indbD >> carType;
        int currentCoordinates; indbD >> currentCoordinates;
        string color; indbD >> color;
        string number; indbD >> number;

        Car tmpCar(model, carType, currentCoordinates, color, number);

        bool status; indbD >> status;

        Driver tmpDriver(name, password, marks, rating, tmpCar, status);
        driverDataBase.push_back(tmpDriver);
    }

    numberOfDrivers = driverDataBase.size();
}

void SavingDataBaseOfPassengers()
{
    ofstream outdbP("DataBaseOfPassengers.txt");

    for (int i = numberOfPassengers; i < passengerDataBase.size(); i++)
    {
        outdbP << i << ' ' << passengerDataBase[i].getName() << ' ' << passengerDataBase[i].getPassword() << ' '
        << passengerDataBase[i].getMarks().size() << endl;

        for (int j = 0; j < passengerDataBase[i].getMarks().size(); j++)
            outdbP << passengerDataBase[i].getMarks()[j] << ' ';

        outdbP << endl;

        outdbP << passengerDataBase[i].getRating() << ' ' << passengerDataBase[i].getHistory().size() << ' ';

        for (int j = 0; j < passengerDataBase[i].getHistory().size(); j++)
        {
            outdbP << passengerDataBase[i].getHistory()[j].getFrom() << ' '
            << passengerDataBase[i].getHistory()[j].getTo() << ' '
            << passengerDataBase[i].getHistory()[j].getDate().getDay() << ' ' << passengerDataBase[i].getHistory()[j].getDate().getMonth() << ' '
            << passengerDataBase[i].getHistory()[j].getDate().getYear() << ' ' << passengerDataBase[i].getHistory()[j].getDate().getHour() << ' '
            << passengerDataBase[i].getHistory()[j].getDate().getMinute() << ' ' << passengerDataBase[i].getHistory()[j].getDate().getSecond() << endl;
        }

        outdbP << endl;
    }

}

void SavingDataBaseOfDrivers()
{
    ofstream outdbD("DataBaseOfDrivers.txt");

    for (int i = numberOfDrivers; i < driverDataBase.size(); i++)
    {
        outdbD << i << ' ' << driverDataBase[i].getName() << ' ' << driverDataBase[i].getPassword() << ' '
        << driverDataBase[i].getMarks().size() << endl;

        for (int j = 0; j < driverDataBase[i].getMarks().size(); j++)
            outdbD << driverDataBase[i].getMarks()[j] << ' ';

        outdbD << endl;

        outdbD << driverDataBase[i].getRating() << ' ';
        outdbD << driverDataBase[i].getCar().getModel() << ' ' << driverDataBase[i].getCar().getCarType() << ' '
        << driverDataBase[i].getCar().getCurrentCoordinates() << ' '
        << driverDataBase[i].getCar().getColor() << ' '
        << driverDataBase[i].getCar().getNumber();

        outdbD << driverDataBase[i].getStatus();

        outdbD << endl;
    }
}

void passengerGateway()
{
    string login, password;

    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < passengerDataBase.size(); i++)
        if (passengerDataBase[i].getName() == login && passengerDataBase[i].getPassword() == password)
        {
            cout << "Logged in successfully" << endl;

            while(true)
            {
                cout << "Order taxi / Check History / Logout";
                string command;
            }
        }

    cout << "account does not exist" << endl;
}

void driverGateway()
{
    string login, password;

    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;

    for (int i = 0; i < driverDataBase.size(); i++)
        if (driverDataBase[i].getName() == login && driverDataBase[i].getPassword() == password)
        {
            cout << "Logged in successfully" << endl;

            while(true)
            {
                cout << "Order taxi / Check History / Logout";
                string command;
            }
        }

    cout << "account does not exist" << endl;
}

void Login()
{
    cout << "Login as who? (as a Passenger or Driver)" << endl;

    string answer; cin >> answer;

    if (answer == "Passenger") passengerGateway();
    if (answer == "Driver") driverGateway();
}

void RegisterPassenger()
{
    string login, password;

    cout << "Login: ";
    cin >> login;
    cout << "Password: ";
    cin >> password;

    Passenger tmpPassenger(login, password);

    passengerDataBase.push_back(tmpPassenger);
}

void RegisterDriver()
{
    string login, password;
    cin >> login >> password;

    //Driver tmpDriver(login, password);
}

void Register()
{
    cout << "Register as who? (as a Passenger or Driver)" << endl;

    string answer; cin >> answer;

    if (answer == "Passenger") RegisterPassenger();
    if (answer == "Driver") RegisterDriver();
}

void Gateway()
{
    cout << "Login or Register?" << endl;

    string answer; cin >> answer;

    if (answer == "Login") Login();
    if (answer == "Register") Register();
}

int main()
{
    cout << "Loading of data base, Please wait." << endl;

    LoadingDataBaseOfPassengers();
    LoadingDataBaseOfDrivers();

    Gateway();

    cout << "Saving of data" << endl;

    SavingDataBaseOfPassengers();
    SavingDataBaseOfDrivers();

    return 0;
}
