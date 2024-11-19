
NAME 		= form

CXX		= c++

CFLAGS		= -std=c++98

INCLUDES	=  Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp PresidentialPardonForm.hpp RobotomyRequestForm.hpp Intern.hpp

FILES		= main Bureaucrat AForm ShrubberyCreationForm PresidentialPardonForm RobotomyRequestForm Intern

SRCS		= $(addsuffix .cpp, $(FILES))

OBJS_DIRS	= .build

OBJS		= 	$(patsubst %.cpp, $(OBJS_DIRS)/%.o, $(SRCS))

all:	$(NAME)

$(NAME) : $(OBJS)
		$(CXX) $(OBJS) -o $@

$(OBJS_DIRS)/%.o: %.cpp $(INCLUDES)
		@mkdir -p $(OBJS_DIRS)
		$(CXX) $(CFLAGS) -o $@ -c $<

clean:
		rm -rf $(OBJS_DIRS)

fclean: clean
		rm -f $(NAME)

re : clean all

.PHONY: all clean fclean re makelib
