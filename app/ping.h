#ifndef PING_H
#define PING_H
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
namespace ping {
struct Chunk {
	unsigned long int size;
	const char* name;
	char* content;
	char crc32[4];
	
	Chunk( 
		unsigned long int getSize,
		const char* getName
		) 
	{
		size = getSize;
		name = getName;
	}
	
	const char* getN() //test for chunk name
	{
		return name;
	}
	
	unsigned long int getSize_int()
	{
		return size; //test for chunk size
	}
	
	std::string getSize_char() // Convert integer size to file-ready char array
	{
		/*unsigned char tempArray[4];
		unsigned long int tempSize = size;*/
		/*
		
		unsigned short int temp;
		
		for ( int i = 0; i < 4; i++ )
		{
			temp = tempSize % 255;
			tempSize /= 255;
			
			tempArray[ 3 - i ] = temp;
		}*/
		/*int i = 0;

    		for (i = 0; i < 4; ++i)
    		{
        		tempArray[i] = (unsigned char)((((unsigned long) tempSize) >> (24 - (8*i))) & 0xFFu);
    		}
	
		return tempArray;*/
		/*std::string str;
		str = std::to_string(size);*/
		std::stringstream stream;
		stream << "0x" << std::setfill ('0') << std::setw(sizeof(unsigned long)*2) << std::hex << size;
		std::string str( stream.str() );
		
		return str;
	}
	
};
//critical chunks
struct IHDR : Chunk { // Head chunk
	IHDR() : Chunk( 13, "IHDR" ) {} //cant send 0000000d
};
/*struct PLTE : Chunk { // Palette chunk
	PLTE() : Chunk("PLTE") {}
};
struct IDAT : Chunk { // Data chunk
	IDAT() : Chunk("IDAT") {}
};
struct IEND : Chunk { // End chunk
	IEND() : Chunk("IEND") {}
};*/
//optional chunksss
// tRNS chunk
// cHRM chunk
// gAMA chunk
// iCCP chunk
// sBIT chunk
// sRGB chunk
// iTXT chunk
// tEXT chunk
// zTXT chunk
// bKGD chunk
// hIST chunk
// pHYs chunk
// sPLT chunk
// tIME chunk

// sTER chunk
}
#endif