#include "classicmode.h"

ClassicMode::ClassicMode(int height, int width, float density, int outputType, string outputFile) : Game(height, width, density, outputType, outputFile){

}

ClassicMode::ClassicMode(string file, int outputType, string outputFile) : Game(file, outputType, outputFile){

}

ClassicMode::~ClassicMode(){

}

// Checks boundaries depending on the qualifications of Classic Mode
int ClassicMode::checkBoundaries(char** arrayGrid, int heightIndex, int widthIndex, int maxHeight, int maxWidth) {

  int neighbors = 0;

  if (heightIndex == 0) { // Top row

    if (widthIndex == 0) { // Left corner

      if (arrayGrid[heightIndex+1][widthIndex] == 'X') { // Lower middle
        neighbors++;
      }
      if (arrayGrid[heightIndex+1][widthIndex+1] == 'X') { // Lower right
        neighbors++;
      }
      if (arrayGrid[heightIndex][widthIndex+1] == 'X') { // Middle right
        neighbors++;
      }
    }

    else if (widthIndex == maxWidth) { // Right corner

      if (arrayGrid[heightIndex+1][widthIndex-1] == 'X') { // Lower left
        neighbors++;
      }
      if (arrayGrid[heightIndex+1][widthIndex] == 'X') { // Lower middle
        neighbors++;
      }
      if (arrayGrid[heightIndex][widthIndex-1] == 'X') { // Middle left
        neighbors++;
      }
    }

    else if (widthIndex != 0 && widthIndex != maxWidth) { // Top row non-corners

      if (arrayGrid[heightIndex+1][widthIndex-1] == 'X') { // Lower left
        neighbors++;
      }
      if (arrayGrid[heightIndex+1][widthIndex] == 'X') { // Lower middle
        neighbors++;
      }
      if (arrayGrid[heightIndex+1][widthIndex+1] == 'X') { // Lower right
        neighbors++;
      }
      if (arrayGrid[heightIndex][widthIndex+1] == 'X') { // Middle right
        neighbors++;
      }
      if (arrayGrid[heightIndex][widthIndex-1] == 'X') { // Middle left
        neighbors++;
      }

    }


  } else if (heightIndex == maxHeight) { // Bottom row

    if (widthIndex == 0) { // Left corner

      if (arrayGrid[heightIndex-1][widthIndex+1] == 'X') { // Upper right
        neighbors++;
      }
      if (arrayGrid[heightIndex-1][widthIndex] == 'X') { // Upper middle
        neighbors++;
      }
      if (arrayGrid[heightIndex][widthIndex+1] == 'X') { // Middle right
        neighbors++;
      }

    }

    else if (widthIndex == maxWidth) { // Right corner

      if (arrayGrid[heightIndex-1][widthIndex-1] == 'X') { // Upper left
        neighbors++;
      }
      if (arrayGrid[heightIndex-1][widthIndex] == 'X') { // Upper middle
        neighbors++;
      }
      if (arrayGrid[heightIndex][widthIndex-1] == 'X') { // Middle left
        neighbors++;
      }

    }

    else if (widthIndex != 0 && widthIndex != maxWidth) { // Bottom row non-corners

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

  } else if (widthIndex == 0) {


    if (arrayGrid[heightIndex+1][widthIndex] == 'X') { // Lower middle
      neighbors++;
    }
    if (arrayGrid[heightIndex+1][widthIndex+1] == 'X') { // Lower right
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



  } else if (widthIndex == maxWidth) {

   if (arrayGrid[heightIndex+1][widthIndex-1] == 'X') { // Lower left
     neighbors++;
   }
   if (arrayGrid[heightIndex+1][widthIndex] == 'X') { // Lower middle
     neighbors++;
   }
   if (arrayGrid[heightIndex][widthIndex-1] == 'X') { // Middle left
     neighbors++;
   }
   if (arrayGrid[heightIndex-1][widthIndex-1] == 'X') { // Upper left
     neighbors++;
   }
   if (arrayGrid[heightIndex-1][widthIndex] == 'X') { // Upper middle
     neighbors++;
   }

 }

  return neighbors;

}
