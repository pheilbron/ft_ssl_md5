/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:57:58 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/06 12:38:53 by pheilbro         ###   ########.fr       */
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

void	ft_ssl_md_print(t_ssl_file *f, t_ssl_checksum *c)
{
	char	*p_hash;
	char	*name;

	if ((p_hash = u32_to_u8_be(f->hash, c->algorithm.hash_len)))
	{
		if ((f->flag & _P) == _P)
			ft_printf("%s%s\n", ((f->flag & IN) != IN) ? f->data : "", p_hash);
		else if ((c->options & _Q) == _Q)
			ft_printf("%s\n", p_hash);
		else if ((c->options & _R) == _R)
			ft_printf("%s %s%s%s\n", p_hash, f->name ? "" : "\"",
					(f->name ? f->name : f->data), f->name ? "" : "\"");
		else
		{
			ft_printf("%s (%s%s%s) = %s\n",
					(name = ft_str_capitalize(c->algorithm.name)) ? name :
					c->algorithm.name, f->name ? "" : "\"", f->name ? f->name :
					f->data, f->name ? "" : "\"", p_hash);
			if (name)
				free(name);
		}
		free(p_hash);
	}
	else
		ft_printf("\n");
}

void	ft_ssl_process_and_print(t_ssl_checksum *chk)
{
	t_ssl_file	*file;

	while (!ft_queue_is_empty(chk->files))
	{
		file = (t_ssl_file *)(ft_queue_dequeue(chk->files));
		if (file->e.no < 0)
			print_non_fatal_error(file, chk->algorithm.name);
		else if ((file->hash =
					malloc(sizeof(*(file->hash)) * chk->algorithm.hash_len)))
		{
			(*(chk->algorithm.f))(file->data, &(file->hash));
			(*(chk->algorithm.print))(file, chk);
		}
		ft_ssl_free_file(file);
	}
	free(chk->files);
}
