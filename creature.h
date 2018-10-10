#pragma once
#include <string>
#include "maze.h"
using namespace std;
class Creature
{
private:
	//This int is where the creature is located in the maze.
	int positionX;
	int positionY;

public:
	//This constructor will set the position of the creature with the following x, y coordinates in the maze.
	 Creature(const int &x, const int& y);
	~Creature();
	//Allows user to get what position the creature is in the maze.
	int getX() const;
	int getY() const;
	//these four methods will check all possible movements of creature in the maze
	string goNorth(Maze &maze, string& path);

	string goSouth(Maze & maze, string& path);

	string goWest(Maze & maze, string &path);

	string goEast(Maze & maze, string &path);
	
	//The two setter methods for the position of creature
	void setX(const int& x);

	void setY(const int& y);

	//Prints coordinates of creature
	friend ostream &operator<<(ostream &out, const Creature &crea);

	//This method takes a maze and returns how the way for the creature to solve it.
	string Solve(Maze &maze);

};

