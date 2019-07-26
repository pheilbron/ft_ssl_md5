NAME		= ft_ssl

CC			= gcc
LIB			= -Llib -lftprintf
INC_FLAGS	= -I inc -I lib/inc
CFLAGS		= -Wall -Werror -Wextra
DEBUG_FLAGS	= -g -fsanitize=address

SRC_DIR		= src
OBJ_DIR		= obj

SRC			= get_info parse_input compute_checksum print_error print_hash \
			  algorithms/ft_sslmd5
OBJS		= $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))


all: $(NAME)

$(NAME): $(OBJS)
	@echo Compiling library.
	@make -C lib/
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(LIB) -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@echo Compiling $<.
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

debug: all
	@$(CC) $(CFLAGS) $(INC_FLAGS) $(DEBUG_FLAGS) $(LIB) -o $@ $<

clean: clean_debug
	make clean -C lib/
	rm -rf $(OBJ_DIR)

clean_debug:
	rm -f debug 
	rm -rf debug.dSYM 

fclean: clean clean_debug
	make fclean -C lib/
	rm -f $(NAME)

re: fclean all

