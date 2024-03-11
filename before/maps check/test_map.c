/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwiemann <hwiemann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 11:30:44 by hwiemann          #+#    #+#             */
/*   Updated: 2023/09/06 11:45:53 by hwiemann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//einbinden von map ueber get next line
// checken ob map valide mit .ber

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && 0 < n)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			break ;
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_bermap()
{
	ft_strncmp(".ber", )
}


