#include "ping.h"

// Constructor
ping::Chunk::Chunk( 
		unsigned long getSize,
		unsigned long getName
		) 
{
	size = getSize;
	int j = 0x1000000; // Converting hex long to char bytes
	for ( int i = 0; i < 4; i++ )
	{
		name[i] = getName / j;
		j /= 0x100;
	}
	content = new char[size];
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

char * ping::Chunk::getName() //test for chunk name
{
	return name;
}

char* ping::Chunk::getContent() const
{
	return content;
}

unsigned char * ping::Chunk::getNameAndContent()
{
	unsigned char * result = new unsigned char[size + 4];
	for ( int i = 0; i < 4; i++ )
		result[i] = name[i];
	for ( int i = 4; i < size; i++ )
		result[i] = content[i];
	return result;
}

// Setters
void ping::Chunk::setCrc32(unsigned long arg)
{
	crc32 = arg;
}

//CRC32 calc
unsigned long ping::calcCrc(unsigned long *CrcTable, unsigned long crc, char *buf, int len)
{
	unsigned long crc32 = crc;
	int n;

	for (n = 0; n < len; n++) {
		crc32 = CrcTable[(crc32 ^ buf[n]) & 0xff] ^ (crc32 >> 8);
	}

	return crc32 ^ 0xffffffffL;
}