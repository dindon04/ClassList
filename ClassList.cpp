#include <iostream>

template<typename T>

class List
{
private:

    struct Node
    {
        T element;
        Node* prev = nullptr;
        Node* next = nullptr;

    };

    Node* first = nullptr;
    Node* last = nullptr;

    int elementsCount = 0;

public:

    List() = default;

    List(const List<T>& newList)
    {
        elementsCount = newList.elementsCount;

        for (Node* node = newList.first; node != nullptr; node = node->next)
        {
            PushBack(node->element);
        }

    }


    List& operator= (const List& newList)
    {
        clear();

        Node* node;

        for (node = newList.first; node != nullptr; node = node->next)
        {
            PushBack(node->element);
        }

        return *this;
    }


    void PushBack(const T& element)
    {
        Node* node = new Node(element, last, nullptr);

        if (last != nullptr)
        {
            last->next = node;
        }
        else
        {
            first = node;
        }

        last = node;
        ++elementsCount;
    }


    void PushFront(const T& element)
    {
        Node* node = new Node(element, first, nullptr);

        if (first != nullptr)
        {
            first->prev = node;
        }
        else
        {
            last = node;
        }

        first = node;
        ++elementsCount;
    }


    void PopBack()
    {
        if (elementsCount == 1)
        {
            delete last;
            last = first = nullptr;
        }
        else
        {
            Node* element = last->prev;

            delete last;

            last = element;
            last->next = nullptr;
        }

        elementsCount--;
    }

    void PopFront()
    {
        if (elementsCount == 1)
        {
            delete first;
            first = last = nullptr;
        }
        else
        {
            Node* element = first->next;

            delete first;

            first = element;
            first->prev = nullptr;
        }

        elementsCount--;
    }


    size_t Size() const
    {
        return elementsCount;
    }


    const T& Front() const
    {
        return first->element;
    }


    bool Empty() const
    {
        return first == nullptr;
    }

    ~List()
    {
        clear();
    }


    void clear()
    {
        Node* element = first;

        while (element != nullptr)
        {
            Node* next = element->next;
            delete element;
            element = next;
        }

        first = nullptr;
        last = nullptr;
        elementsCount = 0;
    }


    void PrintList() const
    {
        Node* element = first;

        while (element)
        {
            std::cout << element->element << " ";

            element = element->next;
        }

        std::cout << std::endl;
    }
};



int main()
{
    List<int> myList;
    myList.PushBack(1);
    myList.PushBack(2);
    myList.PushBack(3);
    myList.PushBack(4);
    myList.PushBack(5);
    myList.PrintList();
    std::cout << "my list size = " << myList.Size() << std::endl << std::endl;

    std::cout << "PopBack()" << std::endl;
    myList.PopBack();
    myList.PrintList();
    std::cout << "my list size = " << myList.Size() << std::endl << std::endl;

    std::cout << "PopFront()" << std::endl;
    myList.PopFront();
    myList.PrintList();
    std::cout << "my list size = " << myList.Size() << std::endl << std::endl;

    std::cout << "Clear()" << std::endl;
    myList.clear();
    myList.PrintList();
    std::cout << "my list size = " << myList.Size() << std::endl << std::endl;
}