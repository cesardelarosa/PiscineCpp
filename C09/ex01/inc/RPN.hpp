#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>

class RPN {
  public:
	RPN();
	RPN(const RPN &src);
	RPN &operator=(const RPN &rhs);
	~RPN();

	void calculate(const std::string &expression);

  private:
	std::stack<int> _stack;

	bool isOperator(char c) const;
	void performOperation(char op);
};

#endif
