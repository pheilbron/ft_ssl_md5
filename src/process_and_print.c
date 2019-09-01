/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_and_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:57:58 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/01 14:46:28 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_ssl.h"
#include "ft_ssl_md.h"
#include "ft_printf.h"

extern t_ssl_algorithm	g_algo_tab[];

static void	(*get_ssl_algorithm(enum e_ssl_algorithm_type type))(char *,
		uint32_t *)
{
	int	i;

	i = 0;
	while (g_algo_tab[i].algorithm)
	{
		if (g_algo_tab[i].type == type)
			return (g_algo_tab[i].f);
		i++;
	}
	return (NULL);
}

static void	ft_ssl_no_print(char *algo_name, uint8_t algo_ops, uint8_t hash_len,
		t_ssl_file *file)
{
	ft_printf("Error: %s, %s, %hhd\n", algo_name, file->file_name,
			(algo_ops > 0 ? algo_ops : hash_len));
}

static void	(*get_ssl_print(enum e_ssl_algorithm_type type))(char *, uint8_t,
		uint8_t, t_ssl_file *)
{
	int	i;

	i = 0;
	while (g_algo_tab[i].algorithm)
	{
		if (type == g_algo_tab[i].type)
			return (g_algo_tab[i].print);
		i++;
	}
	return (&ft_ssl_no_print);
}

void		ft_ssl_process_and_print(t_ssl_checksum *chk)
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
			(*get_ssl_algorithm)(chk->algorithm.type)(file->data, file->hash);
			(*get_ssl_print)(chk->algorithm.type)(chk->algorithm.name,
					chk->options, chk->algorithm.hash_len, file);
		}
		i++;
	}
}
