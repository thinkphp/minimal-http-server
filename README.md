# Simple HTTP Server in C

This repository contains a simple HTTP server written in C that listens on port 8080 and responds to HTTP requests with a basic HTML page.

## Features
- Listens for connections on port 8080.
- Responds to HTTP GET requests with a simple HTML message.
- Demonstrates basic socket programming in C.

## Requirements
- A C compiler (e.g., `gcc`)
- Linux, macOS, or a similar environment with support for socket programming.

## How to Use
1. **Compile the server:**
   ```bash
   gcc -o http_server server.c
   ```

2. **Run the server:**
   ```bash
   ./http_server
   ```

3. **Access the server:**
   Open a web browser and navigate to `http://localhost:8080`, or use `curl`:
   ```bash
   curl http://localhost:8080
   ```

## Server Behavior
- When a client connects, the server reads the HTTP request and prints it to the console.
- It sends back an HTTP response with a simple HTML page:
  ```html
  <html>
  <body>
  <h1>Salut de la server!</h1>
  </body>
  </html>
  ```

## Code Overview
The server implements the following steps:
1. **Socket Creation:**
   Creates a TCP socket using the `socket()` function.

2. **Address Binding:**
   Binds the socket to port 8080 and listens for incoming connections.

3. **Accept and Respond:**
   Accepts client connections, reads the request, and sends a hardcoded HTTP response.

4. **Connection Close:**
   Closes the client connection after responding.

## Example Output
When a client sends a request, the server prints the HTTP request:
```plaintext
Cerere HTTP primită:
GET / HTTP/1.1
Host: localhost:8080
Connection: keep-alive
...
```

The client receives the response:
```html
<html>
<body>
<h1>Salut de la server!</h1>
</body>
</html>
```

## Extending the Server
- **Custom Responses:** Modify the `response` variable to send different HTML content.
- **Multiple Routes:** Parse the request to serve different responses for specific paths.
- **Concurrency:** Use threads or `select()` to handle multiple clients simultaneously.

## Notes
- This server is for educational purposes and is not intended for production use.
- Consider using libraries such as `libmicrohttpd` or `mongoose` for more advanced HTTP server implementations.

## License
This project is licensed under the MIT License. See the `LICENSE` file for details.

