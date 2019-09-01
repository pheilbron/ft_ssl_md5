/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_file.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:49:31 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/01 14:50:04 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_FILE_H
# define FT_SSL_FILE_H

typedef struct	s_ssl_file
{
	int			fd;
	char		*file_name;
	char		*data;
	uint8_t		print_flag;
	uint32_t	*hash;
}				t_ssl_file;

#endif
