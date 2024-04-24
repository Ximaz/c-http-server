##
## EPITECH PROJECT, 2024
## {Workshop} Network Programming
## File description:
## Server's Makefile
##

NAME	:= http_server
SRCS	:=	$(shell find src -name '*.c')
OBJS	:=	$(SRCS:.c=.o)
RM		:=	rm -rf

CC			:=	gcc
CPPFLAGS	:=	-Iinclude/
CFLAGS 		:=	-Wall -Wextra -Werror -pedantic -ansi -fPIE -Wformat \
				-fno-delete-null-pointer-checks -fno-strict-overflow \
				-fno-strict-aliasing -ftrivial-auto-var-init=zero    \
				-Wimplicit-fallthrough -fstack-protector-strong		 \
				-U_FORTIFY_SOURCE -D_GLIBCXX_ASSERTIONS 			 \

ifeq ($(PLATFORM),x86_64)
CFLAGS		+=	-fcf-protection=full -Wl,-z,nodlopen -Wl,-z,noexecstack 	 \
				-fstrict-flex-arrays=3 -Wtrampolines -Wl,-z,relro -Wl,-z,now \
				-fstack-clash-protection
endif

ifeq ($(PLATFORM),aarch64)
CFLAGS		+=	-mbranch-protection=standard
endif

VALGRIND_FLAGS	:=	-s							\
					--leak-check=full			\
					--track-origins=yes			\
					--read-var-info=yes			\
					--trace-children=yes		\
					--show-leak-kinds=all		\
					--read-inline-info=yes		\
					--errors-for-leak-kinds=all

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

valgrind:	$(NAME)
	valgrind $(VALGRIND_FLAGS) ./$<

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean	all
