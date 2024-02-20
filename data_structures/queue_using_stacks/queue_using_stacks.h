#include "stackDLL.h"
#include <stdexcept>

template <typename T>
class QueueUsingStacks
{
public:
    QueueUsingStacks() = default;
    QueueUsingStacks(const QueueUsingStacks &other);
    QueueUsingStacks &operator=(const QueueUsingStacks &other);

    void enqueue(const T &item);
    T dequeue();
    bool empty() const;

private:
    StackDLL<T> inbox;
    StackDLL<T> outbox;
};

template <typename T>
inline QueueUsingStacks<T>::QueueUsingStacks(const QueueUsingStacks &other)
{
    this->inbox = other.inbox;
    this->outbox = other.outbox;
}

template <typename T>
inline QueueUsingStacks<T> &QueueUsingStacks<T>::operator=(const QueueUsingStacks &other)
{
    if (this != &other)
    {
        inbox = this->inbox;
        outbox = this->outbox;
    }
}

template <typename T>
inline void QueueUsingStacks<T>::enqueue(const T &item)
{
    inbox.push(item);
}

template <typename T>
inline T QueueUsingStacks<T>::dequeue()
{
    if (outbox.empty())
    {
        while (!inbox.empty())
        {
            outbox.push(inbox.top());
            inbox.pop();
        }
    }

    T frontElement = outbox.top();
    outbox.pop();
    return frontElement;
}

template <typename T>
inline bool QueueUsingStacks<T>::empty() const
{
    return inbox.empty() && outbox.empty();
}
