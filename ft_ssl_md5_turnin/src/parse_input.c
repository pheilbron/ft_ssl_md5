/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:00:11 by pheilbro          #+#    #+#             */
/*   Updated: 2019/09/06 12:14:03 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include "ft_ssl_error.h"
#include "ft_ssl_message_digest.h"
#include "ft_string.h"

t_ssl_algorithm	g_algo_tab[] =
{
	{md5, "md5", message_digest, &ft_ssl_md5, &ft_ssl_md_print, 4},
	{sha1, "sha1", message_digest, &ft_ssl_sha1, &ft_ssl_md_print, 5},
	{sha224, "sha224", message_digest, &ft_ssl_sha224, &ft_ssl_md_print, 7},
	{sha256, "sha256", message_digest, &ft_ssl_sha256, &ft_ssl_md_print, 8},
	{sha384, "sha384", message_digest, &ft_ssl_sha384, &ft_ssl_md_print, 12},
	{sha512, "sha512", message_digest, &ft_ssl_sha512, &ft_ssl_md_print, 16},
	{sha512, "sha512/224", message_digest, &ft_ssl_sha512_224,
		&ft_ssl_md_print, 7},
	{sha512, "sha512/256", message_digest, &ft_ssl_sha512_256,
		&ft_ssl_md_print, 8},
	{0, NULL, 0, NULL, NULL, 0}
};

static int	parse_ssl_command(t_ssl_checksum *c, char *command)
{
	int	i;

	i = 0;
	while (g_algo_tab[i].name)
	{
		if (ft_strcmp(command, g_algo_tab[i].name) == 0)
		{
			c->algorithm.name = command;
			c->algorithm.algorithm = g_algo_tab[i].algorithm;
			c->algorithm.type = g_algo_tab[i].type;
			c->algorithm.f = g_algo_tab[i].f;
			c->algorithm.print = g_algo_tab[i].print;
			c->algorithm.hash_len = g_algo_tab[i].hash_len;
			return (c->e.no = 1);
		}
		i++;
	}
	c->algorithm.algorithm = -1;
	c->e.data = command;
	return (c->e.no = INV_COMMAND);
}

int			parse_input(t_ssl_checksum *c, char **data, int len)
{
	int	i;

	i = 0;
	if (len == 0)
		return (print_usage(*c));
	ft_ssl_error_init(&(c->e));
	if (parse_ssl_command(c, data[i++]) < 0)
		print_fatal_error(*c);
	else if (c->algorithm.type == message_digest)
		parse_message_digest(c, data, len, &i);
	else
		print_fatal_error(*c);
	return (c->e.no < 0 ? 0 : 1);
}
