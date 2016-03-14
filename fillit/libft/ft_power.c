/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcharles <vuck@hotmail.fr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/30 13:00:26 by vcharles          #+#    #+#             */
/*   Updated: 2015/12/30 13:09:19 by vcharles         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int n, int p)
{
	int		i;

	i = 1;
	while (p-- > 0)
		i = i * n;
	return (i);
}