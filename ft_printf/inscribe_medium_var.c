/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inscribe_medium_var.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppoinot <ppoinot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:07:00 by ppoinot           #+#    #+#             */
/*   Updated: 2017/01/17 18:04:04 by ppoinot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*printf_precision(t_flags *flag, int x)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(flag->precision - x);
	str = ft_memset(str, 48, flag->precision - x);
	return (str);
}

void		inscribe_o_var(va_list *aprtf, t_info *list, t_flags *flag)
{
	unsigned int		cur_arg;
	int 				x;
	int					y;
	int					z;
	char				*cur_arg_string;

	cur_arg = va_arg(*aprtf, unsigned int);
	x = cur_arg / 64;
	y = cur_arg % 64;
	z = y % 8;
	y = y / 8;
	z = z / 1;
	cur_arg_string = ft_itoa(x * 100 + y * 10 + z * 1);
	if ((x = ft_strlen(cur_arg_string)) <= flag->precision)
		cur_arg_string = ft_strjoin(printf_precision(flag, x), cur_arg_string);
	cur_arg_string = add_wof_to_cur_arg_string(cur_arg_string, flag);
	x = ft_strlen(cur_arg_string);
	y = 0;
	list->converted_string = ft_realloc(list->converted_string, 
				ft_strlen(list->converted_string) + ft_strlen(cur_arg_string));
	while (y < (int)ft_strlen(cur_arg_string))
		list->converted_string[list->nb_c_written++] = cur_arg_string[y++];
	ft_strdel(&cur_arg_string);
	return ;
}

void	inscribe_u_var(va_list *aprtf, t_info *list, t_flags *flag)
{
	unsigned int		cur_arg_int;
	char				*cur_arg_string;
	int 				i;
	int 				y;

	cur_arg_int = va_arg(*aprtf, unsigned int);
	cur_arg_string = ft_uitoa(cur_arg_int);
	if ((i = ft_strlen(cur_arg_string)) <= flag->precision)
		cur_arg_string = ft_strjoin(printf_precision(flag, i), cur_arg_string);
	cur_arg_string = add_wof_to_cur_arg_string(cur_arg_string, flag);
	y = 0;
	i = ft_strlen(cur_arg_string);
	list->converted_string = ft_realloc(list->converted_string, 
				ft_strlen(list->converted_string) + i);
	while (y < i)
		list->converted_string[list->nb_c_written++] = cur_arg_string[y++];
	return ;
}

void	inscribe_x_var(va_list *aprtf, t_info *list, t_flags *flag)
{
	unsigned int 		cur_arg_int;
	char				*cur_arg_string;
	int 				i;
	int 				y;

	cur_arg_int = va_arg(*aprtf, unsigned int);
	cur_arg_string = ft_uitoh(cur_arg_int);
	if ((i = ft_strlen(cur_arg_string)) <= flag->precision)
		cur_arg_string = ft_strjoin(printf_precision(flag, i), cur_arg_string);
	y = 0;
	i = ft_strlen(cur_arg_string);
	list->converted_string = ft_realloc(list->converted_string, 
				ft_strlen(list->converted_string) + i);
	while (y < i)
		list->converted_string[list->nb_c_written++] = cur_arg_string[y++];
	return ;
}

void	inscribe_X_var(va_list *aprtf, t_info *list, t_flags *flag)
{
	unsigned int 		cur_arg_int;
	char				*cur_arg_string;
	int 				i;
	int 				y;

	cur_arg_int = va_arg(*aprtf, unsigned int);
	cur_arg_string = ft_uitoh(cur_arg_int);
	if ((i = ft_strlen(cur_arg_string)) <= flag->precision)
		cur_arg_string = ft_strjoin(printf_precision(flag, i), cur_arg_string);
	y = 0;
	while (cur_arg_string[y])
	{
		cur_arg_string[y] = ft_toupper(cur_arg_string[y]);
		y++;
	}
	y = 0;
	i = ft_strlen(cur_arg_string);
	list->converted_string = ft_realloc(list->converted_string, 
				ft_strlen(list->converted_string) + i);
	while (y < i)
		list->converted_string[list->nb_c_written++] = cur_arg_string[y++];
	return ;
}