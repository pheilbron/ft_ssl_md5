# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/29 17:20:30 by pheilbro          #+#    #+#              #
#    Updated: 2019/09/02 19:40:35 by pheilbro         ###   ########.fr        #
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

SRC			= clean get_info parse_input parse_options prep_data \
			  process_and_print error main \
			  algorithms/ft_ssl_md5 #\
			  algorithms/ft_ssl_sha256
OBJ			= $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))


all: $(NAME)

$(NAME): $(OBJ) ../libft/libft.a
	@$(CC) $(CFLAGS) $(LIB) -o $@ $^

../libft/libft.a:
	@make -sC libft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

test_md5:
	gcc $(DEBUG_FLAGS) -I inc -I ../libft/inc -L ../libft -lft test_md5.c src/algorithms/ft_ssl_md5.c src/algorithms/ft_ssl_message_digest.c src/prep_data.c

test_sha:
	gcc $(DEBUG_FLAGS) -I inc -I ../libft/inc -L ../libft -lft test_sha256.c src/algorithms/ft_ssl_sha256.c src/algorithms/ft_ssl_message_digest.c src/prep_data.c

debug: 
	$(CC) $(FLAGS) $(DEBUG_FLAGS) $(INC_FLAGS) src/*.c src/algorithms/*.c ../libft/src/*/*.c ../libft/src/stdio/ft_printf/*.c ../libft/src/stdio/ft_printf/*/*.c

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
