#ifndef SINGLETON_H
#define SINGLETON_H

#include <cassert>
#include <iostream>

template <typename Type>
class Singleton
{
    static Type* Instance; //clase protected, raw pointer??

public:
    Singleton()
    {
        //si el ptr es nulo, no se ha creado el singleton
        assert(Instance == nullptr);
        Instance = static_cast<Type*>(this); //keep calm!!
        std::cout<<"Creating Singleton [OK]\n";
    };

    static Type& GetSingleton()
    {
        return (*Instance);
    }

    static Type* GetSingletonPointer()
    {
        return Instance;
    }

    virtual ~Singleton()
    {
        Instance = nullptr;
    }

};

template <typename Type>
Type* Singleton<Type>::Instance = nullptr;


class Board: public Singleton<Board>// template recursivo
{
public:


};





#endif // SINGLETON_H
