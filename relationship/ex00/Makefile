CXX			= clang++
NAME		= a.out
SRCS		= main.cpp Practice.cpp
CXXFLAGS	= -Wall -Wextra -Werror -pedantic -std=c++98
OBJS		= $(SRCS:.cpp=.o)
HPP			= Practice.hpp

%.o : %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(HPP)
	@echo "\033[0;33mLinking process in progress..."
	$(CXX) -o $(NAME) $(OBJS)
	@echo "\033[0;32m-------------------------------------"
	@echo "\033[0;32m|Compilation and linking successful!|"
	@echo "\033[0;32m-------------------------------------"

clean:
	rm -f $(OBJS)
	@echo "\033[0;33mObject files removed successfully."

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re