/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malena-b <mario3d93@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:37:45 by malena-b          #+#    #+#             */
/*   Updated: 2023/12/19 12:32:41 by malena-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*****************************************************************************/
/*                               CHECK CHARS                                 */
/*****************************************************************************/

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

/*****************************************************************************/
/*                                 STRINGS                                   */
/*****************************************************************************/

int		ft_atoi(const char *str);
char	*ft_strchr(const char	*s, int c);
size_t	ft_strlcat(char	*dst, const char	*src, size_t dstsize);
size_t	ft_strlcpy(char	*dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char	*s1, const char	*s2, size_t	n);
char	*ft_strnstr(const char	*haystack, const char	*needle, size_t len);
char	*ft_strrchr(const char	*s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strdup(const char *s1);
/**
 * @brief Utilizando malloc(3), genera una string que represente el 
 * valor entero recibido como argumento. Los números negativos tienen 
 * que gestionarse.
 * 
 * @param n 
 * @return char* 
 */
char	*ft_itoa(int n);
/**
 * @brief Reserva (utilizando malloc(3)) un array de strings resultante 
 * de separar la string ’s’ en substrings utilizando el caracter ’c’ como 
 * delimitador. El array debe terminar con un puntero NULL.
 * 
 * @param s 
 * @param c 
 * @return char** 
 */
char	**ft_split(char const *s, char c);
/**
 * @brief Reserva (con malloc(3)) y devuelve una substring de la string ’s’.
 * La substring empieza desde el índice ’start’ y tiene una 
 * longitud máxima ’len’.
 * 
 * @param s 
 * @param start 
 * @param len 
 * @return char* 
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief Reserva (con malloc(3)) y devuelve una nueva string, 
 * formada por la concatenación de ’s1’ y’s2’.
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief Elimina todos los caracteres de la string ’set’ desde
 *  el principio y desde el final de ’s1’, hasta encontrar un caracter
 *  no perteneciente a ’set’. La string resultante se devuelve con una 
 * reserva de malloc(3)
 * 
 * @param s1 
 * @param set 
 * @return char* 
 */
char	*ft_strtrim(char const *s1, char const *set);

/*****************************************************************************/
/*                                  MEMORY                                   */
/*****************************************************************************/

void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void	*s, int c, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);

/*****************************************************************************/
/*                                   PUTS                                    */
/*****************************************************************************/

/**
 * @brief Envía el carácter ’c’ al file descriptor especificado.
 * 
 * @param c 
 * @param fd 
 */
void	ft_putchar_fd(char c, int fd);
/**
 * @brief Envía la string ’s’ al file descriptor especificado.
 * 
 * @param s 
 * @param fd 
 */
void	ft_putstr_fd(char *s, int fd);
/**
 * @brief Envía la string ’s’ al file descriptor dado, seguido de un salto 
 * de línea.
 * 
 * @param s 
 * @param fd 
 */
void	ft_putendl_fd(char *s, int fd);
/**
 * @brief Envía el número ’n’ como string al file descriptor dado.
 * 
 * @param n 
 * @param fd 
 */
void	ft_putnbr_fd(int n, int fd);

/*****************************************************************************/
/*                              FT INPUT PARAM                               */
/*****************************************************************************/

/**
 * @brief A cada carácter de la string ’s’, aplica la función ’f’ dando como 
 * parámetros el índice de cada carácter dentro de ’s’ y la dirección del 
 * propio carácter, que podrá modificarse si es necesario.
 * 
 * @param s 
 * @param f 
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/**
 * @brief A cada carácter de la string ’s’, aplica la función ’f’ dando 
 * como parámetros el índice de cada carácter dentro de ’s’ y el propio 
 * carácter. Genera una nueva string con el resultado del uso sucesivo de ’f’
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*****************************************************************************/
/*                                   LIST                                    */
/*****************************************************************************/

/**
 * @brief Crea un nuevo nodo utilizando malloc(3). La variable miembro 
 * ’content’ se inicializa con el contenido del parámetro ’content’. 
 * La variable ’next’, con NULL.
 * 
 * @param content 
 * @return t_list* 
 */
t_list	*ft_lstnew(void *content);
/**
 * @brief Añade el nodo ’new’ al principio de la lista ’lst’.
 * 
 * @param lst 
 * @param new 
 */
void	ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief Cuenta el número de nodos de una lista.
 * 
 * @param lst 
 * @return int 
 */
int		ft_lstsize(t_list *lst);
/**
 * @brief Devuelve el último nodo de la lista.
 * 
 * @param lst 
 * @return t_list* 
 */
t_list	*ft_lstlast(t_list *lst);
/**
 * @brief Añade el nodo ’new’ al final de la lista ’lst’.
 * 
 * @param lst 
 * @param new 
 */
void	ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief Toma como parámetro un nodo ’lst’ y libera la memoria del 
 * contenido utilizando la función ’del’ dada como parámetro, además 
 * de liberar el nodo. La memoria de ’next’ no debe liberarse.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * @brief Elimina y libera el nodo ’lst’ dado y todos los consecutivos de 
 * ese nodo, utilizando la función ’del’ y free(3). Al final, el puntero a 
 * la lista debe ser NULL.
 * 
 * @param lst 
 * @param del 
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));
/**
 * @brief Itera la lista ’lst’ y aplica la función ’f’ en el 
 * contenido de cada nodo.
 * 
 * @param lst 
 * @param f 
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief Itera la lista ’lst’ y aplica la función ’f’ al contenido 
 * de cada nodo. Crea una lista resultante de la aplicación correcta 
 * y sucesiva de la función ’f’ sobre cada nodo. La función ’del’ se 
 * utiliza para eliminar el contenido de un nodo si falla la copia/modificación
 * de algún nodo, en cuyo caso se devuelve la nueva lista apuntando a NULL
 * liberando antes la memoria asignada hasta el momento.
 * 
 * @param lst 
 * @param f 
 * @param del 
 * @return t_list* 
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/*****************************************************************************/
/*                               GET_NEXT_LINE                               */
/*****************************************************************************/

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *pre_read, char *buffer, int bytes_readed);
int		ft_strlen_gnl(char *str);
char	*read_and_save(int fd, char *pre_read);
char	*clean_pre_read(char	*pre_read);
char	*get_new_line(char	*pre_read);
void	copy_read(char *pre_read, char *copy, int j, int len);

/*****************************************************************************/
/*                                 FT_PRINTF                                 */
/*****************************************************************************/

int		ft_printf(char const *str, ...);
int		ft_printchar(char c);
int		ft_printstr(char *str);
int		ft_printdecimal(int n);
int		ft_printunsint(unsigned int n);
int		ft_printhex(unsigned long i, char c);

#endif