#include <iostream>
#include <malloc.h>

using namespace std;

template<class Y>
struct BinaryTreeStructure{
    Y data;
    BinaryTreeStructure* left;
    BinaryTreeStructure* right;
    BinaryTreeStructure* parent;
};

template<class T>
class BinaryTree{
private:
    BinaryTreeStructure<T> *tree;
public:
    /*constructor*/
    BinaryTree(){
        tree=NULL; //empty
    }

    /*Destructor*/
    ~BinaryTree(){
        clearTree();
        delete tree;
    }

    /*Adding elements to tree*/
    bool add(const T element){
        BinaryTreeStructure<T>* y=NULL;
        BinaryTreeStructure<T>* x=tree;
        while (x!=NULL){
            y=x;
            if(element<x->data)
                x=x->left;
            else
                x=x->right;
        }
        BinaryTreeStructure<T>* temp=(BinaryTreeStructure<T>*)calloc(sizeof(T),sizeof(BinaryTreeStructure<T>));
        temp->left=NULL;
        temp->right=NULL;
        temp->parent=y;
        temp->data=element;
        if(y==NULL) {
            tree=temp;
        }
        else{
            if(element<y->data)
                y->left=temp;
            else
                y->right=temp;
        }
        return true;
    }

    /*Output tree to console*/
    void printTree(int r=0) {
        if(tree)
        {
            BinaryTreeStructure<T>* temp;
            temp=tree;
            tree=tree->right;
            printTree(r+3);
            tree=temp;
            for (int i=0; i < r ; i++)
                cout<<" ";
            cout<<tree->data<<endl;
            tree=tree->left;
            printTree(r+3);
            tree=temp;
        }
    }

    /*deleting element by input*/
    bool deleteElement(T element){
        BinaryTreeStructure<T>* z=findElement(element);
        if(z==NULL)
            return false;
        BinaryTreeStructure<T>* y;
        if(z->left==NULL || z->right==NULL)
            y=z;
        else
            y=successor(z);
        BinaryTreeStructure<T>* x;
        if(y->left!=NULL)
            x=y->left;
        else
            x=y->right;
        if(x!=NULL)
            x->parent=y->parent;
        if(y->parent==NULL)
            tree=x;
        else{
            if(y == y->parent->left)
                y->parent->left=x;
            else
                y->parent->right=x;
        }
        if(y!=z)
            z->data=y->data;
        free(y);
        return true;
    }

    /*get the next key by values*/
    T successor(T element){
        BinaryTreeStructure<T>* x = findElement(element);
        if(x->right!=NULL)
            return treeMinimum(x->right)->data;
        BinaryTreeStructure<T>* y = x->parent;
        while(y!=NULL && x==y->right){
            x=y;
            y=y->parent;
        }
        return y->data;
    }

    /*get the previous key by values*/
    T predsucsessor(T element){
        BinaryTreeStructure<T>* x = findElement(element);
        if(x->left!=NULL)
            return treeMinimum(x->left)->data;
        BinaryTreeStructure<T>* y = x->parent;
        while(y!=NULL && x==y->left){
            x=y;
            y=y->parent;
        }
        return y->data;
    }
    /*get adress for succsessor element*/
    BinaryTreeStructure<T>* successor(BinaryTreeStructure<T>* x){
        if(x->right!=NULL)
            return treeMinimum(x->right);
        BinaryTreeStructure<T>* y = x->parent;
        while(y!=NULL && x==y->right){
            x=y;
            y=y->parent;
        }
        return y;
    }

    /*get adress for predsuccsessor element*/
    BinaryTreeStructure<T>* predsucsessor(BinaryTreeStructure<T>* x){
        if(x->left!=NULL)
            return treeMinimum(x->left);
        BinaryTreeStructure<T>* y = x->parent;
        while(y!=NULL && x==y->left){
            x=y;
            y=y->parent;
        }
        return y;
    }

    /*finding element in tree and returns the reference to element*/
    BinaryTreeStructure<T>* findElement(T element){
        BinaryTreeStructure<T>* it=tree;
        while(it!=NULL){
            if(element==it->data) {
                break;
            }
            if(element < it->data){
                it=it->left;
            }
            else{
                it=it->right;
            }
        }
        return it;

    }

    /*gets max element from tree*/
    T getMaxElement(){
        if(tree==NULL)
            return (T)NULL;
        BinaryTreeStructure<T>* temp;
        temp=tree;
        while(temp->right!=NULL)
            temp=temp->right;
        return temp->data;
    }

    /*gets min element from tree*/
    T getMinElement(){
        if(tree==NULL)
            return (T)NULL;
        BinaryTreeStructure<T>* temp;
        temp=tree;
        while(temp->left!=NULL)
            temp=temp->left;
        return temp->data;
    }

    /*gets adress of min element from tree  or subtree root*/
    BinaryTreeStructure<T>* treeMinimum(BinaryTreeStructure<T>* element){
        if(element==NULL)
            return NULL;
        BinaryTreeStructure<T>* it=element;
        BinaryTreeStructure<T>* result;
        while(it!=NULL){
            result=it;
            it=it->left;
        }
        return result;
    }

    /*gets adress of max element from tree  or subtree root*/
    BinaryTreeStructure<T>* treeMaximum(BinaryTreeStructure<T>* element){
        if(element==NULL)
            return NULL;
        BinaryTreeStructure<T>* it=element;
        BinaryTreeStructure<T>* result;
        while(it!=NULL){
            result=it;
            it=it->right;
        }
        return result;
    }

    /*makes list empty*/
    void clearTree(){
        if(tree==NULL) {
            return;
        }
        BinaryTreeStructure<T>* temp;
        temp=tree;
        tree=tree->right;
        clearTree();
        delete tree;
        tree=temp;
        tree=tree->left;
        clearTree();
        delete tree;
        tree=temp;
    }

};