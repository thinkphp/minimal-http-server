#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    char response[] =
        "HTTP/1.1 200 OK\r\n"
        "Content-Type: text/html\r\n"
        "Content-Length: 44\r\n"
        "\r\n"
        "<html><body><h1>Salut de la server!</h1></body></html>";

    // 1. Creare socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Eroare la crearea socketului");
        exit(EXIT_FAILURE);
    }

    // 2. Configurare adresa serverului
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    // 3. Legare socket la adresa și port
    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Eroare la bind");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    // 4. Punere în modul de ascultare
    if (listen(server_socket, 10) < 0) {
        perror("Eroare la listen");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Serverul HTTP rulează pe portul %d...\n", PORT);

    while (1) {
        // 5. Acceptarea unei conexiuni
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket < 0) {
            perror("Eroare la accept");
            continue;
        }

        // 6. Citirea cererii HTTP de la client
        memset(buffer, 0, BUFFER_SIZE);
        read(client_socket, buffer, BUFFER_SIZE - 1);
        printf("Cererere HTTP primită:\n%s\n", buffer);

        // 7. Trimiterea răspunsului HTTP
        write(client_socket, response, sizeof(response) - 1);

        // 8. Închiderea conexiunii cu clientul
        close(client_socket);
    }

    // 9. Închiderea serverului (opțional, dar de obicei serverele rulează continuu)
    close(server_socket);
    return 0;
}
