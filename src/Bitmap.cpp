/*
 * Bitmap.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: steel
 */

#include <fstream>
#include <iostream>

#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitMapInfoHeader.h"

namespace mandelbrot {

Bitmap::Bitmap(int width, int height):
		m_width(width), m_height(height), m_pPixels(new uint8_t[height * width * 3]{0}){

}

bool Bitmap::write(std::string fileName) {
	BitmapFileHeader bitmapFileHeader;
	BitMapInfoHeader bitMapInfoHeader;

	bitmapFileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitMapInfoHeader) + m_width * m_height * 3;
	bitmapFileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitMapInfoHeader);

	bitMapInfoHeader.width = m_width;
	bitMapInfoHeader.height = m_height;

	std::ofstream os(fileName, std::ios::out | std::ios::binary);
	if(!os) {
		std::cout << "Failure while opening the file: " << fileName << "." << std::endl;
		return false;
	}

	os.write(reinterpret_cast<char*>(&bitmapFileHeader), sizeof(BitmapFileHeader));
	os.write(reinterpret_cast<char*>(&bitMapInfoHeader), sizeof(BitMapInfoHeader));
	os.write(reinterpret_cast<char*>(m_pPixels.get()), m_width * m_height * 3);

	os.close();

	if(!os) {
		std::cout << "Failure to close the file: " << fileName << "." << std::endl;
		return false;
	}

	return true;
}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
	uint8_t* pPixel = reinterpret_cast<uint8_t*>( m_pPixels.get() );
	pPixel += 3*(y*m_width + x);
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
}

} /* namespace mandelbrot */
