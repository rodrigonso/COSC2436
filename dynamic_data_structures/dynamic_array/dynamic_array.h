class DynamicArray
{
private:
    int size;
    int count;
    int *data;

public:
    DynamicArray(int s = 10);
    ~DynamicArray();
    void push(int item);
    void pop();

    int length();
    void print();
};