#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

int		ft_printf(char const *str, ...);

/* format functions */
void	ft_print_char(char c, size_t *counter);
void	ft_print_str(char *str, size_t *counter);
void	ft_print_nbr(int num, size_t *counter);
void	ft_print_uint(unsigned int num, size_t *counter);
void	ft_print_hex(unsigned int num, size_t *counter, char *base);
void	ft_print_ptr(void *ptr, size_t *counter);

/* auxiliary functions */
char	*ft_aux(unsigned long long num, char *base);

#endif