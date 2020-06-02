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
#include "LeakedObjectDetector.h"


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
    
    JUCE_LEAK_DETECTOR(Car)
    
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

struct CarWrapper
{
    CarWrapper( Car* carPtr_) : carPtr( carPtr_) {}
    ~CarWrapper()
    {
        delete carPtr;
    }
    
    Car* carPtr = nullptr;
};

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
    
    JUCE_LEAK_DETECTOR(Motorbike)
    
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
struct MotorbikeWrapper
{
    MotorbikeWrapper( Motorbike* MotorbikePtr_) : motorbikePtr( MotorbikePtr_) {}
    ~MotorbikeWrapper()
    {
        delete motorbikePtr;
    }
    
    Motorbike* motorbikePtr = nullptr;
};

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
    
    JUCE_LEAK_DETECTOR(Lorry)

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

struct LorryWrapper
{
    LorryWrapper( Lorry* LorryPtr_) : lorryPtr( LorryPtr_) {}
    ~LorryWrapper()
    {
        delete lorryPtr;
    }
    
    Lorry* lorryPtr = nullptr;
};

struct Motorway
{
    void addCar(Car* car);
    void addMotorBike(Motorbike* motorbike);
    void addLorry(Lorry* lorry);
    void calculateAndPrintChanceOfAccident();
    
    JUCE_LEAK_DETECTOR(Motorway)

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
    double avgSpeedCars = 0;
    double sumSpeedCars = 0;
    if( carsArray.size() == 0 ) avgSpeedCars = 0;
    else
    {
        for(size_t i = 0; i < carsArray.size(); ++i)
        {
            sumSpeedCars += carsArray[i].getSpeed();
        }
        avgSpeedCars = sumSpeedCars/carsArray.size();
    }

    double avgSpeedMotorbikes =  0;
    double sumSpeedMotorbikes = 0;
    if( motorbikesArray.size() == 0 ) avgSpeedMotorbikes = 0;
    else
    {
        for(size_t i = 0; i < motorbikesArray.size(); ++i)
        {
            sumSpeedMotorbikes += motorbikesArray[i].getSpeed();
        }
        avgSpeedMotorbikes = sumSpeedMotorbikes/motorbikesArray.size();
    }
    
    double avgSpeedLorries =  0;
    double sumSpeedLorries = 0;
    if( lorriesArray.size() == 0 ) avgSpeedLorries = 0;
    else
    {
        for(size_t i = 0; i < lorriesArray.size(); ++i)
        {
            sumSpeedLorries += lorriesArray[i].getSpeed();
        }
        avgSpeedLorries = sumSpeedLorries/lorriesArray.size();
    }
    
    chanceOfAccident = avgSpeedCars * CAR_ON_MOTORWAY_COEFF +
    avgSpeedMotorbikes * MOTORBIKE_ON_MOTORWAY_COEFF +
    avgSpeedLorries * LORRY_ON_MOTORWAY_COEFF;
    std::cout << "Chance of an accident on this stretch of motorway is  " << chanceOfAccident << " measured in accidents per million hours\n" << std::endl;
}

struct MotorwayWrapper
{
    MotorwayWrapper(Motorway* motorway_) : motorwayPtr(motorway_) {}
    ~MotorwayWrapper()
    {
        delete motorwayPtr;
    }
    Motorway* motorwayPtr;
};


int main()
{
    CarWrapper fordWrapper( new Car("ford", 70, 3));
    MotorbikeWrapper harleyWrapper( new Motorbike("harley_wrapper", 80, 2 ));
    MotorbikeWrapper ducatiWrapper( new Motorbike("ducati_wrapper", 110, 1 ));
    LorryWrapper bedfordWrapper( new Lorry( "bedford_wrapper", 50, 1 ));
    CarWrapper ferrariWrapper( new Car("ferarriWrapper", 90, 2));
    CarWrapper vwGolfWrapper( new Car("vwGolf", 65, 5)); 

    std::cout << "\nCar [ford_Wrapper.carPtr->getName()]: " << fordWrapper.carPtr->getName()
    << ", traveling at [fordWrapper.carPtr->getSpeed()]: " << fordWrapper.carPtr->getSpeed()
    << "mph, has the following risk report when carrying [fordWrapper.carPtr->getPassengers()]: " << fordWrapper.carPtr->getPassengers()
    << " passengers: \n" << std::endl;
    fordWrapper.carPtr->calculateAndPrintRisk();

    std::cout << "\nMotorbike [harley_Wrapper.motorbikePtr->getName()]: " << harleyWrapper.motorbikePtr->getName()
    << ", traveling at [harleyWrapper.motorbikePtr->getSpeed()]: " << harleyWrapper.motorbikePtr->getSpeed()
    << "mph, has the following risk report when carrying [harleyWrapper.motorbikePtr->getPassengers()]: "
    << harleyWrapper.motorbikePtr->getPassengers() << " passengers: \n" << std::endl;
    harleyWrapper.motorbikePtr->calculateAndPrintRisk();

    std::cout << "\nLorry [bedford_Wrapper.lorryPtr->getName()]: " << bedfordWrapper.lorryPtr->getName()
    << ", traveling at [bedfordWrapper.lorryPtr->getSpeed()]: " << bedfordWrapper.lorryPtr->getSpeed()
    << "mph, has the following risk report when carrying [bedfordWrapper.lorryPtr->getPassengers()]: "
    << bedfordWrapper.lorryPtr->getPassengers() << " passengers: \n" << std::endl;
    bedfordWrapper.lorryPtr->calculateAndPrintRisk();


    MotorwayWrapper motorwayWrapper( new Motorway());
    motorwayWrapper.motorwayPtr->addCar( fordWrapper.carPtr );
    motorwayWrapper.motorwayPtr->addCar( ferrariWrapper.carPtr );
    motorwayWrapper.motorwayPtr->addCar( vwGolfWrapper.carPtr );
    motorwayWrapper.motorwayPtr->addMotorBike( harleyWrapper.motorbikePtr );
    motorwayWrapper.motorwayPtr->addMotorBike( ducatiWrapper.motorbikePtr );
    motorwayWrapper.motorwayPtr->addLorry( bedfordWrapper.lorryPtr );
    motorwayWrapper.motorwayPtr->calculateAndPrintChanceOfAccident();
   
    return 0;
}

