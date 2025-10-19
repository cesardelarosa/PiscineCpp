#pragma once

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain {

  public:
	Brain();
	Brain(const Brain &copy);
	~Brain();
	Brain &operator=(const Brain &rhs);

  private:
	static const size_t n_ideas = 100;
	std::string ideas[n_ideas];
};

#endif
