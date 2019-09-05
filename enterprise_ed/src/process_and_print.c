/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:57:58 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/02 10:14:14 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_ssl.h"
#include "ft_ssl_options.h"
#include "ft_ssl_md.h"
#include "ft_dstring.h"
#include "ft_printf.h"

void	ft_ssl_md_print(char *algo_name, uint8_t algo_ops, uint8_t hash_len,
		t_ssl_file *file)
{
	t_dstring	*p_hash;
	int			i;

	p_hash = ft_dstr_init();
	i = 0;
	while (i < hash_len)
		ft_dstr_addf(p_hash, "%.8x", file->hash[i]);
	if (algo_ops & _Q || file->print_flag & _P)
		ft_printf("%s\n", p_hash->buf);
	else if (algo_ops & _R)
		ft_printf("%s %s\n", p_hash->buf, file->file_name);
	else
		ft_printf("%s (%s) = %s", algo_name, file->file_name, p_hash->buf);
	ft_dstr_free(p_hash);
}

void	ft_ssl_process_and_print(t_ssl_checksum *chk)
{
	int			i;
	t_ssl_file	*file;

	i = 0;
	while (i < chk->files->pos)
	{
		file = (t_ssl_file *)(chk->files->data[i]);
		if (file->fd == -1)
			print_non_fatal_error(file);
		else
		{
			(*(chk->algorithm.f))(file->data, file->hash);
			(*(chk->algorithm.print))(chk->algorithm.name,
			chk->options, chk->algorithm.hash_len, file);
		}
		i++;
	}
}
