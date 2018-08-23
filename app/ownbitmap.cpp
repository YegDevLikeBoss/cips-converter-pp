/*
Copyright (c) Artyom Yeghoyan 2018
*/
#include <iostream>
//#include <bitset> //Debugging purpose
#include "lodepng.h"
#include "bmpdecoder.h"

namespace app{
	struct Pixel //16 bit per channel bitmap pixel structure (8 used)
	{
		unsigned short red;
		unsigned short green;
		unsigned short blue;
		unsigned short alpha;
	};
	struct Bitmap //16 bit per pixel (8 used) bitmap
	{
		int x; //width
		int y; //height
		Pixel** bitmap;
	};

	//lodepng provided std::vector<unsigned char> bitmap to Bitmap::Pixel** converting function
	void vector2Bitmap(
		std::vector<unsigned char> *image, //convert from
		Pixel** bitmap, //convert to
		int x, //width
		int y //height )
	{
		unsigned char* array = image->data(); //Copy vector to array for conversion
		//std::cout << image->size() << ' '; //Debugging purpose
		for (int i = 0; i < image->size(); i += 4 )
		{
			//std::cout<<i/4%x<<'-'<<i/4/x<<' '; //Outputs array dimensions for debugging
			bitmap[ i / 4 % x ][ i / 4 / x ].red = array[ i ]; //R
			bitmap[ i / 4 % x ][ i / 4 / x ].green = array[ i + 1 ]; //G
			bitmap[ i / 4 % x ][ i / 4 / x ].blue = array[ i + 2 ]; //B
			bitmap[ i / 4 % x ][ i / 4 / x ].alpha = array[ i + 3 ]; //A
			//std::bitset<8> bn(array[i+2]);  //Outputs vector contents in binary for debugging
			//std::cout << bn;
		}
		//std::cout << "end of function\n"; //Debugging purpose
	}
}

int main(int argc, char *argv[])
{
	//Following 16 lines of code are provided under license from "bmpdecoder.h" file
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
	
	app::Bitmap bitmap; //Bitmap declaration
	
	//Assigning bitmap size
	bitmap.x = w;
	bitmap.y = h;
	
	//Bitmap allocation
	bitmap.bitmap = new app::Pixel*[bitmap.x];	
	for (int i = 0; i < bitmap.x; i++)
	{
		bitmap.bitmap[i] = new app::Pixel[bitmap.y];
	}
	
	//Vector to bitmap conversion
	app::vector2Bitmap(
		&image,
		bitmap.bitmap,
		bitmap.x,
		bitmap.y );

	//At this point you can freely modify bitmap structure
	
	//Blank white bitmap definition (for future)
	/*for (int i = 0; i < bitmap.x; i++)
			for (int j = 0; j < bitmap.y; j++)
			{
				bitmap.bitmap[i][j].red = bitmap.bitmap[i][j].green = bitmap.bitmap[i][j].blue = bitmap.bitmap[i][j].alpha = 255;
			}*/
	
	std::cout<<"RED\n"; //Red channel output for debugging
	for (int i = 0; i < bitmap.y; i++) {
		for (int j = 0; j < bitmap.x; j++) {
			std::cout << bitmap.bitmap[j][i].red << ' ';
		}
		std::cout << std::endl;
	}
	
	std::cout<<"GREEN\n"; //Green channel output for debugging
	for (int i = 0; i < bitmap.y; i++) {
		for (int j = 0; j < bitmap.x; j++) {
			std::cout << bitmap.bitmap[j][i].green << ' ';
		}
		std::cout << std::endl;
	}
	
	std::cout<<"BLUE\n"; //Blue channel output for debugging
	for (int i = 0; i < bitmap.y; i++)
	{
		for (int j = 0; j < bitmap.x; j++)
		{
			std::cout << bitmap.bitmap[j][i].blue << ' ';
		}
		std::cout << std::endl;
	}
	
	//End of modification
	
	//There will be PNG output in future, but at this point all modifications will be lost
	
	//Bitmap deallocation
	for (int i = 0; i < bitmap.x; i++)
	{
		delete [] bitmap.bitmap[i];
	}
	delete [] bitmap.bitmap;
	
	return 0;
}