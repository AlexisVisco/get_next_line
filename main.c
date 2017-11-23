/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aviscogl <aviscogl@student.le101.fr>       +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 09:39:15 by aviscogl     #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 14:15:31 by aviscogl    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

//#define BUFF_SIZE 1

int		get_next_line(const int fd, char **line);

int		main()
{
	int i = 0;
	int res;
	char *str;
	int fd = open("sample", O_RDONLY);
	while((res = get_next_line(fd, &str)) > 0 && i < 15)
	{
		i++;
		printf("line%3d:%s\n", i, str);
		//printf("line :%s\nres: %i\n", str, res);	
		//printf("\n-------\n");
	}
}