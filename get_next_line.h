/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnextline.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlucille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 16:50:58 by tlucille          #+#    #+#             */
/*   Updated: 2019/05/15 16:22:56 by tlucille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFF_SIZE 1000000
#define	MAX_FD 4864

int				get_next_line(const int fd, char **line);

typedef struct	gnl_list
{
	char	*line;
	char	*rest;
	int		complet;
}				g_list;

#endif
