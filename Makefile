# **************************************************************************** #
#                                                          :::      ::::::::   #
#   Makefile                                             :+:      :+:    :+:   #
#                                                      +:+ +:+         +:+     #
#   By: gugrug <gustavorugg@gmail.com>               +#+  +:+       +#+        #
#                                                  +#+#+#+#+#+   +#+           #
#                                                       #+#    #+#             #
#                                                      ###   ########          #
# **************************************************************************** #

################################## minishell ##################################

# Name of the executable file		#^
NAME				=	minishell	#|

# C Compiler configuration
CC					=	clang
CC_FLAGS			=	$(BASIC_FLAGS) $(CC_TESTS)
BASIC_FLAGS			=	-Wall -Wextra -Werror
CC_TESTS			=	-g #-fsanitize=address

# Location of the dependencies used
SRCS_DIR			=	./srcs
OBJS_DIR			=	./objs
INCS_DIR			=	./includes
LIBS_DIR			=	./libs
DIR_SRCS_MAIN		=	$(SRCS_DIR)/main
DIR_SRCS_PARSER		=	$(SRCS_DIR)/parser
DIR_SRCS_UTILS		=	$(SRCS_DIR)/utils

# Libraries and its location
FT_DIR				=	$(LIBS_DIR)/libft
LIBFT				=	libft.a
LIBS_DIR_ALL		=	-L$(FT_DIR)
LIBS_ALL			=	-lft
INCLUDE				=	-I$(INCS_DIR) -I$(FT_DIR)/include

# Compact to SRCS
SRCS				=	$(SRCS_MAIN)									\
						$(SRCS_PARSER)									\
						$(SRCS_UTILS)

# Sources
SRCS_MAIN			=	$(DIR_SRCS_MAIN)/main.c

SRCS_PARSER			=	$(DIR_SRCS_PARSER)/parser.c

SRCS_UTILS			=	$(DIR_SRCS_UTILS)/utils.c

# OBJS
SUBDIRS				=	main parser utils
DIR_OBJS			=	$(foreach dir, $(SUBDIRS),						\
						$(addprefix $(OBJS_DIR)/, $(dir)))
OBJS				=	$(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

# COMPILING RULES
all: libs $(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CC_FLAGS) $^ $(LIBS_DIR_ALL) $(LIBS_ALL) -o $@
			@echo "push_swap is ready to use!"

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c
			@echo "Making push_swap . . ."
			@mkdir -p $(OBJS_DIR) $(DIR_OBJS)
			@$(CC) $(CC_FLAGS) $(INCLUDE) -c $< -o $@

# LIBS RULES
libs: $(FT_DIR)/$(LIBFT)

$(FT_DIR)/$(LIBFT):
			@echo "Making libft . . ."
			@$(MAKE) -C $(FT_DIR) all
			@echo "libft is ready to use!"

# CLEAN RULES
libs_clean:
			@echo "Full cleaning libft . . ."
			@$(MAKE) -C $(FT_DIR) name_clean
			@echo "libft has been cleaned thoroughly!"

clean:
			@echo "Cleaning push_swap . . ."
			@rm -r $(OBJS_DIR)
			@echo "push_swap has been cleaned!"

name_clean:
			@echo "Removing $(NAME) . . ."
			@rm -f $(NAME)
			@echo "$(NAME) was removed successfully!"

fclean: libs_clean clean name_clean

# VALGRIND RULES
valg:
	valgrind --leak-check=full ./$(NAME) "2 54 6 8907 635 892 639 729 3 938 279 3487 298 63 0282976 29763 388 21 38 "

# BASIC RULES
re: fclean all

.PHONY: all libs libs_clean clean name_clean fclean re
