#include "../include/controllerNode.h"

controllerNode::controllerNode(){
}

controllerNode::~controllerNode(){
}

string controllerNode::readPetition(string petition){
    jH.cargar(petition);

    jsonPetition = jH.buscarEnJSON("petition");

    if (jsonPetition == "addBook") {
        bookTitle = jH.buscarEnJSON("bookTitle");
        bookAuthor = jH.buscarEnJSON("bookAuthor");
        bookPath = jH.buscarEnJSON("bookPath");
        return addBook();
    }
    else {
        return hoffH.huffmanAlgorithm("Error adding the book");
    } 
}

void controllerNode::updateDb() {
    jsonDb = fH.readFile();

}

string controllerNode::addBook() {
    updateDb();
    if (jsonDb == "\n") {
        jsonDb = "{\"diskNodes\" : [{\"bookTitle\" : \"" + bookTitle + "\""
                                + ", \"bookAuthor\" : \"" + bookAuthor + "\""
                                + ", \"bookPath\" : \"" + bookPath +"\"}]}";

        fH.writeFile(jsonDb);
    }
    else {
        jsonDb = jsonDb.substr(0, jsonDb.length() - 3);
        jsonDb.append(", {\"bookTitle\" : \"" + bookTitle + "\""
                    + ", \"bookAuthor\" : \"" + bookAuthor + "\""
                    + ", \"bookPath\" : \"" + bookPath +"\"}]}");
        
        fH.writeFile(jsonDb);
    }

    return hoffH.huffmanAlgorithm("Book added correctly");
}