/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_err_message.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:55:51 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/25 15:18:00 by pheilbro         ###   ########.fr       */
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

t_err_message	g_error_tab[] = 
{
	{0, ""},
	{INV_COMMAND, "is an invalid command."},
	{INV_OPTION, "illegal option"},
	{INV_FILE, "No such file or directory"},
	{DIRECTORY, "Is a directory"}
};

#endif
