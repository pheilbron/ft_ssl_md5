# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/29 17:20:30 by pheilbro          #+#    #+#              #
#    Updated: 2019/09/06 13:01:33 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_ssl

CC			= gcc
LIB			= -Llib -lft
INC_FLAGS	= -I inc -I lib/inc
CFLAGS		= -Wall -Werror -Wextra -g -fsanitize=address

SRC_DIR		= src
OBJ_DIR		= obj

SRC			= clean get_info parse_input parse_options prep_data \
			  process_and_print parse_message_digest error usage main \
			  algorithms/ft_ssl_message_digest \
			  algorithms/ft_ssl_md5 \
			  algorithms/ft_ssl_sha1 \
			  algorithms/ft_ssl_sha224 \
			  algorithms/ft_ssl_sha256 algorithms/ft_ssl_sha256_aux \
			  algorithms/ft_ssl_sha384 \
			  algorithms/ft_ssl_sha512 algorithms/ft_ssl_sha512_aux \
			  algorithms/ft_ssl_sha512_224 algorithms/ft_ssl_sha512_256
OBJ			= $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))


all: $(NAME)

$(NAME): $(OBJ) lib/libft.a
	@$(CC) $(CFLAGS) $(LIB) -o $@ $^

lib/libft.a:
	@make -sC lib

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	make clean -C lib/
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C lib/
	rm -f $(NAME)

re: fclean all
