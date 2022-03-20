/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-hada <mel-hada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 13:01:09 by mel-hada          #+#    #+#             */
/*   Updated: 2022/03/13 18:29:46 by mel-hada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	LIBRARY
*	#include <string.h>
*	DESCRIPTION
*	The strdup() function allocates sufficient memory for a copy of the string 
*	s1, does the copy, and returns a pointer to it.
*	PARAMETERS
*	#1. The string to duplicate.
*	RETURN VALUES
*	The strdup() function returns thE pointer to the copy of s1.
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char		*s2;
	size_t		len;

	len = ft_strlen(s1) + 1;
	s2 = malloc(len);
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, len);
	return (s2);
}
