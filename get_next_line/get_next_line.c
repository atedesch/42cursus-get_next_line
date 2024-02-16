/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atedesch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:17:17 by atedesch          #+#    #+#             */
/*   Updated: 2024/02/16 21:08:19 by atedesch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *input, char *input2)
{
	char	*temp;

	temp = ft_strjoin(input, input2);
	free(input);
	return (temp);
}

char	*ft_next(char *input)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (input[i] && input[i] != '\n')
		i++;
	if (!input[i])
	{
		free(input);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(input) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (input[i])
		line[j++] = input[i++];
	free(input);
	return (line);
}

char	*ft_line(char *input)
{
	char	*line;
	int		i;

	i = 0;
	if (!input[i])
		return (NULL);
	while (input[i] && input[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (input[i] && input[i] != '\n')
	{
		line[i] = input[i];
		i++;
	}
	if (input[i] && input[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_file(int fd, char *res)
{
	char	*buffer;
	int		byte_read;

	if (!res)
		res = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	byte_read = 1;
	while (byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[byte_read] = 0;
		res = ft_free(res, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_next(buffer);
	return (line);
}
