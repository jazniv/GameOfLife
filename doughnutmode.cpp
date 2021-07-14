#include "doughnutmode.h"

DoughnutMode::DoughnutMode(int height, int width, float density, int outputType, string outputFile) : Game(height, width, density, outputType, outputFile){

}

DoughnutMode::DoughnutMode(string file, int outputType, string outputFile) : Game(file, outputType, outputFile){

}

DoughnutMode::~DoughnutMode(){
}

// Checks boundaries depending on the qualifications of Doughnut Mode
int DoughnutMode::checkBoundaries(char** arrayGrid, int heightIndex, int widthIndex, int maxHeight, int maxWidth) {

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
      if (arrayGrid[0][maxWidth] == 'X') { // Top right corner
        neighbors++;
      }
      if (arrayGrid[1][maxWidth] == 'X') { // Diagonal lower left
        neighbors++;
      }
      if (arrayGrid[maxHeight][maxWidth] == 'X') { // Bottom right corner
        neighbors++;
      }
      if (arrayGrid[maxHeight][0] == 'X') { // Bottom left corner
        neighbors++;
      }
      if (arrayGrid[maxHeight][1] == 'X') { // Diagonal upper left
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
      if (arrayGrid[0][0] == 'X') { // Top left corner
        neighbors++;
      }
      if (arrayGrid[1][0] == 'X') { // Diagonal lower left
        neighbors++;
      }
      if (arrayGrid[maxHeight][maxWidth] == 'X') { // Bottom right corner
        neighbors++;
      }
      if (arrayGrid[maxHeight][0] == 'X') { // Bottom left corner
        neighbors++;
      }
      if (arrayGrid[maxHeight][maxWidth-1] == 'X') { // Diagonal upper left
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
      if (arrayGrid[maxHeight][widthIndex] == 'X') { // Upper middle
        neighbors++;
      }
      if (arrayGrid[maxHeight][widthIndex-1] == 'X') { // Upper left
        neighbors++;
      }
      if (arrayGrid[maxHeight][widthIndex+1] == 'X') { // Upper right
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
      if (arrayGrid[0][maxWidth] == 'X') { // Top right corner
        neighbors++;
      }
      if (arrayGrid[0][0] == 'X') { // Top left corner
        neighbors++;
      }
      if (arrayGrid[0][1] == 'X') { // Diagonal lower right
        neighbors++;
      }
      if (arrayGrid[maxHeight][maxWidth] == 'X') { // Bottom right corner
        neighbors++;
      }
      if (arrayGrid[maxHeight-1][maxWidth] == 'X') { // Diagonal upper left
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
      if (arrayGrid[0][0] == 'X') { // Top left corner
        neighbors++;
      }
      if (arrayGrid[0][maxWidth] == 'X') { // Top right corner
        neighbors++;
      }
      if (arrayGrid[0][maxWidth-1] == 'X') { // Diagonal lower left
        neighbors++;
      }
      if (arrayGrid[maxHeight][0] == 'X') { // Bottom left corner
        neighbors++;
      }
      if (arrayGrid[maxHeight-1][0] == 'X') { // Diagonal upper right
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
      if (arrayGrid[0][widthIndex+1] == 'X') { // Lower right
        neighbors++;
      }
      if (arrayGrid[0][widthIndex-1] == 'X') { // Lower left
        neighbors++;
      }
      if (arrayGrid[0][widthIndex] == 'X') { // Lower middle
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
    if (arrayGrid[heightIndex-1][maxWidth] == 'X') { // Upper left
      neighbors++;
    }
    if (arrayGrid[heightIndex][maxWidth] == 'X') { // Middle left
      neighbors++;
    }
    if (arrayGrid[heightIndex+1][maxWidth] == 'X') { // Lower left
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
   if (arrayGrid[heightIndex][0] == 'X') { // Middle right
     neighbors++;
   }
   if (arrayGrid[heightIndex-1][0] == 'X') { // Upper right
     neighbors++;
   }
   if (arrayGrid[heightIndex+1][0] == 'X') { // Lower right
     neighbors++;
   }

 }

  return neighbors;

}
