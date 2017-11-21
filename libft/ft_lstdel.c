/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:23:33 by aviscogl          #+#    #+#             */
/*   Updated: 2017/11/13 13:18:23 by aviscogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **list, void (*del)(void *, size_t))
{
	t_list	*erase;
	t_list	*next;

	erase = *list;
	while (erase)
	{
		next = erase->next;
		del(erase->content, erase->content_size);
		free(erase);
		erase = next;
	}
	*list = NULL;
}
