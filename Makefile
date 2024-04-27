##
## EPITECH PROJECT, 2024
## {Workshop} Network Programming
## File description:
## Server's Makefile
##

NAME	:= http_server
SRCS	:=	$(shell find libs -name '*.c') $(shell find src -name '*.c')
OBJS	:=	$(SRCS:.c=.o)
RM		:=	rm -rf

CC			:=	gcc
CPPFLAGS	:=	-Iinclude/
CFLAGS 		:=	-Wall -Wextra -Werror -std=gnu89 -fPIE -Wformat		 \
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

CFLAGS		+= -g

TESTS_CFLAGS	:=	-g -Wall -Wextra -Werror
TESTS_SRCS		:=	$(shell find tests -type f -name 'tests_*.c')
TESTS_OBJS		:=	$(TESTS_SRCS:.c=.o)

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

tests/%.o:	CFLAGS = -Wall -Wextra -Werror
tests/%.o:	tests/%.c
	@$(CC) $(TESTS_CFLAGS) $(CPPFLAGS) -o $@ -c $<

tests_run:	CFLAGS = -DCRITERION_NO_MAIN -g --coverage
tests_run:	fclean	$(OBJS)	$(TESTS_OBJS)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) $(TESTS_OBJS) -o unit_tests -lcriterion
	CRITERION_NO_EARLY_EXIT=1 ./unit_tests
	gcovr -e tests .

valgrind:	tests_run
	valgrind $(VALGRIND_FLAGS) ./unit_tests

clean:
	@$(RM) $(OBJS)
	@$(RM) $(TESTS_OBJS)
	@$(RM) $(shell find . -type f -name '*.gcno')
	@$(RM) $(shell find . -type f -name '*.gcda')

fclean:	clean
	$(RM) $(NAME)
	$(RM) unit_tests

re:	fclean	all
