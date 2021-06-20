struct Node
{
    int key;      // number
    string value; // value
    Node *next;   // pointer to remember memory address of next node

    Node() : key(0), value(""), next(0){};
    Node(int Key, string Value) : key(Key), value(Value), next(0){};
    Node(Node const &data) : key(data.key), value(data.value), next(data.next){};
};

class HashTable
{
private:
    int size,     // size: size of table, count: number of data
        count;    // count/size = load factor
    Node **table; // pointer to pointer, hash table

    int hashFunction(int key); // Multiplication method
    void tableDoubling();
    void tableShrinking();
    void reHashing(int size_orig);

public:
    HashTable(){};
    HashTable(int m) : size(m), count(0)
    {
        table = new Node *[size]; // allocate the first demension of table
        for (int i = 0; i < size; i++)
            table[i] = 0; // ensure every slot points to NULL
    }
    ~HashTable();

    void Insert(Node data); // consider tableDoubling()
    void Delete(int key);   // consider tableShrinking()
    string Search(int key);
    void displayTable();
};

