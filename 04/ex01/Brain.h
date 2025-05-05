#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain
{
private:
	std::string ideas[100];

public:
	Brain();
	Brain(const Brain &copy);
	virtual ~Brain();

	Brain &operator=(const Brain &src);

	const std::string get_idea(int i)const;
	const std::string *get_idea_adr(int i)const;
	void set_idea(int i, std::string idea);
};

#endif