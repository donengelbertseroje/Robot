#include "Robot.h"
#include "Table.h"
#include "CommandHandler.h"
#include <iostream>
#include <memory>
#include <cassert>

using namespace std;

void Test()
{
				shared_ptr<Robot> robotPtr = make_shared<Robot>();
				shared_ptr<Table> tablePtr = make_shared<Table>();
				CommandHandler						commandHandler;

				Robot* robot = robotPtr.get();
				Table* table = tablePtr.get();

				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::North));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 0));

				commandHandler.ParseCommand("MOVE");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::North));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 0));

				commandHandler.ParseCommand("LEFT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::North));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 0));

				commandHandler.ParseCommand("riGHT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::North));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 0));

				commandHandler.ParseCommand("PlACE 2,2,NORTH");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::North));
				assert((table->GetXCoordinate() == 2));
				assert((table->GetYCoordinate() == 2));
				

				//test right turn
				commandHandler.ParseCommand("right");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 2));
				assert((table->GetYCoordinate() == 2));

				//test go to farthest of east
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 3));
				assert((table->GetYCoordinate() == 2));

				//test go to farthest of east
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 4));
				assert((table->GetYCoordinate() == 2));

				//test go to farthest of east
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 4));
				assert((table->GetYCoordinate() == 2));

				//test go to farthest of east
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 4));
				assert((table->GetYCoordinate() == 2));

				//test turn left
				commandHandler.ParseCommand("left");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::North));
				assert((table->GetXCoordinate() == 4));
				assert((table->GetYCoordinate() == 2));

				//test go to farthest of north
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::North));
				assert((table->GetXCoordinate() == 4));
				assert((table->GetYCoordinate() == 3));

				//test go to farthest of north
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::North));
				assert((table->GetXCoordinate() == 4));
				assert((table->GetYCoordinate() == 4));

				//test go to farthest of north
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::North));
				assert((table->GetXCoordinate() == 4));
				assert((table->GetYCoordinate() == 4));

				//test go to farthest of east
				commandHandler.ParseCommand("right");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 4));
				assert((table->GetYCoordinate() == 4));

				//test go to farthest of east
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 4));
				assert((table->GetYCoordinate() == 4));

				//test go to farthest of east
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 4));
				assert((table->GetYCoordinate() == 4));

				//test turn left
				commandHandler.ParseCommand("left");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::North));
				assert((table->GetXCoordinate() == 4));
				assert((table->GetYCoordinate() == 4));

				//test turn left
				commandHandler.ParseCommand("left");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::West));
				assert((table->GetXCoordinate() == 4));
				assert((table->GetYCoordinate() == 4));

				//test go to farthest of west
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::West));
				assert((table->GetXCoordinate() == 3));
				assert((table->GetYCoordinate() == 4));

				//test go to farthest of west
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::West));
				assert((table->GetXCoordinate() == 2));
				assert((table->GetYCoordinate() == 4));

				//test go to farthest of west
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::West));
				assert((table->GetXCoordinate() == 1));
				assert((table->GetYCoordinate() == 4));

				//test go to farthest of west
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::West));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 4));

				//test go to farthest of west
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::West));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 4));

				//test turn left
				commandHandler.ParseCommand("left");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::South));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 4));

				//test go to farthest of south
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::South));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 3));

				//test go to farthest of south
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::South));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 2));

				//test go to farthest of south
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::South));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 1));

				//test go to farthest of south
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::South));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 0));

				//test go to farthest of south
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::South));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 0));

				//test go to farthest of south
				commandHandler.ParseCommand("move");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::South));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 0));

				//test turn left
				commandHandler.ParseCommand("left");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				commandHandler.ParseCommand("RePORT");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 0));

				//========================
				//TEST for INVALID commands
				//========================
				commandHandler.ParseCommand("PlACE 2,n,NRTH");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 0));

				commandHandler.ParseCommand("PlACE 2,2 NORTH");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 0));

				commandHandler.ParseCommand("PlAC 2,2,NRTH");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 0));

				commandHandler.ParseCommand("mVe");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 0));

				commandHandler.ParseCommand("tetset");
				commandHandler.ExecuteCommand((RobotInterface*)robot, (TableInterface*)table);
				assert((robot->GetOrientation() == OrientationEnum::East));
				assert((table->GetXCoordinate() == 0));
				assert((table->GetYCoordinate() == 0));

				cout << "===== unit test done =====" << endl << endl;
}

void MainFlow()
{
				string inputData;
				shared_ptr<Robot>			robotPtr = make_shared<Robot>();
				shared_ptr<Table>			tablePtr = make_shared<Table>();
				CommandHandler						commandHandler;

				Robot* robot = robotPtr.get();
				Table* table = tablePtr.get();


				cout << "Start entering command:" << endl;
				while (true)
				{
								getline(cin, inputData);
								commandHandler.ParseCommand(inputData);
								commandHandler.ExecuteCommand((RobotInterface *)robot, (TableInterface *)table);
				}


}

int main()
{
				Test();

				MainFlow();




				return 0;

}

