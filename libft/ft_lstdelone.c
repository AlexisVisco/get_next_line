/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:50:09 by aviscogl          #+#    #+#             */
/*   Updated: 2017/11/13 13:18:17 by aviscogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **list, void (*del)(void*, size_t))
{
	if (*list)
		(*del)((*list)->content, (*list)->content_size);
	ft_memdel((void **)list);
}
