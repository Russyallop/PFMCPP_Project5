/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
		
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
		{ 
            // 2b) explicitly using 'this' inside this member function.
			std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
		}  
		
        int returnValue() { return 3; }
        float memberVariable = 3.14f;
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
		
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
		
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}

#include <iostream>
#include <vector>
#include <string>


#define PASSENGER_COEFF 0.0000005
#define CAR_ON_MOTORWAY_COEFF 0.0000002
#define MOTORBIKE_ON_MOTORWAY_COEFF 0.0000006
#define LORRY_ON_MOTORWAY_COEFF 0.0000006

struct Car
{
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
    std::string name;
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

struct Motorbike
{
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
    std::string name;
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

struct Lorry
{
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
    std::string name;
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
            std::cout << "Chance of an accident on this stretch of motorway is  " << chanceOfAccident << " measured in accidents per hour" << std::endl;
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
	Example::main();
	
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
