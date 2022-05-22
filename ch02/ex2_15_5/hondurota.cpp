// This is the implementation of the ADT Hondurota.
// The interface is in the file hondurota.h

#include "hondurota.h"

#include <iostream>
#include <cassert>
#include <cstdlib>

using namespace std;

double Hondurota::addFuel(double gal)
{
    assert(gal >= 0.0);

    m_Speed = 0.0;

    if (m_Fuel + gal <= m_TankCapacity)
       m_Fuel += gal;
    else
    {
        cout << "Tank full, excess fuel remaining "
             << gal - (m_TankCapacity - m_Fuel) << "gal\n";
        m_Fuel = m_TankCapacity;
    }
    return m_Fuel;
}

double Hondurota::getSpeed() const
{
    return m_Speed;
}

Hondurota::Hondurota(double fuel, double odom, double capacity,
                     double mpg) : m_Fuel(fuel), m_Odometer(odom),
                                   m_TankCapacity(capacity),
                                   m_MPG(mpg), m_Speed(0.0)
{
    assert(fuel >= 0.0 && odom >= 0.0 && capacity >= 0.0 && mpg >= 0.0);
}

double Hondurota::getTankCapacity() const
{
    return m_TankCapacity;
}

double Hondurota::getMPG() const
{
    return m_MPG;
}

double Hondurota::drive(double speed, int minutes)
{
    if (m_Fuel <= 0.0)
        cout << "Warning! Tank empty: unable to drive.";
    else
    {
        m_Speed = speed;
        double distanceTravelled = 
            speed * (static_cast<double>(speed) / 60.0);
        double fuelUsed = distanceTravelled / m_MPG;
        if (m_Fuel <= fuelUsed)
        {
            cout << "Warning! Tank empty: unable to drive.";
            m_Fuel = 0.0;
            distanceTravelled -= (fuelUsed - m_Fuel) * m_MPG;
        }
        else m_Fuel -= fuelUsed;
        m_Odometer += distanceTravelled;
    }

    return m_Fuel;
}

double Hondurota::getFuel() const
{
    return m_Fuel;
}

double Hondurota::getOdometer() const
{
    return m_Odometer;
}

double Hondurota::highwayDrive(double distance, double speedLimit)
{   // Declare variables for calculation.
    double optimalSpeed = 45.0, consumptionRate = m_MPG;
    int elapsedTime = 0;

    // Seed random number generator.
    srand(time(0));

    // Set speed to speedLimit.
    m_Speed = speedLimit;

    while (m_Fuel > 0.0 && distance > 0.0)
    {
        // Add random change from -5mph to +5mph
        m_Speed += ((rand() % 10) + 1.0) - 5.0;

        // Do not allow speed to exceed speedLimit + 40mph.
        if (m_Speed >= speedLimit + 40.0) m_Speed = speedLimit + 40.0;

        // Do not allow speed to become negative.
        if (m_Speed < 0.0) m_Speed = 0.0;

        // Adjust consumption rate for each mph > optimal.
        consumptionRate *= 1.01 * (m_Speed - optimalSpeed);

        // Adjust figures for one minute elapsed.
        elapsedTime++;
        distance -= m_Speed / 60.0;
        m_Odometer += m_Speed / 60.0;
        m_Fuel -= (m_Speed / 60.0) / consumptionRate;
    }

    // Alert if automobile has stopped.
    if (m_Fuel <= 0.0) cout << "Warning! Out of fuel.\n";

    return elapsedTime;
}
