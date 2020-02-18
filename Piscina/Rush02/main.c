/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pserrano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 11:27:55 by pserrano          #+#    #+#             */
/*   Updated: 2019/10/20 19:57:34 by pserrano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	(void)argv;
	(void)argc;
	char *dict = "numbers.dict";
	char buffer[ft_get_bytes_file(dict)];

	ft_open_dict(buffer, dict);
}
