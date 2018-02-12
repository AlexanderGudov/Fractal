/*
 * ZoomList.cpp
 *
 *  Created on: Feb 12, 2018
 *      Author: steel
 */

#include <iostream>
#include "ZoomList.h"

namespace mandelbrot {

ZoomList::ZoomList(int width, int height): m_width(width), m_height(height) {

}


void ZoomList::add(const Zoom& zoom) {
	zooms.push_back(zoom);

	m_xFractCenter += (zoom.x - m_width /2 ) * m_totalScale;
	m_yFractCenter += (zoom.y - m_height/2 ) * m_totalScale;
	m_totalScale *= zoom.scale;

	std::cout << "m_xFractCenter = " << m_xFractCenter << "; " << "m_yFractCenter = " << m_xFractCenter << "; " \
			  << "m_totalScale = " << m_totalScale << std::endl;
}

std::pair<double, double> ZoomList::rescale(int x, int y) {

	double xFractal = (x - m_width/2 ) * m_totalScale + m_xFractCenter;
	double yFractal = (y - m_height/2) * m_totalScale + m_yFractCenter;

	return std::pair<double, double>(xFractal, yFractal);
}

} /* namespace mandelbrot */
