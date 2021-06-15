    }
 
    if (index == 1){
        head = head->next;
        if (head){
            head->prev = nullptr;
        }
        x = p->data;
        delete p;
    } else {
        for (int i=0; i<index-1; i++){
            p = p->next;
        }
        p->prev->next = p->next;
        if (p->next){
            p->next->prev = p->prev;
        }
        x = p->data;
        delete p;
    }
    return x;
}
 
void DoublyLinkedList::Reverse() {
    Node* p = head;
    Node* temp;
    while (p != nullptr){
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;
 
        // Need to check the following condition again
        if (p->next == nullptr){
            p->next = p->prev;
            p->prev = nullptr;
            head = p;
            break;
        }
    }
}
 
DoublyLinkedList::~DoublyLinkedList() {
    Node* p = head;
    while (head){
        head = head->next;
        delete p;
        p = head;
    }
}
 
 
int main() {
 
    int A[] {1, 3, 5, 7, 9};
 
    DoublyLinkedList dll(A, sizeof(A)/sizeof(A[0]));
    cout << "Length: " << dll.Length() << endl;
 
    dll.Insert(0, 11);
    dll.Insert(6, 13);
    dll.Display();
 
    dll.Delete(1);
    dll.Delete(6);
    dll.Display();
 
    dll.Reverse();
    dll.Display();
 
    return 0;
}
