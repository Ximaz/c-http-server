/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** http.h
*/

#ifndef __HTTP_HEADERS_H_
    #define __HTTP_HEADERS_H_

    #define HTTP_LINE_SEP "\r\n"
    #define HTTP_LINE_SEP_LEN 2
    #define UNUSED __attribute__((unused))

    #include "buffer.h"
    #include "compat.h"
    #include "hashmap.h"

typedef enum e_http_method {
    HTTP_GET,
    HTTP_POST,
    HTTP_PUT,
    HTTP_PATCH,
    HTTP_DELETE,
    HTTP_HEAD,
    HTTP_TRACE,
    HTTP_OPTIONS,
    HTTP_METHODS_LIMIT
} http_method_t;

UNUSED static const char *HTTP_METHODS[HTTP_METHODS_LIMIT] = {
    "GET", "POST", "PUT", "PATCH", "DELETE", "HEAD", "TRACE", "OPTIONS"
};

typedef enum e_http_version {
    HTTP_1_0,
    HTTP_1_1,
    HTTP_2_0,
    HTTP_3_0,
    HTTP_VERSIONS_LIMIT
} http_version_t;

UNUSED static const buffer_t HTTP_VERSIONS[HTTP_VERSIONS_LIMIT] = {
    { "HTTP/1", 7 },
    { "HTTP/1.1", 8 },
    { "HTTP/2", 7 },
    { "HTTP/3", 7 },
};

typedef struct s_http_header {
    buffer_t key;
    buffer_t value;
} http_header_t;

typedef hashmap_t http_headers_t; /* {header_name: header_value} */

typedef enum e_http_status {
    HTTP_100,
    HTTP_101,
    HTTP_102,
    HTTP_103,
    HTTP_200,
    HTTP_201,
    HTTP_202,
    HTTP_203,
    HTTP_204,
    HTTP_205,
    HTTP_206,
    HTTP_207,
    HTTP_208,
    HTTP_226,
    HTTP_300,
    HTTP_301,
    HTTP_302,
    HTTP_303,
    HTTP_304,
    HTTP_305,
    HTTP_306,
    HTTP_307,
    HTTP_308,
    HTTP_400,
    HTTP_401,
    HTTP_402,
    HTTP_403,
    HTTP_404,
    HTTP_405,
    HTTP_406,
    HTTP_407,
    HTTP_408,
    HTTP_409,
    HTTP_410,
    HTTP_411,
    HTTP_412,
    HTTP_413,
    HTTP_414,
    HTTP_415,
    HTTP_416,
    HTTP_417,
    HTTP_418,
    HTTP_421,
    HTTP_422,
    HTTP_423,
    HTTP_424,
    HTTP_425,
    HTTP_426,
    HTTP_428,
    HTTP_429,
    HTTP_431,
    HTTP_451,
    HTTP_500,
    HTTP_501,
    HTTP_502,
    HTTP_503,
    HTTP_504,
    HTTP_505,
    HTTP_506,
    HTTP_507,
    HTTP_508,
    HTTP_510,
    HTTP_511,
    HTTP_STATUS_LIMIT
} http_status_t;

UNUSED static const char *HTTP_STATUS[HTTP_STATUS_LIMIT] = {
    "100",
    "101",
    "102",
    "103",
    "200",
    "201",
    "202",
    "203",
    "204",
    "205",
    "206",
    "207",
    "208",
    "226",
    "300",
    "301",
    "302",
    "303",
    "304",
    "305",
    "306",
    "307",
    "308",
    "400",
    "401",
    "402",
    "403",
    "404",
    "405",
    "406",
    "407",
    "408",
    "409",
    "410",
    "411",
    "412",
    "413",
    "414",
    "415",
    "416",
    "417",
    "418",
    "421",
    "422",
    "423",
    "424",
    "425",
    "426",
    "428",
    "429",
    "431",
    "451",
    "500",
    "501",
    "502",
    "503",
    "504",
    "505",
    "506",
    "507",
    "508",
    "510",
    "511",
};

typedef struct s_http_request {
    http_method_t method;
    char uri[PATH_MAX];
    http_version_t version;
    http_headers_t headers;
    buffer_t body;
    buffer_t raw;
} http_request_t;

typedef struct s_http_response {
    http_status_t status;
    http_version_t version;
    http_headers_t headers;
    buffer_t content;
    buffer_t raw;
} http_response_t;

typedef struct s_http_error_generator {
    http_status_t error_code;
    void (*handler)(http_response_t *resp);
} http_error_generator_t;

void http_error_file_not_found(http_response_t *resp);

void http_error_internal_error(http_response_t *resp);

static const http_error_generator_t HTTP_ERRORS[] = {
    { HTTP_404, http_error_file_not_found },
    { HTTP_500, http_error_internal_error },
    { -1, NULL }
};


int parse_http_method(const char *method, http_request_t *output);

int parse_http_uri(const char *uri, http_request_t *output);

int parse_http_version(const char *version, http_request_t *output);

http_header_t *parse_http_header(const buffer_t *raw);

buffer_t *get_http_header(const http_headers_t *headers, const char *key);

void parse_http_request(const buffer_t *raw, http_request_t *output);

void get_http_uri_resource(const char *path, http_response_t *resp);

void make_http_header(http_header_t *header, const char *key,
    const char *value);

int set_http_header(http_headers_t *headers, http_header_t *header);

void destroy_http_request(http_request_t *req);

void destroy_http_response(http_response_t *resp);

#endif /* !__HTTP_HEADERS_H_ */
