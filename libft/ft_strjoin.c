/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le101.fr>       +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/10 09:28:17 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 14:50:31 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_size;
	char	*res;

	if (!s1 || !s2)
		return (NULL);
	total_size = ft_strlen(s1) + ft_strlen(s2);
	if (!(res = ft_strnew(total_size + 120))))
		return (NULL);
	while (*s1)
	{
		*res++ = *s1;
		s1++;
	}
	while (*s2)
	{
		*res++ = *s2;
		s2++;
	}
	return (res - total_size);
}
