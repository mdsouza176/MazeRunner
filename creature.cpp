
#include "creature.h"








Creature::Creature(const int & x, const int &y)
{
	positionX = x;
	positionY = y;

}

Creature::~Creature()
{
}

//Returns the x posiiton of the creature in the maze.
int Creature::getX() const
{
	return positionX;
}

//Returns the y position of the creature in the maze.
int Creature::getY() const
{
	return positionY;
}


// This is a recursive backtracking method that looks whether going
//north and all combinations with north as the first step will lead
//to the exit, else it returns X.

string Creature::goNorth(Maze &maze, string & path)
{
	//if going north is clear and has not been visited before, move north and call again.

	if (maze.IsClear(this->getX()-1, this->getY()) && maze.withinMaze(this->getX() - 1, this->getY())) {
		this->positionX -= 1;
		path += "N";

		if (maze.isExit(this->getX(), this->getY())) {
			return path;
		}
		else {
			string newPath = "";
			if (goNorth(maze, newPath) != "X") {
				path += newPath;
				return path;
			}
			else {
				newPath = "";
			}
			if (goEast(maze, newPath) != "X") {
				path += newPath;
				return path;
			}
			else {
				newPath = "";
			}
			if (goWest(maze, newPath) != "X") {
				path += newPath;
				return path;
			}
			else {
				path.pop_back();
				maze.MarkAsVisited(this->positionX, this->positionY);
				this->positionX++;
			}
		}
	}
	return "X";
}
// This is a recursive backtracking method that looks whether going
//east and all combinations with east as the first step will lead
//to the exit, else it returns X.
string Creature::goEast(Maze &maze, string &path) {
	if (maze.IsClear(this->getX(), this->getY()+1) && maze.withinMaze(this->getX(), this->getY() + 1)) {
		this->positionY += 1;
		path += "E";
		if (maze.isExit(this->getX(), this->getY())) {
			return path;
		}
		string newPath = "";
		if (goEast(maze, newPath) != "X") {
			path += newPath;
			return path;
		}
		else {
			newPath = "";
		}
		if (goNorth(maze, newPath) != "X") {
			path += newPath;
			return path;
		}
		else {
			newPath = "";
		}
		if (goSouth(maze, newPath) != "X") {
			path += newPath;
			return path;
		}
		else {
			newPath = "";
			path.pop_back();
			maze.MarkAsVisited(this->getX(), this->getY());
			this->positionY--;
		}
	}
	return "X";
}
//This is a recursive backtracking method that looks whether going 
//south and all combinations with south as the first step will lead
//to the exit, else it returns X.
string Creature::goSouth(Maze &maze, string &path) {
	if (maze.IsClear(this->getX() +1, this->getY()) && maze.withinMaze(this->getX() + 1, this->getY())) {
		this->positionX++;
		path += "S";

		if (maze.isExit(this->getX(), this->getY())) {
			return path;
		}
		else {
			string newPath = "";
			if (goSouth(maze, newPath) != "X") {
				path += newPath;
				return path;
			}
			else {
				newPath = "";
			}
			if (goEast(maze, newPath) != "X") {
				path += newPath;
				return path;
			}
			else {
				newPath = "";
			}
			if (goWest(maze, newPath) != "X") {
				path += newPath;
				return path;
			}
			else {
				path.pop_back();
				maze.MarkAsVisited(this->positionX, this->positionY);
				this->positionX--;
			}
		}
	}
	return "X";
}
// This is a recursive backtracking method that looks whether going
//west and all combinations with west as the first step will lead
//to the exit, else it returns X.
string Creature::goWest(Maze &maze, string &path) {
	if (maze.IsClear(this->getX(), this->getY() - 1) && maze.withinMaze(this->getX(), this->getY() - 1)) {
		this->positionY -= 1;
		path += "W";
		if (maze.isExit(this->getX(), this->getY())) {
			return path;
		}
		string newPath = "";
		if (goWest(maze, newPath) != "X") {
			path += newPath;
			return path;
		}
		else {
			newPath = "";
		}
		if (goNorth(maze, newPath) != "X") {
			path += newPath;
			return path;
		}
		else {
			newPath = "";
		}
		if (goSouth(maze, newPath) != "X") {
			path += newPath;
			return path;
		}
		else {
			path.pop_back();
			maze.MarkAsVisited(this->getX(), this->getY());
			this->positionY++;
		}
	}
	return "X";
}

//method that can change position of x
void Creature::setX(const int & x)
{
	this->positionX = x;
}
//method that can change creature position y
void Creature::setY(const int & y)
{
	this->positionY = y;
}
//This method checks whether there is an exit to the following maze
//by going north, south, east, west, all possible combinations
//and if there is, returns that path as a string, else returns X.
string Creature::Solve(Maze & maze)
{
	string path = "";
	if (maze.isExit(this->positionX, this->positionY) == true) {
		return "At Exit";
	}
	path = goNorth(maze, path);
	if (path == "X") {
		path = "";
		path = goSouth(maze, path);
	}
	if (path == "X") {
		path = "";
		path = goEast(maze, path);
	}
	if (path == "X") {
		path = "";
		path = goWest(maze, path);
	}
	return path;
}


//Prints out the creatures current position.
ostream &operator<<(ostream &out, const Creature &crea) {
	out << "(" << crea.getX() << ", " << crea.getY() << ")";
	return out;
}

