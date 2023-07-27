# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mstegema <mstegema@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/07/12 13:58:59 by mstegema      #+#    #+#                  #
#    Updated: 2023/07/27 14:18:03 by mstegema      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME	= minitalk
PROG1	= client
PROG2	= server

# compilation
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
HEADER	= $(INCDIR)/$(NAME).h
LIBFT	= libft/bin/libft.a

ifdef DEBUG
LINKS	+= -fsanitize=address -g
endif

# directories
SRCDIR	= src
INCDIR	= inc
OBJDIR	= obj
BINDIR	= bin

# sources
SRCS1	= src/client.c
SRCS2	= src/server.c

# objects
OBJS1	= $(SRCS1:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
OBJS2	= $(SRCS2:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

# colours
PURPLE	= \033[0;35m
NC		= \033[0m

# rules
all: $(LIBFT) $(BINDIR)/$(PROG1) $(BINDIR)/$(PROG2)

$(LIBFT):
	@$(MAKE) -C ./libft

$(BINDIR)/$(PROG1): $(OBJS1)
	@mkdir -p $(BINDIR)
	@$(CC) -o $(BINDIR)/$(PROG1) $(OBJS1) $(LIBFT) $(LINKS)
	@echo "$(PURPLE)$(PROG1)$(NC) has been created"

$(BINDIR)/$(PROG2): $(OBJS2)
	@mkdir -p $(BINDIR)
	@$(CC) -o $(BINDIR)/$(PROG2) $(OBJS2) $(LIBFT) $(LINKS)
	@echo "$(PURPLE)$(PROG2)$(NC) has been created"

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEADER)
	@mkdir -p $(OBJDIR)
	@$(CC) -c $(CFLAGS) $(LINKS) $< -o $@
	@echo "Compiling: $(PURPLE)$<$(NC)"

debug:
	$(MAKE) DEBUG=1

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJDIR)
	@echo "$(PURPLE)object files$(NC) have been removed"

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -rf $(BINDIR)
	@echo "$(PURPLE)$(PROG1), $(PROG2) & directories$(NC) have been removed"

re: fclean all

.PHONY: all clean fclean re
