/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:57:58 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/05 17:08:17 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_ssl.h"
#include "ft_ssl_options.h"
#include "ft_ssl_md.h"
#include "ft_dstring.h"
#include "ft_queue.h"
#include "ft_printf.h"

void    ft_ssl_md_print(t_ssl_file *file, t_ssl_checksum *c, int first)
{
	char    *print_hash;
	uint8_t i;
	char    *name;

	if ((print_hash = u32_to_u8_be(file->hash, c->hash_len)))
	{
		i = 0;
		if (first && (options & _P) == _P)
			ft_printf("%s\n%s\n", file->name, print_hash);
		else if ((options & _Q) == _Q)
			ft_printf("%s\n", print_hash);
		else if ((options & _R) == _R)
			ft_printf("%s %s\n", print_hash, file->name);
		else
			ft_printf("%s (%s) = %s\n",
					(name = ft_str_capitalize(c->algorithm.name)) ?
					name : c->algorithm.name, file->name, print_hash);
		if (name)
			free(name);
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
	while (!ft_queue_is_empty(c->files))
	{
		file = (t_ssl_file *)(ft_queue_dequeue(c->files));
		if (file->e.no < 0)
			print_non_fatal_error(hash);
		else
		{
			(*(chk->algorithm.f))(file->data, file->hash);
			(*(chk->algorithm.print))(file, chk, first);
			first = 0;
		}
		ft_ssl_free_file(file);
	}
	free(c->files);
}
