/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */

#include <iostream>
#include <vector>
#include <string>
#include "LeakedObjectDetector.h"
#include "Car.h"
#include "Motorbike.h"
#include "Lorry.h"
#include "Wrappers.h"


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

