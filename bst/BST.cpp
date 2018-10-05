#include "BST.h"
#include <iostream>

using namespace std;

BST::BST()
{
    //ctor
    root = NULL;
}

BST::~BST()
{
    //dtor
}

bool BST::isEmpty()
{
    return root==NULL;
}

int BST::height()
{
	return height(root); 
}

int BST::height(BSTNode *no)
{
	if (no == NULL)
		return -1;
	int leftHeight = height(no->getLeft());
	int rightHeight = height(no->getRight());
	if (leftHeight < rightHeight)
		return 1 + rightHeight;
	else
		return 1 + leftHeight;
}

int BST::qtNodes()
{
    return qtNodes(root);
}

int BST::qtNodes(BSTNode* no)
{
    if (no == NULL)
		return 0;
	int qtleft = qtNodes (no->getLeft());
	int qtright = qtNodes (no->getRight());
	return qtleft + qtright + 1;
}

void BST::inserir (int valor)
{
    root = inserir(root,valor);
}

BSTNode* BST::inserir(BSTNode* node, int valor)
{
    
    if (node == NULL)
       	return new BSTNode(valor);
    if (valor < node->getData())
    {
        node->setLeft(inserir(node->getLeft(), valor));
        return node;
    
    }
    else if (valor > node->getData())
            {
               
              node->setRight(inserir(node->getRight(),valor));
              return node;

      }
}

void BST::preOrder()
{
    preOrder(root);
}

void BST::inOrder()
{
    inOrder(root);
}

void BST::posOrder()
{
    posOrder(root);
}

void BST::preOrder(BSTNode *no)
{
    if (no!=NULL)
    {
        cout<<no->getData()<<endl;
        preOrder(no->getLeft());
        preOrder(no->getRight());
    }
}

void BST::posOrder(BSTNode *no)
{
    if (no!=NULL)
    {
        posOrder(no->getLeft());
        posOrder(no->getRight());
        cout<<no->getData()<<endl;
    }
}

void BST::inOrder(BSTNode *no)
{
    if (no!=NULL)
    {
        inOrder(no->getLeft());
        cout<<no->getData()<<endl;
        inOrder(no->getRight());

    }
}

BSTNode*  BST::remover(int valor){
    remover(root, valor);
}

BSTNode* BST::remover(BSTNode *no, int valor){

 

      if(no->getData() == valor){
        if((no->getRight() == NULL )&& (no->getLeft()== NULL)){
            delete(no);
            return NULL;
          }



      else if((no->getRight() == NULL)){
         BSTNode* aux;
         aux = no->getLeft();
         delete(no);
         return aux;
      }
      else if(no->getLeft() == NULL){
        BSTNode* aux;
        aux = no->getRight();
        delete(no);
        return aux;
      }

   

      BSTNode* esquerda = no->getLeft();
      while(esquerda->getRight() != NULL)
        esquerda = esquerda->getRight();

      no->setData(esquerda->getData());
      remover(esquerda, esquerda->getData());
    }

   

      if(valor > no->getData()){
        no->setRight(remover(no->getRight(), valor));
      }
      else
      no->setLeft(remover(no->getLeft(), valor));
}

     BSTNode* BST::busca(int valor){
       busca(root, valor);
     }

     BSTNode* BST::busca(BSTNode *no, int valor){
       if(no == NULL){
         return NULL;
       }
       int d = no->getData();
       if(d == valor){
         return no;
       }
       if(valor < d){
         return busca(no->getLeft(), valor);
       }
       else if(valor > d){
         return busca(no->getRight(), valor);
       }
     }
