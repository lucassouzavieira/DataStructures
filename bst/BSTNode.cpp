#include "BSTNode.h"
#include <iostream>

using namespace std;

BSTNode::BSTNode()
{
    //ctor
    {
        left = NULL;
        right = NULL;
    }

}

BSTNode::BSTNode(int d)
{
    //ctor
    {
        data = d;
        left = NULL;
        right = NULL;
    }

}

BSTNode::~BSTNode()
{
    //dtor
}

int BSTNode::getData()
{
    return data;
}

void BSTNode::setData(int d)
{
    data = d;
}

BSTNode* BSTNode::getLeft()
{
    return left;
}

BSTNode* BSTNode::getRight()
{
    return right;
}

void BSTNode::setRight(BSTNode *node)
{
    right = node;
}

void BSTNode::setLeft(BSTNode *node)
{
    left = node;
}
