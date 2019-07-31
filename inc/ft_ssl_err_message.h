/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_err_message.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:55:51 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/30 13:58:36 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_ERR_MESSAGE_H
# define FT_SSL_ERR_MESSAGE_H

# define INV_COMMAND -1
# define INV_OPTION -2
# define INV_FILE -3
# define DIRECTORY -4

typedef struct	s_err_message
{
	int		errno;
	char	*message;
}				t_err_message;

#endif
