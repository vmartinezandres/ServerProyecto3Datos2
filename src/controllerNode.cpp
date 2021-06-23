#include "../include/controllerNode.h"

controllerNode::controllerNode(){
}

controllerNode::~controllerNode(){
}

void controllerNode::updateDb() {
    jsonDb = fH.readFile();
}

void controllerNode::addBook(int iD, string title, string author, string path) {
    updateDb();
    if (jsonDb == "\n") {
        jsonDb = "{\"diskNodes\" : [{\"bookID\" : " + to_string(iD) 
                                + ", \"bookTitle\" : \"" + title + "\""
                                + ", \"bookAuthor\" : \"" + author + "\""
                                + ", \"bookPath\" : \"" + path +"\"}]}";

        fH.writeFile(jsonDb);
    }
    else {
        jsonDb = jsonDb.substr(0, jsonDb.length() - 3);
        jsonDb.append(", {\"bookID\" : " + to_string(iD) 
                    + ", \"bookTitle\" : \"" + title + "\""
                    + ", \"bookAuthor\" : \"" + author + "\""
                    + ", \"bookPath\" : \"" + path +"\"}]}");
        
        fH.writeFile(jsonDb);
    }
}