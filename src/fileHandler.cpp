#include "../include/fileHandler.h"


fileHandler::fileHandler() {

}

fileHandler::~fileHandler() {
}

void fileHandler::writeFile(string text) {
    outFile.open(source, ios::out); // Creating file (output mode)

    if (outFile.fail()) {
        cout << "Error: File couldn't be created" << endl;
        exit(1);
    }
    else {
        outFile << text;
        outFile.close(); // Close file
    }
    

}

string fileHandler::readFile() {
    inFile.open(source, ios::in); // Open file (input mode)

    if (inFile.fail()) {
        cout << "Error: File couldn't be opened" << endl;
        exit(1);
    }
    else {
        while (!inFile.eof()) { // While isn't the end of the file
            getline(inFile, textLine); // gets one line
            fileText.append(textLine + "\n");
        }

        inFile.close(); //Close file

        return fileText;
        
    }
} 
