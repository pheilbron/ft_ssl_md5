/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:15:44 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 11:22:11 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_ERROR_H
# define FT_SSL_ERROR_H

# include "ft_ssl.h"

# define INV_COMMAND -1
# define INV_OPTION -2
# define INV_FILE -3
# define DIRECTORY -4
# define MISSING_ARG -5
# define SYS_ERROR -6

typedef struct	s_err_message
{
	int		errno;
	char	*message;
}				t_err_message;

typedef struct	s_error
{
	int		no;
	char	*data;
}				t_error;

void			print_usage(t_ssl_checksum chk);
void			print_fatal_error(t_error e, t_ssl_checksum chk);
void			set_ssl_error(t_ssl_file *file, t_error e);

#endif
