#include <vector>
#include "book.h"

class Library
{
private:
    vector<Book> data;

public:
    void insert(Book b)
    {
        data.push_back(b);
    }

    int getSize() { return data.size(); }

    Book getAt(int idx)
    {
        return data.at(idx);
    }

    vector<Book> getData()
    {
        return data;
    }

    vector<Book> find(string key, string val)
    {
        vector<Book> res;
        for (int i = 0; i < data.size(); i++)
        {
            Book curr = data.at(i);
            if (key == "genre")
            {
                if (curr.getGenre() == val)
                {
                    res.push_back(curr);
                    continue;
                }
            }
        }
        return res;
    }

    void print()
    {
        for (int i = 0; i < data.size(); i++)
        {
            data.at(i).print();
        }
    }
};