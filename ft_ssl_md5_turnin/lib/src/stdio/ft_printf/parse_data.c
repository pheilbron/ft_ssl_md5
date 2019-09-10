/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 19:30:58 by pheilbro          #+#    #+#             */
/*   Updated: 2019/08/29 21:41:06 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_ctype.h"
#include "ft_stdlib.h"

void	set_data_flags(const char **s, int *pos, t_form *format)
{
	while (is_data_flag((*s)[*pos]))
	{
		if ((*s)[*pos] == '#')
			format->flags |= _ALT;
		else if ((*s)[*pos] == '0')
			format->flags |= _ZERO;
		else if ((*s)[*pos] == '-')
			format->flags |= _LEFT_JUST;
		else if ((*s)[*pos] == '+')
			format->flags |= _SIGN;
		else if ((*s)[*pos] == ' ')
			format->flags |= _BLANK;
		(*pos)++;
	}
}

void	set_data_precision(const char **s, int *pos, t_form *format,
		va_list *ap)
{
	(*pos)++;
	if (ft_isdigit((*s)[*pos]))
		format->pre = ft_atoi_end(*s + *pos, pos);
	else if ((*s)[*pos] == '*')
	{
		format->pre = va_arg(*ap, int);
		(*pos)++;
	}
	else
		format->pre = 0;
}

void	set_data_fw(const char **s, int *pos, t_form *format, va_list *ap)
{
	if (ft_isdigit((*s)[*pos]) && (*s)[*pos] != '0')
		format->fw = ft_atoi_end(*s + *pos, pos);
	else if ((*s)[*pos] == '*')
	{
		if ((format->fw = va_arg(*ap, int)) < 0)
		{
			format->flags |= _LEFT_JUST;
			format->fw *= -1;
		}
		(*pos)++;
	}
}

void	set_data_lmod(const char **s, int *pos, t_form *format)
{
	while (is_data_lmod((*s)[*pos]))
	{
		format->lmod += (*s)[*pos];
		(*pos)++;
	}
	*s += *pos;
	*pos = 0;
}

void	ft_form_clean(t_form *f)
{
	if (f->type >= 'A' && f->type <= 'Z')
	{
		f->type += 'a' - 'A';
		f->flags |= _CAP;
		f->lmod = (((!f->lmod || f->lmod == ('h' + 'h') ||
				f->lmod == 'h') && f->type != 'x') ? 'l' : f->lmod);
	}
	if (!(f->type == 'a' || f->type == 'd' || f->type == 'e' || f->type == 'f'
				|| f->type == 'f' || f->type == 'g' || f->type == 'i'))
	{
		f->flags &= ~_BLANK;
		f->flags &= ~_SIGN;
	}
	if (f->pre == -1 && (f->type == 'f' || f->type == 'g' || f->type == 'f'
				|| f->type == 'a'))
		f->pre = 6;
	if (f->type != 'b' && f->type != 'o' && f->type != 'x' && f->type != 'a' &&
			f->type != 'e' && f->type != 'f' && f->type != 'g')
		f->flags &= ~_ALT;
	if (f->type == 'f' && f->lmod == 'L')
		f->lmod = ('l' + 'l');
	f->flags = ((f->flags & _LEFT_JUST) || f->pre > 0) ?
		(f->flags & ~_ZERO) : f->flags;
}
