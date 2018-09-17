#include <iostream>
#include <fstream>
#include "ping.h"

// Constructor
ping::Chunk::Chunk( 
		unsigned long getSize,
		const char * getName
		) 
{
	size = getSize;
	name = getName;
	content = new unsigned char[size];
}

// Getters
unsigned long ping::Chunk::getCrc32()
{
	return crc32;
}

unsigned long ping::Chunk::getSizeInt()
{
	return size;
}

std::string ping::Chunk::getSizeChar() // Convert integer size to file-ready char array
{
	std::stringstream stream;
	stream << "0x" << std::setfill ('0') << std::setw(sizeof(unsigned long)*2) << std::hex << size;
	std::string str( stream.str() );
		
	return str;
}

const char* ping::Chunk::getName() //test for chunk name
{
	return name;
}

// Setters
void ping::Chunk::setCrc32(unsigned long arg)
{
	crc32 = arg;
}

//CRC32 calc
unsigned long ping::calcCrc(unsigned long *CrcTable, unsigned long crc, unsigned char *buf, int len)
{
	unsigned long crc32 = crc;
	int n;

	for (n = 0; n < len; n++) {
		crc32 = CrcTable[(crc32 ^ buf[n]) & 0xff] ^ (crc32 >> 8);
	}

	return crc32 ^ 0xffffffffL;
}