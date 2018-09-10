#include <iostream>
#include <fstream>
#include "ping.h"

// Chunk structure constuctor
ping::Chunk( 
		unsigned long int getSize,
		const char* getName
		) 
	{
		size = getSize;
		name = getName;
	}