#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = nullptr;
    }
};

class LinkedList{
    public:
    Node* head = nullptr;
    int count = 0; 

    void addAtBegin(int data){
        Node* newNode = new Node(data);
        Node* temp = head;
        head = newNode;
        head->next = temp;
        this->count++;
    }
    void viewAll(){
        Node* temp = head;
        while(temp != nullptr){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }
    void searchByValue(int data){
        Node* temp = head;
        bool isFound = false;
        if(count == 0){
            cout<<"Linked List is Empty !";
        }else{

            while(temp != nullptr){
                if(temp->data == data){
                    isFound = true;
                }
                temp = temp->next;
            }
        (isFound == true) ? cout<<"Data Found !"<<endl : cout<<"Data Not Found !";
        }


    }
    void deleteAtAny(int pos){
        if(count == 0){
            cout<<"Linked List is Empty !";
            return;
        }else{
            Node* current = head, *prev = head;

            for(int i = 0; i < pos; i++){
                current = current->next;
            }
            for(int i = 0; i < pos - 1; i++){
                prev = prev->next;
            }

            prev->next = current->next;
            delete current;
            prev = nullptr;
            delete prev;
            this->count--;


        }

    }
    void updateValue(int data, int pos){
        Node* temp = head;
        for(int i = 0; i < pos;i++){
            temp = temp->next; 
        }
        temp->data = data;
    }
};
int main(){
 LinkedList list;
 int choice;

 do{
    cout<<"\nEnter 1 for Add At Beginning... ";
    cout<<"\nEnter 2 View All value... ";
    cout<<"\nEnter 3 for search value... ";
    cout<<"\nEnter 4 for Delete At Any Position... ";
    cout<<"\nEnter 5 for Update value... ";
    cout<<"\nEnter 0 To Exit... ";
    cout<<"\nEnter Your Choice... : ";
    cin>>choice;

    switch(choice){
        case 1:{
            int data;
            cout<<"Enter Value : ";
            cin>>data;

            list.addAtBegin(data);

            break;
        }
        case 2:{
            list.viewAll();
       
            break;
        }
        case 3:{

            int data;
            cout<<"Enter Value : ";
            cin>>data;

            list.searchByValue(data);
            break;
        }
        case 4:{
            int pos;
            cout<<"Enter Position : ";
            cin>>pos;
            list.deleteAtAny(pos);
            break;
        }
        case 5:{

            int data; int pos;

            cout<<"Enter Position : ";
            cin>>pos;
            cout<<"Enter Value : ";
            cin>>data;

            list.updateValue(data, pos);

            break;
        }
        case 0:{
            cout<<"Thank You...";
            break;
        }
        default:
        cout<<"Invalid Choice...";
    }

 }while(choice != 0);
return 0;
}