/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_err_message.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:55:51 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/28 12:00:22 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_ERR_MESSAGE_H
# define FT_SSL_ERR_MESSAGE_H

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

#endif
