#ifndef INVENTORY_CONTROL_H
#define INVENTORY_CONTROL_H

#include <QString>

class AutoPart 
{
public:
    virtual int getCount() const = 0;
        //Function to return the number of items of the derived class
        //stored in the inventory.

    virtual double getPrice() const = 0;
        //Function to return the price of the item of the derived
        //class.

    virtual QString toString() const = 0;
        //Function to return the name of the object of the derived
        //class as a QString.

    virtual void setCount(int count) = 0;
        //Function to set the number of items of the derived class
        //stored in the inventory.

    virtual void incCount() = 0;
        //Function to increase the number of items of the derived
        //class stored in the inventory by 1.

    virtual void setPrice(double price) = 0;
        //Function to set the price of the item of the derived class.
        
private:
    int m_Count;
    double m_Price;
    QString m_Name;
};

class EnginePart: public AutoPart
{
public:
    virtual QString getSerialNo() const = 0;
        //Function to return the serial number of the engine part.

    virtual void setSerialNo(QString serialNo) = 0;
        //Function to set the serial number of the engine part.

private:
    QString m_SerialNo;
};

class Alternator: public EnginePart
{
public:
    int getCount() const;
        //Function to return the number of alternators stored in the inventory.

    double getPrice() const;
        //Function to return the price of the alternator.

    QString toString() const;
        //Function to return the name of the alternator as a QString.

    QString getSerialNo() const;
        //Function to return the serial number of the alternator.

    void setCount(int count);
        //Function to set the number of alternators stored in the inventory.

    void incCount();
        //Function to increase the number of alternators stored in the inventory by 1.

    void setPrice(double price);
        //Function to set the price of the alternator.

    void setSerialNo(QString serialNo);
        //Function to set the serial number of the alternator.
};

class Radiator: public EnginePart
{
public:
    int getCount() const;
        //Function to return the number of radiators stored in the inventory.

    double getPrice() const;
        //Function to return the price of the radiator.

    QString toString() const;
        //Function to return the name of the radiator as a QString.

    QString getSerialNo() const;
        //Function to return the serial number of the radiator.

    void setCount(int count);
        //Function to set the number of radiators stored in the inventory.

    void incCount();
        //Function to increase the number of radiators stored in the inventory by 1.

    void setPrice(double price);
        //Function to set the price of the radiator.

    void setSerialNo(QString serialNo);
        //Function to set the serial number of the radiator.
};

class Accessory: public AutoPart
{
public:
    virtual QString getColour() const = 0;
        //Function to return the colour of the accessory.

    virtual void setColour(Qstring colour) = 0;
        //Function to set the colour of the accessory.
        
private:
    QString m_Colour;
};

class SeatBelt: public Accessory
{
public:
    int getCount() const;
        //Function to return the number of seatbelts stored in the inventory.

    double getPrice() const;
        //Function to return the price of the seatbelt.

    QString toString() const;
        //Function to return the name of the seatbelt as a QString.

    QString getColour() const;
        //Function to return the colour of the seatbelt.

    void setCount(int count);
        //Function to set the number of seatbelts stored in the inventory.

    void incCount();
        //Function to increase the number of seatbelts stored in the inventory by 1.

    void setPrice(double price);
        //Function to set the price of the seatbelt.

    void setColour(QString colour);
        //Function to set the colour of the seatbelt.
};

class BodyPart: public AutoPart
{
public:
    virtual QString getColour() const = 0;
        //Function to return the colour of the body part.

    virtual void setColour(Qstring colour) = 0;
        //Function to set the colour of the body part.
        
private:
    QString m_Colour;
private:
};

class Fender: public BodyPart
{
public:
    int getCount() const;
        //Function to return the number of fenders stored in the inventory.

    double getPrice() const;
        //Function to return the price of the fender.

    QString toString() const;
        //Function to return the name of the fenders as a QString.

    QString getColour() const;
        //Function to return the colour of the fender.

    void setCount(int count);
        //Function to set the number of fenders stored in the inventory.

    void incCount();
        //Function to increase the number of fenders stored in the inventory by 1.

    void setPrice(double price);
        //Function to set the price of the fender.

    void setColour(QString colour);
        //Function to set the colour of the fender.
};
#endif //INVENTORY_CONTROL_H
