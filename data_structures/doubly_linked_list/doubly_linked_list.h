#pragma once

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
bool operator==(const DoublyLinkedList<T> &lhs,
                const DoublyLinkedList<T> &rhs) {}

template <typename T>
bool operator!=(const DoublyLinkedList<T> &lhs,
                const DoublyLinkedList<T> &rhs) {}
