#ifndef SERVERPROYECTO3DATOS2_CONTROLLERNODE_H
#define SERVERPROYECTO3DATOS2_CONTROLLERNODE_H

#include "../include/fileHandler.h"
#include <string>

using namespace std;

class controllerNode {

private:
    fileHandler fH;
    string jsonDb;

    
public:
    controllerNode();
    ~controllerNode();
    void updateDb();
    void addBook(int iD, string title, string author, string path);



};

#endif //SERVERPROYECTO3DATOS2_CONTROLLERNODE_H