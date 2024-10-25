#ifndef _TABLEINTERFACE_ 
#define _TABLEINTERFACE_ 


//No need to define virtual destructor because no explicit use of "new" and "delete"
//So no need to apply rule of 5
class TableInterface
{
protected:
    unsigned int xCoordinate = 0;
    unsigned int yCoordinate = 0;


public:
				virtual void												SetCoordinate(int xCoordinate, int yCoordinate) = 0;
				virtual unsigned int				GetXCoordinate() = 0;
				virtual unsigned int				GetYCoordinate() = 0;
				
};

#endif // _TABLEINTERFACE_ 