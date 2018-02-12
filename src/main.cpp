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
#include <cstdint>
#include <cmath>

#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitMapInfoHeader.h"
#include "Mandelbrot.h"
#include "Zoom.h"
#include "ZoomList.h"

using namespace mandelbrot;

int const WIDTH  = 1920;
int const HEIGHT = 1080;

int main() {

	double xMin{999999.0 };
	double xMax{-999999.0};
	double yMin{999999.0 };
	double yMax{-999999.0};
	double  min{999999.0 };
	double  max{-999999.0};
	unsigned int total_pixels{0};

	std::unique_ptr< int [] > histogram( new int[Mandelbrot::MAX_ITERATIONS]{0});
	std::unique_ptr< int [] > iterNumPerPixel( new int[WIDTH * HEIGHT]{0});

	std::string fileName("table.txt");
	Bitmap bitmap(1920, 1080);
	ZoomList zoomList(WIDTH, HEIGHT);

	zoomList.add( Zoom(WIDTH/2, HEIGHT/2, 2.0/WIDTH) );

	std::ofstream ofs(fileName, std::ios::out);
	if(!ofs) {
		std::cout << "Failure while opening the file: " << fileName << "." << std::endl;
	}

	for(int y = 0; y < HEIGHT; y++) {
		for(int x = 0; x < WIDTH; x++) {
/*			double xFractal = (x - 5*WIDTH/8) * 2.0/HEIGHT;
			double yFractal = (y - HEIGHT/2 ) * 2.0/HEIGHT;*/

/*			double xFractal = (x - WIDTH/2  ) * 2.0/HEIGHT;
			double yFractal = (y - HEIGHT/2 ) * 2.0/HEIGHT;*/

			std::pair<double, double> coords = zoomList.rescale(x, y);

			int iterations = Mandelbrot::getIterations(coords.first, coords.second);

			iterNumPerPixel[y*WIDTH + x] = iterations;

			if(iterations != Mandelbrot::MAX_ITERATIONS) {
				histogram[iterations]++;
			}

/*			if( xFractal < xMin) {xMin= xFractal;}
			if( xFractal > xMax) {xMax= xFractal;}
			if( yFractal < yMin) {yMin = yFractal;}
			if( yFractal > yMax) {yMax = yFractal;}*/

			if( coords.first < xMin) {xMin= coords.first;}
			if( coords.first > xMax) {xMax= coords.first;}
			if( coords.second < yMin) {yMin = coords.second;}
			if( coords.second > yMax) {yMax = coords.second;}
		}
	}

	for(unsigned int i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
		total_pixels += histogram[i];
	}

	std::cout << "total_pixels = "<< total_pixels << "(calculated by summing up). On the other hand WIDTH * HEIGHT = " << WIDTH * HEIGHT << std::endl;

	std::cout << "x range: " << "[" << xMin << "; " << xMax << "]" << std::endl;
	std::cout << "y range: " << "[" << yMin << "; " << yMax << "]" << std::endl;
	std::cout << "color range: " << "[" << min << "; " << max << "]" << std::endl;

	for(int y = 0; y < HEIGHT; y++) {
		for(int x = 0; x < WIDTH; x++) {
			uint8_t red   = 0;
			uint8_t green = 0;
			uint8_t blue  = 0;

			int iterations = iterNumPerPixel[y*WIDTH + x];

			if(iterations != Mandelbrot::MAX_ITERATIONS) {
				double hue = 0.0;
				for(int i = 0; i <= iterations; i++){
					hue += static_cast<double>(histogram[i]) / total_pixels;
				}
				green = pow(255, hue);
			}

			bitmap.setPixel(x, y, red, green, blue);

		}
	}

	bitmap.write("test.bmp");

	std::cout << "Finished." << std::endl;

	ofs.close();
	return 0;
}
