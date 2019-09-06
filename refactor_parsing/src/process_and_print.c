/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:57:58 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/05 21:49:34 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_ssl.h"
#include "ft_ssl_options.h"
#include "ft_ssl_message_digest.h"
#include "ft_dstring.h"
#include "ft_string.h"
#include "ft_queue.h"
#include "ft_printf.h"

char	*u32_to_u8_be(uint32_t *hash, uint8_t len)
{
	t_dstring	*ret;
	int			i;

	ret = ft_dstr_init();
	i = 0;
	while (i < len)
		ft_dstr_addf(ret, "%.8x", hash[i++]);
	return (ft_dstr_release(ret));
}

void    ft_ssl_md_print(t_ssl_file *file, t_ssl_checksum *c, int first)
{
	char    *print_hash;
	char    *name;

	if ((print_hash = u32_to_u8_be(file->hash, c->algorithm.hash_len)))
	{
		if (first && (c->options & _P) == _P)
			ft_printf("%s%s\n", file->data, print_hash);
		else if ((c->options & _Q) == _Q)
			ft_printf("%s\n", print_hash);
		else if ((c->options & _R) == _R)
			ft_printf("%s %s%s%s\n", print_hash, file->file_name ? "" : "\"",
					(file->file_name ? file->file_name : file->data),
					file->file_name ? "" : "\"");
		else
		{
			ft_printf("%s (%s%s%s) = %s\n",
					(name = ft_str_capitalize(c->algorithm.name)) ? name :
					c->algorithm.name, file->file_name ? "" : "\"",
					file->file_name ? file->file_name : file->data,
					file->file_name ? "" : "\"", print_hash);
			if (name)
				free(name);
		}
		free(print_hash);
	}
	else
		ft_printf("\n");
}

void	ft_ssl_process_and_print(t_ssl_checksum *chk)
{
	t_ssl_file	*file;
	int			first;

	first = 1;
	while (!ft_queue_is_empty(chk->files))
	{
		file = (t_ssl_file *)(ft_queue_dequeue(chk->files));
		if (file->e.no < 0)
			print_non_fatal_error(file, chk->algorithm.name);
		else if ((file->hash =
					malloc(sizeof(*(file->hash)) * chk->algorithm.hash_len)))
		{
			(*(chk->algorithm.f))(file->data, &(file->hash));
			(*(chk->algorithm.print))(file, chk, first);
			first = 0;
		}
		ft_ssl_free_file(file);
	}
	free(chk->files);
}
