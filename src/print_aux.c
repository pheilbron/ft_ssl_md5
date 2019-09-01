/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 13:59:25 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/01 14:50:51 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_md.h"
#include "ft_dstring.h"

void	ft_ssl_md_print(char *algo_name, uint8_t algo_ops, uint8_t hash_len,
		t_ssl_file *file)
{
	t_dstring	*p_hash;
	int			i;

	p_hash = ft_dstr_init();
	i = 0;
	while (i < hash_len)
		ft_dstr_fadd(p_hash, "%.8x", file->hash[i]);
	if (options & _Q || file->print_flag & _P)
		ft_printf("%s\n", p_hash);
	else if (options & _R)
		ft_printf("%s %s\n", p_hash, file->file_name);
	else
		ft_printf("%s (%s) = %s", algo_name, file.file_name, p_hash);
	ft_dstr_free(p_hash);
}
