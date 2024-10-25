#ifndef _TABLE_
#define _TABLE_

#include "TableInterface.h"

class Table : TableInterface
{
protected:

public:
    Table();
    void            SetCoordinate(int xCoordinate, int yCoordinate);
    unsigned int    GetXCoordinate();
    unsigned int    GetYCoordinate();


};


#endif //_TABLE_