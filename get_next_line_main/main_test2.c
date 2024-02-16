/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atedesch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 21:02:19 by atedesch          #+#    #+#             */
/*   Updated: 2024/02/16 21:05:03 by atedesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../get_next_line/get_next_line.h"
#include "../get_next_line/get_next_line_utils.c"
#include "../get_next_line/get_next_line.c"

int	main(void)
{
	int		fd;
	char	*line;
	char	*line2;
	char	*line3;
	char	*line4;

	fd = open("myfile.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Errore apertura file");
		return (1);
	}
	line = get_next_line(fd);
	printf("%s", line);
	free(line);
	line2 = get_next_line(fd);
	printf("%s", line2);
	free(line2);
	line3 = get_next_line(fd);
	printf("%s", line3);
	free(line3);
	line4 = get_next_line(fd);
	printf("%s", line4);
	free(line4);
	if (close(fd) < 0)
	{
		perror("Errore chiusura file");
		return (1);
	}
	return (0);
}
