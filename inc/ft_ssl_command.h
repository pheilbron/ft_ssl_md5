
#ifndef FT_SSL_COMMAND_H
# define FT_SSL_COMMAND_H

typedef struct	s_ssl_command
{
	enum e_ssl_algorithm		algorithm;
	char						*name;
	enum e_ssl_algorithm_type	type;
}				t_ssl_command;

t_ssl_command	g_command_tab[] =
{
	{md5, "md5", message_digest},
	{0, NULL, 0}
};

#endif
