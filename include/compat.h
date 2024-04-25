/*
** EPITECH PROJECT, 2024
** {Workshop} Network Programming
** File description:
** compat.h
*/

#ifndef __COMPAT_H_
    #define __COMPAT_H_

    #if !defined(__APPLE__)
        #include <linux/limits.h>
    #else
        #include <limits.h>
    #endif

#endif /* !__COMPAT_H_ */
