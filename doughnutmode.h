#ifndef DOUGHNUTMODE_H
#define DOUGHNUTMODE_H

#include "game.h"
#include <iostream>
#include <fstream>

using namespace std;

class DoughnutMode : public Game{

  public:
    DoughnutMode(int height, int width, float density, int outputType, string outputFile);
    DoughnutMode(string file, int outputType, string outputFile);
    ~DoughnutMode();

    int checkBoundaries(char** arrayGrid, int heightIndex, int widthIndex, int maxHeight, int maxWidth);

};

#endif
