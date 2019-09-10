/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:56:51 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 19:42:21 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		(*g_convert_data(char type))(t_dstring *, t_form, va_list *)
{
	size_t		i;
	const t_con	contab[] = {{'b', &set_unsigned_fstring},
		{'c', &set_char_fstring}, {'d', &set_int_fstring},
		{'f', &set_float_fstring}, {'i', &set_int_fstring},
		{'n', &get_chars_written}, {'o', &set_unsigned_fstring},
		{'p', &set_pointer_fstring}, {'r', &set_non_print_fstring},
		{'s', &set_string_fstring}, {'u', &set_unsigned_fstring},
		{'x', &set_unsigned_fstring}, {'%', &set_mod_fstring},
		{0, &set_int_fstring}};

	i = 0;
	while (contab[i].type != 0)
	{
		if (contab[i].type == type)
			return (contab[i].f);
		i++;
	}
	return (contab[i].f);
}
