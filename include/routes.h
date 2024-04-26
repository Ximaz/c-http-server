/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** routes.h
*/

#ifndef __ROUTES_H_
    #define __ROUTES_H_

    #include "http.h"
    #include "server.h"

void get_index(http_server_t *server, UNUSED http_client_t *client,
    UNUSED http_request_t *req, http_response_t *resp);

#endif /* !__ROUTES_H_ */
