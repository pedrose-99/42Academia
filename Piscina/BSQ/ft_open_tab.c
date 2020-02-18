/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:51:03 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/21 19:37:25 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_open_dict(char *buffer, char *lib)
{
	int fd;
	int i;
	int bytes_read;

	i = 0;
	bytes_read = 1;
	fd = open(lib, O_RDONLY);
	if (fd == 0)
	{
		write(1, "Dict Error\n", 11);
	}
	else if (ft_is_error(lib))
	{
		write(1, "Error\n", 11);
	}
	else
	{
		while (bytes_read)
			bytes_read = read(fd, &buffer[i++], 1);
		close(fd);
	}
}

int		ft_get_bytes_file(char *dict)
{
	int		total_bytes;
	int		byte_readed;
	int		fd;
	char	*c;

	total_bytes = 0;
	byte_readed = 1;
	fd = open(dict, O_RDONLY);
	while (byte_readed)
	{
		byte_readed = read(fd, &c, 1);
		total_bytes++;
	}
	close(fd);
	return (total_bytes);
}

int		check_file(char *file)
{
	return (close(open(file, O_RDONLY)));
}
