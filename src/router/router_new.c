/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** router_new.c
*/

#include <stddef.h>
#include <stdlib.h>
#include "hashmap.h"
#include "http.h"
#include "server.h"

void router_new(http_router_t *router)
{
    http_method_t method = 0;

    for (; method < HTTP_METHODS_LIMIT; ++method)
        hashmap_new(&((*router)[method]), NULL);
}
