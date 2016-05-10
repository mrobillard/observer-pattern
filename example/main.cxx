
//
// main.cxx
//

// This example demonstrates a simple, trivial (pointless) use of the observer pattern.
// The generator class generates a random number between 0 and 10. If (when)
// that number matches the number passed in as an argument, the generator will
// fire an event that the consumer will listen to and report to the console.

#include <stdio>
#include <chrono>
#include <ctime>

#include "generator.hxx"
#include "consumer.hxx"

int main ( int argc, char ** argv )
{

    int magicNumber;

	//
	// Parse Command Line Arguments
	//
    if ( argc == 2 )
	{
        magicNumber = argv[1];
	} else {
	    // Exit application
        std::cout << "Incorrect application usage." << std::endl;

        return -1;
	}

	//
	// Object graph creation
	//
    Generator generator ( magicNumber ); // Observable
    Consumer consumer ();                // Observer

    //
    // Register Observers
    //
    generator.AddObserver ( &consumer );

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now ();
    generator.Run ();
    end = std::chrono::system_clock::now ();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t ( end );

    std::cout << "Finished computation at " << std::ctime ( &end_time )
              << "Elapsed Time: " << elapsed_seconds.count () << "s\n";

    //
    // Deregister Observer
    //
    generator.RemoveObserver ( &consumer );

	return 0;

}
