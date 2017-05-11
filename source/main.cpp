/*!
	\file main.cpp
	\brief Entry Point
	\author Tiago Ventura (tiago.ventura@gmail.com)
*/

#include <iostream>
#include "MLM.hpp"

int main( int argc, char * argv[] )
{
	try
	{
		MLM::MLMCommandLineApplication app( argc, argv );
		app.run();
		return 0;
	}
	catch( const MLM::Exception &e )
	{
		std::cerr << "MLM Network Exception: " << e.msg() << std::endl;
	}
	catch( const std::exception &e )
	{
		std::cerr << "STL Exception: " << e.what() << std::endl;
	}
	catch( ... )
	{
		std::cerr << "Unknown Exception." << std::endl;
	}

	return 1;
}

/* $Id: main.cpp 427 2017-05-02 12:18:23Z tiago.ventura $ */

