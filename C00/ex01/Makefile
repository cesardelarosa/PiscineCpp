NAME     = phonebook
SRCS     = phonebook.cpp
OBJS     = $(SRCS:.cpp=.o)
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean all
