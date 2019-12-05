/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:10:14 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/05 20:35:51 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FLAGS_H
# define LS_FLAGS_H

# define FLAGS_USAGE "usage: ft_ls [-GRSTafglrtu1] [file ...]"

# define BIT_1_ONE        (1 << 0)
# define BIT_A_HIDDEN     (1 << 1)
# define BIT_F_NO_SORT    (1 << 2)
# define BIT_G_COLOR      (1 << 3)
# define BIT_G_NO_OWNER   (1 << 4)
# define BIT_L_LIST       (1 << 5)
# define BIT_R_RECURSIVE  (1 << 6)
# define BIT_R_SORT_REV   (1 << 7)
# define BIT_S_SORT_SIZE  (1 << 8)
# define BIT_T_FULL_TIME  (1 << 9)
# define BIT_T_SORT_TIME  (1 << 10)
# define BIT_U_ACCESS     (1 << 11)

# define BIT_NO_TOTAL     (1 << 31)

# define F_ONE        '1'
# define F_HIDDEN     'a'
# define F_NO_SORTED  'f'
# define F_COLOR      'G'
# define F_NO_OWNER   'g'
# define F_LIST       'l'
# define F_RECURSIVE  'R'
# define F_REVERSE    'r'
# define F_SIZE       'S'
# define F_FULL_TIME  'T'
# define F_TIME       't'
# define F_ACCESS     'u'

#endif
