/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:59:12 by aviscogl          #+#    #+#             */
/*   Updated: 2017/11/13 14:02:20 by aviscogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *list, void (*print_function)(t_list*))
{
	if (!list)
		return ;
	ft_putchar('{');
	while (list)
	{
		print_function(list);
		list = list->next;
		if (list)
			ft_putstr(", ");
	}
	ft_putchar('}');
}
