/*
 * BitMapInfoHeader.h
 *
 *  Created on: Jan 23, 2018
 *      Author: steel
 */

#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>

#pragma pack(push, 1)

namespace mandelbrot {
struct BitMapInfoHeader {
	uint32_t headerSize{40};
	int32_t width;
	int32_t height;
	uint16_t planes{1};
	uint16_t bitPerPixel{24}; // 1 byte for each color (R and G and B)
	uint32_t compression{0};  // we don't use compression
	uint32_t dataSize{0};	  // we are going to set this later to the size of data that we write
	uint32_t horizontalResolution{2400};
	uint32_t verticalResolution{2400};
	uint32_t colors{0};
	uint32_t importantColors{0};
};
}// end of namespace mandelbrot
#pragma pack(pop)



#endif /* BITMAPINFOHEADER_H_ */
