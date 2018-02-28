/*
 * Path.hpp
 *
 *  Created on: Dec 9, 2016
 *      Author: Adam Caulfield and Chris Bellotti
 */

#ifndef PATH_HPP_
#define PATH_HPP_

class Grid;
class GridPosition;

class Path{
	friend class Grid;
	friend class GridPosition;
	GridPosition * pathStart;
	GridPosition * pathEnd;
	int size;

public:
	Path();
	~Path();
	GridPosition * getPathStart();
	GridPosition * getPathEnd();
	int getSize();
};



#endif /* PATH_HPP_ */
