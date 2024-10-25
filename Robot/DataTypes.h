#ifndef _DATATYPES_
#define _DATATYPES_

enum OrientationEnum
{
    North = 0,
    East = 1,
    South = 2,
    West = 3
};

enum CommandEnum
{
    UNSUPPORTED = 0,
    PLACE,
    MOVE,
    LEFT,
    RIGHT,
    REPORT,
};
#endif // _DATATYPES_