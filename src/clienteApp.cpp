#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int sock;
    sockaddr_in server_addr{};

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    inet_pton(AF_INET, "192.168.1.130", &server_addr.sin_addr);

    connect(sock, (sockaddr*)&server_addr, sizeof(server_addr));

    const char* mensaje = "Hola servidor";
    send(sock, mensaje, strlen(mensaje), 0);

    char buffer[1024] = {0};
    recv(sock, buffer, sizeof(buffer), 0);

    std::cout << "Respuesta del servidor: " << buffer << std::endl;

    close(sock);

    return 0;
}
