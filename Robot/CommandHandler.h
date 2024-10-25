#ifndef _COMMANDHANDLER_
#define _COMMANDHANDLER_

#include <string>
#include "RobotInterface.h"
#include "TableInterface.h"


struct PlaceCommand
{
    unsigned int                xCoordinate = 0;
    unsigned int                yCoordinate = 0;
    OrientationEnum             orientation = OrientationEnum::North;
};

class CommandHandler
{
private:
    PlaceCommand                placeCommand;
    CommandEnum                 command = UNSUPPORTED;
    bool                        isPlaced = false;

public:
    CommandHandler();

    void ParseCommand(std::string);
    void ExecuteCommand(RobotInterface* robot, TableInterface* table);





};

#endif //_COMMANDHANDLER_