#pragma once

#include <stdexcept>

template <typename T>
struct Node
{
    Node *previous;
    T data;
    Node *next;

    Node(const T &d, Node *p = nullptr, Node *n = nullptr)
        : data{d}, previous{p}, next{n} {}
};

template <typename T>
class DoublyLinkedListIterator;

template <typename T>
class DoublyLinkedList
{
public:
    DoublyLinkedList() = default;
    DoublyLinkedList(const DoublyLinkedList &);
    DoublyLinkedList &operator=(const DoublyLinkedList &);
    ~DoublyLinkedList();

    /**
     * Appends the given value to the end of the container.
     * O(1) time complexity
     */
    void push_back(const T &value);

    /**
     * O(1) time complexity
     * @throw std::runtime_error
     */
    void pop_back();

    void push_front(const T &value);

    void pop_front();

    /**
     * return interator
     */
    DoublyLinkedListIterator<T> begin() noexcept;
    DoublyLinkedListIterator<T> end() noexcept;

    /**
     * Insert value before pos.
     * @return Iterator pointing to the inserted value
     */
    DoublyLinkedListIterator<T> insert(DoublyLinkedListIterator<T> pos, const T &value);

    /**
     * Removes the elemnt at pos
     */
    DoublyLinkedListIterator<T> erase(DoublyLinkedListIterator<T> pos);

    T &front();
    const T &front() const;

    T &back();
    const T &back() const;

    size_t size() const noexcept;

    bool empty() const noexcept;

    void clear();

private:
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;
    size_t currentSize = 0;
};

template <typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
    while (head)
    {
        Node<T> *nextHead = head->next;
        delete head;
        head = nextHead;
    }
}

template <typename T>
inline void DoublyLinkedList<T>::push_back(const T &value)
{
    Node<T> *node = new Node{value};
    ++currentSize;

    // if empty
    if (!head)
    {
        head = tail = node;
        return;
    }

    tail->next = node;
    node->previous = tail;
    tail = node;
}

template <typename T>
inline void DoublyLinkedList<T>::pop_back()
{
    if (empty())
    {
        throw std::runtime_error{"Calling pop_back() on an empty list."};
    }

    --currentSize;

    if (currentSize == 0)
    {
        delete tail;
        head = tail = nullptr;
    }
    else
    {
        tail = tail->previous;
        delete tail->next;
        tail->next = nullptr;
    }
}

template <typename T>
inline void DoublyLinkedList<T>::push_front(const T &value)
{
    Node<T> *node = new Node{value};
    ++currentSize;

    if (!head)
    {
        head = tail = node;
        return;
    }

    head->previous = node;
    node->next = head;
    head = node;
}

template <typename T>
inline void DoublyLinkedList<T>::pop_front()
{
    if (empty())
    {
        throw std::runtime_error{"Calling pop_front() on an empty list"};
    }

    --currentSize;

    if (currentSize == 0)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        head = head->next;
        delete head->previous;
        head->previous = nullptr;
    }
}

template <typename T>
inline T &DoublyLinkedList<T>::front()
{
    return head->data;
}

template <typename T>
inline const T &DoublyLinkedList<T>::front() const
{
    return head->data;
}

template <typename T>
inline T &DoublyLinkedList<T>::back()
{
    return tail->data;
}

template <typename T>
inline const T &DoublyLinkedList<T>::back() const
{
    return tail->data();
}

template <typename T>
inline size_t DoublyLinkedList<T>::size() const noexcept
{
    return currentSize;
}

template <typename T>
inline bool DoublyLinkedList<T>::empty() const noexcept
{
    return !head;
}

template <typename T>
inline void DoublyLinkedList<T>::clear()
{
    while (!empty())
    {
        pop_back();
    }
}

template <typename T>
bool operator==(const DoublyLinkedList<T> &lhs,
                const DoublyLinkedList<T> &rhs) {}

template <typename T>
bool operator!=(const DoublyLinkedList<T> &lhs,
                const DoublyLinkedList<T> &rhs) {}
