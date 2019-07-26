#include "libft.h"

size_t	ft_dstr_extend(t_dstring *s, size_t len)
{
	t_dstring	temp;

	ft_dstr_new(&temp, s->buf, s->pos, s->pos);
	ft_dstr_del(*s);
	ft_dstr_new(s, temp.buf, temp.pos, len);
	ft_dstr_del(temp);
	return (s->cap);
}
