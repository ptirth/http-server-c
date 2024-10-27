/*
 * http-server-c: A simple HTTP server written in C
 * Copyright (C) 2024  Tirth Patel
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

#include "mydefs.h"
#include <errno.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define SOCK_PROTOCOL 0
#define SOCKOPT_REUSEADDR 1
#define CONNECTION_BACKLOG 5

int main(int argc, char *argv[]) {
  printf("http-server-c  Copyright (C) 2024  Tirth Patel\n"
         "This program comes with ABSOLUTELY NO WARRANTY;\n"
         "This is free software, and you are welcome to redistribute it\n"
         "under certain conditions; for more details read the copy of\n"
         "GNU General Public LICENSE that came with the software.\n"
         "If you did not receive a copy, see "
         "<https://www.gnu.org/licenses/>.\n\n");

  i32 server_fd = socket(AF_INET, SOCK_STREAM, SOCK_PROTOCOL);
  if (server_fd == -1) {
    printf("E: Failed to open server socket: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  i32 reuseaddr = SOCKOPT_REUSEADDR;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuseaddr,
                 sizeof(reuseaddr))) {
    printf("E: Set socket opt failed: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  struct sockaddr_in server_addr = {
      .sin_family = AF_INET,
      .sin_port = htons(SERVER_PORT),
      .sin_addr = {htonl(INADDR_ANY)},
  };
  if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
    printf("E: Bind to port failed: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  if (listen(server_fd, CONNECTION_BACKLOG)) {
    printf("E: Listen failed: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }

  struct sockaddr_in client_addr;
  socklen_t client_addr_len = sizeof(client_addr);

  printf("Waiting for client to connect...\n");
  i32 connection =
      accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);

  if (connection == -1) {
    printf("E: Connection to client failed: %s\n", strerror(errno));
    return EXIT_FAILURE;
  }
  printf("Client connected!\n");

  close(connection);
  close(server_fd);

  return EXIT_SUCCESS;
}
