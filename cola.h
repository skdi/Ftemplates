#ifndef COLA_H
#define COLA_H


template<class T>
class cola
{
    public:
        cola();
        bool vacia();
        void encolar(T data);
        void descolar();


    private:
        struct Node{
            T dato;
            Node *next;
        };

        Node *sig;
        Node *ant;
        int contador;

};

#endif // COLA_H
