/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 18:11:24 by aviscogl          #+#    #+#             */
/*   Updated: 2017/11/21 16:08:32 by aviscogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					copyuntil(char **dst, char *src, char c)
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
		if (!(*dst = ft_strjoinchar(*dst, src[count])))
			return (0);
		count++;
	}
	return (pos);
}

static t_list		*valid_list(t_list **file, int fd)
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

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_list	*memorized;
	t_list			*current;
	int				stream_size;
	int				i;

	if (fd < 0 || read(fd, buf, 0) < 0 || line == NULL)
	{
		printf("cond arret 2");
		return -1;
	}
	current = valid_list(&memorized, fd);
	while ((stream_size = read(fd, buf, BUFF_SIZE)))
	{
		buf[stream_size] = '\0';
		if(!(current->content = ft_strjoin(current->content, buf)))
		{
			printf("end ??\n");
			return 0;
		}
		if (ft_strchr(buf, '\n'))
		{
			printf("hello\n");
			break ;
		}
	}
	if (stream_size < BUFF_SIZE && !ft_strlen((char *)current->content))
	{
		printf("|%c|\n", buf[0]);
		return (0);
	}
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