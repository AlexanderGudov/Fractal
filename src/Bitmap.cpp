/*
 * Bitmap.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: steel
 */

#include "Bitmap.h"

namespace mandelbrot {

Bitmap::Bitmap(int width, int height): m_width(width), m_height(height) {

}

bool Bitmap::write(std::string fileName) {
	return false;
}

void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

}

} /* namespace mandelbrot */
