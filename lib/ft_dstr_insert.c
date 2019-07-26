#include "libft.h"

void	ft_dstr_insert(t_dstring *s, char *new_data, size_t len, size_t pos)
{
	if (s->cap < s->pos + len + 1)
		ft_dstr_extend(s, s->cap * 2 + (s->cap >= len ? 0 : len));
	ft_memmove(s->buf + pos + len, s->buf + pos, s->pos - pos);
	ft_memcpy(s->buf + pos, new_data, len);
	s->buf[s->pos + len] = '\0';
	s->pos += len;
}
