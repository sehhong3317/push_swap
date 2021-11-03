/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_max.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:20:09 by sehee             #+#    #+#             */
/*   Updated: 2021/10/31 17:20:29 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_max(int num1, int num2, int num3)
{
	int	max;

	max = num1;
	if (num2 > max)
		max = num2;
	if (num3 > max)
		max = num3;
	return (max);
}
