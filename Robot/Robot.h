#ifndef _ROBOT_
#define _ROBOT_

#include "RobotInterface.h"
#include "DataTypes.h"
#include <string>
#include <map>
#include <memory>



class Robot: RobotInterface
{
private:
    unsigned int const  maxOrientation = 4;
    std::map<OrientationEnum, std::string>   orientationMap =
    {
        {North  , "NORTH"},
        {East   , "EAST"},
        {South  , "SOUTH"},
        {West   , "WEST"}
    };
protected:
    OrientationEnum orientation = OrientationEnum::North;
public:
    Robot();
    void Place(TableInterface* table, unsigned int xCoordinate, unsigned int yCoordinate, OrientationEnum orientation);
    void Move(TableInterface* table);
    void Left();
    void Right();
    void Report(TableInterface* table) ;
    OrientationEnum GetOrientation();
};

#endif //_ROBOT_