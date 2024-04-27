/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** router_register_route.c
*/

#include <stdlib.h>
#include "hashmap.h"
#include "http.h"
#include "server.h"

int router_register_route(http_router_t *router, http_method_t method,
    const char *route, route_handler_t handler)
{
    http_routes_t *routes = &((*router)[method]);

    return hashmap_set(routes, route, handler);
}
