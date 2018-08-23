#include <iostream>

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
	//layer
	
}
namespace imgfile
{
	
}

int main()
{
	//bitmap declaration
	app::Bitmap bitmap;
	
	//bitmap size
	std::cout << "size";
	std::cin >>bitmap.x;
	std::cin >>bitmap.y;
	
	//bitmap allocation
	bitmap.bitmap = new app::Pixel*[bitmap.x];
	
	for (int i = 0; i < bitmap.x; i++)
	{
		bitmap.bitmap[i] = new app::Pixel[bitmap.y];
	}
	
	//processing bitmap
	for (int i = 0; i < bitmap.x; i++)
		for (int j = 0; j < bitmap.y; j++)
		{
			bitmap.bitmap[i][j].red = bitmap.bitmap[i][j].green = bitmap.bitmap[i][j].alpha = 0;
			bitmap.bitmap[i][j].blue = 255;
		}
	
	for (int i = 0; i < bitmap.x; i++)
	{
		for (int j = 0; j < bitmap.y; j++)
		{
			std::cout << bitmap.bitmap[i][j].red;
		}
		std::cout << std::endl;
	}
	
		for (int i = 0; i < bitmap.x; i++)
	{
		for (int j = 0; j < bitmap.y; j++)
		{
			std::cout << bitmap.bitmap[i][j].blue;
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
