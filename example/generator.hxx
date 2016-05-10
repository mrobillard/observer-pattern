
#include <stdlib.h>

#include "observable.hxx"

/**
 *
 *
 *
 */
class Generator : Observable 
{

private:

    /**
	 *
	 */
    int _number;

public:

    /**
	 *
	 */
	Generator ( int number )
	{
  
        _number = number;

	}

	/**
     *
	 */
    Run ()
	{
        rand ( time ( NULL ) );

		// generate secret number between 1 and 10: */
        int iSecret = rand() % 10 + 1;
	}

};
