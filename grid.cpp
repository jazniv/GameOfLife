#include "grid.h"
#include <cstring>
#include <fstream>

// Builds grid from file
Grid::Grid(string file){
  string line;
  ifstream inFS;
  inFS.open(file);

  if (inFS.is_open()) {

    // Gets height and width from file
    int lineNum = 1;
    while (getline(inFS, line) && lineNum < 3) {
      if (lineNum == 1) {
        m_height = stoi(line);
      } else if (lineNum == 2) {
        m_width = stoi(line);
      }
      lineNum++;
    }

    m_grid = new char*[m_height];
    for (int i = 0; i < m_height; ++i) {
      m_grid[i] = new char[m_width];
    }

  }
  inFS.close();
  buildGridFromFile(file);

}

void Grid::buildGridFromFile(string file){
  string line;
  ifstream inFS;
  inFS.open(file);

  int nextLine = 0;
  int l = 0;
  while (getline(inFS, line)) {

    // Skip over height and width lines
    if (nextLine < 2) {
      nextLine++;
    } else {

      // Create char array from line
      char gridLine[line.length() + 1];
      strcpy(gridLine, line.c_str());

      // Populate m_grid with gridLine contents
      for (int k = 0; k < m_width; ++k) {
        m_grid[l][k] = gridLine[k];
      }
      l++;
    }


  }
  inFS.close();

}

// Copy constructor
Grid::Grid(Grid* g){
  m_height = g->getHeight();
  m_width = g->getWidth();
  char** g_Grid = g->getGrid();

  m_grid = new char*[m_height];
  for (int i = 0; i < m_height; ++i) {
    m_grid[i] = new char[m_width];
  }

  for (int j = 0; j < m_height; ++j) {
    for (int k = 0; k < m_width; ++k) {
      m_grid[j][k] = g_Grid[j][k];
    }
  }

}

// Builds empty Grid
Grid::Grid(int height, int width){
  m_height = height;
  m_width = width;
  m_grid = new char*[m_height];

  for (int i = 0; i < m_height; ++i) {
    m_grid[i] = new char[m_width];
  }

  for (int j = 0; j < m_height; ++j) {
    for (int k = 0; k < m_width; ++k) {
      m_grid[j][k] = '-';
    }
  }

}

// Builds grid from input
Grid::Grid(int height, int width, float density){
  m_height = height;
  m_width = width;
  m_grid = new char*[m_height];

  for (int i = 0; i < m_height; ++i) {
    m_grid[i] = new char[m_width];
  }

  for (int j = 0; j < m_height; ++j) {
    for (int k = 0; k < m_width; ++k) {
      m_grid[j][k] = '-';
    }
  }

  randomizeGrid(density);

}

void Grid::randomizeGrid(float density){

  srand (time(NULL));
  int numFilled = density * (m_height * m_width);

  while (numFilled > 0) {

    int randHeight = rand()%m_height;
    int randWidth = rand()%m_width;

    if (m_grid[randHeight][randWidth] == '-') {
      m_grid[randHeight][randWidth] = 'X';
      numFilled--;
    }

  }

}

Grid::~Grid(){
  for (int i = 0; i < m_height; ++i) {
	   delete[] m_grid[i];
  }
  delete [] m_grid;
}

char** Grid::getGrid(){
  return m_grid;
}

int Grid::getHeight(){
  return m_height;
}

int Grid::getWidth(){
  return m_width;
}

void Grid::addCell(int heightIndex, int widthIndex){
  m_grid[heightIndex][widthIndex] = 'X';
}

void Grid::deleteCell(int heightIndex, int widthIndex){
  m_grid[heightIndex][widthIndex] = '-';
}

void Grid::copyGrid(Grid* g){
  char** g_Grid = g->getGrid();

  for (int j = 0; j < m_height; ++j) {
    for (int k = 0; k < m_width; ++k) {
      m_grid[j][k] = g_Grid[j][k];
    }
  }
}

string Grid::printGrid(){
  string gridString = "";
  for (int i = 0; i < m_height; ++i) {
    for (int j = 0; j < m_width; ++j) {
      gridString += m_grid[i][j];
      gridString += " ";
    }
    gridString += "\n";
  }

  return gridString;
}

bool Grid::isEqual(Grid* g){

  return (this->printGrid() == g->printGrid());
}
