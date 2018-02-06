/*
 * Mandelbrot.h
 *
 *  Created on: Feb 1, 2018
 *      Author: steel
 */

#ifndef MANDELBROT_H_
#define MANDELBROT_H_

namespace mandelbrot {

class Mandelbrot {
public:
	static const int MAX_ITERATIONS = 1000;
public:
	static int getIterations(double x, double y);
};

} /* namespace mandelbrot */

#endif /* MANDELBROT_H_ */
