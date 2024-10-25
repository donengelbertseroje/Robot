#ifndef _ROBOTINTERFACE_
#define _ROBOTINTERFACE_

#include "TableInterface.h"
#include "DataTypes.h"
#include <memory>

//No need to define virtual destructor because no explicit use of "new" and "delete"
//So no need to apply rule of 5
class RobotInterface
{
public:
    virtual void Place(TableInterface* table, unsigned int xCoordinate, unsigned int yCoordinate, OrientationEnum orientation) = 0;
    virtual void Move(TableInterface* table) = 0;
    virtual void Left() = 0;
    virtual void Right() = 0;
    virtual void Report(TableInterface* table) = 0;
    virtual OrientationEnum GetOrientation() = 0;

};

#endif //_ROBOTINTERFACE_