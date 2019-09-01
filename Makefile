# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/29 17:20:30 by pheilbro          #+#    #+#              #
#    Updated: 2019/09/01 16:23:00 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ssl

CC			= gcc
LIB			= -L../libft -lft
INC_FLAGS	= -I inc -I ../libft/inc
CFLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -g -fsanitize=address

SRC_DIR		= src
OBJ_DIR		= obj

SRC			= main get_info parse_input parse_options process_and_print \
			  prep_data error clean \
			  algorithms/ft_ssl_md5 #\
			  algorithms/ft_ssl_sha256
OBJS		= $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))


all: $(NAME)

$(NAME): $(OBJS)
	@echo Compiling library.
	@make -C ../libft
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(LIB) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@echo Compiling $<.
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

debug: all
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(DEBUG_FLAGS) $(LIB) -o $@ $<

clean: clean_debug
	#make clean -C lib/
	rm -rf $(OBJ_DIR)

clean_debug:
	rm -f debug 
	rm -rf debug.dSYM 

fclean: clean clean_debug
	#make fclean -C lib/
	rm -f $(NAME)

re: fclean all
