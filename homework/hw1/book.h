#include <iostream>
using namespace std;

class Book
{
private:
    string author, title, genre;
    int year;

public:
    Book()
    {
        author = "n/a";
        title = "n/a";
        genre = "n/a";
        year = 1900;
    }

    void setTitle(string t)
    {
        title = t;
    }
    void setAuthor(string a) { author = a; }
    void setGenre(string g) { genre = g; }
    void setYear(int y) { year = y; }

    string getTitle()
    {
        return title;
    }
    string getAuthor() { return author; }
    string getGenre() { return genre; }
    int getYear() { return year; }

    void print()
    {
        cout << "Genre: " << genre << "," << title << "," << author << "," << year << endl;
    }
};