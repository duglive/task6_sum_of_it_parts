// parts.h

#ifndef _PARTS_H_
#define _PARTS_H_

#include <vector>
#include <map>
#include <string>

using namespace std;

//**************** Part ****************
class Part 
{

public:
    typedef std::map<Part*, int> Sub;

public:
    string name;
    Sub subparts;
    Part(string const &n) : name(n) {};
    void describe(void);
    int count_howmany(Part const *p);
};

//**************** NameContainer ****************
class NameContainer  
{

private:
	typedef map<string,Part*> name_map;

private:
    name_map namemap;

public:
	NameContainer(void) {};
	~NameContainer(void);
	Part* lookup(string const &name);
};

extern void add_part(string const &x, int q, string const &y);
extern NameContainer partContainer; 

#endif
