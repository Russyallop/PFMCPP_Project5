/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12

 Create a branch named Part1

Purpose:  This project continues developing Project3 and will take you through how to write code that doesn't leak as well as how to refactor. 

 Destructors

 If you didn't do Project3, write 3 UDTs below (where it asks for Copied UDTs) that have: 
        member functions,
        member variables, 
        constructors that initialize the members. 
        for() or while() loops that modify member variables
        
 Define your implementations of all functions OUTSIDE of the class. 
 Then do instruction 2)
 
 If you DID do Project 3, do instruction 1)
 
 1) Copy a few of your user-defined types (the ones with constructors and for()/while() loops from Project 3) here
 2) add destructors
        make the destructors do something like print out the name of the class.

	If you already did Chapter2 part 10 on Coliru and don't have a Project3, just grab some UDTs from your Coliru Ch2P10 submission. 
 
 3) add 2 new UDTs that use only the types you copied above.
 4) Add destructors to these 2 new types that do stuff.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 5) copy over your main() from the end of Project3 and get it to compile with the types you copied over.
        remove any code in main() that uses types you didn't copy over.
 
 6) Instantiate your 2 UDT's from step 4) in the main() function at the bottom.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

/*
 copied UDT 1:
 */

/*
 copied UDT 2:
 */

/*
 copied UDT 3:
 */

/*
 new UDT 4:
 */

/*
 new UDT 5:
 */

#include <iostream>
#include <vector>
using namespace std;

#define PASSENGER_COEFF 0.0000005
#define CAR_ON_MOTORWAY_COEFF 0.0000002
#define MOTORBIKE_ON_MOTORWAY_COEFF 0.0000006
#define LORRY_ON_MOTORWAY_COEFF 0.0000006

class Car
{
public:
    Car() : speed(0), passengers(0){}
    Car(double speed, int passengers) : speed(speed), passengers(passengers)
    {
        for(int i=0;i<passengers;i++)
        {
            passengerRiskArray.push_back(0);
        }
        cout<<"Car created"<<endl;
    }
    ~Car()
    {
        cout<<"Car destroyed"<<endl;
    }
    double getSpeed();
    void calculateAndPrintRisk();
    
private:
    int speed;
    int passengers;
    vector<double> passengerRiskArray;
    vector<double> riskCoeffArray = { 0.5, 0.7, 0.8, 0.8, 0.9};
    
};
double Car::getSpeed()
{
    return speed;
}
void Car::calculateAndPrintRisk()
{
    for(int i=0;i<passengers;i++)
    {
        passengerRiskArray[i] = riskCoeffArray[i]*speed*passengers*PASSENGER_COEFF;
        cout << "Risk to passenger " << i+1 << " is: " << passengerRiskArray[i] << " measured in fatalities per journey"<< endl;
    }
}
class Motorbike
{
public:
    Motorbike() : speed(0), passengers(0){}
    Motorbike(double speed, int passengers) : speed(speed), passengers(passengers)
    {
        for(int i=0;i<passengers;i++)
        {
            passengerRiskArray.push_back(0);
        }
        cout<<"Motorbike created"<<endl;
    }
    ~Motorbike()
    {
        cout<<"Motorbike destroyed"<<endl;
    }
    double getSpeed();
    void calculateAndPrintRisk();
    
    
private:
    int speed;
    int passengers;
    vector<double> passengerRiskArray;
    vector<double> riskCoeffArray = { 1.85, 1.95};
    
};
double Motorbike::getSpeed()
{
    return speed;
}
void Motorbike::calculateAndPrintRisk()
{
    for(int i=0;i<passengers;i++)
    {
        passengerRiskArray[i] = riskCoeffArray[i]*speed*passengers*PASSENGER_COEFF;
        cout << "Risk to passenger " << i+1 << " is: " << passengerRiskArray[i] << " measured in fatalities per journey"<<endl;
    }
}
class Lorry
{
public:
    Lorry() : speed(0), passengers(0){}
    Lorry(double speed, int passengers) : speed(speed), passengers(passengers)
    {
        for(int i=0;i<passengers;i++)
        {
            passengerRiskArray.push_back(0);
        }
        cout<<"Lorry created"<<endl;
    }
    ~Lorry()
    {
        cout<<"Lorry destroyed"<<endl;
    }
    double getSpeed();
    void calculateAndPrintRisk();

private:
    int speed;
    int passengers;
    vector<double> passengerRiskArray;
    vector<double> riskCoeffArray = { 0.2, 0.2, 0.2};
    
};
double Lorry::getSpeed()
{
    return speed;
}
void Lorry::calculateAndPrintRisk()
{
    for(int i=0;i<passengers;i++)
    {
        passengerRiskArray[i] = riskCoeffArray[i]*speed*passengers*PASSENGER_COEFF;
        cout << "Risk to passenger " << i+1 << " is: " << passengerRiskArray[i] << " measured in fatalities per journey"<<endl;
    }
}
class Motorway
{
public:

    Motorway()
    {

        cout<<"MotorWay created"<<endl;
    }
    ~Motorway()
    {
        cout<<"MotorWay destroyed"<<endl;
    }
    void addCar(Car& car);
    void addMotorBike(Motorbike& motorbike);
    void addLorry(Lorry& lorry);
    void calculateAndPrintChanceOfAccident();
    
private:

    vector<Car> carsArray;
    vector<Motorbike> motorbikesArray;
    vector<Lorry> lorriesArray;
    double chanceOfAccident;
    
};
void Motorway::addCar(Car& car)
{
    carsArray.push_back(car);
}
void Motorway::addMotorBike(Motorbike& motorbike)
{
    motorbikesArray.push_back(motorbike);
}
void Motorway::addLorry(Lorry& lorry)
{
    lorriesArray.push_back(lorry);
}
void Motorway::calculateAndPrintChanceOfAccident()
{
    double sumSpeedCars = 0;
    for(int i=0;i<carsArray.size();i++)
    {
        sumSpeedCars += carsArray[i].getSpeed();
    }
    double avgSpeedCars = sumSpeedCars/carsArray.size();
    
    double sumSpeedMotorbikes = 0;
    for(int i=0;i<motorbikesArray.size();i++)
    {
        sumSpeedMotorbikes += motorbikesArray[i].getSpeed();
    }
    double avgSpeedMotorbikes = sumSpeedMotorbikes/motorbikesArray.size();
    
    double sumSpeedLorries = 0;
    for(int i=0;i<lorriesArray.size();i++)
    {
        sumSpeedLorries += lorriesArray[i].getSpeed();
    }
    double avgSpeedLorries = sumSpeedLorries/lorriesArray.size();
    
    chanceOfAccident = avgSpeedCars*CAR_ON_MOTORWAY_COEFF +
                        avgSpeedMotorbikes*MOTORBIKE_ON_MOTORWAY_COEFF +
                        avgSpeedLorries*LORRY_ON_MOTORWAY_COEFF;
            cout << "Chance of an accident on this stretch of motorway is  " << chanceOfAccident << " measured in accidents per hour" << endl;
}
int main() {
    Car ford(70,3);
    Motorbike harley(80,2);
    Motorbike ducati(110,2);
    Lorry bedford(50,3);
    Car ferrari(90,1);
    Car vwGolf(65,5);

    ford.calculateAndPrintRisk();
    harley.calculateAndPrintRisk();
    bedford.calculateAndPrintRisk();
    
    Motorway motorway;
    motorway.addCar(ford);
    motorway.addCar(ferrari);
    motorway.addCar(vwGolf);
    motorway.addMotorBike(harley);
    motorway.addMotorBike(ducati);
    motorway.addLorry(bedford);
    motorway.calculateAndPrintChanceOfAccident();
    return 0;
}
