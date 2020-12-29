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
    using NodeTypePtr = std::shared_ptr< Node<Type> >;

    //data
    Type Data{};

    //constructors
    Node()=default;
    Node(const Type& data):Data{data}{}

    //leaves
    NodeTypePtr Left{nullptr};
    NodeTypePtr Right{nullptr};

    NodeTypePtr Parent{nullptr};

};

/*
Class Binaty tree
*/
template <typename Type>
class BinaryTree
{

    //alias for simplicity
    using NodeTypePtr = std::shared_ptr< Node<Type> >;

    //Pinter to Root
    NodeTypePtr Root{nullptr};

    //Auxiliary methods
    auto Find(const Type& data,  NodeTypePtr& node, const NodeTypePtr& parent=nullptr) ;
    void Print(const NodeTypePtr& node); //in order

public:
    BinaryTree()=default;

    //Main methods
    const auto& Find(const Type& data); //Find for public use
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
auto BinaryTree<Type>::Find(const Type& data,  NodeTypePtr& node, const NodeTypePtr& parent)
{

    using leafAndParentType = std::tuple<NodeTypePtr&, const NodeTypePtr&>;

    if(node == nullptr)
    {
        return leafAndParentType(node, parent); //returning leaf and parent
    }

    if(node->Data == data)
    {
        return leafAndParentType(node, parent);
    }

    return (node->Data > data) ? Find(data, node->Left, node) : Find(data, node->Right, node);


}

template<typename  Type>
const auto& BinaryTree<Type>::Find(const Type& data)
{
    return std::get<0>(Find(data, Root));
}


template<typename  Type>
const auto& BinaryTree<Type>::Insert(const Type& data)
{
    auto [leaf, parent] = Find(data, Root);

    if (leaf == nullptr)
    {
        leaf = std::make_shared<Node<Type>>(data);
        leaf->Parent = parent;
    }

    return leaf;
}




#endif // BINARYTREE_H
