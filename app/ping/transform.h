#ifndef TRANSFORM_H
#define TRANSFORM_H
#include <iostream>
namespace trans {
// Convert unsigned long int to string
	class Transform {
	private:
		mutable char * ConstCharArray;
	public:
		Transform()
		{
			ConstCharArray = new char[4];
		}
		
		~Transform()
		{
			delete [] ConstCharArray;
		}
	
		void LongToCharArr(unsigned long arg) const
		{
			int denom = 0x100;
			for ( int i = 0; i < 4; i++ )
			{
				unsigned char temp = arg % denom;
				ConstCharArray[ 3 - i ] = temp;
				arg /= denom;
			}
		}
		
		char * getArray() const
		{
			return ConstCharArray;
		}
	};
}
#endif