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
#include <string>


#define PASSENGER_COEFF 0.0000005
#define CAR_ON_MOTORWAY_COEFF 0.0000002
#define MOTORBIKE_ON_MOTORWAY_COEFF 0.0000006
#define LORRY_ON_MOTORWAY_COEFF 0.0000006

class Car
{
public:
    
    Car(std::string name_, double speed_, int passengers_) : name(name_), speed(speed_), passengers(passengers_) 
    {
        for(size_t i = 0; i < passengers; ++i)
        {
            passengerRiskArray.push_back(0);
        }
        std::cout << name << " was created" << std::endl;
    }
    ~Car()
    {
        std::cout << name << " was destroyed" << std::endl;
    }
    double getSpeed();
    void calculateAndPrintRisk();
    
private:
    std::string name{""};
    double speed{0};
    int passengers;
    std::vector<double> passengerRiskArray;
    std::vector<double> riskCoeffArray = {0.5, 0.7, 0.8, 0.8, 0.9};
    
};
double Car::getSpeed()
{
    return speed;
}
void Car::calculateAndPrintRisk()
{
    for(size_t i = 0; i < passengerRiskArray.size(); ++i)
    {
        passengerRiskArray[i] = riskCoeffArray[i] * speed * passengerRiskArray.size() * PASSENGER_COEFF;
        std::cout << "Risk to passenger " << i + 1 << " is: " << passengerRiskArray[i] << " measured in fatalities per journey"<< std::endl;
    }
}
class Motorbike
{
public:
    
    Motorbike(std::string name_, double speed_, int passengers_) : name(name_), speed(speed_), passengers(passengers_)
    {
        for(size_t i = 0; i < passengers; ++i)
        {
            passengerRiskArray.push_back(0);
        }
        std::cout << name << " was created" << std::endl;
    }
    ~Motorbike()
    {
        std::cout << name << " was destroyed" << std::endl;
    }
    double getSpeed();
    void calculateAndPrintRisk();
    
    
private:
    std::string name{""};
    double speed{0};
    int passengers;
    std::vector<double> passengerRiskArray;
    std::vector<double> riskCoeffArray = { 1.85, 1.95};
    
};
double Motorbike::getSpeed()
{
    return speed;
}
void Motorbike::calculateAndPrintRisk()
{
    for(size_t i = 0; i < passengerRiskArray.size(); ++i)
    {
        passengerRiskArray[i] = riskCoeffArray[i] * speed * passengerRiskArray.size() * PASSENGER_COEFF;
        std::cout << "Risk to passenger " << i + 1 << " is: " << passengerRiskArray[i] << " measured in fatalities per journey"<< std::endl;
    }
}
class Lorry
{
public:
    
    Lorry(std::string name_, double speed_, int passengers_) : name(name_), speed(speed_), passengers(passengers_)
    {
        for(size_t i = 0; i < passengers; ++i)
        {
            passengerRiskArray.push_back(0);
        }
        std::cout << name << " was created" << std::endl;
    }
    ~Lorry()
    {
        std::cout << name << " was destroyed" << std::endl;
    }
    double getSpeed();
    void calculateAndPrintRisk();

private:
    std::string name{""};
    double speed{0};
    int passengers;
    std::vector<double> passengerRiskArray;
    std::vector<double> riskCoeffArray = { 0.2, 0.2, 0.2};
    
};
double Lorry::getSpeed()
{
    return speed;
}
void Lorry::calculateAndPrintRisk()
{
    for(size_t i = 0; i < passengerRiskArray.size(); ++i)
    {
        passengerRiskArray[i] = riskCoeffArray[i] * speed * passengerRiskArray.size() * PASSENGER_COEFF;
        std::cout << "Risk to passenger " << i + 1 << " is: " << passengerRiskArray[i] << " measured in fatalities per journey"<< std::endl;
    }
}
class Motorway
{
public:

    Motorway()
    {

        std::cout << "MotorWay created" << std::endl;
    }
    ~Motorway()
    {
        std::cout << "MotorWay destroyed" << std::endl;
    }
    void addCar(Car* car);
    void addMotorBike(Motorbike* motorbike);
    void addLorry(Lorry* lorry);
    void calculateAndPrintChanceOfAccident();
    
private:

    std::vector<Car> carsArray;
    std::vector<Motorbike> motorbikesArray;
    std::vector<Lorry> lorriesArray;
    double chanceOfAccident;
    
};
void Motorway::addCar(Car* car)
{
    carsArray.push_back(*car);
}
void Motorway::addMotorBike(Motorbike* motorbike)
{
    motorbikesArray.push_back(*motorbike);
}
void Motorway::addLorry(Lorry* lorry)
{
    lorriesArray.push_back(*lorry);
}
void Motorway::calculateAndPrintChanceOfAccident()
{
    double sumSpeedCars = 0;
    for(size_t i = 0; i < carsArray.size(); ++i)
    {
        sumSpeedCars += carsArray[i].getSpeed();
    }
    double avgSpeedCars = sumSpeedCars/carsArray.size();
    
    double sumSpeedMotorbikes = 0;
    for(size_t i = 0; i < motorbikesArray.size(); ++i)
    {
        sumSpeedMotorbikes += motorbikesArray[i].getSpeed();
    }
    double avgSpeedMotorbikes = sumSpeedMotorbikes/motorbikesArray.size();
    
    double sumSpeedLorries = 0;
    for(size_t i = 0; i < lorriesArray.size(); ++i)
    {
        sumSpeedLorries += lorriesArray[i].getSpeed();
    }
    double avgSpeedLorries = sumSpeedLorries/lorriesArray.size();
    
    chanceOfAccident = avgSpeedCars * CAR_ON_MOTORWAY_COEFF +
                        avgSpeedMotorbikes * MOTORBIKE_ON_MOTORWAY_COEFF +
                        avgSpeedLorries * LORRY_ON_MOTORWAY_COEFF;
            std::cout << "Chance of an accident on this stretch of motorway is  " << chanceOfAccident << " measured in accidents per hour" << std::endl;
}
int main() {
    Car ford("ford", 70,3);
    Motorbike harley("harley", 80,2);
    Motorbike ducati("ducati", 110,1);
    Lorry bedford("bedford", 50,1);
    Car ferrari("ferrari", 90,2);
    Car vwGolf("vwGolf", 65,5);

    ford.calculateAndPrintRisk();
    harley.calculateAndPrintRisk();
    bedford.calculateAndPrintRisk();
    
    Motorway motorway;
    motorway.addCar(&ford);
    motorway.addCar(&ferrari);
    motorway.addCar(&vwGolf);
    motorway.addMotorBike(&harley);
    motorway.addMotorBike(&ducati);
    motorway.addLorry(&bedford);
    motorway.calculateAndPrintChanceOfAccident();
    return 0;
}
