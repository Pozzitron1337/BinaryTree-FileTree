#include <iostream>
#include <string>
#include <fstream>

#include "BinaryTree.cpp"

class FileTree{
private:
    BinaryTree<string> file_words;
    fstream file;
public:
    FileTree(string file_path){
        file.open(file_path,
                  std::fstream::in |  //access to read
                  std::fstream::out   //access to write
        );

    }
    ~FileTree(){
        file.close();
    }

    void printFileWords(){
        file.clear();               //clear stream
        file.seekg(0,ios_base::beg);//set pointer to begin
        string word;
        while(file >> word) {
            cout<<word<<" "<<endl;

        }
        cout<<endl;
    }

    void printTreeWords(){
        file_words.printTree();
    }

    void addFileWordsToTree(){
        file.clear();               //clear stream
        file.seekg(0,ios_base::beg);//set pointer to begin
        string buffer;
        while(file>>buffer) {
            file_words.add(buffer);
        }
        file_words.printTree();
    }

    int findWordInFile(string word){
        file.clear();               //clear stream
        file.seekg(0,ios_base::beg);//set pointer to begin
        int result=file.tellg();
        string buffer;
        while(file>>buffer) {
            if(!word.compare(buffer)){
                break;
            }
            result=file.tellg();
        }
        if(result==-1){
            file.clear();               //clear stream
            file.seekg(0,ios_base::end);//set pointer to end
            result=file.tellg();        //get pointer positiion;
            file<<" ";
            file<<word;
        }
        return result+1;
    }

    BinaryTreeStructure<string>* findWordInTree(string word){
        if(!file_words.findElement(word))
            file_words.add(word);
        return findWordInTree(word);
    }

    void findWord(string word){
        findWordInFile(word);
        findWordInTree(word);
    }


    void deleteWordFromFile(string word){
        int position=findWordInFile(word);
        file.clear();
        file.seekp(position);
        int wordSize=word.size();
        for(int i=0;i<wordSize;i++)
            file<<" ";
    }
    void deleteWordFromTree(string word){
        file_words.deleteElement(word);
    }

    void deleteWord(string word){
        deleteWordFromFile(word);
        deleteWordFromTree(word);
    }
};
