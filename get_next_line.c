/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:11:24 by aviscogl          #+#    #+#             */
/*   Updated: 2017/11/20 21:10:43 by aviscogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strjoinch(char const *s1, char c)
{
	char	*new_str;
	size_t	i;
	size_t	s1_len;

	if (!s1 || !c)
		return (NULL);
	s1_len = ft_strlen(s1);
	new_str = ft_strnew(s1_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	return (new_str);
}

int			copyuntil(char **dst, char *src, char c)
{
	int		i;
	int		count;
	int		pos;

	i = -1;
	count = 0;
	while (src[++i])
		if (src[i] == c)
			break ;
	pos = i;
	if (!(*dst = ft_strnew(i)))
		return (0);
	while (src[count] && count < i)
	{
		if (!(*dst = ft_strjoinch(*dst, src[count])))
			return (0);
		count++;
	}
	return (pos);
}

static t_list	*valid_list(t_list **file, int fd)
{
	t_list *tmp;

	tmp = *file;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = ft_lstnew("\0", fd);
	ft_lstadd(file, tmp);
	tmp = *file;
	return (tmp);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*memorized;
	t_list			*current;
	int				stream_size;
	int				i;

	if (fd < 0 || read(fd, buf, 0) < 0 || line == NULL)
		return -1;
	current = valid_list(&memorized, fd);
	while ((stream_size = read(fd, buf, BUFF_SIZE)))
	{
		buf[stream_size] = '\0';
		if(!(current->content = ft_strjoin(current->content, buf)))
			return 0;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (stream_size < BUFF_SIZE && !ft_strlen(current->content))
		return (0);
	i = copyuntil(line, current->content, '\n');
	if (i < (int)ft_strlen(current->content))
		current->content += (i + 1);
	else
		ft_strclr(current->content);
	return (1);
}

int		main(int n, char **argv)
{
	char *str;
	if (n < 2 || n > 2)
		return 0;
	char *filename = argv[1];
	int fd = open(filename, O_RDONLY);
	if (fd < 0)
		return 0;
	while(get_next_line(fd, &str) >= 1)
		printf("- %s\n", str);
}