/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl_md.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 14:45:26 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/01 14:50:37 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_MD_H
# define FT_SSL_MD_H

# include <stdint.h>
# include "ft_ssl_file.h"

void			ft_ssl_md_print(char *algo_name, uint8_t algo_ops,
		uint8_t hash_len, t_ssl_file *file);

#endif
