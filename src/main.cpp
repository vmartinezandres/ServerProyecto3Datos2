#include <iostream>
#include "../include/controllerNode.h"

using namespace std;

int main() {
    controllerNode cn;
    cn.addBook(1, "Pantalones Cortos", "Lara Rios", "books/pantalones.text");
    //cn.addBook(2, "Harry Potter", "J. K. Rowling", "books/harry.text");
    return 0;
}