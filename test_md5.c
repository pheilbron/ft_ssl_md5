#include <stddef.h>
#include <stdlib.h>
#include "ft_printf.h"
#include "ft_ssl_md5.h"

int	main(void)
{
//	ft_printf("%.8llb %.8llb %.8llb %.8llb\n", '@', '@', '@', '@');
//	ft_printf("%d\n", 65/4);
//	ft_ssl_md5("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@", NULL);
	uint32_t	hash[4];
	ft_ssl_md5("", &hash);
	ft_ssl_md5("a", &hash);
	ft_ssl_md5("abc", &hash);
	ft_ssl_md5("The quick brown fox jumps over the lazy dog", &hash);
	return (0);
}
