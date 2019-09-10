# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/04 19:31:10 by pheilbro          #+#    #+#              #
#    Updated: 2019/09/06 09:58:11 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

STRING		= ft_strlen ft_strdup ft_strcpy ft_strncpy ft_strcat ft_strlcat \
			  ft_strchr ft_strrchr ft_strstr ft_strnstr ft_strcmp ft_strncmp \
			  ft_toupper ft_tolower ft_memccpy ft_strncat ft_strnew \
			  ft_strdel ft_strclr ft_striter ft_striteri ft_strmap \
			  ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin \
			  ft_strtrim ft_strsplit ft_stpncpy ft_strndup ft_stpcpy \
			  ft_strlcpy ft_lrotstr ft_modstrncmp ft_lmodrotstr ft_memset \
			  ft_bzero ft_memcpy ft_memmove ft_memchr ft_memcmp ft_memdel \
			  ft_memndup ft_wstrlen ft_str_capitalize
CTYPE		= ft_isspace ft_isblank ft_isalpha ft_isdigit ft_isalnum \
			  ft_isascii ft_isprint
STDIO		= ft_putchar ft_putstr ft_putendl ft_putnbr ft_putchar_fd \
			  ft_putstr_fd ft_putendl_fd ft_putnbr_fd
STDLIB		= ft_itoa ft_atoi ft_lltoa ft_ulltoa_base get_next_line \
			  ft_memalloc ft_atoi_end
LIST		= ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstiter \
			  ft_lstmap
VECTOR		= ft_vect_add ft_vect_del ft_vect_resize ft_vect_new \
			  ft_vect_init ft_vect_free ft_vect_get ft_vect_set
DSTRING     = ft_dstr_add ft_dstr_add_nc ft_dstr_del ft_dstr_free \
			  ft_dstr_new ft_dstr_resize ft_dstr_init ft_dstr_insert \
			  ft_dstr_insert_nc ft_dstr_overwrite ft_dstr_release \
			  ft_dstr_fadd
QUEUE		= ft_queue_init ft_queue_is_empty ft_queue_enqueue \
			  ft_queue_dequeue ft_queue_peek ft_queue_push
MATH		= ft_pow ft_max ft_min ft_llpow ft_ullpow ft_int_sqrt
PRINTF		= ft_printf ft_sprintf parse_data format printf_adjust_fw \
			  printf_type convert_data ft_fstring ft_printf_ldtoa \
			  conversions/char \
			  conversions/chars_written \
			  conversions/color \
			  conversions/float \
			  conversions/integer \
			  conversions/mod \
			  conversions/non_print_string \
			  conversions/pointer \
			  conversions/string \
			  conversions/unsigned_integer

SRC_DIR		= src
OBJ_DIR		= obj

SRC			= $(patsubst %, string/%, $(STRING)) \
			  $(patsubst %, ctype/%, $(CTYPE)) \
			  $(patsubst %, stdio/%, $(STDIO)) \
			  $(patsubst %, stdlib/%, $(STDLIB)) \
			  $(patsubst %, list/%, $(LIST)) \
			  $(patsubst %, vector/%, $(VECTOR)) \
			  $(patsubst %, dstring/%, $(DSTRING)) \
			  $(patsubst %, queue/%, $(QUEUE)) \
			  $(patsubst %, math/%, $(MATH)) \
			  $(patsubst %, stdio/ft_printf/%, $(PRINTF))
OBJS		= $(patsubst %, $(OBJ_DIR)/%.o, $(SRC))

AR			= ar
CC			= gcc
INC_FLAGS	= -I inc -I lib/inc
CFLAGS		= -Wall -Werror -Wextra 

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) -rcs $@ $(OBJS)
	@ranlib $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c 
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC_FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all
