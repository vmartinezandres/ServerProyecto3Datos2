#ifndef SERVERPROYECTO3DATOS2_FILEHANDLER_H
#define SERVERPROYECTO3DATOS2_FILEHANDLER_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class fileHandler {

private:
    ofstream outFile;
    ifstream inFile;

    string source = "database/raid.json";
    string fileText;
    string textLine;
    
public:
    fileHandler();
    ~fileHandler();

    void writeFile(string text);
    string readFile();
};

#endif //SERVERPROYECTO3DATOS2_FILEHANDLER_H