
#include <iostream>
#include <fstream>
#include "maze.h"

using namespace std;


//Constructor takes a string name and opens the text file with that
//name and adds the maze attributes from the text file to the 
//maze by using a 2d character array.
Maze::Maze(std::string &maze)
{
	ifstream openFile;
	openFile.open(maze);
		openFile >> width;
		openFile >> height;
		openFile >> rowExit;
		openFile >> colExit;
		for (int i = 0; i < height; i++) {
			openFile >> std::noskipws >> mazeStorage[i][0];
			for (int j = 0; j < width; j++) {
				openFile >> std::noskipws >> mazeStorage[i][j];
			}
		}

		
}

//Basic destructor
Maze::~Maze()
{

}
//Checks whether a space is at the given coordinate.
bool Maze::IsClear(const int &row, const int &column) const
{
	return (mazeStorage[row][column] == ' ');
}

//Checks whether an X is at the given coordinate.
bool Maze::IsWall(const int &row, const int &column) const
{
	return (mazeStorage[row][column] == 'x');
}

//Checks whether a * is at the given coordinate.
bool Maze::IsPath(const int &row, const int &column) const
{
	return (mazeStorage[row][column] == '*');
}
//Checks whether a plus is at the given coordinate.
bool Maze::IsVisited(const int &row, const int &column) const
{
	return (mazeStorage[row][column] == '+');
}
//Prints a * at the given coordinate to mark as part of the path
void Maze::MarkAsPath(const int &row, const int &column)
{
	mazeStorage[row][column] = '*';
}
//Prints a + at the given coordinate a mark as visited
void Maze::MarkAsVisited(const int &row, const int &column)
{
	mazeStorage[row][column] = '+';
}

void Maze::MarkAsClear(const int & row, const int & column)
{
	mazeStorage[row][column] = ' ';
}
//Can mark the creature in the maze so its more convenient to see it
void Maze::MarkAsCreature(const int & row, const int & column)
{
	mazeStorage[row][column] = 'o';
}
//Checks whether the position is the exit of the maze
bool Maze::isExit(const int & row, const int & column)
{
	return (row == this->rowExit && column == this->colExit);
}

//Checks whether the position is within the allocated size of maze
bool Maze::withinMaze(const int & row, const int & col)
{
	if (row > this->height-1 ||  col > this->width-1 || row <0 || col < 0) {
		return false;
	}
	return true;
}



//The friend function prints out the specs of the maze and the actual maze 
//itself which has been stored in a char array.
ostream & operator<<(ostream & out, const Maze & maze)
{
	out << maze.width << " " << maze.height <<endl << maze.rowExit << " " << maze.colExit;
	out << endl;
	for (int i = 0; i < maze.height; i++) {
		for (int j = 0; j < maze.width; j++) {
			out << std::noskipws<< maze.mazeStorage[i][j];

		}
		out << endl;
	}
	return out;
}
