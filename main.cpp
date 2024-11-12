#include <iostream>
#include <fstream>

using namespace std;

string reverse(string text) {
  string reversed = "";

  for (int i = text.length() - 1; i >= 0; i--) {
    reversed += text[i];
  }

  return reversed;
}

int main() {
  string userInput;
  string text;
  string filePrefix = "CSC450_CT5_mod5";
  ofstream fileOut(filePrefix + ".txt", ios::app);
  ifstream fileIn(filePrefix + ".txt", ios::app);
  ofstream fileOutReverse(filePrefix + "-reverse.txt", ios::app);  


  // Get user input.
  cout << "Enter some text:" << endl;
  getline(cin, userInput);
  
  // Append user input to file.
  fileOut << userInput << endl;

  // Iterate and reverse each line in source file
  // and output to target file.
  while (getline(fileIn, text)) {
    fileOutReverse << reverse(text) << endl;
  }

  // Close file streams.
  fileOut.close();
  fileIn.close();
  fileOutReverse.close();

  return 0;
}