#include "Table.h"
#include <algorithm>
#include <iostream>

using namespace std;

const unsigned int xSize = 5;
const unsigned int ySize = 5;


//well, this is just to showcase constexpr
constexpr int xSize0Origin = xSize - 1;
constexpr int ySize0Origin = xSize - 1;

Table::Table()
{
}


void Table::SetCoordinate(int xCoordinate, int yCoordinate)
{
    this->xCoordinate = std::clamp(xCoordinate, 0, xSize0Origin);
    this->yCoordinate = std::clamp(yCoordinate, 0, ySize0Origin);
}

unsigned int Table::GetXCoordinate()
{
     return xCoordinate;
}

unsigned int Table::GetYCoordinate()
{
     return yCoordinate;
}