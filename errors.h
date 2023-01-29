#ifndef ERRORS_H
#define ERRORS_H

# include "fdf.h"

# define	ARGC_ERR		"ERROR, here an example : ./fdf test_maps/42.fdf"
# define 	MALLOC_ERR		"allocation failed "
# define	PERROR			"PERROR"
# define 	MLX_INIT_ERR	"ERROR in 'MLX' lib initialization "
# define 	MLX_WIN_ERR		"ERROR in 'MLX' window creation "
# define 	MLX_IMG_ERR		"ERROR in 'MLX' image creation "
# define 	MLX_DATA_ERR	"ERROR in 'MLX' add data "
# define 	MAP_ERR			"Error parsing : X coordinates are not homogeneous"
#endif //FDF_ERRORS_H
