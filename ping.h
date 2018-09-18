#ifndef PING_H
#define PING_H
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
namespace ping {

struct Chunk {
protected:
	unsigned long size;           // Size of chunk
	char name[4];  // Name of chunk
	mutable char* content; // Data of chunk
	unsigned long crc32;       // CRC32 for chunk
public:
	Chunk( 
		unsigned long getSize,
		unsigned long getName
		) ;

	unsigned long getCrc32();               // Return CRC32 value
	void setCrc32(unsigned long arg); // Set CRC32 value	
	char* getName();            //test for chunk name
	char* getContent() const;         // Return content
	unsigned long getSizeInt();             // Numerical representation of chunk size
	std::string getSizeChar();                 // Hex representation of chunk size
	unsigned char * getNameAndContent();
	
	
};

//critical chunks
struct IHDR : Chunk { // Head chunk
	IHDR() : Chunk( 0x0000000dL , 0x49454e44L/*0x49484452L */) {}
	
	void createContent(unsigned long x, unsigned long y) const
	{
		content[0] = 0x00;
		content[1] = 0x00;
		content[2] = 0x00;
		content[3] = 0x64;
		content[4] = 0x00;
		content[5] = 0x00;
		content[6] = 0x00;
		content[7] = 0x64;
		content[8] = 0x08;
		content[9] = 0x02;
		content[10] = 0x00;
		content[11] = 0x00;
		content[12] = 0x00;
	}
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

unsigned long calcCrc(unsigned long *CrcTable, unsigned long crc, char *buf, int len);

}
#endif