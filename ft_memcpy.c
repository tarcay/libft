/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarcay <tarcay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 11:42:34 by tarcay            #+#    #+#             */
/*   Updated: 2020/12/30 21:54:26 by tarcay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_mem;
	const char	*src_mem;

	if(!dest && !src)
		return (dest);

	dest_mem = dest;
	src_mem = src;
	while (n)
	{
		*dest_mem = *src_mem;
		src_mem++;
		dest_mem++;
		n--;
	}
	return (dest);
}
