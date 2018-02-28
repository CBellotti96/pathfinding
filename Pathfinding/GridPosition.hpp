#ifndef GRIDPOSITION_HPP_
#define GRIDPOSITION_HPP_

#include "Grid.hpp"
#include <string>
class Grid; //declaring Grid before using in GridPosition
class Path;
class GridPosition{
	friend class Grid;
	friend class Path;
	char value;
	/*Identifies what is at this position
	 *
	 * For example 'P' could identify a Player, 'T' could identify a target
	 */

	int gridRow;
	//the value of the row in Grid which this position is

	int gridCol;
	//the value of the column in Grid which this position is

	Grid * mainGrid;
	//Pointer to the Grid object that holds this Position object

	GridPosition * next;
	//Pointer to next position in a path

	GridPosition * left;
	GridPosition * right;

public:
	GridPosition();
	//Default Constructor

	GridPosition(char v, Grid * g);
	/* Constructor method for Position
	 */

	~GridPosition();
	//destructor
	int getGridRow();
	int getGridCol();
	char getValue();
	GridPosition *** getGrid();
	//getters
};


#endif /* GRIDPOSITION_HPP_ */
