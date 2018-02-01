//============================================================================
// Name        : Fractal.cpp
// Author      : Kravchuk A.V.
// Version     :
// Copyright   : Your copyright notice
//++++++++++++++++++++++++++++++ Description ++++++++++++++++++++++++++++++ :

//                           Bitmap-File Structure:
//Each bitmap file contains:
//1)a bitmap-file header (BitmapFileHeader.h);
//2)a bitmap-information header (BitMapInfoHeader.h);
//3)a color table;
//4)an array of bytes that defines the bitmap bits.
//
//============================================================================

#include <iostream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitMapInfoHeader.h"

using namespace mandelbrot;

int main() {

	int const WIDTH  = 1920;
	int const HEIGHT = 1080;

//	std::cout << "Size of BitmapFileHeader: " << sizeof(BitmapFileHeader) << " bytes."<< std::endl;
//	std::cout << "Size of BitMapInfoHeader: " << sizeof(BitMapInfoHeader) << " bytes."<< std::endl;
	Bitmap bitmap(1920, 1080);
	for(int y = 0; y < HEIGHT; y++) {
		for(int x = 0; x < WIDTH; x++) {
			if(y < HEIGHT/3) {
				bitmap.setPixel(x, y,  0xFF,  0x00,  0x00);
			} else if (y < 2*HEIGHT/3) {
				bitmap.setPixel(x, y,  0x00,  0x00,  0xFF);
			} else if (y < HEIGHT) {
				bitmap.setPixel(x, y,  0xFF,  0xFF,  0xFF);
			}
		}
	}

	bitmap.write("test.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}
