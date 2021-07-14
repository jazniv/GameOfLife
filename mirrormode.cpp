#include "mirrormode.h"

MirrorMode::MirrorMode(int height, int width, float density, int outputType, string outputFile) : Game(height, width, density, outputType, outputFile){

}

MirrorMode::MirrorMode(string file, int outputType, string outputFile) : Game(file, outputType, outputFile){

}

MirrorMode::~MirrorMode(){
}

// Checks boundaries depending on the qualifications of Mirror Mode
int MirrorMode::checkBoundaries(char** arrayGrid, int heightIndex, int widthIndex, int maxHeight, int maxWidth) {

  int neighbors = 0;

  if (heightIndex == 0) { // Top row

    if (widthIndex == 0) { // Left corner

      if (arrayGrid[heightIndex+1][widthIndex] == 'X') { // Lower middle
        neighbors+=2;
      }
      if (arrayGrid[heightIndex+1][widthIndex+1] == 'X') { // Lower right
        neighbors++;
      }
      if (arrayGrid[heightIndex][widthIndex+1] == 'X') { // Middle right
        neighbors+=2;
      }
      if (arrayGrid[heightIndex][widthIndex] == 'X') { // Reflection of self
        neighbors+=3;
      }

    }

    else if (widthIndex == maxWidth) { // Right corner

      if (arrayGrid[heightIndex+1][widthIndex-1] == 'X') { // Lower left
        neighbors++;
      }
      if (arrayGrid[heightIndex+1][widthIndex] == 'X') { // Lower middle
        neighbors+=2;
      }
      if (arrayGrid[heightIndex][widthIndex-1] == 'X') { // Middle left
        neighbors+=2;
      }
      if (arrayGrid[heightIndex][widthIndex] == 'X') { // Reflection of self
        neighbors+=3;
      }

    }

    else if (widthIndex != 0 && widthIndex != maxWidth) { // Top row non-corners

      if (arrayGrid[heightIndex+1][widthIndex-1] == 'X') { // Lower left
        if (widthIndex - 1 == 0) { // If neighbor has reflection
          neighbors+=2;
        } else {
          neighbors++;
        }
      }
      if (arrayGrid[heightIndex+1][widthIndex] == 'X') { // Lower middle
        neighbors++;
      }
      if (arrayGrid[heightIndex+1][widthIndex+1] == 'X') { // Lower right
        if (widthIndex + 1 == maxWidth) { // If neighbor has reflection
          neighbors+=2;
        } else {
          neighbors++;
        }
      }
      if (arrayGrid[heightIndex][widthIndex+1] == 'X') { // Middle right
        neighbors+=2;
      }
      if (arrayGrid[heightIndex][widthIndex-1] == 'X') { // Middle left
        neighbors+=2;
      }
      if (arrayGrid[heightIndex][widthIndex] == 'X') { // Reflection of self
        neighbors++;
      }

    }


  } else if (heightIndex == maxHeight) { // Bottom row

    if (widthIndex == 0) { // Left corner

      if (arrayGrid[heightIndex-1][widthIndex+1] == 'X') { // Upper right
        neighbors++;
      }
      if (arrayGrid[heightIndex-1][widthIndex] == 'X') { // Upper middle
        neighbors+=2;
      }
      if (arrayGrid[heightIndex][widthIndex+1] == 'X') { // Middle right
        neighbors+=2;
      }
      if (arrayGrid[heightIndex][widthIndex] == 'X') { // Reflection of self
        neighbors+=3;
      }

    }

    else if (widthIndex == maxWidth) { // Right corner

      if (arrayGrid[heightIndex-1][widthIndex-1] == 'X') { // Upper left
        neighbors++;
      }
      if (arrayGrid[heightIndex-1][widthIndex] == 'X') { // Upper middle
        neighbors+=2;
      }
      if (arrayGrid[heightIndex][widthIndex-1] == 'X') { // Middle left
        neighbors+=2;
      }
      if (arrayGrid[heightIndex][widthIndex] == 'X') { // Reflection of self
        neighbors+=3;
      }

    }

    else if (widthIndex != 0 && widthIndex != maxWidth) { // Bottom row non-corners

      if (arrayGrid[heightIndex-1][widthIndex-1] == 'X') { // Upper left
        if (widthIndex - 1 == 0) { // If neighbor has reflection
          neighbors+=2;
        } else {
          neighbors++;
        }
      }
      if (arrayGrid[heightIndex-1][widthIndex+1] == 'X') { // Upper right
        if (widthIndex + 1 == maxWidth) { // If neighbor has reflection
          neighbors+=2;
        } else {
          neighbors++;
        }
      }
      if (arrayGrid[heightIndex-1][widthIndex] == 'X') { // Upper middle
        neighbors++;
      }
      if (arrayGrid[heightIndex][widthIndex+1] == 'X') { // Middle right
        neighbors+=2;
      }
      if (arrayGrid[heightIndex][widthIndex-1] == 'X') { // Middle left
        neighbors+=2;
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
