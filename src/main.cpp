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
#include <fstream>
#include <iomanip>
#include <memory>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitMapInfoHeader.h"
#include "Mandelbrot.h"
#include <cstdint>
using namespace mandelbrot;

int const WIDTH  = 1920;
int const HEIGHT = 1080;

int main() {

	double xMin{999999.0 };
	double xMax{-999999.0};
	double yMin{999999.0 };
	double yMax{-999999.0};
	double min{999999.0 };
	double max{-999999.0};
	unsigned int total_pixels{0};

	std::unique_ptr< int [] > histogram( new int[Mandelbrot::MAX_ITERATIONS]{0});
	std::unique_ptr< int [] > iterNumPerPixel( new int[WIDTH * HEIGHT]{0});

	std::string fileName("table.txt");

	Bitmap bitmap(1920, 1080);

	std::ofstream ofs(fileName, std::ios::out);
	if(!ofs) {
		std::cout << "Failure while opening the file: " << fileName << "." << std::endl;
	}

	for(int y = 0; y < HEIGHT; y++) {
		for(int x = 0; x < WIDTH; x++) {
			double xFractal = (x - 5*WIDTH/8) * 2.0/HEIGHT;
			double yFractal = (y - HEIGHT/2 ) * 2.0/HEIGHT;

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			iterNumPerPixel[y*WIDTH + x] = iterations;

			if(iterations != Mandelbrot::MAX_ITERATIONS) {
				histogram[iterations]++;
			}

			uint8_t color = (uint8_t)(256 * (double)iterations / Mandelbrot::MAX_ITERATIONS);
			color = color * color * color;

			bitmap.setPixel(x, y, 0, color, 0);


			if( xFractal < xMin) {xMin= xFractal;}
			if( xFractal > xMax) {xMax= xFractal;}
			if( yFractal < yMin) {yMin = yFractal;}
			if( yFractal > yMax) {yMax = yFractal;}

			if(color < min) {min = color;}
			if(color> max) {max = color;}
		}
	}

	for(unsigned int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		total_pixels += histogram[i];
		ofs << "histogram[" << i << "] = " << histogram[i] << std::endl;
	}

	ofs << std::endl << std::endl << std::endl;


	for(unsigned int i = 0; i < HEIGHT * WIDTH; i++) {
		ofs << "iterNumPerPixel[" << i << "] = " << iterNumPerPixel[i] << std::endl;
	}

	ofs << "The total number of pixels in image equals to " <<  WIDTH * HEIGHT << std::endl;
	ofs << "total_pixels = "<< total_pixels << "(calculated by summing up)." << std::endl;

	std::cout << "x range: " << "[" << xMin << "; " << xMax << "]" << std::endl;
	std::cout << "y range: " << "[" << yMin << "; " << yMax << "]" << std::endl;
	std::cout << "color range: " << "[" << min << "; " << max << "]" << std::endl;

	bitmap.write("test.bmp");

	std::cout << "Finished." << std::endl;

	ofs.close();
	return 0;
}
