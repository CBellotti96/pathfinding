/*
 * main.cpp
 *
 *  Created on: Dec 6, 2016
 *      Author: Adam Caulfield and Chris Bellotti
 */
#include <string>
#include "Path.hpp"
#include "Grid.hpp"
#include "GridPosition.hpp"
#include <iostream>
using namespace std;

int main(){

	Grid * userGrid = new Grid(10,10);
	GridPosition * p1 = new GridPosition('C',userGrid);
	GridPosition * p2 = new GridPosition('A',userGrid);
	GridPosition * p3 = new GridPosition('D',userGrid);
	GridPosition * p4 = new GridPosition('B',userGrid);

	userGrid->placeOnGrid(p1,2,4);
	userGrid->placeOnGrid(p2,8,9);
	userGrid->placeOnGrid(p3,6,7);
	userGrid->placeOnGrid(p4,0,8);
	userGrid->printGrid();
	GridPosition * trip[4] = {p1,p2,p3,p4};

	cout << "WELCOME TO GRID" << endl;
	cout << "Enter 'PATH' to find a path between 2 points" << endl;
	cout << "Enter 'TRIP' to find the shortest path between all points" << endl;
	cout << "Enter anything to exit.." << endl;
	string response;
	cin >> response;
	if(response == "PATH"){
		cout << "Enter a starting location defined on the grid (ex A or B)" << endl;
		string s1;
		cin >> s1;
		char start = s1[0];
		while(userGrid->search(start,userGrid->getRoot())==NULL){
			cout << "Please try again" << endl;
			cin >> s1;
			start = s1[0];
		}
		cout << "Enter a stopping location: " << endl;
		string s2;
		cin >> s2;
		char stop = s2[0];
		while(userGrid->search(stop,userGrid->getRoot())==NULL || start == stop){
			cout << "Please try again" << endl;
			cin >> s2;
			stop = s2[0];
		}
		GridPosition * gridStart = userGrid->search(start,userGrid->getRoot());
		GridPosition * gridStop = userGrid->search(stop,userGrid->getRoot());
		Path * userPath = userGrid->getShortestPath(gridStart,gridStop);
		userPath->~Path();
	}
	else if(response == "TRIP"){
		cout << "Enter a starting location defined on the grid (ex A or B)" << endl;
		string s1;
		cin >> s1;
		char start = s1[0];
		while(userGrid->search(start,userGrid->getRoot())==NULL){
			cout << "Please try again" << endl;
			cin >> s1;
			start = s1[0];
		}
		GridPosition * tmp = trip[0];
		int i = 0;
		while(tmp->getValue() != start){
			i++;
			tmp = trip[i];
		}
		trip[i] = trip[0];
		trip[0] = tmp;

		userGrid->getShortestTrip(trip,0,3);
	}

	/********************* TESTING ***********************************
		cout << "Testing Grid() constructor..." << endl;
		Grid * mainGrid = new Grid(10,10);
		cout << "Testing printGrid()..." << endl;
		mainGrid->printGrid();

		cout << endl;
		cout << "Testing placeOnGrid()...." << endl;
		cout << endl;
		cout << "Placing Player 1" << endl;
		GridPosition * player1 = new GridPosition('C',mainGrid);
		mainGrid->placeOnGrid(player1,2,4); //places in row 2, column 4
		cout << "Player 1 row: " << player1->getGridRow() << endl;
		cout << "Player 1 col: " << player1->getGridCol() << endl;
		cout << endl;
		cout << "Placing Target 1" << endl;
		GridPosition * target1 = new GridPosition('T',mainGrid);
		mainGrid->placeOnGrid(target1,8,2);
		cout << "Target 1 row: " << target1->getGridRow() << endl;
		cout << "Target 1 col: " << target1->getGridCol() << endl;
		cout << endl;
		cout << "Placing House 1" << endl;
		GridPosition * house1 = new GridPosition('B',mainGrid);
		mainGrid->placeOnGrid(house1,6,5);
		cout << "House 1 row: " << house1->getGridRow() << endl;
		cout << "House 1 col: " << house1->getGridCol() << endl;
		mainGrid->printGrid();

		cout << endl;
		cout << "Testing removeFromGrid..." << endl;
		cout << "Removing Target 1...." << endl;
		mainGrid->removeFromGrid(target1);
		cout << "Finished removing..." << endl;
		mainGrid->printGrid();

		cout << endl;
		cout << "Testing getShortestPath.. " << endl;
		Path * path1 = mainGrid->getShortestPath(player1, house1);

		cout << "Deleting path1..." << endl;
		path1->~Path();
		mainGrid->printGrid();

		cout << endl;
		cout << "Testing getShortestPath.. " << endl;
		Path * path2 = mainGrid->getShortestPath(house1, player1);

		cout << "Deleting path2..." << endl;
		path2->~Path();
		mainGrid->printGrid();

		cout << "Placing House 2" << endl;
		GridPosition * house2 = new GridPosition('A',mainGrid);
		mainGrid->placeOnGrid(house2,7,7);
		cout << "House 2 row: " << house2->getGridRow() << endl;
		cout << "House 2 col: " << house2->getGridCol() << endl;
		cout << endl;
		cout << "Placing House 3" << endl;
		GridPosition * house3 = new GridPosition('D',mainGrid);
		mainGrid->placeOnGrid(house3,3,9);
		cout << "House 3 row: " << house3->getGridRow() << endl;
		cout << "House 3 col: " << house3->getGridCol() << endl;
		mainGrid->printGrid();

		Grid * mainGrid2 = mainGrid;

		cout << "Testing getShortestTrip" << endl;
		GridPosition * trip1[4] = {player1, house1, house2, house3};
		mainGrid->getShortestTrip(trip1,0,3);

		GridPosition * root = mainGrid->getRoot();

		GridPosition * p1 = mainGrid->search('K',root);
		GridPosition * p2 = mainGrid->search('_',root);
		GridPosition * p3 = mainGrid->search('A',root);

		path2->~Path();
	**********************************************************/

	return 0;
}




