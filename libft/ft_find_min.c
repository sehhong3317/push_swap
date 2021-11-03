/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_min.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sehee <sehee@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:23:37 by sehee             #+#    #+#             */
/*   Updated: 2021/10/31 19:29:46 by sehee            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_find_min(int num1, int num2, int num3)
{
	int	min;

	min = num1;
	if (num2 < min)
		min = num2;
	if (num3 < min)
		min = num3;
	return (min);
}
