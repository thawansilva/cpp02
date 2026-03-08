NAME := canonical_class

# Source files and Objects
SRC := main.cpp Fixed.cpp
OBJS := $(SRC:%.cpp=%.o)

# Flags
C++ := c++
CFLAGS := -Wall -Wextra -Werror -std=c++98
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
