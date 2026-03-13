NAME := bsp

# Source files and Objects
SRC := main.cpp Fixed.cpp Point.cpp bsp.cpp
OBJS := $(SRC:%.cpp=%.o)

# Flags
C++ := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98 -g2 -O0
CPPFLAGS := $(addprefix -I, .)

all: $(NAME) 

$(NAME): $(OBJS)
	$(C++) $(OBJS) -o $@

%.o: %.cpp
	$(C++) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
