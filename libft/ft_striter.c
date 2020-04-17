/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_striter.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jirwin <jirwin@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/17 12:21:41 by jirwin			#+#	#+#			 */
/*   Updated: 2019/09/19 12:46:27 by jirwin		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s)
			f(s++);
}
