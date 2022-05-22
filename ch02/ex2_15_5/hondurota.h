#ifndef HONDUROTA_H
#define HONDUROTA_H

// This is the interface for the ADT Hondurota,
// a modern automobile with member variables representing
// fuel, odomoter, tank capacity, MPG (miles per gallon),
// speed, and associated member functions. The implementation
// is in the file hondurota.cpp

class Hondurota
{
public:
    double addFuel(double gal);
    // Function to add fuel to the automobile.
    // Precondition: m_Fuel + gal <= tank capacity.
    // Postcondition: m_Speed = 0.0; m_Fuel incremented by gal.

    double getSpeed() const;
    // Function to return the current speed of the automobile.
    // Postcondition: Returned m_Speed.

    Hondurota(double fuel = 0.0, double odom = 0.0,
              double capacity = 0.0, double mpg = 0.0);
    // Constructor function with paramters.
    // Postcondition: m_Fuel = fuel; m_Odometer = odom;
    //  m_TankCapacity = capacity; m_MPG = mpg; speed = 0.0.

    double getTankCapacity() const;
    // Function to return the capacity of the automobile's tank.
    // Postcondition: Returned m_TankCapacity.

    double getMPG() const;
    // Function to return the MPG (miles per gallon) representing
    //  the automobile's average fuel consumption.
    // Postcondition: Returned m_MPG.

    double drive(double speed, int minutes);
    // Function to simulate the automobile driving at speed MPH
    // for minutes minutes.
    // Precondition: m_Fuel > 0.0; speed >= 0.0; minutes > 0.
    // Postcondition: m_Odometer incremented; m_Speed = speed;
    //  fuel decremented; returned remaining value of m_Fuel.
    
    double getFuel() const;
    // Function to return the number of gallons of fuel left
    //  in the automobile's tank.
    // Postcondition: Returned m_Fuel.
    
    double getOdometer() const;
    // Function to return the odometer reading of the automobile.
    // Postcondition: Returned m_Odometer.

    double highwayDrive(double distance, double speedLimit);
    // Function to simulate driving on the highway, close to
    //  the given speed limit.
    // Postcondition: Returned the elapsed time for the trip.
    
private:
    double m_Fuel;
    double m_Odometer;
    double m_TankCapacity;
    double m_MPG;
    double m_Speed;
};
#endif // HONDUROTA_H
