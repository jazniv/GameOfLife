#ifndef GAMESETUP_H
#define GAMESETUP_H

#include "classicmode.h"
#include "doughnutmode.h"
#include "mirrormode.h"
#include <iostream>
#include <fstream>

using namespace std;

class GameSetup{

  public:
    GameSetup();
    ~GameSetup();
    void setup();
    void handleInputFile();
    void handleRandomAssignment();

    bool isValidInput;

    int inputType;
    string inputFile;
    int gameType;
    int height;
    int width;
    float density;
    int outputType;
    string outputFile;

    ClassicMode* classicModeGame;
    DoughnutMode* doughnutModeGame;
    MirrorMode* mirrorModeGame;

};

#endif
