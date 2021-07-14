#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <fstream>
using namespace std;

class Grid{
  public:
    Grid(int height, int width);
    Grid(int height, int width, float density);
    Grid(Grid* g);
    Grid(string file);
    ~Grid();

    // Getters
    int getHeight();
    int getWidth();
    char** getGrid();

    void addCell(int heightIndex, int widthIndex);
    void deleteCell(int heightIndex, int widthIndex);
    string printGrid();
    bool isEqual(Grid* g);
    void copyGrid(Grid* g);

    int m_height;
    int m_width;
    char **m_grid;

  private:
    void randomizeGrid(float density);
    void buildGridFromFile(string file);

};

#endif
