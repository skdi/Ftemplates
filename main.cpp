#include <iostream>

using namespace std;


template<typename T>
const T& minimo (const T &a,const T &b){
    if(a<b)
        return a;
    else
        return b;
}


template <class T>
const T& operator<(const T &a,const T &b){
  return (a>b)?a:b;
}


int main()
{
    //parte 2
    int a=5;
    int b=6;
    char c='g';
    char d='f';
    cout<<minimo<int>(a,b)<<endl;
    cout<< (a<b) <<endl;
    printf("%c \n",c<d);

    // parte 3

    /* rectangle *rect;
     triangle(*rect);*/

    /*
    if (type_info(a)==triangle)
        return triangle *a;
    else if(type_info(a)==rectangle)
            return rectangle *a;
    else
        return NULL;
    */



}


