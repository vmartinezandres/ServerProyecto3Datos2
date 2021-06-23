#ifndef SERVERPROYECTO3DATOS2_SERVER_H
#define SERVERPROYECTO3DATOS2_SERVER_H

#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

#include "../include/jsonHandler.h"
#include "../include/controllerNode.h"

using namespace std;

class server {

private:
    int puerto = 54000;
    string ip = "0.0.0.0";
    string peticionCliente;
    string respuestaServer;
    controllerNode cn;

public:
    /**
     * @brief iniciarServidor iniciar el servidor para escuchar futuras peticiones
     * @return true/false si el servidor se inicio o no
     */
    bool inicarServidor();
};

#endif //SERVERPROYECTO3DATOS2_SERVER_H