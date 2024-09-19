#include<iostream>
#include<string>
#include<conio.h>
#include<Windows.h>
void main_menu();
using namespace std;

const int MAX_FLIGHTS = 100;
const int MIN_GAP_BETWEEN_LOCAL_FLIGHTS = 2;

class Admin;
class Passenger;
class PassengerPanel;
class Time;
class Flight;
class FlightSchedule;
class Time {
    int hours;
    int minutes;

public:
    Time() : hours(0), minutes(0) {}
    Time(int hours, int minutes) : hours(hours), minutes(minutes) {}
    Time(const Time& other) : hours(other.hours), minutes(other.minutes) {}

    void setTime(int hours, int minutes) {
        this->hours = hours;
        this->minutes = minutes;
    }

    int getHours() const { return hours; }
    void setHours(int hours) { this->hours = hours; }

    int getMinutes() const { return minutes; }
    void setMinutes(int minutes) { this->minutes = minutes; }

    int getTotalMinutes() const { return ((hours * 60) + minutes); }

    void display() const {
        cout << (hours < 10 ? "0" : "") << hours << ":" << (minutes < 10 ? "0" : "") << minutes;
    }
};

class Flight {
    string* airplaneId;
    string* origin;
    string* destination;
    Time* departureTime;
    Time* arrivalTime;
    int availableSeats;
    int economypassenger = 50;
    int businesspassenger = 10;
    bool* isLocal;


public:
    int flightCount = 0;
    Flight()
    {
        economypassenger = 50;
        businesspassenger = 10;
        airplaneId = new string[60];
        origin = new string[60];
        destination = new string[60];
        departureTime = new Time[60];
        arrivalTime = new Time[60];
        /*airplaneId = NULL;
        origin = NULL;
        destination = NULL;*/
        departureTime[0].setTime(1, 1);
        departureTime[1].setTime(2, 2);
        arrivalTime[0].setTime(3, 3);
        arrivalTime[1].setTime(3, 3);
        airplaneId[0] = { "123" };
        airplaneId[1] = { "456" };
        origin[0] = "Pakistan";
        origin[1] = "UAE";
        destination[0] = "UAE";
        destination[1] = "Pakistan";
        availableSeats = 60;
        isLocal = new bool[2];
        isLocal[0] = true;
        isLocal[1] = true;
        flightCount += 2;
    }
    Flight(string* airplaneId, string* origin, string* destination, Time* departureTime,
        Time* arrivalTime, int availableSeats, bool* isLocal)
        : airplaneId(airplaneId), origin(origin), destination(destination), departureTime(departureTime),
        arrivalTime(arrivalTime), availableSeats(availableSeats), isLocal(isLocal), economypassenger(50), businesspassenger(10) {}
    Flight(string airplaneid, string origin, string destination, Time departureTime, Time arrivalTime, int availableSeats, bool isLocal)
    {
        this->airplaneId = new string[60];
        this->origin = new string[60];
        this->destination = new string[60];
        this->departureTime = new Time[60];
        this->arrivalTime = new Time[60];
        this->isLocal = new bool[2];
        this->airplaneId[flightCount + 1] = airplaneid;
        this->origin[flightCount + 1] = origin;
        this->destination[flightCount + 1] = destination;
        this->departureTime[flightCount + 1] = departureTime;
        this->arrivalTime[flightCount + 1] = arrivalTime;
        this->isLocal[flightCount + 1] = isLocal;
        this->availableSeats = availableSeats;
        flightCount++;
    }
    Flight(const Flight& other)
    {
        airplaneId = new string[other.flightCount];
        origin = new string[other.flightCount];
        destination = new string[other.flightCount];
        departureTime = new Time[other.flightCount];
        arrivalTime = new Time[other.flightCount];
        isLocal = new bool[other.flightCount];
        availableSeats = other.availableSeats;
        economypassenger = other.economypassenger;
        businesspassenger = other.businesspassenger;
        flightCount = other.flightCount;

        for (int i = 0; i < flightCount; i++)
        {
            airplaneId[i] = other.airplaneId[i];
            origin[i] = other.origin[i];
            destination[i] = other.destination[i];
            departureTime[i] = other.departureTime[i];
            arrivalTime[i] = other.arrivalTime[i];
            isLocal[i] = other.isLocal[i];
        }
    }


    string* getAirplaneId() { return airplaneId; }
    string* getOrigin() { return origin; }
    string* getDestination() { return destination; }
    Time* getDepartureTime() { return departureTime; }
    Time* getArrivalTime() { return arrivalTime; }
    string getAirplaneId(int i) { return airplaneId[i]; }
    string getOrigin(int i) { return origin[i]; }
    string getDestination(int i) { return destination[i]; }
    Time getArrivalTime(int i) { return arrivalTime[i]; }
    Time getDepartureTime(int i) { return departureTime[i]; }
    int getAvailableSeats() const { return availableSeats; }
    int getflightCount() const { return flightCount; }
    bool* getIsLocal() { return isLocal; }
    bool getIsLocal(int i) { return isLocal[i]; }
    int getbpassenger() { return businesspassenger; }
    int getepassenger() { return economypassenger; }

    void setAirplaneId(string* airplaneId) { this->airplaneId = airplaneId; }
    void setOrigin(string* origin) { this->origin = origin; }
    void setDestination(string* destination) { this->destination = destination; }
    void setDepartureTime(Time* departureTime) { this->departureTime = departureTime; }
    void setArrivalTime(Time* arrivalTime) { this->arrivalTime = arrivalTime; }
    void setAvailableSeats(int availableSeats) { this->availableSeats = availableSeats; }
    void setflightCount(int flightCount) { this->flightCount = flightCount; }
    void setIsLocal(bool* isLocal) { this->isLocal = isLocal; }
    void setAirplaneId(string airplaneId, int j) { this->airplaneId[j] = airplaneId; }
    void setOrigin(string origin, int j) { this->origin[j] = origin; }
    void setDestination(string destination, int j) { this->destination[j] = destination; }
    void setDepartureTime(Time departureTime, int j) { this->departureTime[j] = departureTime; }
    void setArrivalTime(Time arrivalTime, int j) { this->arrivalTime[j] = arrivalTime; }
    void setIsLocal(bool isLocal, int j) { this->isLocal[j] = isLocal; }
    void setbpassenger(int bp) { businesspassenger = bp; }
    void setepassenger(int ep) { economypassenger = ep; }

    void display() const
    {
        for (int i = 0;i < flightCount;i++)
        {
            cout << "Airplane ID: " << this->airplaneId[i] << ", Origin: " << origin[i] << ", Destination: " << destination[i] << ", Departure Time: ";
            departureTime[i].display();
            cout << ", Arrival Time: ";
            arrivalTime[i].display();
            cout << ", Available Seats: " << availableSeats << ", Type: " << (isLocal ? "Local" : "International") << endl;
        }

    }
    void displaysearch(int j) const
    {
        for (int i = 0;airplaneId[i] != "";i++)
        {
            if (i == j)
            {
                cout << "Airplane ID: " << airplaneId[i] << ", Origin: " << origin[i] << ", Destination: " << destination[i] << ", Departure Time: ";
                departureTime[i].display();
                cout << ", Arrival Time: ";
                arrivalTime[i].display();
                cout << ", Available Seats: " << availableSeats << ", Type: " << (isLocal ? "Local" : "International") << endl;
            }
        }

    }
    ~Flight() {
        delete[] airplaneId;
        delete[] origin;
        delete[] destination;
        delete[] departureTime;
        delete[] arrivalTime;
        delete[] isLocal;
    }
};

class FlightSchedule {
private:
    Flight flights[MAX_FLIGHTS];

    int* flightDuration = new int[MAX_FLIGHTS];
public:
    FlightSchedule(){}
    FlightSchedule(const Flight* flightsArr, int* durationsArr, int flightCount)
    {
        for (int i = 0; i < flightCount; i++) {
            flights[i] = flightsArr[i];
            flightDuration[i] = durationsArr[i];
        }
    }
    FlightSchedule(const FlightSchedule& other) {
        for (int i = 0; i < MAX_FLIGHTS; i++) {
            flights[i] = other.flights[i];
            flightDuration[i] = other.flightDuration[i];
        }
    }
    bool canAddFlight(Flight& flight) {
        for (int j = 0;j < flight.getflightCount();j++)
        {
            flightDuration[j] = flight.getArrivalTime(j).getTotalMinutes() - flight.getDepartureTime(j).getTotalMinutes();
            if (flight.getIsLocal(j)) {
                for (int i = 0; i < (flights[i].getflightCount()); ++i) {
                    if (flights[i].getAirplaneId() == flight.getAirplaneId()) {
                        int gap = flight.getDepartureTime(i).getTotalMinutes() - flights[i].getArrivalTime(i).getTotalMinutes();
                        if (gap < MIN_GAP_BETWEEN_LOCAL_FLIGHTS * 60) {
                            return false;
                        }
                    }
                }
            }
            return true;
        }

    }

    int findFlightByAirplaneId(const string& airplaneId) {
        for (int i = 0; i < (flights[i].getflightCount()); i++) {
            if (flights[i].getAirplaneId(i) == airplaneId) {
                cout << "The Airplane you searched has following Flight scheduled :" << endl;
                flights[i].displaysearch(i);
                return i;
            }
        }
        return -1;
    }

    /*FlightSchedule() : flightCount(0) {}*/

    void addFlight(Flight& flight, string id, string origi, string destin, Time t1, Time t2, int seats, bool local) {
        if (flights->getflightCount() >= MAX_FLIGHTS) {
            throw runtime_error("Flight schedule is full.");
        }
        else if (!canAddFlight(flight)) {
            throw runtime_error("Cannot add flight due to scheduling constraints.");
        }
        else
        {
            flights[flights->getflightCount() + 1].setAirplaneId((id), (flights->getflightCount() + 1));
            flights[flights->getflightCount() + 1].setArrivalTime(flight.getArrivalTime(0), (flights->getflightCount() + 1));
            flights[flights->getflightCount() + 1].setAvailableSeats(flight.getAvailableSeats());
            flights[flights->getflightCount() + 1].setDepartureTime(flight.getDepartureTime(0), (flights->getflightCount() + 1));
            flights[flights->getflightCount() + 1].setDestination(flight.getDestination(0), (flights->getflightCount() + 1));
            flights[flights->getflightCount() + 1].setflightCount(flight.getflightCount());
            flights[flights->getflightCount() + 1].setIsLocal(flight.getIsLocal(0), (flights->getflightCount() + 1));
            flights[flights->getflightCount() + 1].setOrigin(flight.getOrigin(0), (flights->getflightCount() + 1));
            //cout << flights[flights->getflightCount() + 1].getAirplaneId(flights->getflightCount() + 1);
            flights->setflightCount(flights->getflightCount() + 1);
            cout << "Flight added successfully!" << endl;
        }

    }

    void displayFlights() {

        flights->display();

    }

    void searchFlights(string& keyword) {
        for (int i = 0; i < flights->getflightCount(); ++i) {
            if (flights[i].getOrigin(i) == keyword)
            {
                cout << "Following are the flights scheduled from " << keyword << " :" << endl;
                flights[i].displaysearch(i);
            }
        }

    }

    void updateFlight(Flight& updatedFlight) {
        int i = 0;
        int index = findFlightByAirplaneId(updatedFlight.getAirplaneId(i));
        if (index != -1) {
            if (canAddFlight(updatedFlight)) {
                flights[index] = updatedFlight;
                cout << "Flight updated successfully !" << endl;
            }
            else {
                throw runtime_error("Cannot update flight due to scheduling constraints.");
            }
        }
        else {
            cout << "Flight not found." << endl;
        }
    }

    void removeFlight(const string& airplaneId) {
        int index = findFlightByAirplaneId(airplaneId);
        if (index != -1) {
            
            for (int i = index; i < flights->getflightCount() - 1; i++) {
                flights[i] = flights[i + 1];
            }
            flights->setflightCount(flights->getflightCount() - 1);
        }
        else {
            throw runtime_error("Flight not found.");
        }
    }

    string searchBookFlights(string& keyword, string& key2) {
        for (int i = 0; i < flights->getflightCount(); ++i) {
            if (flights[i].getOrigin(i) == keyword && flights[i].getDestination(i)==key2)
            {
                return flights[i].getAirplaneId(i);
            }
            else
            {
                return "0";
            }
        }

    }

    bool book(int i, string type, int num)
    {
        if (flights[i].getAvailableSeats() > num)
        {
            if (type == "Economy" || type == "economy")
            {
                flights[i].setepassenger(flights[i].getepassenger() - num);
                flights[i].setAvailableSeats(flights[i].getAvailableSeats() - num);
                return true;
            }
            else if (type == "Business" || type == "business")
            {
                flights[i].setbpassenger(flights[i].getbpassenger() - num);
                flights[i].setAvailableSeats(flights[i].getAvailableSeats() - num);
                return true;
            }
            else
            {
                cout << "You entered some wron info !" << endl;
            }
        }
        else
        {
            cout << "Flight do not have required available seats !" << endl;
            cout << "Kindly select another flight or you can decrease the number of seats you want to book !" << endl;
            cout << "Thank you !" << endl;
        }
    }
    bool cancel(int i, string type, int num)
    {
            if (type == "Economy" || type == "economy")
            {
                flights[i].setepassenger(flights[i].getepassenger() + num);
                flights[i].setAvailableSeats(flights[i].getAvailableSeats() + num);
                return true;
            }
            else if (type == "Business" || type == "business")
            {
                flights[i].setbpassenger(flights[i].getbpassenger() + num);
                flights[i].setAvailableSeats(flights[i].getAvailableSeats() + num);
                return true;
            }
            else
            {
                cout << "You entered some wrong info !" << endl;
                return false;
            }
    }
    ~FlightSchedule() {
        delete[] flightDuration;
    }
};

class Admin {
    FlightSchedule f;
    string username = "Umar";
    string password = "Umar@123";
    string inquiry;
public:
    Admin(){}
    Admin(const string& username, const string& password)
        : username(username), password(password) {}
    Admin(const Admin& other)
        : f(other.f), username(other.username), password(other.password), inquiry(other.inquiry) {}

    bool login(const string& username, const string& password) const {
        return this->username == username && this->password == password;
    }

    void changeFlightSchedule() {
        int choice = 0;
        // Code for changing flight schedule
        Sleep(1000);
        system("CLS");
        cout << "The flights already present are:" << endl;
        f.displayFlights();
        Sleep(4000);
        system("CLS");
        cout << "Select option to schhedule the Flight:" << endl;
        cout << "1.   Search a Flight" << endl;
        cout << "2.   Find a Flight" << endl;
        cout << "3.   Add a Flight" << endl;
        cout << "4.   Update a Flight" << endl;
        cout << "5.   Display Flights" << endl;
        cout << "6.   Remove a Flight" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            Sleep(2000);
            system("CLS");
            string keyword;
            cout << "Enter the Departure place:" << endl;
            cin >> keyword;
            f.searchFlights(keyword);
            Sleep(2000);
            system("CLS");
        }
        break;
        case 2:
        {
            Sleep(2000);
            system("CLS");
            string id;
            cout << "Enter the id of the Plane :" << endl;
            cin >> id;
            f.findFlightByAirplaneId(id);
            Sleep(4000);
            system("CLS");
        }
        break;
        case 3:
        {
            string ID, origin, destin;
            int hour1, minute1, hour2, minute2;
            bool local;
            cout << "Enter the ID of Airplane you want to add flight of :" << endl;
            cin >> ID;
            cout << "Enter the Origin of flight :" << endl;
            cin >> origin;
            cout << "Enter the Destination of flight :" << endl;
            cin >> destin;
            cout << "Enter the Time (Hour) of flight departure:" << endl;
            cin >> hour1;
            cout << "Enter the Time (Minute) of flight departure:" << endl;
            cin >> minute1;
            cout << "Enter the Time (Hour) of flight arrival:" << endl;
            cin >> hour2;
            cout << "Enter the Time (Minute) of flight arrival:" << endl;
            cin >> minute2;
            cout << "Enter true/false if the flight is local enter 1 else enter 0:" << endl;
            cin >> local;
            Sleep(2000);
            system("CLS");
            Time t1(hour1, minute1);
            Time t2(hour2, minute2);
            Flight newflight(ID, origin, destin, t1, t2, 60, local);
            f.addFlight(newflight, ID, origin, destin, t1, t2, 60, local);
            Sleep(4000);
            system("CLS");
        }
        break;
        case 4:
        {
            string ID, origin, destin;
            int hour1, minute1, hour2, minute2;
            bool local;
            cout << "Enter the ID of Airplane you want to add flight of :" << endl;
            cin >> ID;
            cout << "Enter the Origin of flight :" << endl;
            cin >> origin;
            cout << "Enter the Destination of flight :" << endl;
            cin >> destin;
            cout << "Enter the Time (Hour) of flight departure:" << endl;
            cin >> hour1;
            cout << "Enter the Time (Minute) of flight departure:" << endl;
            cin >> minute1;
            cout << "Enter the Time (Hour) of flight arrival:" << endl;
            cin >> hour2;
            cout << "Enter the Time (Minute) of flight arrival:" << endl;
            cin >> minute2;
            cout << "Enter true/false if the flight is local enter 1 else enter 0:" << endl;
            cin >> local;
            Sleep(2000);
            system("CLS");
            Time t1(hour1, minute1);
            Time t2(hour2, minute2);
            Flight newflight(ID, origin, destin, t1, t2, 60, local);
            f.updateFlight(newflight);
            Sleep(4000);
            system("CLS");

        }
        break;
        case 5:
        {
            Sleep(1000);
            system("CLS");
            cout << "The flights scheduled are:" << endl;
            f.displayFlights();
            Sleep(4000);
            system("CLS");
        }
        break;
        case 6:
        {
            Sleep(2000);
            system("CLS");
            string id;
            cout << "Enter the id of the Plane :" << endl;
            cin >> id;
            f.removeFlight(id);
            Sleep(4000);
            system("CLS");
        }
        }
    }

    void addNewRoute() 
    {
        Sleep(2000);
        system("CLS");
        string dep, arr, ID;
        int timetaken, starttimehour, starttimeminute, endtimehour, endtimeminute;
        bool localornot;
        cout << "Enter the Airplane ID that you want to add route of: " << endl;
        cin >> ID;
        cout << "Enter the departure place :" << endl;
        cin >> dep;
        cout << "Enter the arrival place :" << endl;
        cin >> arr;
        cout << "Enter the ending time (Hours) of the flight: " << endl;
        cin >> endtimehour;
        cout << "Enter the ending time (Minutes) of the flight: " << endl;
        cin >> endtimeminute;
        /*cout << "Enter the estimated time taken to cover the route: " << endl;
        cin >> timetaken;*/
        cout << "Enter the starting time (Hours) of the flight: " << endl;
        cin >> starttimehour;
        cout << "Enter the starting time (Minutes) of the flight: " << endl;
        cin >> starttimeminute;
        cout << "Is the Flight route local or international if the flight is local enter 1 else enter 0:" << endl;
        cin >> localornot;

        Time t1(starttimehour, starttimeminute);
        Time t2(endtimehour, endtimeminute);
        Flight newflight(ID, dep, arr, t1, t2, 60, localornot);
        f.addFlight(newflight, ID, dep, arr, t1, t2, 60, localornot);
        //if(f.canAddFlight())
        cout << "New route added." << endl;
        Sleep(2000);
        system("CLS");
    }

    void updatePassengerRestrictions() {
        // Code for updating maximum number of passengers allowed on a plane
        cout << "Passenger restrictions updated." << endl;
    }

    void updateAirlineInquiry(string inq) {
        // Code for updating airline inquiry details
        inquiry = inq;
        cout << "Airline inquiry details updated." << endl;
    }
};


const int MAX_PASSENGERS = 100;  // Maximum number of passengers

class Passenger {
    string cnic;
    string name;
    int age;
    string username;
    string password;
    string accountDetails;
public:
    Passenger() {
        cnic = "";
        name = "";
        age = 0;
        username = "";
        password = "";
        accountDetails = "";
    }
    Passenger(const string& cnic, const string& name, int age, const string& username, const string& password, const string& accountDetails)
        : cnic(cnic), name(name), age(age), username(username), password(password), accountDetails(accountDetails) {}
    Passenger(const Passenger& other)
        : cnic(other.cnic), name(other.name), age(other.age),
        username(other.username), password(other.password),
        accountDetails(other.accountDetails) {}

    const string& getCNIC() const {
        return cnic;
    }

    string getName() {
        return name;
    }

    int getAge() const {
        return age;
    }

    string getUsername() {
        return username;
    }

    string getPasswordd() {
        return password;
    }

    string getPassword() {
        string password;
        char ch;
        ch = _getch();

        while (ch != '\n' && ch != '\r') {
            if (ch == '\b' || ch == 127) {
                if (password.length() > 0) {
                    cout << "\b \b";
                    password.pop_back();
                }
            }
            else {
                cout << "*";
                password.push_back(ch);
            }
            ch = _getch();
        }
        this->password = password;
        return password;
    }

    void resetPassword(const string& newPassword) {
        password = newPassword;
        cout << "Password reset successful." << endl;
    }

    void resetUsername(const string& newUsername) {
        username = newUsername;
        cout << "Username reset successful." << endl;
    }

    void display() const {
        cout << "CNIC: " << cnic << ", Name: " << name << ", Age: " << age << ", Username: " << username << ", Password: " << password << endl;
    }
};

bool VerifyFinancialDetail(const string& accountDetails) {
    // Check that the account details are valid
    // For example, we might check that the account number and routing number are both valid and match each other
    // This implementation simply returns true for any account details
    return true;
}


class PassengerPanel {
    Passenger passengers[10];
    int passengerCount;
    Passenger pass;
    Passenger confirmPassword;
    FlightSchedule fl1;
public:

    PassengerPanel() : passengerCount(0) {}
    PassengerPanel(FlightSchedule fs) : fl1(fs), passengerCount(0) {}
    PassengerPanel(const PassengerPanel& other) {
        passengerCount = other.passengerCount;
        for (int i = 0; i < passengerCount; i++) {
            passengers[i] = other.passengers[i];
        }
        pass = other.pass;
        confirmPassword = other.confirmPassword;
        fl1 = other.fl1;
    }

    bool allDigits(const string& str) {
        for (char c : str) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }

    int findPassengerByCNIC(const string& cnic) {
        for (int i = 0; i < passengerCount; i++) {
            if (passengers[i].getCNIC() == cnic) {
                return i;
            }
        }
        return -1;
    }

    bool is_lower(char c) {
        return (c >= 'a' && c <= 'z');
    }

    bool is_upper(char c) {
        return (c >= 'A' && c <= 'Z');
    }

    bool is_digit(char c) {
        return (c >= '0' && c <= '9');
    }

    bool is_special(char c) {
        return (c < '0' || (c > '9' && c < 'A') || (c > 'Z' && c < 'a') || c > 'z');
    }

    bool isPasswordValid(const string& password) {
        if (password.length() < 8) return false;

        bool hasLowercase = false;
        bool hasUppercase = false;
        bool hasDigit = false;
        bool hasSpecial = false;

        for (char c : password) {
            if (is_lower(c)) {
                hasLowercase = true;
            }
            else if (is_upper(c)) {
                hasUppercase = true;
            }
            else if (is_digit(c)) {
                hasDigit = true;
            }
            else {
                hasSpecial = true;
            }
        }
        return hasLowercase && hasUppercase && hasDigit && hasSpecial;
    }

    void registerUser() {
        // Get user identification details
        string cnic, name;
        int age;
        cout << "User Registration" << endl;
        cout << "-----------------" << endl;
        cout << "Enter CNIC (13 digits): ";
        cin >> cnic;
        if (cnic.length() != 13 || !allDigits(cnic)) {
            cout << "Invalid CNIC. Please enter a valid 13-digit CNIC." << endl;
            Sleep(1000);
            system("CLS");
            return;
        }
        if (findPassengerByCNIC(cnic) != -1) {
            cout << "This CNIC is already registered." << endl;
            Sleep(1000);
            system("CLS");
            return;
        }
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter age: ";
        cin >> age;

        // Get user account details
        string username, account;

        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password (8 characters, with at least one uppercase letter, one lowercase letter, one digit, and one special character): ";
        //password.getPassword();
        if (!isPasswordValid(pass.getPassword())) {
            cout << endl;
            cout << "Invalid password. Please enter a valid password." << endl;
            Sleep(1000);
            system("CLS");
            return;
        }
        cout << endl;
        /*while (!isPasswordValid(password.getPassword())) {
            if (!isPasswordValid(password.getPassword())) {
                cout << "Invalid password. Please enter a valid password." << endl;
                cout << "Enter again: ";
                password.getPassword();

                return;
            }
            else {
                break;
            }
        }*/

        cout << "Confirm password: ";
        confirmPassword.getPassword();
        if (pass.getPasswordd() != confirmPassword.getPasswordd()) {
            cout << endl;
            cout << "Passwords do not match. Please try again." << endl;
            Sleep(1000);
            system("CLS");
            return;
        }
        cout << endl;
        cout << "Enter account details for payments (Account Number): " << endl;
        cin >> account;
        if (!VerifyFinancialDetail(account)) {
            throw runtime_error("Account details could not be verified.");
        }
        try {
            passengers[passengerCount] = Passenger(cnic, name, age, username, pass.getPasswordd(), account);
            passengerCount += 1;
        }
        catch (const exception& e) {
            throw runtime_error("Failed to register passenger.");
        }
        // Create passenger object and add to passengers array
        passengers[passengerCount] = Passenger(cnic, name, age, username, pass.getPasswordd(), account);
        passengerCount += 1;
        cout << "Registration successful." << endl;

    }

    void registerDependent() {
        // Get adult passenger's CNIC
        string cnic;
        cout << "Dependent Registration" << endl;
        cout << "---------------------" << endl;
        cout << "Enter adult passenger's CNIC: ";
        cin >> cnic;
        int index = findPassengerByCNIC(cnic);
        if (index == -1) {
            throw runtime_error("This CNIC is not registered.");
        }

        // Get dependent identification details
        string dependentCNIC, dependentName;
        int dependentAge;
        cout << "Enter dependent's CNIC (13 digits): ";
        cin >> dependentCNIC;
        if (dependentCNIC.length() != 13 || !allDigits(dependentCNIC)) {
            throw runtime_error("Invalid CNIC. Please enter a valid 13-digit CNIC.");
            Sleep(1000);
            system("CLS");
        }
        if (findPassengerByCNIC(dependentCNIC) != -1) {
            throw runtime_error("This CNIC is already registered.");
        }
        cout << "Enter dependent's name: ";
        cin >> dependentName;
        cout << "Enter dependent's age: ";
        cin >> dependentAge;

        // Create passenger object and add to passengers array
        try {
            passengers[passengerCount] = Passenger(dependentCNIC, dependentName, dependentAge, "", "", "");
            passengerCount += 1;
        }
        catch (const exception& e) {
            throw runtime_error("Failed to register dependent.");
            Sleep(1000);
            system("CLS");
        }
        passengers[index].display();
        cout << "Dependent registration successful." << endl;
        Sleep(1000);
        system("CLS");
    }
    bool login(string name, string pass)
    {
        /*cout << name << pass;*/
        for (int i = 0;i < passengerCount;i++)
        {

            if (passengers[i].getUsername() == name && passengers[i].getPasswordd() == pass)
            {
                return true;
                break;
            }
            else
            {
                return false;
            }
        }
    }
    void book(int i,string type,int num)
    {
        fl1.book(i, type, num);
    }
    
    string searchbooking(string dep, string des)
    {
        string id= fl1.searchBookFlights(dep, des);
        return id;
    }

    int findbyid(string id)
    {
        return fl1.findFlightByAirplaneId(id);
    }

    bool cancel(int i, string type, int num)
    {
        if (fl1.cancel(i, type, num))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

void adminMain(Admin& admin) {
    // Admin login
    string username;
    Passenger p;
    string inq;
    cout << "Admin login" << endl;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    if (admin.login(username, p.getPassword())) {
        cout << endl;
        cout << "Login successful." << endl;
        Sleep(1500);
        system("CLS");
        // Admin Panel functionalities
        int choice;
        do {
            cout << "Admin Panel Menu" << endl;
            cout << "-----------------" << endl;
            cout << "1. Change flight schedule" << endl;
            cout << "2. Add new route" << endl;
            //cout << "3. Update passenger restrictions" << endl;
            cout << "3. Update airline inquiry" << endl;
            cout << "4. Logout" << endl;
            cin >> choice;

            switch (choice) {
            case 1:
                admin.changeFlightSchedule();
                break;
            case 2:
                admin.addNewRoute();
                break;
            /*case 3:
                admin.updatePassengerRestrictions();
                break;*/
            case 3:
                
                cout << "Enter the inquiry :" << endl;
                cin >> inq;
                admin.updateAirlineInquiry(inq);
                break;
            case 4:
                system("CLS");
                cout << "Logout successful." << endl;
                Sleep(1000);
                system("CLS");
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }

            cout << endl;
        } while (choice != 4);
    }
    else {
        cout << endl;
        cout << "Login failed. Incorrect username or password." << endl;
        Sleep(1000);
        system("CLS");
    }
}

double CostEstimation(int choice2, int choice3, int choice4)
{
                
                if (choice2 == 1)
                {
                    
                    if (choice3 == choice4)
                    {
                        cout << "You are already in the city!" << endl;
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 1 && choice4 == 2) || (choice3 == 2 && choice4 == 1))
                    {
                        //cout << "Your cost will be: Rs." << (1.3 * 10000) << endl;
                        return (1.3 * 10000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 1 && choice4 == 3) || (choice3 == 3 && choice4 == 1))
                    {
                        //cout << "Your cost will be: Rs." << (1.93 * 10000) << endl;
                        return (1.93 * 10000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 1 && choice4 == 4) || (choice3 == 4 && choice4 == 1))
                    {
                        //cout << "Your cost will be: Rs." << (2.25 * 10000) << endl;
                        return (2.25 * 10000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 1 && choice4 == 5) || (choice3 == 5 && choice4 == 1))
                    {
                        //cout << "Your cost will be: Rs." << (2.6 * 10000) << endl;
                        return (2.6 * 10000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 2 && choice4 == 3) || (choice3 == 3 && choice4 == 2))
                    {
                        //cout << "Your cost will be: Rs." << (1.3 * 10000) << endl;
                        return (1.3 * 10000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 2 && choice4 == 4) || (choice3 == 4 && choice4 == 2))
                    {
                        //cout << "Your cost will be: Rs." << (6.6 * 10000) << endl;
                        return (6.6 * 10000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 2 && choice4 == 5) || (choice3 == 5 && choice4 == 2))
                    {
                        //cout << "Your cost will be: Rs." << (1.6 * 10000) << endl;
                        return (1.6 * 10000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 3 && choice4 == 4) || (choice3 == 4 && choice4 == 3))
                    {
                        //cout << "Your cost will be: Rs." << (4.3 * 10000) << endl;
                        return (4.3 * 10000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 3 && choice4 == 5) || (choice3 == 5 && choice4 == 3))
                    {
                        //cout << "Your cost will be: Rs." << (1.3 * 10000) << endl;
                        return (1.3 * 10000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 4 && choice4 == 5) || (choice3 == 5 && choice4 == 4))
                    {
                        //cout << "Your cost will be: Rs." << (1.9 * 10000) << endl;
                        return (1.9 * 10000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else
                    {
                        cout << "You entered wrong option !" << endl;
                        Sleep(1000);
                        system("CLS");
                        

                    }
                }
                else if (choice2 == 2)
                {
                    
                    if (choice3 == choice4)
                    {
                        cout << "You are already in the country!" << endl;
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 1 && choice4 == 2) || (choice3 == 2 && choice4 == 1))
                    {
                        //cout << "Your cost will be: Rs." << (3.5 * 20000) << endl;
                        return (3.5 * 20000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 1 && choice4 == 3) || (choice3 == 3 && choice4 == 1))
                    {
                        //cout << "Your cost will be: Rs." << (11.38 * 20000) << endl;
                        return (11.38 * 20000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 1 && choice4 == 4) || (choice3 == 4 && choice4 == 1))
                    {
                        //cout << "Your cost will be: Rs." << (1.88 * 20000) << endl;
                        return (1.88 * 20000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 1 && choice4 == 5) || (choice3 == 5 && choice4 == 1))
                    {
                        //cout << "Your cost will be: Rs." << (2.74 * 20000) << endl;
                        return (2.74 * 20000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 2 && choice4 == 3) || (choice3 == 3 && choice4 == 2))
                    {
                        //cout << "Your cost will be: Rs." << (9.68 * 20000) << endl;
                        return (9.68 * 20000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 2 && choice4 == 4) || (choice3 == 4 && choice4 == 2))
                    {
                        //cout << "Your cost will be: Rs." << (2.7 * 20000) << endl;
                        return (2.7 * 20000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 2 && choice4 == 5) || (choice3 == 5 && choice4 == 2))
                    {
                        //cout << "Your cost will be: Rs." << (2.1 * 20000) << endl;
                        return (2.1 * 20000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 3 && choice4 == 4) || (choice3 == 4 && choice4 == 3))
                    {
                        //cout << "Your cost will be: Rs." << (12.03 * 20000) << endl;
                        return (12.03 * 20000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 3 && choice4 == 5) || (choice3 == 5 && choice4 == 3))
                    {
                        //cout << "Your cost will be: Rs." << (11.75 * 20000) << endl;
                        return (11.75 * 20000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else if ((choice3 == 4 && choice4 == 5) || (choice3 == 5 && choice4 == 4))
                    {
                        //cout << "Your cost will be: Rs." << (1.83 * 20000) << endl;
                        return (1.83 * 20000);
                        Sleep(1000);
                        system("CLS");
                        
                    }
                    else
                    {
                        cout << "You entered wrong option !" << endl;
                        Sleep(1000);
                        system("CLS");
                        

                    }
                }
                else
                {
                    cout << "You entered wrong option !" << endl;
                }
}

class Book
{
private:
    int ticket[200];
    string type[200], dep[200], des[200];
    double price[200], payment[200];
    int i[200], num[200];
    int numbooked=-1;
    string id[200];
    char c;
    bool checkpay=false;
    //FlightSchedule fl1;
public:
    Book(){}
    Book(int t[], string ty[], string d[], string de[], double pr[], double pay[], int ii[], int n[], string i[], char ch, bool cp, int nb)
    {
        for (int j = 0; j < 200; j++)
        {
            ticket[j] = t[j];
            type[j] = ty[j];
            dep[j] = d[j];
            des[j] = de[j];
            price[j] = pr[j];
            payment[j] = pay[j];
            i[j] = ii[j];
            num[j] = n[j];
            id[j] = i[j];
        }
        c = ch;
        checkpay = cp;
        numbooked = nb;
    }
    Book(const Book& other)
    {
        for (int j = 0; j < 200; j++)
        {
            ticket[j] = other.ticket[j];
            type[j] = other.type[j];
            dep[j] = other.dep[j];
            des[j] = other.des[j];
            price[j] = other.price[j];
            payment[j] = other.payment[j];
            i[j] = other.i[j];
            num[j] = other.num[j];
            id[j] = other.id[j];
        }
        c = other.c;
        checkpay = other.checkpay;
        numbooked = other.numbooked;
    }
    void book(PassengerPanel& p)
    {
        checkpay = false;
        
        
        
        Sleep(1000);
        system("CLS");
        cout << "Enter your bank balance: " << endl;
        cin >> price[numbooked + 1];
        int choice2;
        cout << "---------------" << endl;
        cout << endl;
        cout << "Enter type of Passenger: " << endl;
        cout << "1.   Local" << endl;
        cout << "2.   international" << endl;
        cin >> choice2;
        if (choice2 == 1)
        {
            int choice3;
            int choice4;
            Sleep(1000);
            system("CLS");
            cout << "Enter name of Departure City by selecting from the below menu:" << endl;
            cout << "Islamabad" << endl;
            cout << "Lahore" << endl;
            cout << "Quetta " << endl;
            cout << "Peshawar" << endl;
            cout << "Karachi" << endl;
            cin >> dep[numbooked+1];
            if (dep[numbooked + 1] == "Islamabad")
            {
                choice3 = 1;
            }
            else if (dep[numbooked + 1] == "Lahore")
            {
                choice3 = 2;
            }
            else if (dep[numbooked + 1] == "Quetta")
            {
                choice3 = 3;
            }
            else if (dep[numbooked + 1] == "Peshawar")
            {
                choice3 = 4;
            }
            else if (dep[numbooked + 1] == "Karachi")
            {
                choice3 = 5;
            }
            else
            {
                cout << "You entered wrong departure !" << endl;
                cout << "Try selecting from the menu" << endl;
                book(p);
            }
            cout << "Enter name of Destination City by selecting from the below menu:" << endl;
            cout << "Islamabad" << endl;
            cout << "Lahore" << endl;
            cout << "Quetta " << endl;
            cout << "Peshawar" << endl;
            cout << "Karachi" << endl;
            cin >> des[numbooked + 1];
            if (des[numbooked + 1] == "Islamabad")
            {
                choice4 = 1;
            }
            else if (des[numbooked + 1] == "Lahore")
            {
                choice4 = 2;
            }
            else if (des[numbooked + 1] == "Quetta")
            {
                choice4 = 3;
            }
            else if (des[numbooked + 1] == "Peshawar")
            {
                choice4 = 4;
            }
            else if (des[numbooked + 1] == "Karachi")
            {
                choice4 = 5;
                payment[numbooked + 1] = CostEstimation(choice2, choice3, choice4);
            }
            else
            {
                cout << "You entered wrong destination !" << endl;
                cout << "Try selecting from the menu" << endl;
                book(p);
            }
            
        }
        else if (choice2 == 2)
        {
            int choice3;
            int choice4;
            Sleep(1000);
            system("CLS");
            cout << "Enter name of Departure Country from the below menu:" << endl;
            cout << "Pakistan" << endl;
            cout << "Turkey" << endl;
            cout << "Canada " << endl;
            cout << "UAE" << endl;
            cout << "Saudi Arabia" << endl;
            cin >> dep[numbooked + 1];
            if (dep[numbooked + 1] == "Pakistan")
            {
                choice3 = 1;
            }
            else if (dep[numbooked + 1] == "Turkey")
            {
                choice3 = 2;
            }
            else if (dep[numbooked + 1] == "Canada")
            {
                choice3 = 3;
            }
            else if (dep[numbooked + 1] == "UAE")
            {
                choice3 = 4;
            }
            else if (dep[numbooked + 1] == "Saudi Arabia")
            {
                choice3 = 5;
            }
            else
            {
                cout << "You entered wrong departure !" << endl;
                cout << "Try selecting from the menu" << endl;
                book(p);
            }
            cout << "Enter name of Destination Country from the below menu:" << endl;
            cout << "Pakistan" << endl;
            cout << "Turkey" << endl;
            cout << "Canada " << endl;
            cout << "UAE" << endl;
            cout << "Saudi Arabia" << endl;
            cin >> des[numbooked + 1];
            if (des[numbooked + 1] == "Pakistan")
            {
                choice4 = 1;
            }
            else if (des[numbooked + 1] == "Turkey")
            {
                choice4 = 2;
            }
            else if (des[numbooked + 1] == "Canada")
            {
                choice4 = 3;
            }
            else if (des[numbooked + 1] == "UAE")
            {
                choice4 = 4;
            }
            else if (des[numbooked + 1] == "Saudi Arabia")
            {
                choice4 = 5;
            }
            else
            {
                cout << "You entered wrong destination !" << endl;
                cout << "Try selecting from the menu" << endl;
                book(p);
            }
            payment[numbooked + 1] =CostEstimation(choice2, choice3, choice4);
        }
        else
        {
            cout << "You entered wrong option !" << endl;
            book(p);
        }
        id[numbooked + 1] = p.searchbooking(dep[numbooked + 1],des[numbooked + 1]);
        if (id[numbooked + 1] == "0")
        {
            cout << "No such flight available !";
            return;
        }
        cout << "The airplane id having a flight schedule on your route is: " << endl;
        cout << id[numbooked + 1] << endl;
        cout << "Enter the type of seat you want to book (Economy or Business) :" << endl;
        cin >> type[numbooked + 1];
        cout << "Enter the number of seats you want to book :" << endl;
        cin >> num[numbooked + 1];
        i[numbooked + 1] = p.findbyid(id[numbooked + 1]);
        cout << "Your total payment will be: Rs." << payment[numbooked + 1] << endl;
        cout << "Enter (y/n) to proceed to payment " << endl;
        cin >> c;
        if (c == 'y' || c == 'Y')
        {
            if (payment[numbooked + 1] < price[numbooked + 1])
            {
                price[numbooked + 1] -= payment[numbooked + 1];
                checkpay = true;
            }
            else
            {
                cout << "You do not have enough money !" << endl;
                checkpay = false;
                return;
            }
        }
        else if (c == 'n' || c == 'N')
        {
            cout << "OK" << endl;
            return;
        }
        if (checkpay == false)
        {
            cout << "You have not paid yet !" << endl;
            book(p);
        }
        else if (checkpay == true)
        {
            p.book(i[numbooked + 1], type[numbooked + 1], num[numbooked + 1]);
            numbooked++;
            ticket[numbooked] = numbooked + 1;
            cout << "Your ticket has booked and your ticket number is: " << ticket[numbooked] << endl;
        }
    }
    void cancel(PassengerPanel& p)
    {
        int tick;
        cout << "Enter the ticket number you want to cancel ticket of: " << endl;
        cin >> tick;
        for (int j = 0;j < 200;j++)
        {
            if (ticket[j] == tick)
            {
                if (p.cancel(i[j], type[j], num[j]) == true)
                {
                    cout << "Your payment was Rs." << payment[j] << " and your balance was Rs." << price[j] << endl;
                    price[j] = (price[j] + (0.75 * payment[j]));
                    payment[j] = payment[j] - (0.25 * payment[j]);
                    cout << "Your balance is now Rs." << (price[j]) << endl;
                    cout << "25 % of your payment has been deducted !" << endl;
                    cout << "Remaining has been transferred into your balance !" << endl;
                }
            }
        }
    }
};

// Function for passenger interaction
void passengerMain(PassengerPanel& passengerPanel) {
    FlightSchedule fl;
    Book b;
    int choice;
    do {
        cout << "Passenger Panel Menu" << endl;
        cout << "---------------------" << endl;
        cout << "1. Register user" << endl;
        cout << "2. Register dependent" << endl;
        cout << "3. Login" << endl;
        cout << "4. Most visited country" << endl;
        cout << "5. Estimated Travelling Cost" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        try {
            switch (choice) {
            case 1:
            {
                Sleep(1000);
                system("CLS");
                passengerPanel.registerUser();
                Sleep(1000);
                system("CLS");
            }

            break;
            case 2:
                passengerPanel.registerDependent();
                break;
            case 3:
            {
                int choose = 0;
                Passenger p;
                string name, pass;
                Sleep(1000);
                system("CLS");
                cout << "Passenger login" << endl;
                cout << "Username: ";
                cin >> name;
                cout << "Password: ";
                pass = p.getPassword();
                if (passengerPanel.login(name, pass) == true)
                {
                    Sleep(1000);
                    system("CLS");
                    cout << endl;
                    do
                    {
                        cout << "Login successful !" << endl;
                        cout << "Select an option:" << endl;
                        cout << "1. Check Route Details" << endl;
                        cout << "2. Search a flight" << endl;
                        cout << "3. Check Cost" << endl;
                        cout << "4. Book a flight" << endl;
                        cout << "5. Cancel a flight" << endl;
                        cout << "6. Logout" << endl;
                        cin >> choose;
                        switch (choose)
                        {
                            case 1:
                            {
                                Sleep(1000);
                                system("CLS");
                                cout << "Following are the Route Details:" << endl;
                                fl.displayFlights();
                                Sleep(1000);
                                system("CLS");
                            }
                            break;
                            case 2:
                            {
                                Sleep(1000);
                                system("CLS");
                                string keyword;
                                cout << "Enter the place of departure (Current place):" << endl;
                                cin >> keyword;
                                fl.searchFlights(keyword);
                                Sleep(1000);
                                system("CLS");
                            }
                            break;
                            case 3:
                            {
                                Sleep(1000);
                                system("CLS");
                                int choice2;
                                cout << "Cost Estimation:" << endl;
                                cout << "---------------" << endl;
                                cout << endl;
                                cout << "Enter type of Passenger: " << endl;
                                cout << "1.   Local" << endl;
                                cout << "2.   international" << endl;
                                cin >> choice2;
                                if (choice2 == 1)
                                {
                                    int choice3;
                                    int choice4;
                                    Sleep(1000);
                                    system("CLS");
                                    cout << "Select Departure City:" << endl;
                                    cout << "1.   Islamabad" << endl;
                                    cout << "2.   Lahore" << endl;
                                    cout << "3.   Quetta " << endl;
                                    cout << "4.   Peshawar" << endl;
                                    cout << "5.   Karachi" << endl;
                                    cin >> choice3;
                                    cout << "Select Destination City:" << endl;
                                    cout << "1.   Islamabad" << endl;
                                    cout << "2.   Lahore" << endl;
                                    cout << "3.   Quetta " << endl;
                                    cout << "4.   Peshawar" << endl;
                                    cout << "5.   Karachi" << endl;
                                    cin >> choice4;
                                    cout << "Your cost will be Rs. " << CostEstimation(choice2, choice3, choice4);
                                }
                                else if (choice2 == 2)
                                {
                                    int choice3;
                                    int choice4;
                                    Sleep(1000);
                                    system("CLS");
                                    cout << "Select Departure Country:" << endl;
                                    cout << "1.   Pakistan" << endl;
                                    cout << "2.   Turkey" << endl;
                                    cout << "3.   Canada " << endl;
                                    cout << "4.   UAE" << endl;
                                    cout << "5.   Saudi Arabia" << endl;
                                    cin >> choice3;
                                    cout << "Select Destination Country:" << endl;
                                    cout << "1.   Pakistan" << endl;
                                    cout << "2.   Turkey" << endl;
                                    cout << "3.   Canada " << endl;
                                    cout << "4.   UAE" << endl;
                                    cout << "5.   Saudi Arabia" << endl;
                                    cin >> choice4;
                                    cout << "Your cost will be Rs. " << CostEstimation(choice2, choice3, choice4);
                                }
                                else
                                {
                                    cout << "You entered wrong option !" << endl;
                                }
                                
                                Sleep(1000);
                                system("CLS");
                            }
                            break;
                            case 4:
                            {
                                Sleep(1000);
                                system("CLS");
                                //cout << "Book" << endl;
                                b.book(passengerPanel);
                                Sleep(1000);
                                system("CLS");
                            }
                            break;
                            case 5:
                            {
                                Sleep(1000);
                                system("CLS");
                                b.cancel(passengerPanel);
                                Sleep(6000);
                                system("CLS");
                                //cout << "Cancel" << endl;
                            }
                            break;
                            case 6:
                            {
                                Sleep(1000);
                                system("CLS");
                                cout << "Logout Successful !" << endl;
                                Sleep(1000);
                                system("CLS");
                                break;
                            }
                            default:
                                cout << "Invalid choice. Please try again." << endl;
                        }
                    } while (choose != 6);
                }
                else
                {
                    cout << endl;
                    cout << "Incorrect Username or Password !" << endl;
                    Sleep(1000);
                    system("CLS");
                }

            }
            break;
            case 5:
            {
                Sleep(1000);
                system("CLS");
                int choice2;
                cout << "Cost Estimation:" << endl;
                cout << "---------------" << endl;
                cout << endl;
                cout << "Enter type of Passenger: " << endl;
                cout << "1.   Local" << endl;
                cout << "2.   international" << endl;
                cin >> choice2;
                if (choice2 == 1)
                {
                    int choice3;
                    int choice4;
                    Sleep(1000);
                    system("CLS");
                    cout << "Select Departure City:" << endl;
                    cout << "1.   Islamabad" << endl;
                    cout << "2.   Lahore" << endl;
                    cout << "3.   Quetta " << endl;
                    cout << "4.   Peshawar" << endl;
                    cout << "5.   Karachi" << endl;
                    cin >> choice3;
                    cout << "Select Destination City:" << endl;
                    cout << "1.   Islamabad" << endl;
                    cout << "2.   Lahore" << endl;
                    cout << "3.   Quetta " << endl;
                    cout << "4.   Peshawar" << endl;
                    cout << "5.   Karachi" << endl;
                    cin >> choice4;
                    cout<<"Your cost will be Rs. "<<CostEstimation(choice2, choice3, choice4);
                }
                else if (choice2 == 2)
                {
                    int choice3;
                    int choice4;
                    Sleep(1000);
                    system("CLS");
                    cout << "Select Departure Country:" << endl;
                    cout << "1.   Pakistan" << endl;
                    cout << "2.   Turkey" << endl;
                    cout << "3.   Canada " << endl;
                    cout << "4.   UAE" << endl;
                    cout << "5.   Saudi Arabia" << endl;
                    cin >> choice3;
                    cout << "Select Destination Country:" << endl;
                    cout << "1.   Pakistan" << endl;
                    cout << "2.   Turkey" << endl;
                    cout << "3.   Canada " << endl;
                    cout << "4.   UAE" << endl;
                    cout << "5.   Saudi Arabia" << endl;
                    cin >> choice4;
                    cout << "Your cost will be Rs. " << CostEstimation(choice2, choice3, choice4);
                }
                else
                {
                    cout << "You entered wrong option !" << endl;
                }
                Sleep(1000);
                system("CLS");
                
            }
            break;
            case 6:
                cout << "Exiting." << endl;
                system("CLS");
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }
        catch (const runtime_error& e) {
            cout << "Error: " << e.what() << endl;
        }

        cout << endl;
    } while (choice != 6);
}

void key() {
    cout << "Enter any key to continue........" << endl;
    _getch();
}

void displayPublicInformation()
{
    Sleep(1000);
    system("CLS");
    cout << "Welcome to NAFS Airlines!" << endl;
    cout << "We are a leading airline company that operates in five major cities of Pakistan: Islamabad, Lahore, Quetta, Peshawar, and Karachi." << endl;
    cout << "Each city has two airports located at the North and South, and NAFS has 10 airplanes in each city." << endl;
    cout << "Due to COVID-19, a maximum of 5 planes can land at a time in an airport, and passengers are seated with a gap of one seat in economy class." << endl;
    cout << "NAFS has established a network of flights in 25 countries around the globe, but due to travel bans in some countries, we abide by international travelling laws." << endl;
    cout << "We greatly value our passengers and strive to provide safe, reliable, and affordable air travel to our customers." << endl;
    cout << "Thank you for choosing NAFS Airlines for your travel needs. We look forward to serving you!" << endl;
    Sleep(3000);
    system("CLS");
    main_menu();
}

void searchFlights()
{
    //search
    FlightSchedule f;
    Sleep(2000);
    system("CLS");
    string keyword;
    cout << "Enter the Departure place:" << endl;
    cin >> keyword;
    f.searchFlights(keyword);
    Sleep(2000);
    system("CLS");
    main_menu();
}

void main_menu()
{
    Admin admin("Umar", "Umar123");
    PassengerPanel passengerPanel;

    int choice;
    do {
        cout << "Main Menu" << endl;
        cout << "---------" << endl;
        cout << "1. Admin" << endl;
        cout << "2. Passenger" << endl;
        cout << "3. Public information" << endl;
        cout << "4. Search flights" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("CLS");
            adminMain(admin);
            break;
        case 2:
            system("CLS");
            passengerMain(passengerPanel);
            break;
        case 3:
            displayPublicInformation();
            break;
        case 4:
            searchFlights();
        case 5:
            cout << "Exiting the application..." << endl;
            Sleep(1500);
            exit(0);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
    } while (choice != 3);
}

int main()
{
    key();
    system("CLS");
    main_menu();
    return 0;
}
