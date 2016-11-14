
#ifndef que_H
#define que_H

template <typename T> class que {
public:

    T* queue;

    que() {
    };

    que(T* qu) {
        this->queue = qu;
    };

    virtual ~que() {
		detele[] queue;
    };

private:

};

#endif /* que_H */
