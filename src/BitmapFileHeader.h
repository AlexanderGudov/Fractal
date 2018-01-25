/*
 * BitmapFileHeader.h
 *
 *  Created on: Jan 22, 2018
 *      Author: steel
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

#pragma pack(push, 1) // exact fit - no padding

namespace mandelbrot {
struct BitmapFileHeader {
	//	char header[2]{'B', 'M'};
	uint8_t header[2]{0x42, 0x4D};
	uint32_t fileSize;
	uint32_t reserved{0x0};
	uint32_t dataOffset;
};
} // end of namespace mandelbrot
#pragma pack(pop)



#endif /* BITMAPFILEHEADER_H_ */
