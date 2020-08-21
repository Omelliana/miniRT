/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bodysseu <bodysseu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 22:29:46 by bodysseu          #+#    #+#             */
/*   Updated: 2020/08/21 15:57:06 by bodysseu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		main(int argc, char *argv[])
{
	if ((argc == 1) || (argc > 3))
		error_exit("|Wrong count of arguments|");
	if (!ft_strstr(argv[1], ".rt"))
		error_exit("|Wrong file extension|");
	if (argc == 2)
		open_window(argv);
	else if (argc == 3 && (ft_strcmp(argv[2], "--save") == 0))
		save(argv);
	else
		error_exit("|Wrong argument|");
	return (0);
}
