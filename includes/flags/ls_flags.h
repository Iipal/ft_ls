/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flags.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 19:10:14 by tmaluh            #+#    #+#             */
/*   Updated: 2020/01/25 19:23:19 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_FLAGS_H
# define LS_FLAGS_H

# define FLAGS_USAGE "usage: ft_ls [-GRSTafglrtu1] [file ...]"

# define F_MAX_QTY        12

# define F_ONE            '1'
# define BIT_1_ONE        (1 << 0)

# define F_HIDDEN         'a'
# define BIT_A_HIDDEN     (1 << 1)

# define F_NO_SORT        'f'
# define BIT_F_NO_SORT    (1 << 2)

# define F_COLOR          'G'
# define BIT_G_COLOR      (1 << 3)

# define F_NO_OWNER       'g'
# define BIT_G_NO_OWNER   (1 << 4)

# define F_LIST           'l'
# define BIT_L_LIST       (1 << 5)

# define F_RECURSIVE      'R'
# define BIT_R_RECURSIVE  (1 << 6)

# define F_REVERSE        'r'
# define BIT_R_SORT_REV   (1 << 7)

# define F_SORT_SIZE      'S'
# define BIT_S_SORT_SIZE  (1 << 8)

# define F_FULL_TIME      'T'
# define BIT_T_FULL_TIME  (1 << 9)

# define F_SORT_TIME      't'
# define BIT_T_SORT_TIME  (1 << 10)

# define F_ACCESS         'u'
# define BIT_U_ACCESS     (1 << 11)

# define BIT_NO_TOTAL     (1 << 31)

#endif
