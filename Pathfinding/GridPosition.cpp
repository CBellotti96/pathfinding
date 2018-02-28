/*
 * GridPosition.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: Adam Caulfield and Chris Bellotti
 */

#include "Grid.hpp"
#include "GridPosition.hpp"
#include <string>
#include <iostream>
using namespace std;

GridPosition::GridPosition(){
	value = '_'; //empty
	mainGrid = NULL;
	gridRow = NULL;
	gridCol = NULL;
	next = NULL;
	left = NULL;
	right = NULL;
}

GridPosition::GridPosition(char v, Grid * g){
	value = v;
	mainGrid = g;
	gridRow = NULL;
	gridCol = NULL;
	next = NULL;
	next = NULL;
	left = NULL;
	right = NULL;
}

GridPosition::~GridPosition(){
	value = NULL;
	mainGrid = NULL;
	gridRow = -1;
	gridCol = -1;
}

int GridPosition::getGridCol(){
	return gridCol;
}

int GridPosition::getGridRow(){
	return gridRow;
}

char GridPosition::getValue(){
	return value;
}

GridPosition *** GridPosition::getGrid(){
	return mainGrid->grid;
}

