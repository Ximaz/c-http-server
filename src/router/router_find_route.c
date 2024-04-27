/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** router_find_route.c
*/

#include "hashmap.h"
#include "http.h"
#include "server.h"

route_handler_t *router_find_route(const http_router_t *router,
    http_method_t method, const char *route)
{
    http_routes_t *routes = (http_routes_t *) &((*router)[method]);

    return hashmap_get(routes, route);
}
