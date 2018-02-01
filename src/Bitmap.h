/*
 * Bitmap.h
 *
 *  Created on: Jan 25, 2018
 *      Author: steel
 */

#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>
#include <cstdint>
#include <memory>

namespace mandelbrot {

class Bitmap {
private:
	int m_width{0};
	int m_height{0};
	std::unique_ptr<uint8_t []> m_pPixels{nullptr};
public:
	Bitmap(int width, int height);
	bool write(std::string fileName);
	void setPixel(int x /*column*/, int y /*row*/, uint8_t red, uint8_t green, uint8_t blue);
};

} /* namespace mandelbrot */

#endif /* BITMAP_H_ */
