#ifndef SERVERPROYECTO3DATOS2_JSONHANDLER_H
#define SERVERPROYECTO3DATOS2_JSONHANDLER_H

#include <iostream>
#include <string>

using namespace std;

class jsonHandler {

private:
    string archivoJSON;
    string palabra;
    int final = 0;
    bool isRespuesta = false;

public:
    /**
     * @brief cargar cargar la peticion completa del cliente en formato JSON
     * @param archivo el archivo en formato JSON
     */
    void cargar(string archivo);

    /**
     * @brief buscarEnJSON busca dentro del archivo el valor ingresado
     * @param parametro parametro del JSON a buscar
     * @return El valor buscado en el JSON 
     */
    string buscarEnJSON(string parametro);

    /**
     * @brief recortarComillas elimina las comillas del valor a entregar
     * @param parametro parametro del JSON a buscar
     * @param inicio desde donde se va a recortar
     * @return El valor buscado en el JSON 
     */
    string recortarComillas(string parametro, int inicio); 

};



#endif //SERVERPROYECTO3DATOS2_JSONHANDLER_H