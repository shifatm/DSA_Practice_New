//Defines the structure of the linked list -> Custom data type
class Node{
    public:
    int data;
    Node* next;
    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


class MyLinkedList {
public:
    //Initializes the head with NULL and size of the list as ZERO
    Node* head = nullptr;
    int size = 0;
    MyLinkedList(){}
    
    int get(int index) {
        //if the index = size i.e. Node with that index doesn't exist
        if(size == 0 || index >= size) return -1;
        Node* temp = head;
        for(int i = 0; i < index; i++){
            temp = temp->next;
        }
        return temp->data;
    }
    
    void addAtHead(int val) {
        Node* temp = new Node(val);
        if (head != nullptr) {
            temp->next = head;
        }
        //If the head is NULL i.e. size = 0
        head = temp;
        size++;
    }
    
    void addAtTail(int val) {
        Node* temp = new Node(val);

        //size = 0
        if (head == nullptr) {
            head = temp;
            size++;
            return;
        }

        Node* curr = head;
        while(curr != nullptr && curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = temp;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if (index > size) {
            return;
        }

        // add at the last index or when size = 0
        if (index == size) {
            addAtTail(val);
            return;
        }

        //add at head when size = 1
        if (index == 0 && size == 1) {
            addAtHead(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* curr = head;
        for(int i = 0; i < index - 1; i++){
            curr = curr->next;
        }
        Node* temp1 = curr->next;
        curr->next = newNode;
        newNode->next = temp1;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (head == nullptr || index >= size) return;
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            size--;
            delete temp;
            return;
        }

        Node* curr = head;
        for(int i = 0; i < index-1; i++){
            curr = curr->next;
        }
        //deleting the last node
        if (index == size - 1) {
            Node* temp = curr->next;
            curr->next = nullptr;
            delete temp;
        } else {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;   
        }
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
