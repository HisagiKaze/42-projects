/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:00:42 by ppoinot           #+#    #+#             */
/*   Updated: 2016/12/05 16:57:30 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# include "./libft/libft.h"

typedef struct		s_gnl
{
	char		*string;
	char		*buffer;
	int			ret;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
