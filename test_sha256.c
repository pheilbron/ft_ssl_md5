#include <stddef.h>
#include "ft_printf.h"
#include "ft_ssl_sha256.h"

int	main(void)
{
//	ft_printf("%.8llb %.8llb %.8llb %.8llb\n", '@', '@', '@', '@');
//	ft_printf("%d\n", 65/4);
//	ft_ssl_md5("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", NULL);
	uint32_t	*hash = malloc(sizeof(*hash) * 8);
	ft_ssl_sha256("abc", &hash);
//	ft_ssl_md5("The quick brown fox jumps over the lazy dog", NULL);
	return (0);
}
