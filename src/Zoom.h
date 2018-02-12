/*
 * Zoom.h
 *
 *  Created on: Feb 12, 2018
 *      Author: steel
 */

#ifndef ZOOM_H_
#define ZOOM_H_

namespace mandelbrot {

struct Zoom {
	int x{0};
	int y{0};
	double scale{0.0};

	Zoom(int x, int y, double scale): x(x), y(y), scale(scale) {}
};

} /* namespace mandelbrot */

#endif /* ZOOM_H_ */
