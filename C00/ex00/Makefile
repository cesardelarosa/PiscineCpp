NAME     = megaphone

SRCDIR   = src
OBJDIR   = obj

SRCS     = megaphone.cpp

OBJS     = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))

CXX      = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re