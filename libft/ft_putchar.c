/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putchar.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jirwin <jirwin@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/17 14:38:52 by jirwin			#+#	#+#			 */
/*   Updated: 2019/09/17 14:38:56 by jirwin		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
