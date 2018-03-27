/*
 * ZoomList.h
 *
 *  Created on: Feb 12, 2018
 *      Author: steel
 */

#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include <utility>
#include <cstdint>
#include "Zoom.h"

namespace mandelbrot {

class ZoomList {
private:
	uint32_t m_xCenter{0};
	uint32_t m_yCenter{0};
	double m_scale{1.0};

	int m_width{0};
	int m_height{0};
	std::vector<Zoom> m_zooms;

public:
	ZoomList(int width, int height);
	void add(const Zoom& zoom);
	std::pair<double, double> parallelTransAndScaling(int x, int y);
};

} /* namespace mandelbrot */

#endif /* ZOOMLIST_H_ */
