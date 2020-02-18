/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amunoz-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:50:34 by amunoz-g          #+#    #+#             */
/*   Updated: 2019/10/20 17:32:51 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isspace(char str)
{
	return (str == '\t' || str == '\v' || str == '\f' || str == '\r' ||
			str == ' ') ? (1) : (0);
}

int		ft_is_error(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		if (ft_is_num(c[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

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
