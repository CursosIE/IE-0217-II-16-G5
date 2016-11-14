
#ifndef NODE_H
#define NODE_H

template <typename T> class Node {
public:

    T D;
	///Constructor de la clase nodo
    Node() {
    };
	///Constructor sobrecargado de la clase nodo
    Node(Node* l, Node* r, Node* p, T* d) {
        D = d;
    };
	///Destructor de la clase nodo
    virtual ~Node() {
    };

private:

};

#endif /* NODE_H */

