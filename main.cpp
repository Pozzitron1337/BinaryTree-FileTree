#include <iostream>
#include <string>

#include "FileTree.cpp"
int main() {
    BinaryTree<int> bt;
    bt.add(1);
    bt.add(3);
    bt.add(0);
    bt.add(5);
    bt.add(7);
    bt.add(4);
    bt.add(2);
    bt.add(14);
    bt.printTree();
    cout<<endl;
    cout<<bt.successor(bt.findElement(7))<<endl;
    cout<<"Max element: "<<bt.getMaxElement()<<endl;
    cout<<"Found element: "<<bt.findElement(7)<<endl;
    cout<<bt.predsucsessor(14);
    bt.deleteElement(14);

    bt.printTree();

    BinaryTree<string> bt2;
    bt2.add("dsa");
    bt2.add("ii12");
    bt2.add("poop");
    bt2.add("asd");
    bt2.add("wwhehhhhe");
    bt2.printTree();


    FileTree ft("text.txt");
    ft.printFileWords();
    ft.addFileWordsToTree();
    ft.findWordInFile("book");
    ft.printFileWords();
    ft.deleteWordFromFile("for");
    ft.printFileWords();
    ft.printTreeWords();

    return 0;
}