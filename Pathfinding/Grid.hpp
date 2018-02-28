/*
 * Grid.hpp
 *
 *  Created on: Nov 30, 2016
 *      Author: adamc
 */

#ifndef Grid_HPP_
#define Grid_HPP_

#include <string>
#include "GridPosition.hpp"
using namespace std;
class GridPosition; //declaring GridPosition before use
class Path;
class Grid{
	friend class GridPosition;
	friend class Path;
	GridPosition *** grid;
	int width;
	int height;
	GridPosition * root;

//Header file for a path-finding program

public:
	Grid(int r, int c);
	//initializes grid as an empty RxC array of Positions

	~Grid();
	//Destructor method

	void makeGrid();
	//initializes an empty grid
	//used in the constructor

	char getValueAtPosition(GridPosition p);
	//returns the char 'value' at Position p

	Path * getShortestPath(GridPosition * start, GridPosition * end);
	/* Takes two Position object's as parameters, assuming the player is starting at 'start' and ending at 'end'
	 * returns an integer array shortest[rows][cols] = {h,v}, where:
	 * 				h: least amount of horizontal moves
	 * 				v: least amount of vertical moves
	 * to get from 'start' to 'end'
	 */

	void getShortestTrip(GridPosition ** multiplePositions, int start, int size);
	/* Takes in an array (list) of Position objects
	 *
	 * Finds the shortest way to go to all of the positions in multiplePositions
	 *
	 * Returns an array of Position objects which contains the order to visist each position to create the shortest trip
	 *
	 */

	void placeOnGrid(GridPosition * p, int row, int col);
	//Places p on the grid at the given row and col

	void removeFromGrid(GridPosition * p);
	//swaps Position p with an empty space

	void printGrid();
	//prints the Grid

	void addToTree(GridPosition * pos, GridPosition * tRoot);

	GridPosition * search(char c, GridPosition * pos);

	GridPosition * getRoot();
};

#endif /* Grid_HPP_ */
