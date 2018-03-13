/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_xml_read_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cpierre <cpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/13 20:04:26 by cpierre           #+#    #+#             */
/*   Updated: 2018/03/13 20:06:38 by cpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_obj_t	ft_read_obj_type(t_str str)
{
	if (str == NULL || ft_strlen(str) < 1)
		ft_exit("err parser");
	ft_strupcase(str);
	if (ft_is_any_string(str, 2, "CONE", "CON"))
		return (CONE);
	else if (ft_is_any_string(str, 3, "CYLINDER", "CYLINDRE", "CYL"))
		return (CYLINDER);
	else if (ft_is_any_string(str, 3, "PLANE", "PLAN", "PLA"))
		return (PLANE);
	else if (ft_is_any_string(str, 2, "DISC", "DISK", "DIS"))
		return (DISK);
	else if (ft_is_any_string(str, 2, "TRIANGLE", "TRI"))
		return (TRIANGLE);
	else if (ft_is_any_string(str, 2, "PARABOLOID", "PARA"))
		return (PARABOLOID);
	else if (ft_is_any_string(str, 2, "HYPERBOLOID", "HYP"))
		return (HYPERBOLOID);
	else
		return (SPHERE);
}

t_obj_t	ft_read_obj_textype_material(t_str str)
{
	if (str == NULL || ft_strlen(str) < 1)
		ft_exit("err parser");
	ft_strupcase(str);
	if (ft_is_any_string(str, 2, "DEFAULT", "DEF"))
		return (DEFAULT);
	else if (ft_is_any_string(str, 1, "CHESS"))
		return (CHESS);
	else if (ft_is_any_string(str, 1, "PERLIN"))
		return (PERLIN);
	else if (ft_is_any_string(str, 1, "MARBLE"))
		return (MARBLE);
	else if (ft_is_any_string(str, 2, "REFLECTIVE", "REFL"))
		return (REFLECTIVE);
	else if (ft_is_any_string(str, 2, "REFRACTIVE", "REFR"))
		return (REFRAFLECTIVE);
	else
		return (DEFAULT);
}
