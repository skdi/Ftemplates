#ifndef PILA_H
#define PILA_H

template <class T>
class pila{

private:
    int size,top;
    T *ps;
public:
    pila(int tamano);
    void push(T valor);
    T pop();
    bool lleno();
    bool vacio();

};

#endif // PILA_H

/*main(){
  pila<int> s(3);
  s.push(1)
  cout<<s.pop<<endl;*/
