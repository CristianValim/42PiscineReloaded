/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvalim-d <cvalim-d@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 17:43:48 by cvalim-d          #+#    #+#             */
/*   Updated: 2024/10/24 17:47:13 by cvalim-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

void	error_message(const char *message, int length)
{
	write(2, message, length);
}

int	open_file(char *filename)
{
	return (open(filename, O_RDONLY));
}

void	read_and_display(int fd)
{
	char	buffer[BUFFER_SIZE];
	ssize_t	bytes_read;

	while (1)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		write(1, buffer, bytes_read);
	}
}

int	main(int argc, char *argv[])
{
	int	fd;

	if (argc < 2)
		error_message("File name missing.\n", 19);
	else if (argc > 2)
		error_message("Too many arguments.\n", 20);
	else
	{
		fd = open_file(argv[1]);
		if (fd == -1)
			error_message("Cannot read file.\n", 18);
		else
		{
			read_and_display(fd);
			close(fd);
		}
	}
	return (0);
}
