NAME = guess_who
COMPILER = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Base.cpp
HEADERS = Base.hpp A.hpp B.hpp C.hpp

OBJ = $(SRCS:.cpp=.o)

%.o : %.cpp ${HEADERS}
	$(COMPILER) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJ)
	$(COMPILER) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re