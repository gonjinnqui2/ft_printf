/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_isalnum.c									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: jirwin <jirwin@student.42.fr>			  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2019/09/16 17:26:19 by jirwin			#+#	#+#			 */
/*   Updated: 2019/09/16 17:47:38 by jirwin		   ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

int		ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
		(c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
