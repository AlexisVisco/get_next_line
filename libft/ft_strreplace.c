/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 14:16:08 by aviscogl          #+#    #+#             */
/*   Updated: 2017/11/13 14:34:38 by aviscogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strreplace(char *search, char *replace, char *subject)
{
	char *result;

	result = ft_strreplace_first(search, replace, subject);
	if (ft_strstr(result, search))
		return (ft_strreplace(search, replace, result));
	return (result);
}
