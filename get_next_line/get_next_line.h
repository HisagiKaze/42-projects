/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/04 12:16:42 by ppoinot           #+#    #+#             */
/*   Updated: 2016/03/18 16:48:39 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include "../libft/libft.h"

typedef	struct			s_gnl
{
	int					line;
	char				*sentence;
	int					fd;
}						t_gnl;

#endif
