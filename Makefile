##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## Makefile
##

NAME			=	MyGKrellm

CPPFLAGS		=	-std=c++20 -W -Wall -Wextra -Werror -I./include/

SRC_DIR			=	./src/

TEST_DIR		=	./tests/

MODULES_DIR		=	./src/Modules/

NCURSE_DIR		=	./src/Displayer/NCURSE/

SFML_DIR		=	./src/Displayer/SFML/

SRCS			=	$(SRC_DIR)main.cpp					\
					$(SRC_DIR)MyGKrellm.cpp 			\
					$(MODULES_DIR)OSKernel.cpp			\
					$(MODULES_DIR)DateTime.cpp			\
					$(MODULES_DIR)CPU.cpp				\
					$(MODULES_DIR)Hostname.cpp			\
					$(MODULES_DIR)RAM.cpp				\
					$(MODULES_DIR)Network.cpp			\
					$(NCURSE_DIR)NcurseDisplayer.cpp	\
					$(SFML_DIR)SFMLDisplay.cpp			\
					$(SFML_DIR)SFMLInit.cpp				\
					$(SFML_DIR)SFMLDisplayer.cpp		\

OBJS		=	$(SRCS:.cpp=.o)

VAL_TO		=	--track-origins=yes
VAL_SL		=	--show-leak-kinds=all
VAL_LC		=	--leak-check=full

all: $(NAME)
	@echo "Build ok!"

$(NAME): $(OBJS)
	g++ -o $(NAME) $(OBJS) $(CFLAGS) $(CPPFLAGS) -lncurses -lsfml-graphics -lsfml-window -lsfml-system

debug: CPPFLAGS += -g3
debug: $(NAME)
	@echo "Build debug ok!"

tests_run: $(NAME)
	$(MAKE) -C $(TEST_DIR)
	@echo "Build tests_run ok!"
	gcovr --html --html-details -o $(TEST_DIR)cov.html
	gcovr

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C $(TEST_DIR) -s
	@echo "Clean ok!"

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C $(TEST_DIR) -s
	@echo "Fclean ok!"

re: fclean all

.PHONY: all debug tests_run clean fclean re