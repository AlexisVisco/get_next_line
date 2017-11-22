/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.le101.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 09:39:15 by aviscogl          #+#    #+#             */
/*   Updated: 2017/11/22 13:37:29 by aviscogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

#define BUFF_SIZE 42

int		get_next_line(const int fd, char **line);

int		main()
{
	char *str;
	int fd = open("sample", O_RDONLY);
	while(get_next_line(fd, &str))
	{
		printf("%s\n", str);
	}
}