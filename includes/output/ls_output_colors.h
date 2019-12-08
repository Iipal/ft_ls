/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_output_colors.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmaluh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 17:16:00 by tmaluh            #+#    #+#             */
/*   Updated: 2019/12/08 15:45:59 by tmaluh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_OUTPUT_COLORS_H
# define LS_OUTPUT_COLORS_H

# include "libftprintf_colors.h"

# define LS_CLR_DEFAULT PF_FG_CLR_DEFAULT PF_BG_CLR_DEFAULT

# define LS_CLR_DIR     PF_FG_CLR_LCYAN
# define LS_CLR_CHR     PF_BG_CLR_YELLOW PF_FG_CLR_LBLACK
# define LS_CLR_BLK     PF_BG_CLR_CYAN PF_FG_CLR_LBLACK
# define LS_CLR_LNK     PF_FG_CLR_MAGENTA
# define LS_CLR_EXE     PF_FG_CLR_RED
# define LS_CLR_SOCK    PF_FG_CLR_GREEN

# include "libftprintf_colors_end.h"

#endif
