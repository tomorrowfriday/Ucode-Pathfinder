NAME  =     pathfinder.a
CFLG  =     -std=c11 -Wall -Wextra -Werror -Wpedantic -g
COMP  =     clang
SRCD  =     src
INCD  =     inc
OBJD  =     obj
INC   =     pathfinder.h
SRC   =     main.c
INCS  =     $(addprefix $(INCD)/, $(INC))
SRCS  =     $(addprefix $(SRCD)/, $(SRC))
OBJS  =     $(addprefix $(OBJD)/, $(SRC:%.c=%.o))
all: install clean
install: $(NAME)
	@cd ./libmx && make

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@printf "\r\33[2K$@\t   \033[32;1mcreated\033[0m\n"
$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@$(COMP) $(CFLG) -c $< -o $@ -I$(INCD)
	@printf "\r\33[2K$(NAME)\t   \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%) "
$(OBJS): | $(OBJD)
$(OBJD):
	@mkdir -p $@
clean:
	@rm -rf $(OBJD)
	@printf "$(OBJD)\t   \033[31;1mdeleted\033[0m\n"
uninstall: clean
	@rm -rf $(NAME)
	@printf "$(NAME)\t   \033[31;1muninstalled\033[0m\n"
reinstall: uninstall install
start: 
	clang -std=c11 -Wall -Wextra -Werror -Wpedantic main.c pathfinder.a && ./a.out