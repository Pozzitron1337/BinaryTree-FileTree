#include <iostream>
#include <malloc.h>

using namespace std;

template<class Y>
struct BinaryTreeStructure{
    Y data;
    BinaryTreeStructure* left;
    BinaryTreeStructure* right;
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
        if(!tree){
            tree=(BinaryTreeStructure<T>*)calloc(sizeof(T),sizeof(BinaryTreeStructure<T>*));
            tree->data = element;
            tree->left=NULL;
            tree->right=NULL;
            return true;
        }
        BinaryTreeStructure<T>* temp;
        BinaryTreeStructure<T>* it=tree;
        while(it!=NULL){
            if(element==it->data)
                return false;
            if(element<it->data){
                temp=it;
                it=it->left;
            }
            else{
                temp=it;
                it=it->right;
            }
        }
        if(element < temp->data){
            it=(BinaryTreeStructure<T>*)calloc(sizeof(T),sizeof(BinaryTreeStructure<T>));
            it->data = element;
            it->left=NULL;
            it->right=NULL;
            temp->left=it;
        }
        else {
            it=(BinaryTreeStructure<T>*)calloc(sizeof(T),sizeof(BinaryTreeStructure<T>));
            it->data = element;
            it->left=NULL;
            it->right=NULL;
            temp->right=it;
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

    /*delete element flom tree*/
    void deleteElement(T element){
        if(!tree)
            return;
        BinaryTreeStructure<T>* it=tree;     //iterator
        BinaryTreeStructure<T>* prev_it=NULL;//previous value of iterator
        BinaryTreeStructure<T>* lefttree;    //the left-hand tree from deleting element
        BinaryTreeStructure<T>* righttree;   //the right-hand tree from deleting element
        while(it!=NULL){
            if(element==it->data) {
                lefttree=it->left;
                righttree=it->right;
                break;
            }
            if(element < it->data){
                prev_it=it;
                it=it->left;
            }
            else{
                prev_it=it;
                it=it->right;
            }
        }
        if(it==NULL)
            return;
        if(prev_it->data > it->data)   //if left-hand
        {
            delete it;                 //delete element
            prev_it->left=righttree;   //saving the order
            while(prev_it->left!=NULL) //moving to smallest element
                prev_it=prev_it->left;
            prev_it->left=lefttree;    //save the order of tree
        }
        else
        {
            delete it;
            prev_it->right=lefttree;
            while(prev_it->right!=NULL)
                prev_it=prev_it->right;
            prev_it->right=righttree;
        }
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