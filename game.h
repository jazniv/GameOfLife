#ifndef GAME_H
#define GAME_H

#include "grid.h"
#include <iostream>
#include <fstream>

using namespace std;

class Game{

  public:
    Game(int height, int width, float density, int outputType, string outputFile);
    Game(string file, int outputType, string outputFile);
    ~Game();

    void play();
    void output();
    int checkNeighbors(int heightIndex, int widthIndex);
    int numNeighbors(Grid* grid, int heightIndex, int widthIndex);
    virtual int checkBoundaries(char** arrayGrid, int heightIndex, int widthIndex, int maxHeight, int maxWidth);
    bool isStabilized();
    bool isEmpty();

    string printGeneration(Grid* grid);
    void writeToFile();

    int generationNum;
    int m_outputType;
    string m_outputFile;
    Grid* currGrid;
    Grid* prevGen1Grid;
    Grid* prevGen2Grid;
    Grid* prevGen3Grid;

};

#endif
