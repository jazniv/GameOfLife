#ifndef MIRRORMODE_H
#define MIRRORMODE_H

#include "game.h"
#include <iostream>
#include <fstream>

using namespace std;

class MirrorMode : public Game{

  public:
    MirrorMode(int height, int width, float density, int outputType, string outputFile);
    MirrorMode(string file, int outputType, string outputFile);
    ~MirrorMode();

    int checkBoundaries(char** arrayGrid, int heightIndex, int widthIndex, int maxHeight, int maxWidth);

};

#endif
