/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:15:44 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/25 15:15:53 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_ERROR_H
# define FT_SSL_ERROR_H

typedef struct	s_error
{
	int		no;
	char	*data;
}				t_error;

#endif
