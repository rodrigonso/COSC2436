template <typename T>
struct node
{
    node<T> *next;
    T data;
};

template <typename T>
class stackll
{
private:
    node<T> *top;

public:
    stackll();
    void print();
    void pop();
    void push(T d);
    bool isEmpty();
    T peek();
};