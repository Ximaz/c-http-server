/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** http_headers.h
*/

#ifndef __HTTP_HEADERS_H_
    #define __HTTP_HEADERS_H_

typedef struct s_http_req_opt_headers {
    char *sec_gpc;
    char *sec_fetch_dest;
    char *sec_fetch_mode;
    char *sec_fetch_site;
    char *sec_fetch_user;
} http_req_opt_headers_t;

typedef struct s_http_req_headers {
    char *host;
    char *user_agent;
    char *accept;
    char *accept_language;
    char *accept_encoding;
    char *dnt;
    char *connection;
    char *cookie;
    char *upgrade_insecure_requests;
    char *pragma;
    char *cache_control;
} http_req_headers_t;

#endif /* !__HTTP_HEADERS_H_ */
