#include "game.h"
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

Game::Game(int height, int width, float density, int outputType, string outputFile){
  generationNum = 0;
  m_outputType = outputType;
  m_outputFile = outputFile;
  currGrid = new Grid(height, width, density);
  prevGen1Grid = new Grid(height, width);
  prevGen2Grid = new Grid(height, width);
  prevGen3Grid = new Grid(height, width);
}

Game::Game(string file, int outputType, string outputFile){
  generationNum = 0;
  m_outputType = outputType;
  m_outputFile = outputFile;
  currGrid = new Grid(file);
  prevGen1Grid = new Grid(file);
  prevGen2Grid = new Grid(file);
  prevGen3Grid = new Grid(file);
}

Game::~Game(){
}

void Game::play(){


    while (isStabilized() == false && isEmpty() == false && generationNum < 10000) {

      output();
      generationNum++;

      Grid* newGrid = new Grid(currGrid);
      prevGen3Grid->copyGrid(prevGen2Grid);
      prevGen2Grid->copyGrid(prevGen1Grid);
      prevGen1Grid->copyGrid(currGrid);

      for (int i = 0; i < currGrid->getHeight(); ++i) {
        for (int j = 0; j < currGrid->getWidth(); ++j) {

          switch(checkNeighbors(i, j)) {
            case 0:
              newGrid->deleteCell(i, j);
              break;
            case 1:
              break;
            case 2:
              newGrid->addCell(i, j);
              break;
            case 3:
              newGrid->deleteCell(i, j);
              break;

          }
        }
      }

    currGrid = new Grid(newGrid);

  }

}

int Game::checkNeighbors(int heightIndex, int widthIndex){
  int currNeighbors = numNeighbors(currGrid, heightIndex, widthIndex);
  int prevGen1Neighbors = numNeighbors(prevGen1Grid, heightIndex, widthIndex);
  int prevGen2Neighbors = numNeighbors(prevGen2Grid, heightIndex, widthIndex);
  float averageNeighbors;

  if (generationNum > 2) {
    averageNeighbors = (currNeighbors + prevGen1Neighbors + prevGen2Neighbors) / 3.0;
  } else if (generationNum > 1) {
    averageNeighbors = (currNeighbors + prevGen1Neighbors) / 2.0;
  } else {
    averageNeighbors = currNeighbors;
  }

  if (averageNeighbors < 1.51) {
    return 0;
  } else if (averageNeighbors < 2.51) {
    return 1;
  } else if (averageNeighbors < 3.51) {
    return 2;
  } else if (averageNeighbors >= 3.51) {
    return 3;
  } else {
    return -1;
  }


}

int Game::numNeighbors(Grid* grid, int heightIndex, int widthIndex){

  char** arrayGrid = grid->getGrid();
  int maxHeight = grid->getHeight() - 1;
  int maxWidth = grid->getWidth() - 1;

  int neighbors = 0;

  if (heightIndex == 0 || widthIndex == 0 || heightIndex == maxHeight || widthIndex == maxWidth) {

    neighbors += checkBoundaries(arrayGrid, heightIndex, widthIndex, maxHeight, maxWidth);

  } else {

    if (arrayGrid[heightIndex+1][widthIndex-1] == 'X') { // Lower left
      neighbors++;
    }
    if (arrayGrid[heightIndex+1][widthIndex] == 'X') { // Lower middle
      neighbors++;
    }
    if (arrayGrid[heightIndex+1][widthIndex+1] == 'X') { // Lower right
      neighbors++;
    }
    if (arrayGrid[heightIndex-1][widthIndex-1] == 'X') { // Upper left
      neighbors++;
    }
    if (arrayGrid[heightIndex-1][widthIndex+1] == 'X') { // Upper right
      neighbors++;
    }
    if (arrayGrid[heightIndex-1][widthIndex] == 'X') { // Upper middle
      neighbors++;
    }
    if (arrayGrid[heightIndex][widthIndex+1] == 'X') { // Middle right
      neighbors++;
    }
    if (arrayGrid[heightIndex][widthIndex-1] == 'X') { // Middle left
      neighbors++;
    }

  }

  return neighbors;
}

int Game::checkBoundaries(char** arrayGrid, int heightIndex, int widthIndex, int maxHeight, int maxWidth){
  return -1;
}

bool Game::isStabilized(){
  if (generationNum > 3) {
    return (currGrid->isEqual(prevGen2Grid) || currGrid->isEqual(prevGen1Grid) || currGrid->isEqual(prevGen3Grid));
  } else {
    return false;
  }
}

bool Game::isEmpty(){
  Grid* emptyGrid = new Grid(currGrid->getHeight(), currGrid->getWidth());
  return currGrid->isEqual(emptyGrid);
}

string Game::printGeneration(Grid* grid){
  string genString = to_string(generationNum);
  return "Generation: " + genString + "\n" + grid->printGrid();
}

void Game::writeToFile(){
  ofstream outFS;
  outFS.open(m_outputFile, ios::app);
  outFS << printGeneration(currGrid) << endl;
  outFS.close();
}

void Game::output(){

  switch(m_outputType){
      case 1: // Pause
        cout << printGeneration(currGrid);
        sleep(1);
        break;
      case 2: // Enter
        cout << printGeneration(currGrid);
        cout << "Press enter to continue..." << endl;
        cin.ignore();
        break;
      case 3: // File
        writeToFile();
        break;
    }

}
