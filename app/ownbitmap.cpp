/*
Copyright (c) Artyom Yeghoyan 2018
*/
#include <iostream>
#include <bitset>
#include "lodepng.h"
#include "bmpdecoder.h"

namespace app{
	// pixel
	struct Pixel
	{
		unsigned short red;
		unsigned short green;
		unsigned short blue;
		unsigned short alpha;
	};
	//bitmap
	struct Bitmap
	{
		int x;
		int y;
		Pixel** bitmap;
	};
	//vector to bitmap conversion
	void vector2Bitmap(std::vector<unsigned char> *image, Pixel** bitmap, int x, int y)
	{
		unsigned char* array = image->data();
		std::cout << image->size() << ' ';
		for (int i = 0; i < image->size(); i+=4)
		{
			//std::cout<<i/4%x<<'-'<<i/4/x<<' '; //Outputs array dimensions for debugging
			bitmap[ i / 4 % x ][ i / 4 / x ].red = array[i];
			bitmap[ i / 4 % x ][ i / 4 / x ].green = array[i+1];
			bitmap[ i / 4 % x ][ i / 4 / x ].blue = array[i+2];
			bitmap[ i / 4 % x ][ i / 4 / x ].alpha = array[i+3];
			//std::bitset<8> bn(array[i+2]);  //Outputs vector contents in binary for debugging
			//std::cout << bn;
		}
		std::cout << "end of function\n";
	}
}

int main(int argc, char *argv[])
{
	if(argc < 2)
	{
		std::cout << "Please provice input BMP file name" << std::endl;
		return 0;
	}

	std::vector<unsigned char> bmp;
	lodepng::load_file(bmp, argv[1]);
	std::vector<unsigned char> image;
	unsigned w, h;
	unsigned error = decodeBMP(image, w, h, bmp);

	if(error) {
    		std::cout << "BMP decoding error " << error << std::endl;
		return 0;
	}
	
	//bitmap declaration
	app::Bitmap bitmap;
	
	//bitmap size
	/*std::cout << "size";
	std::cin >>bitmap.x;
	std::cin >>bitmap.y;*/
	bitmap.x = w;
	bitmap.y = h;
	
	//bitmap allocation
	bitmap.bitmap = new app::Pixel*[bitmap.x];
	
	for (int i = 0; i < bitmap.x; i++)
	{
		bitmap.bitmap[i] = new app::Pixel[bitmap.y];
	}
	
	
	
	//processing bitmap
	
	app::vector2Bitmap(&image, bitmap.bitmap, bitmap.x, bitmap.y);

	
	/*for (int i = 0; i < bitmap.x; i++)
		for (int j = 0; j < bitmap.y; j++)
		{
			bitmap.bitmap[i][j].red = bitmap.bitmap[i][j].green = bitmap.bitmap[i][j].alpha = 0;
			bitmap.bitmap[i][j].blue = 255;
		}*/
	
	for (int i = 0; i < bitmap.y; i++)
	{
		for (int j = 0; j < bitmap.x; j++)
		{
			std::cout << bitmap.bitmap[j][i].red << ' ';
		}
		std::cout << std::endl;
	}
	
	std::cout<<"    g    \n";
	
	for (int i = 0; i < bitmap.y; i++)
	{
		for (int j = 0; j < bitmap.x; j++)
		{
			std::cout << bitmap.bitmap[j][i].green << ' ';
		}
		std::cout << std::endl;
	}
	
	std::cout<<"    b    \n";
	
	for (int i = 0; i < bitmap.y; i++)
	{
		for (int j = 0; j < bitmap.x; j++)
		{
			std::cout << bitmap.bitmap[j][i].blue << ' ';
		}
		std::cout << std::endl;
	}
	
	//bitmap deallocation
	for (int i = 0; i < bitmap.x; i++)
	{
		delete [] bitmap.bitmap[i];
	}
	delete [] bitmap.bitmap;
	
	return 0;
}