#include <iostream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
    int server_fd, client_fd;
    sockaddr_in server_addr{}, client_addr{};
    socklen_t client_len = sizeof(client_addr);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    bind(server_fd, (sockaddr*)&server_addr, sizeof(server_addr));
    listen(server_fd, 1);

    std::cout << "Servidor escuchando en puerto 8080...\n";

    client_fd = accept(server_fd, (sockaddr*)&client_addr, &client_len);

    char buffer[1024] = {0};
    recv(client_fd, buffer, sizeof(buffer), 0);

    std::cout << "Mensaje recibido: " << buffer << std::endl;

    const char* respuesta = "Hola desde el servidor";
    send(client_fd, respuesta, strlen(respuesta), 0);

    close(client_fd);
    close(server_fd);

    return 0;
}
