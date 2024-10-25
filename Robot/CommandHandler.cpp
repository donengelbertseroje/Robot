#include    "CommandHandler.h"
#include    <algorithm>
#include    <regex>
#include    "DataTypes.h"
#include <iostream>

using namespace std;

CommandHandler::CommandHandler()
{


}


void CommandHandler::ParseCommand(string referenceString)
{
    regex exprPlace("^\\s*PLACE\\s*(\\d+)\\s*,\\s*(\\d+)\\s*,\\s*(NORTH|SOUTH|WEST|EAST)\\s*$");
    regex exprMove("^\\s*MOVE\\s*$");
    regex exprLeft("^\\s*LEFT\\s*$");
    regex exprRight("^\\s*RIGHT\\s*$");
    regex exprReport("^\\s*REPORT\\s*$");
    smatch match;

    //change to lower case
    transform(referenceString.begin(), referenceString.end(), referenceString.begin(), ::toupper);

    if (regex_search(referenceString, match, exprPlace))
    {
        string strOrientation;
        placeCommand.xCoordinate = stoi(match.str(1));
        placeCommand.yCoordinate = stoi(match.str(2));


        strOrientation = match.str(3);
        cout << strOrientation << endl;
        if (!strOrientation.compare("NORTH"))
        {
            placeCommand.orientation = OrientationEnum::North;
        }
        else if (!strOrientation.compare("SOUTH"))
        {
            placeCommand.orientation = OrientationEnum::South;
        }
        else if (!strOrientation.compare("WEST"))
        {
            placeCommand.orientation = OrientationEnum::West;
        }
        else //remaing will always be east because of the regex
        {
            placeCommand.orientation = OrientationEnum::East;
        }

        command = CommandEnum::PLACE;
    }
    else if (regex_search(referenceString, match, exprMove))
    {
        command = CommandEnum::MOVE;
    }
    else if (regex_search(referenceString, match, exprLeft))
    {
        command = CommandEnum::LEFT;
    }
    else if (regex_search(referenceString, match, exprRight))
    {
        command = CommandEnum::RIGHT;
    }
    else if (regex_search(referenceString, match, exprReport))
    {
        command = CommandEnum::REPORT;
    }
    else
    {
        command = CommandEnum::UNSUPPORTED;
    }

    if (command != CommandEnum::UNSUPPORTED)
    {
        cout << referenceString << endl;
    }
}


void CommandHandler::ExecuteCommand(RobotInterface* robot, TableInterface* table)
{
    switch (command)
    {
        case PLACE: 
            //cout << "x " << placeCommand.xCoordinate << endl;
            //cout << "y " << placeCommand.yCoordinate << endl;
            //cout << "o " << placeCommand.orientation << endl;

            robot->Place(table, placeCommand.xCoordinate, placeCommand.yCoordinate, placeCommand.orientation);
            isPlaced = true;
            break;

        case MOVE:
            if (isPlaced)
            {
                robot->Move(table);
            }
            break;

        case LEFT:
            if (isPlaced)
            {
                robot->Left();
            }
            break;

        case RIGHT:
            if (isPlaced)
            {
                robot->Right();
            }
            break;

        case REPORT:
            robot->Report(table);
            break;

        default:
            //do nothing
            break;
    }
}
