##
## EPITECH PROJECT, 2023
## MAKEFILE
## File description:
## Makefile
##

NAME		=	unit_tests

CPPFLAGS	=	-W -Wall -Wextra -Werror -I ../include/

LDFLAGS		=	--coverage -lcriterion

SRC_DIR		=	../src/

MODULES_DIR	=	../src/Modules/

SRC_TESTS	=	$(MODULES_DIR)CPU.cpp		\
				$(MODULES_DIR)DateTime.cpp	\
				$(MODULES_DIR)OSKernel.cpp	\
				$(MODULES_DIR)RAM.cpp		\
				$(MODULES_DIR)Network.cpp	\

UT_FILES	=	TestsCPU.cpp				\
				TestsDateTime.cpp			\
				TestsOSKernel.cpp			\
				TestsRAM.cpp				\
				TestsNetwork.cpp			\

SRC_OBJS	=	$(SRC_TESTS:.c=.o)

UT_OBJS		=	$(UT_FILES:.c=.o)

all: $(NAME)
	@echo "Build ok!"

$(NAME) :
	g++ -c $(SRC_TESTS) $(CFLAGS) $(CPPFLAGS) $(LFLAGS) $(LDFLAGS)
	g++ -c $(UT_FILES) $(CFLAGS) $(CPPFLAGS) $(LFLAGS)
	g++ -o $(NAME) *.o $(CFLAGS) $(CPPFLAGS) $(LFLAGS) -lcriterion -lgcov
	./$(NAME)


clean:
	$(RM) *.html
	$(RM) *.css
	$(RM) $(SRC_DIR)*.gcno
	$(RM) $(SRC_DIR)*.gcda
	$(RM) $(TEST_DIR)*.gcda
	$(RM) $(TEST_DIR)*.gcno
	$(RM) $(TEST_DIR)*.o
	$(RM) $(TESTS_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
