#include <iostream>
#include <fstream>
#include "ping.h"

/*struct Ping //PNG structure
{
	const unsigned char header[] = { 0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, '\0'};
	
	void writeHeader()
	{
		for (int i = 0; i < 8; i++ ) 
	}
};*/

int main()
{
	std::cout << "hi"; //debug
	ping::Chunk** chunk = new ping::Chunk*[1]; //array of chunks
	chunk[0] = new ping::IHDR();
	std::cout << "hi"; //debug
	std::cout << chunk[0]->getSize_char(); //debug
	
	const unsigned char header[] = { 0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, '\0'};
	
	//std::cout << header; //debug
	
	std::ofstream file;
	file.open("test.png", std::ios::binary );
	file << header << chunk[0]->getN();
	file.write(chunk[0]->getSize_char(), sizeof(char)*chunk[0]->getSize_char().size());
	file.close();
	
	return 0;	
}
