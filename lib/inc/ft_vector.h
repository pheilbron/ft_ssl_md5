/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pheilbro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 08:45:45 by pheilbro          #+#    #+#             */
/*   Updated: 2019/07/28 08:45:58 by pheilbro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

# include <stdlib.h>

typedef struct	s_vector
{
	char	*data;
	size_t	size;
	size_t	pos;
}				t_vector;

t_vector		*ft_vect_new(char *s, size_t len, size_t size);
size_t			ft_vect_add(t_vector *v, char *s, size_t len);
size_t			ft_vect_insert(t_vector *v, size_t pos, char *s, size_t len);
size_t			ft_vect_extend(t_vector *v, size_t len);
size_t			ft_vect_del(t_vector *v);

#endif
