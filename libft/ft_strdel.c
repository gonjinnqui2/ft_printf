/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_strdel.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jirwin <jirwin@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/16 19:12:29 by jirwin			#+#	#+#			 */
/*   Updated: 2019/09/17 12:10:37 by jirwin		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}
