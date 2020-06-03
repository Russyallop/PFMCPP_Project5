
#include "Motorway.h"

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
