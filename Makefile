MAIN=push_swap
MAIN_BONUS=checker
NAME=libft.a
BONUS_SRC=bonus/checker.c
CC=gcc
CCFLAGS= -Wall -Wextra -Werror
MAINSRC=srcs/main.c
PUSHSRC = srcs/utils.c
SRCS = ft_atoi.c \
       ft_bzero.c \
	ft_calloc.c \
       ft_itoa.c \
       ft_isalnum.c \
       ft_isalpha.c \
       ft_isascii.c \
       ft_isdigit.c \
       ft_isprint.c \
       ft_memchr.c \
       ft_memcmp.c \
       ft_memcpy.c \
       ft_memmove.c \
       ft_memset.c \
       ft_putchar_fd.c \
       ft_putendl_fd.c \
       ft_putnbr_fd.c \
       ft_putstr_fd.c \
       ft_split.c \
       ft_strchr.c \
       ft_strdup.c \
       ft_strjoin.c \
       ft_strlcat.c \
       ft_strlcpy.c \
       ft_strlen.c \
       ft_strmapi.c \
       ft_strncmp.c \
       ft_strnstr.c \
       ft_strrchr.c \
       ft_strtrim.c \
       ft_substr.c \
       ft_tolower.c \
       ft_toupper.c \
       ft_striteri.c \
       ft_lstsize.c \
       ft_lstnew.c \
       ft_strcmp.c \
       ft_lstadd_back.c \
       get_next_line.c \
       get_next_line_utils.c \
       parse_numbers.c \
       stack_operations.c \
       sort.c \
       utils.c \
       utils2.c \
       sort_big.c \
       pa_pb.c \
       ra_rb_rr.c \
       rra_rrb_rrr.c \
       sa_sb_ss.c \
       algo_500.c \
       main_utils.c \
       stack_operations2.c \

OBJS = srcs/libft/ft_atoi.o \
       srcs/libft/ft_bzero.o \
	srcs/libft/ft_calloc.o \
       srcs/libft/ft_itoa.o \
       srcs/libft/ft_isalnum.o \
       srcs/libft/ft_isalpha.o \
       srcs/libft/ft_isascii.o \
       srcs/libft/ft_isdigit.o \
       srcs/libft/ft_isprint.o \
       srcs/libft/ft_memchr.o \
       srcs/libft/ft_memcmp.o \
       srcs/libft/ft_memcpy.o \
       srcs/libft/ft_memmove.o \
       srcs/libft/ft_memset.o \
       srcs/libft/ft_putchar_fd.o \
       srcs/libft/ft_putendl_fd.o \
       srcs/libft/ft_putnbr_fd.o \
       srcs/libft/ft_putstr_fd.o \
       srcs/libft/ft_split.o \
       srcs/libft/ft_strchr.o \
       srcs/libft/ft_strdup.o \
       srcs/libft/ft_strjoin.o \
       srcs/libft/ft_strlcat.o \
       srcs/libft/ft_strlcpy.o \
       srcs/libft/ft_strlen.o \
       srcs/libft/ft_strmapi.o \
       srcs/libft/ft_strncmp.o \
       srcs/libft/ft_strnstr.o \
       srcs/libft/ft_strrchr.o \
       srcs/libft/ft_strtrim.o \
       srcs/libft/ft_substr.o \
       srcs/libft/ft_tolower.o \
       srcs/libft/ft_toupper.o \
       srcs/libft/ft_striteri.o \
       srcs/libft/get_next_line.o \
       srcs/libft/get_next_line_utils.o \
       srcs/libft/ft_strcmp.o \
       srcs/parse_numbers.o \
       srcs/stack_operations.o \
       srcs/sort.o \
       srcs/libft/ft_lstsize.o \
       srcs/libft/ft_lstnew.o \
       srcs/libft/ft_lstadd_back.o \
       srcs/libft/ft_lstnew.o \
       srcs/utils2.o \
       srcs/sort_big.o \
       srcs/instructions/pa_pb.o \
       srcs/instructions/ra_rb_rr.o \
       srcs/instructions/rra_rrb_rrr.o \
       srcs/instructions/sa_sb_ss.o \
       srcs/algo_500.o \
       srcs/main_utils.o \
       srcs/utils.o \
       srcs/stack_operations2.o \


RM = rm -rf

.c.o:	
			${CC} ${CCFLAGS} -c $<

all:		${MAIN}
              
$(MAIN):	${NAME}
			${CC} $(MAINSRC) $(NAME) ${PUSHSRC} -o $(MAIN)

$(NAME):	${OBJS}
			ar rcs ${NAME} ${SRCS:.c=.o}

bonus: 		${NAME}
			${CC} ${CCFLAGS} $(NAME) $(BONUS_SRC) -o $(MAIN_BONUS)

clean:
			${RM} ${SRCS:.c=.o} ${BONUS_OBJS}

fclean:		clean
			${RM} ${NAME} $(MAIN) ${MAIN_BONUS}

re:			fclean all