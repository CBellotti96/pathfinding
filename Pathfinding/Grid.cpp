/*
 * Grid.cpp
 *
 *  Created on: Nov 30, 2016
 *      Author: Adam Caulfield and Chris Bellotti
 */

#include "Grid.hpp"
#include "GridPosition.hpp"
#include "Path.hpp"
#include <iostream>
#include <stdlib.h>
using namespace std;

Grid::Grid(int R, int C){
	width = C;
	height = R;
	grid = new GridPosition**[height];
	for(int r=0; r<height; r++){
		grid[r] = new GridPosition*[width];
	}
	makeGrid();
	root = NULL;
}

Grid::~Grid(){
	for(int c = 0; c<width; c++){
		for(int r = 0; r<height; r++){
			grid[r][c]->~GridPosition();
		}
	}
	width = 0;
	height = 0;
	root = NULL;
	grid = NULL;
}

void Grid::makeGrid(){
	for(int c = 0; c<width; c++){
		for(int r = 0; r<height; r++){
			grid[r][c] =  new GridPosition('_', this);
		}
	}
}

char Grid::getValueAtPosition(GridPosition p){
	char pValue = p.getValue();
	return pValue;
}

Path * Grid::getShortestPath(GridPosition * start, GridPosition * end){
	int rowDiff = start->gridRow - end->gridRow;
	int colDiff = start->gridCol - end->gridCol;

	cout << "Your trip will cover " << (abs(rowDiff)+abs(colDiff)) << " spaces" << endl;

	Path * newPath = new Path();

	newPath->pathStart = start;
	newPath->pathEnd = end;
	newPath->size = 2;

	GridPosition * p = start;
	if(rowDiff < 0){
		//int r=-1;
	//	cout << "rowDiff < 0" << endl;
		for(int r = -1; r>=rowDiff; r--){
			p->next = (p->getGrid())[p->gridRow + 1][p->gridCol]; //goes up
			p->next->gridRow = p->gridRow + 1;
			p->next->gridCol = p->gridCol;
			if(p->next!=NULL && p->next->value == '_'){
				p->next->value = 'x';
			}
//			printGrid();
//			cout << endl;
			p = p->next;
			newPath->size++;
		}
	}
	if(rowDiff > 0){
	//	cout << "rowDiff > 0" << endl;
	//	cout << "oops " << endl;
		for(int r = rowDiff; r>0; r--){
			p->next = (p->getGrid())[p->gridRow - 1][p->gridCol]; //goes up
			p->next->gridRow = p->gridRow - 1;
			p->next->gridCol = p->gridCol;
			if(p->next!=NULL && p->next->value == '_'){
				p->next->value = 'x';
			}
	//		printGrid();
	//		cout << endl;
			p = p->next;
			newPath->size++;
		}
	}
	if(colDiff < 0){
	//	cout << "colDiff < 0" << colDiff << endl;
		for(int r = colDiff; r<0; r++){
			p->next = (p->getGrid())[p->gridRow][p->gridCol+1]; //goes up
			p->next->gridRow = p->gridRow;
			p->next->gridCol = p->gridCol+1;
			if(p->next!=NULL && p->next->value == '_'){
				p->next->value = 'x';
			}
//			printGrid();
//			cout << endl;
			p = p->next;
			newPath->size++;
		}
	}

	if(colDiff > 0){
//		cout << "colDiff > 0" << endl;
		for(int c = colDiff; c>0; c--){
			p->next = (p->getGrid())[p->gridRow][p->gridCol-1]; //goes up
			p->next->gridRow = p->gridRow;
			p->next->gridCol = p->gridCol-1;
			if(p->next!=NULL && p->next->value == '_'){
				p->next->value = 'x';
			}
//			printGrid();
//			cout << endl;
			p = p->next;
			newPath->size++;
		}
	}
	cout <<"Shortest path: " << endl;
	printGrid();

	return newPath;
}

void Grid::getShortestTrip(GridPosition ** multiplePositions, int start, int size){
	int minDistance = 999999;

	if(start == size){
		for(int i=0; i<=size; i++){
			cout << multiplePositions[i]->value << "(" << multiplePositions[i]->gridRow << ", " << multiplePositions[i]->gridCol << ")" << "->";
		}
		cout << endl;

	}

	else{
		int minIndex = 0;
		for(int i = start+1; i<=size; i++){
			int rowDiff = abs(multiplePositions[start]->gridRow - multiplePositions[i]->gridRow);
			int colDiff = abs(multiplePositions[start]->gridCol - multiplePositions[i]->gridCol);
			int dist = rowDiff+colDiff;
			if(dist<minDistance){
				minDistance = dist;
				minIndex = i;
			}//if
		}//for
		GridPosition * tmp = multiplePositions[minIndex];
		multiplePositions[minIndex] = multiplePositions[start+1];
		multiplePositions[start+1] = tmp;

		Path * p = getShortestPath(multiplePositions[start],multiplePositions[start+1]);
		getShortestTrip(multiplePositions, start+1, size);
	}


}


void Grid::placeOnGrid(GridPosition * p, int row, int col){
	p->gridRow = row;
	p->gridCol = col;
	grid[row][col] = p;

	if(p->mainGrid->root == NULL){
		p->mainGrid->root = p;
	}
	else{
		addToTree(p,p->mainGrid->root);
	}
}

void Grid::removeFromGrid(GridPosition * p){
	int r = p->gridRow;
	int c = p->gridCol;
	grid[r][c] = new GridPosition();
	p->~GridPosition();
}

void Grid::printGrid(){
	for(int r = 0; r<width; r++){
		cout << "[ ";
		for(int c = 0; c<height; c++){
			cout << grid[r][c]->getValue() << "  ";
		}
		cout << "]" << endl;
	}
}

void Grid::addToTree(GridPosition * pos, GridPosition * treeRoot){
	if(treeRoot->value > pos->value){
		if(treeRoot->left == NULL){
			treeRoot->left = pos;
		}

		else{
			addToTree(pos,treeRoot->left);
		}
	}
	if(treeRoot->value < pos->value){
		if(treeRoot->right == NULL){
			treeRoot->right = pos;
		}

		else{
			addToTree(pos,treeRoot->right);
		}
	}
}

GridPosition * Grid::search(char c, GridPosition * pos){
	if(pos->value == c){
		return pos;
	}

	if(pos->left !=NULL && c < pos->value){
		return search(c,pos->left);
	}
	if(pos->right != NULL && c > pos->value){
		return search(c,pos->right);
	}
	else{
		cout << c << " is not on the Grid" << endl;
		return NULL;
	}


}

GridPosition * Grid::getRoot(){
	return root;
}

/*
 * Path struct (linked list)
 *
 * find all players/target
 * find closest player/target
 *
 *
 */



