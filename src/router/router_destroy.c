/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** router_destroy.c
*/

#include "hashmap.h"
#include "http.h"
#include "server.h"

void router_destroy(http_router_t *router)
{
    http_method_t method = 0;

    for (; method < HTTP_METHODS_LIMIT; ++method)
        hashmap_clear(&((*router)[method]));
}
