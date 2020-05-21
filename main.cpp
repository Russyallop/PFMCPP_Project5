/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 3) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 4) write the name of your class where it says "OwnerClass"
 
 5) write wrapper classes for each type similar to how it was shown in the video
 
 7) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

 8) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example
 */

#include <iostream>
#include <vector>
#include <string>


#define PASSENGER_COEFF 0.5
#define CAR_ON_MOTORWAY_COEFF 0.2
#define MOTORBIKE_ON_MOTORWAY_COEFF 0.6
#define LORRY_ON_MOTORWAY_COEFF 0.1

struct Car
{
    Car(std::string name_, double speed_, unsigned long passengers_) : name(name_), speed(speed_), passengers(passengers_)
    {
        for(size_t i = 0; i < passengers; ++i)
        {
            passengerRiskArray.push_back(0);
        }
        
    }
 
    void memberFunc()
    {
            std::cout << "\nCar [Car name]: " << this->name << ", traveling at [Car getSpeed()]:" << this->getSpeed() << "mph, has the following risk report when carrying [Car passengers]: " << this->passengers << " passengers: \n" << std::endl;
            this->calculateAndPrintRisk();
    }
    
    double getSpeed();
    void calculateAndPrintRisk();
    std::string getName();
    unsigned long getPassengers();
  
private:
    std::string name;
    double speed{0};
    unsigned long passengers;
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
        std::cout << "Risk to passenger " << i + 1 << " is: " << passengerRiskArray[i] << " measured in fatalities per million journeys\n"<< std::endl;
    }
}

std::string Car::getName()
{
    return name;
}

unsigned long Car::getPassengers()
{
    return passengers;
}

struct Motorbike
{
    Motorbike(std::string name_, double speed_, unsigned long passengers_) : name(name_), speed(speed_), passengers(passengers_)
    {
        for(size_t i = 0; i < passengers; ++i)
        {
            passengerRiskArray.push_back(0);
        }

    }


    void memberFunc()
    {
            std::cout << "\nMotorbike [Motorbike name]: " << this->name << ", traveling at [Motorbike getSpeed()]:" << this->getSpeed() << "mph, has the following risk report when carrying [Motorbike passengers]: " << this->passengers << " passengers: \n" << std::endl;
            this->calculateAndPrintRisk();
    }
    
    double getSpeed();
    void calculateAndPrintRisk();
    std::string getName();
    unsigned long getPassengers();
private:
    std::string name;
    double speed{0};
    unsigned long passengers;
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
        std::cout << "Risk to passenger " << i + 1 << " is: " << passengerRiskArray[i] << " measured in fatalities per million journeys\n"<< std::endl;
    }
}
std::string Motorbike::getName()
{
    return name;
}

unsigned long Motorbike::getPassengers()
{
    return passengers;
}

struct Lorry
{
    Lorry(std::string name_, double speed_, unsigned long passengers_) : name(name_), speed(speed_), passengers(passengers_)
    {
        for(size_t i = 0; i < passengers; ++i)
        {
            passengerRiskArray.push_back(0);
        }

    }


    void memberFunc()
    {
            std::cout << "\nLorry [Lorry name]: " << this->name << ", traveling at [Lorry getSpeed()]:" << this->getSpeed() << "mph, has the following risk report when carrying [Lorry passengers]: " << this->passengers << " passengers: \n" << std::endl;
            this->calculateAndPrintRisk();
    }
    
    double getSpeed();
    void calculateAndPrintRisk();
    std::string getName();
    unsigned long getPassengers();
private:
    std::string name;
    double speed{0};
    unsigned long passengers;
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
        std::cout << "Risk to passenger " << i + 1 << " is: " << passengerRiskArray[i] << " measured in fatalities per million journeys\n"<< std::endl;
    }
}
std::string Lorry::getName()
{
    return name;
}

unsigned long Lorry::getPassengers()
{
    return passengers;
}

struct Motorway
{
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
    std::cout << "Chance of an accident on this stretch of motorway is  " << chanceOfAccident << " measured in accidents per million hours\n" << std::endl;
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already:
 Make a pull request after you make your first commit
 pin the pull request link and this repl.it link to our DM thread in a single message.
 
 send me a DM to review your pull request when the project is ready for review.
 
 Wait for my code review.
 */

int main()
{   
    Car ford("ford", 70,3);
    Motorbike harley("harley", 80,2);
    Motorbike ducati("ducati", 110,1);
    Lorry bedford("bedford", 50,1);
    Car ferrari("ferrari", 90,2);
    Car vwGolf("vwGolf", 65,5);
    
    std::cout << "\nCar [ford.getName()]: " << ford.getName() << ", traveling at [ford.getSpeed()]:" << ford.getSpeed() << "mph, has the following risk report when carrying [ford.getPassengers()]: " << ford.getPassengers() << " passengers: \n" << std::endl;
    ford.calculateAndPrintRisk();

    ford.memberFunc();
    
    std::cout << "\nMotorbike [harley.getName()]: " << harley.getName() << ", traveling at [harley.getSpeed()]:" << harley.getSpeed() << "mph, has the following risk report when carrying [harley.getPassengers()]: " << harley.getPassengers() << " passengers: \n" << std::endl;
    harley.calculateAndPrintRisk();

    harley.memberFunc();
    
    std::cout << "\nLorry [bedford.getName()]: " << bedford.getName() << ", traveling at [bedford.getSpeed()]:" << bedford.getSpeed() << "mph, has the following risk report when carrying [bedford.getPassengers()]: " << bedford.getPassengers() << " passengers: \n" << std::endl;
    bedford.calculateAndPrintRisk();

    bedford.memberFunc();   


    
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
