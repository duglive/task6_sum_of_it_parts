#include <iostream>
using namespace std;
#include "parts.h"

void Part::describe()
{
    cout << "Part " << this -> name << " subparts are: " << endl;

    Sub::iterator i = subparts.begin();

    if (i != subparts.end())
    {
        for (i; i != subparts.end(); ++i)
        {
            cout << i -> second << " " << i->first -> name << endl;
        }
    }
    else
    {
        cout << "It has no subparts." << endl;
    }
}

int Part::count_howmany(Part const *p)
{
    if (this == p)
    {
        return 1;
    }

    int sum = 0;

    for (Sub::iterator i = subparts.begin(); i != subparts.end(); ++i)
    {
        sum += i -> second*i -> first -> count_howmany(p);
    }

    return sum;
}

Part* NameContainer::lookup(string const &name)
{
    name_map::iterator i = namemap.find(name);

    if (i != namemap.end())
    {
        return i -> second;
    }
    else
    {
        Part* part = new Part(name);
        namemap.insert(pair<string, Part*>(name, part));

        return part;
    }
}

void add_part(string const &x, int q, string const &y)
{
    Part* part = partContainer.lookup(x);
    Part* subPart = partContainer.lookup(y);
    part -> subparts.insert(pair<Part*, int>(subPart, q));
}