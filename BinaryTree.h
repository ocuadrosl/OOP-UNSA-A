#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <vector>
#include <iostream>
#include <memory>


/*
Struct Node
*/
template <typename Type>
struct Node
{
    //alias for simplicity
    using NodeTypePtr = std::unique_ptr< Node<Type> >;

    //data
    Type Data{};

    //constructors
    Node()=default;
    Node(const Type& data):Data{data}{}

    //leaves
    NodeTypePtr Left{nullptr};
    NodeTypePtr Right{nullptr};

};

/*
Class Binary tree
*/
template <typename Type>
class BinaryTree
{

    //alias for simplicity
    using NodeTypePtr = std::unique_ptr< Node<Type> >;

    //Pinter to Root
    NodeTypePtr Root{nullptr};

    //Auxiliary methods
    auto& Find(const Type& data,  NodeTypePtr& node) ;
    void Print(const NodeTypePtr& node); //in order

public:
    BinaryTree()=default;

    //Main methods
    const auto& Find(const Type& data) ;
    const auto& Insert(const Type& data);
    void Print() {Print(Root);};


};

template<typename Type>
void BinaryTree<Type>::Print(const NodeTypePtr& node)
{

    if (node == nullptr)
    {
        return;
    }
    Print(node->Left);
    std::cout<<node->Data<<"\n";
    Print(node->Right);
}


template<typename Type>
auto& BinaryTree<Type>::Find(const Type& data,  NodeTypePtr& node)
{

    if(node == nullptr)
    {
        return node;
    }

    if(node->Data == data)
    {
        return node;
    }

    return (node->Data > data) ? Find(data, node->Left) : Find(data, node->Right);


}

template<typename  Type>
const auto& BinaryTree<Type>::Find(const Type& data)
{
    return Find(data, Root);
}


template<typename  Type>
const auto& BinaryTree<Type>::Insert(const Type& data)
{
    auto& node = Find(data, Root);

    if (node == nullptr)
    {
        node = std::make_unique<Node<Type>>(data);
    }

    return node;
}




#endif // BINARYTREE_H
