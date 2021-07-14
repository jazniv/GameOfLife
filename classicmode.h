#ifndef CLASSICMODE_H
#define CLASSICMODE_H

#include "game.h"
#include <iostream>
#include <fstream>

using namespace std;

class ClassicMode : public Game{

  public:
    ClassicMode(int height, int width, float density, int outputType, string outputFile);
    ClassicMode(string file, int outputType, string outputFile);
    ~ClassicMode();

    int checkBoundaries(char** arrayGrid, int heightIndex, int widthIndex, int maxHeight, int maxWidth);

};

#endif
