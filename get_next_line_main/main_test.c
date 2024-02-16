/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atedesch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 20:40:45 by atedesch          #+#    #+#             */
/*   Updated: 2024/02/16 21:00:14 by atedesch         ###   ########.fr       */
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

	fd = open("myfile.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Errore apertura file");
		return (1);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	if (close(fd) < 0)
	{
		perror("Errore chiusura file");
		return (1);
	}
	return (0);
}
