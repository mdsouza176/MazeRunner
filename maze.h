#pragma once
#include <string>
#include <iostream>

using namespace std;

class Maze
{
private:
	//This variable represents how large the array which stores the maze can get.
	static const int MAX_MAZE_SIZE = 100;
	//This is the char array that will hold the entire maze
	char mazeStorage[MAX_MAZE_SIZE][MAX_MAZE_SIZE];
	//The four ints below store the specs of the maze.

	int height;
	int width;
	int rowExit;
	int colExit;
	//This is a the creature that is used by the maze
	
public:
	//This is the maze constructor that takes a the name of the text file with the maze.
	explicit Maze(std::string maze);
	
	//This should print out the entire maze along with the creature which is inside of it.
	friend ostream &operator<<(ostream &out, const Maze &maze);

	//This destructor will destroy the array that is created by the constructor.
	~Maze();
	//Returns whether the position at the row and column has x or creature in it.
	bool IsClear(const int &row, const int &column) const;

	//returns whether the posiiton at row and column has an x in it
	bool IsWall(const int &row, const int &column) const;

	//Returns whether the coordinate is part of the path
	bool IsPath(const int &row, const int &column) const;

	//Returns whether the row and column coordinate has been visited or not
	bool IsVisited(const int &row, const int &column) const;

	void MarkAsPath(const int &row, const int &column);

	void MarkAsVisited(const int &row, const int &column);
	
	//This method marks a position in the maze as a empty.
	void MarkAsClear(const int &row, const int &column);

	//This method marks the maze with the creaure
	void MarkAsCreature(const int &row, const int &column);
	
	//This returns whether the position you are at in the maze is the exit.
	bool isExit(const int &row, const int& column);

	bool withinMaze(const int & row, const int & col);
};

