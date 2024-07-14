#-*-Makefile-*-

CC = cc
CFLAGS =  -g -Wall -Wextra -Werror -pthread -fsanitize=thread #-fsanitize=address 

SRCM = philo.c parse_init.c run_philos.c phils_funcs.c phils_funcs2.c monitors_funcs.c setters.c getters.c utils.c \

OBJM = $(SRCM:%.c=%.o)

SRCB = 

OBJB = $(SRCB:%.c=%.o)

#binaries :
NAME = philo
BONUS = 
HEADER_MAN = philo.h
HEADER_BON = 

all: $(NAME) $(BONUS)
man: $(NAME)
bonus: $(BONUS)

#Build mandatory part :
$(NAME): $(OBJM)
	cc $(CFLAGS) $^ -o $@ 
# Compile object files for mandatory part :
$(OBJM):%.o:%.c $(HEADER_MAN)
	$(CC) $(CFLAGS) -c $< -o $@

#Build bonus part :
$(BONUS): $(OBJB)
	cc $(CFLAGS) $^ -o $@
# Compile object files for bonus part :
$(OBJB):%.o:%.c $(HEADER_BON)
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f $(OBJM) $(OBJB)
fclean: clean
	rm -f $(NAME) $(BONUS)
re: fclean all 
