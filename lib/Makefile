# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/30 13:56:22 by pheilbro          #+#    #+#              #
#    Updated: 2019/07/25 18:48:52 by pheilbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libft.a

MEMORY		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_memchr.c \
				ft_memcmp.c ft_memalloc.c ft_memdel.c ft_memndup.c 
STRING		=	ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c \
				ft_strcat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
				ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_isalpha.c \
				ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
				ft_toupper.c ft_tolower.c ft_memccpy.c ft_strncat.c \
				ft_strnew.c ft_strdel.c ft_strclr.c \
				ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
				ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
				ft_strtrim.c ft_strsplit.c ft_stpncpy.c ft_strndup.c \
				ft_isspace.c ft_stpcpy.c ft_strlcpy.c ft_isblank.c \
				ft_lrotstr.c ft_modstrncmp.c ft_lmodrotstr.c
PRINT		=	ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
				ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
LIST		=	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
				ft_lstiter.c ft_lstmap.c
VECTOR		=	ft_vect_add.c ft_vect_del.c ft_vect_extend.c ft_vect_new.c \
				ft_vect_insert.c
DSTRING		=	ft_dstr_add.c ft_dstr_del.c ft_dstr_extend.c ft_dstr_new.c \
				ft_dstr_insert.c ft_dstr_init.c
ADDN		=	ft_itoa.c ft_pow.c get_next_line.c ft_atoi_end.c ft_atoi.c \
				ft_max.c ft_lltoa.c ft_ulltoa_base.c ft_wstrlen.c ft_min.c

OBJ_DIR		=	./obj

SRCS		=	$(MEMORY) $(STRING) $(PRINT) $(LIST) $(VECTOR) $(DSTRING) \
				$(ADDN)
OBJS		=	$(SRCS:%.c=$(OBJ_DIR)/%.o)

CC			=	gcc
AR			=	ar
INC			=	-I inc/
CFLAGS		=	-Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@echo Creating libft.a...
	@$(AR) rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@echo Compiling $<.
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@echo Removing object files...
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo Removing libft.a...
	@rm -f $(NAME)

re: fclean all
