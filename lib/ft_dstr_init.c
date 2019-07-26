#include "libft.h"

void	ft_dstr_init(t_dstring *s)
{
	if ((s->buf = malloc(sizeof(*(s->buf)) * 8)))
	{
		s->buf[0] = '\0';
		s->cap = 8;
		s->pos = 0;
	}
}
