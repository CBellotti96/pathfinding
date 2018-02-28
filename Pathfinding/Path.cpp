/*
 * Path.cpp
 *
 *  Created on: Dec 9, 2016
 *      Author: Adam Caulfield and Chris Bellotti
 */

#include "Path.hpp"
#include "Grid.hpp"
#include "GridPosition.hpp"

Path::Path(){
	size = 0;
	pathStart = NULL;
	pathEnd = NULL;
}
Path::~Path(){
	GridPosition *** g = pathStart->getGrid();

	GridPosition * p = pathStart;
	while(p->next!= pathEnd){
		p->next->value = '_';
		GridPosition * tmp = p->next;
		p->next = NULL;
		p = tmp;
	}
	pathStart = NULL;
	pathEnd = NULL;

}
GridPosition * Path::getPathStart(){
	return pathStart;

}
GridPosition * Path::getPathEnd(){
	return pathEnd;
}
int Path::getSize(){
	return size;
}



