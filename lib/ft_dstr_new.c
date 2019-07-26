#include "libft.h"

void	ft_dstr_new(t_dstring *s, char *data, size_t len, size_t cap)
{
	if ((s->buf = malloc(sizeof(*data) * (cap + 1))))
	{
		ft_memcpy(s->buf, data, len);
		s->buf[len] = '\0';
		s->cap = cap;
		s->pos = len;
	}
}
