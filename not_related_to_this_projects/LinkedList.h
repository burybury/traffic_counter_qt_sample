

/**
    Linkedlist container. Copies object by value.
**/

template <class T> class Node : public AllocableByNew
{
public:
    T data;
    Node* next;
    Node* prev;
    Node(T d) : data(d), next(nullptr), prev(nullptr)
    {}    
};

template <class T> class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;

public:

    LinkedList() : head(nullptr), tail(nullptr) {}

    class Iterator
    {
    public:

        Iterator(Node<T>* node) : node(node) {}

        int a;
        Node<T>* node;
        const T& operator*() const
        {
            return node->data;
        }
        Iterator operator++(int)
        {
            if (node)
            {
                node = node->next;
            }
            return Iterator(node);
        }
        Iterator operator++()
        {
            Node<T>* prev = node;
            if (node)
            {
                node = node->next;
            }
            return Iterator(prev);
        }
        bool operator==(const Iterator& other)
        {
            return node == other.node;
        }
        bool operator!=(const Iterator& other)
        {
            return node != other.node;
        }

    };

    Iterator begin()
    {
        return Iterator(head);
    }
    Iterator end()
    {
        return Iterator(nullptr);
    }

    void add(const T& data)
    {
        Node<T>* tmp = new Node<T>(data);
        if (!tail && !head)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tmp;
        }

    }

    void remove(T data){

        Node<T>* prev = nullptr;

        for (Iterator it = begin(); it != end(); it++)
        {
            Node<T>* current = it.node;
            if (current->data == data)
            {
                if (current == head)
                {
                    //first
                    head = head->next;
                }
                else
                {
                    if (current->next)
                    {
                        // middle
                        prev->next = current->next;
                    }
                    else
                    {
                        // last
                        prev->next = nullptr;
                        tail = prev;
                    }

                }
                delete current;
                break;

            }
            prev = current;
        }

    }
};

