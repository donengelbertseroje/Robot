#include "Robot.h"
#include <iostream> 
#include <format> 

using namespace std;


Robot::Robot()
{

}

void Robot::Place(TableInterface * table, unsigned int xCoordinate, unsigned int yCoordinate, OrientationEnum orientation)
{
    table->SetCoordinate(xCoordinate, yCoordinate);
    this->orientation = orientation;
}

void Robot::Move(TableInterface* table)
{
    switch (orientation)
    {
        case North: 
            table->SetCoordinate(table->GetXCoordinate(), table->GetYCoordinate() + 1);
            break;
        case East:
            table->SetCoordinate(table->GetXCoordinate() + 1, table->GetYCoordinate());
            break;
        case South:
            table->SetCoordinate(table->GetXCoordinate(), table->GetYCoordinate() - 1);
            break;
        case West:
            table->SetCoordinate(table->GetXCoordinate() - 1, table->GetYCoordinate());
            break;
        default:
            //this will not happen
            break;
    }
}

void Robot::Left()
{
    int intOrientation = orientation;
    intOrientation = --intOrientation % maxOrientation;
    orientation = (OrientationEnum)intOrientation;

}

void Robot::Right()
{
    int intOrientation = orientation;
    intOrientation = ++intOrientation % maxOrientation;
    orientation = (OrientationEnum)intOrientation;
}

void Robot::Report(TableInterface* table)
{
    string str = format("Output: {0}, {1}, {2}", table->GetXCoordinate(), table->GetYCoordinate(), orientationMap[OrientationEnum(orientation)]);
    cout << str << endl;
}

OrientationEnum Robot::GetOrientation()
{
    return orientation;
}
