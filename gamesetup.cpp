#include <iostream>
#include <fstream>
#include "gamesetup.h"

GameSetup::GameSetup(){
  isValidInput = false;
}

GameSetup::~GameSetup(){

}

void GameSetup::setup(){

  cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
  cout << "\tWelcome to the Game of Life!" << endl;
  cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

  while (isValidInput == false) {
    cout << "Would you like to submit a file or create a random configuration?" << endl;
    cout << "Type 1 to submit a file." << endl;
    cout << "Type 2 for random configuration." << endl;
    cin >> inputType;
    if (inputType == 1) {
      handleInputFile();
      isValidInput = true;
    } else if (inputType == 2) {
      handleRandomAssignment();
      isValidInput = true;
    } else {
      cin.clear();
      cin.ignore();
      cout << "Invalid input. Please try again." << endl;
    }
  }

  isValidInput = false;

  while (isValidInput == false) {
    cout << "What boundary mode would you like to run in?" << endl;
    cout << "Enter 1 for Classic Mode" << endl;
    cout << "Enter 2 for Doughnut Mode" << endl;
    cout << "Enter 3 for Mirror Mode" << endl;

    cin >> gameType;

    if (gameType == 1 || gameType == 2 || gameType == 3) {
      isValidInput = true;
    } else {
      cin.clear();
      cin.ignore();
      cout << "Invalid input. Please try again." << endl;
    }

  }

  isValidInput = false;

  while (isValidInput == false) {
    cout << "While playing, would you like a brief pause between generations, to be prompted to press enter after each generation, or to output your grids to a file?" << endl;
    cout << "Enter 1 for pause" << endl;
    cout << "Enter 2 to press enter" << endl;
    cout << "Enter 3 to output to a file" << endl;
    cin >> outputType;

    if (outputType == 3) {
      cout << "Enter your desired output file name" << endl;
      cout << "Example: example.txt" << endl;
      cin >> outputFile;

      string fileName = outputFile;
      fstream checkFile(fileName);
      checkFile.open(fileName, ios::out);
      if (!checkFile) {
        cin.clear();
        cin.ignore();
        cout << "Invalid input. Please try again." << endl;
      } else {
        cout << "File created successfully!" << endl;
        isValidInput = true;
        checkFile.close();
      }

    } else if (outputType == 1 || outputType == 2){
      outputFile = "";
      isValidInput = true;
    } else {
      cin.clear();
      cin.ignore();
      cout << "Invalid input. Please try again." << endl;
    }

  }

  isValidInput = false;

  cout << "Excellent! Your game is ready to begin." << endl;
  cin.ignore();

  if (inputType == 1) { // Handle input file

    if (gameType == 1) { // Classic Mode
      classicModeGame = new ClassicMode(inputFile, outputType, outputFile);
      classicModeGame->play();
    } else if (gameType == 2) { // Doughnut Mode
      doughnutModeGame = new DoughnutMode(inputFile, outputType, outputFile);
      doughnutModeGame->play();
    } else if (gameType == 3) { // Mirror Mode
      mirrorModeGame = new MirrorMode(inputFile, outputType, outputFile);
      mirrorModeGame->play();
    }


  } else if (inputType == 2) { // Handle Random Assignment

    if (gameType == 1) { // Classic Mode
      classicModeGame = new ClassicMode(height, width, density, outputType, outputFile);
      classicModeGame->play();
    } else if (gameType == 2) { // Doughnut Mode
      doughnutModeGame = new DoughnutMode(height, width, density, outputType, outputFile);
      doughnutModeGame->play();
    } else if (gameType == 3) { // Mirror Mode
      mirrorModeGame = new MirrorMode(height, width, density, outputType, outputFile);
      mirrorModeGame->play();
    }
  }

  cout << "Your game is complete!" << endl;
  cout << "Press enter to exit the program." << endl;
  cin.ignore();

}

void GameSetup::handleInputFile(){

  isValidInput = false;

  while (isValidInput == false) {
    cout << "You selected to submit an input file." << endl;
    cout << "Please enter the name of your file." << endl;
    cout << "Example: example.txt" << endl;
    cin >> inputFile;

    ifstream checkFile(inputFile);

    if (!checkFile.is_open()) {
      cin.clear();
      cin.ignore();
      cout << "Invalid input. Please try again." << endl;
    } else {
      isValidInput = true;
      checkFile.close();
    }

  }

  cout << "Excellent!" << endl;

}

void GameSetup::handleRandomAssignment(){

  isValidInput = false;

  while (isValidInput == false) {
    cout << "How many rows would you like your grid to have?" << endl;
    cout << "Please enter an integer." << endl;
    cin >> height;

    if (!cin.good() || height < 2) {
      cin.clear();
      cin.ignore();
      cout << "Invalid input. Please try again." << endl;
    } else if (height > 1){
      isValidInput = true;
    }

  }

  isValidInput = false;

  while (isValidInput == false) {
    cout << "How many columns would you like your grid to have?" << endl;
    cout << "Please enter an integer." << endl;
    cin >> width;

    if (!cin.good() || width < 2) {
      cin.clear();
      cin.ignore();
      cout << "Invalid input. Please try again." << endl;
    } else if (width > 1) {
      isValidInput = true;
    }

  }

  isValidInput = false;

  while (isValidInput == false) {
    cout << "How dense would you like your starting population to be?" << endl;
    cout << "Enter a decimal between 0 and 1, representing the percentage." << endl;
    cin >> density;

    if (density > 1 || density <= 0){
      cin.clear();
      cin.ignore();
      cout << "Invalid input. Please try again." << endl;
    } else if (cin.good()){
      isValidInput = true;
    }

  }

}
