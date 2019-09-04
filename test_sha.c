#include <stddef.h>
#include "ft_printf.h"
#include "ft_ssl_sha1.h"
#include "ft_ssl_sha256.h"
#include "ft_ssl_sha512.h"

int	main(void)
{
	uint32_t	*hash = malloc(sizeof(*hash) * 16);
	ft_ssl_sha256("abc", &hash);
	ft_printf("%.8x %.8x %.8x %.8x %.8x %.8x %.8x %.8x\n",
			hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6], hash[7]);
//	ft_printf("%.8x %.8x %.8x %.8x %.8x %.8x %.8x %.8x %.8x %.8x %.8x %.8x %.8x %.8x %.8x %.8x\n",
//			hash[0], hash[1], hash[2], hash[3], hash[4], hash[5], hash[6],
//			hash[7], hash[8], hash[9], hash[10], hash[11], hash[12], hash[13],
//			hash[14], hash[15]);
	return (0);
}
