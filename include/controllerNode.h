#ifndef SERVERPROYECTO3DATOS2_CONTROLLERNODE_H
#define SERVERPROYECTO3DATOS2_CONTROLLERNODE_H

#include <string>

#include "../include/fileHandler.h"
#include "../include/jsonHandler.h"
#include "../include/hoffmanHandler.h"

using namespace std;

class controllerNode {

private:
    fileHandler fH;
    jsonHandler jH;
    hoffmanHandler hoffH;
    string jsonDb;
    string jsonPetition;

    string bookTitle;
    string bookAuthor;
    string bookPath;

    
public:
    controllerNode();
    ~controllerNode();
    string readPetition(string petition);
    void updateDb();
    string addBook();



};

#endif //SERVERPROYECTO3DATOS2_CONTROLLERNODE_H