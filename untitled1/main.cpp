#include <iostream>
#include <string>
using namespace std;
class list{
private:
    struct node {
        int data{};
        string data_word;
        node * next{};
    };
    typedef struct node* nodeptr;

    nodeptr curr;
    nodeptr tmp;
public:
    nodeptr head;
    list(){
        head= nullptr;
        curr = nullptr;
        tmp = nullptr;
    }
    void AddNode(int addData,string addWord){
        auto n = new node;
        n->next = nullptr;
        n->data= addData;
        n->data_word=std::move(addWord);
        if(head != nullptr){
            curr = head;
            while (curr->next != nullptr){
                curr =  curr->next;
            }
            curr->next = n;
        }
        else{
            head = n;
        }
    }
    void deleteNode(const string& word){
        nodeptr delPtr;
        tmp = head;
        curr = head;
        while (curr != nullptr && curr->data_word != word){
            tmp = curr;
            curr = curr->next;
        }
        if(curr == nullptr){

        }
        else{
            delPtr = curr;
            curr = curr->next;
            tmp->next = curr;
            delete delPtr;
        }
    }
    void printList(){
     curr = head;
        while (curr != nullptr){
            cout<<curr->data_word<<" "<<curr->data<<endl;
            curr = curr->next;
        }
    }
    int size(){
        curr = head;
        int i =0;
        while (curr != nullptr){
            i++;
            curr = curr->next;

        }
        return i;
    }
};
class map{
private:
    static const int hashGroups = 100;
    list table[hashGroups];
public:
    bool isEmpty(){
        int sum =0;
        for(auto & i : table){
            sum += i.size();
        }
        if(!sum){
            return true;
        }
        else{
            return false;
        }
    }
    static int hasFunction(const string& word){
        int key=0;
        for(char i : word){
            key = key + i;
        }
     return key % hashGroups;
    }
    void insertItem(const string& value){
        int hashValue = hasFunction(value);
        auto & cell = table[hashValue];
        auto bItr = cell.head;
        while (bItr != nullptr){
            if(bItr->data_word == value){
                bItr->data++;
                break;
            }
            else{
                cell.AddNode(1,value);
            }
            bItr = bItr->next;
        }
        cout<<"It worked"<<endl;

    }

     void removeItem(const string& word){
        int hashValue = hasFunction(word);
        auto & cell = table[hashValue];
        auto bItr = cell.head;
        while (bItr != nullptr){
            if(bItr->data_word == word){
               cell.deleteNode(word);
                break;
            }
            else{

            }
            bItr = bItr->next;
        }

    }
    void printList(){
        for(int i=0;i<hashGroups;i++){
            if(table[i].size()==0)continue;
            table[i].printList();
            }
        }
};

int main() {
    map ht;
    if(ht.isEmpty()){
        cout<< "Its working"<<endl;
    }
    else{
        cout<< "Its not working"<<endl;

    }
    ht.insertItem("bill");
    ht.insertItem("rick");
    ht.insertItem("ozan");
    ht.insertItem("atakan");
    ht.printList();
    return 0;
}
