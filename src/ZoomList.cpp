/*
 * ZoomList.cpp
 *
 *  Created on: Feb 12, 2018
 *      Author: steel
 */

#include <iostream>
#include "ZoomList.h"

namespace mandelbrot {

ZoomList::ZoomList(int width, int height): m_width(width), m_height(height) {}


void ZoomList::add(const Zoom& zoom) {
	m_zooms.push_back(zoom);

	m_xCenter = (zoom.x + m_xCenter) - m_width/2 ;
	m_yCenter = (zoom.y + m_yCenter) - m_height/2;
	m_combinedScale *= zoom.scale;

	std::cout << "m_xCenter = " << m_xCenter << "; "/
			  << "m_yCenter = " << m_yCenter << "; " \
			  << "m_scale = " << m_scale << std::endl;
}

std::pair<double, double> ZoomList::parallelTranslAndScaling(int x, int y) {

	double xFractal = ( x + ( (-m_width/2 ) + m_xCenter ) ) * m_scale;
	double yFractal = ( y + ( (-m_height/2) + m_yCenter ) ) * m_scale;

	return std::pair<double, double>(xFractal, yFractal);
}

} /* namespace mandelbrot */
