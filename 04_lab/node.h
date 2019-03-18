#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {
   private:
    T value;
    Node* next;
   public:
    Node(T _value) : T(_value), next(nullptr);
    Node(T _value, const Node& _next) : T(_value), next(_next);
    ~Node();
    Node(const Node& other) : T(other.value), next(nullptr);
};

#endif