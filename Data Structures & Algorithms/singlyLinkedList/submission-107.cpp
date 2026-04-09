class LinkedList {
    
public:
    
  int l_value;
        LinkedList* l_next;

        LinkedList() {
            l_value=0;
            l_next = nullptr;
        }
        LinkedList(int value, LinkedList* next = nullptr) {
            l_value = value;
            l_next = next;
        }
        LinkedList* head;
    int get(int index) {
       LinkedList* current = l_next;
        int count = 0;
        while (current != nullptr) {
            if (count == index) return current->l_value;
            current = current->l_next;
            count++;
        }
       return -1;
    }

    void insertHead(int val) {
       l_next = new LinkedList(val, l_next);
    }

    void insertTail(int val) {
        LinkedList* current = this;
        while (current->l_next != nullptr) {
            current = current->l_next;
        }
        current->l_next = new LinkedList(val);
    }

bool remove(int index) {
    if (l_next == nullptr) {
        return false;
    }
    if (index == 0) { 
        l_next = l_next->l_next;
        return true;
    }
    LinkedList* current = l_next;

    for (int i = 0; i < index - 1; i++) {
        if (current->l_next == nullptr) return false; 
        current = current->l_next;
    }
  
    if (current->l_next==nullptr) return false;
    current->l_next = current->l_next->l_next;
  
    return true;
}
    vector<int> getValues() {
        vector<int> vals;
        LinkedList* current = this->l_next;
        while (current != nullptr) {
            vals.push_back(current->l_value);
            current = current->l_next;
        }
        return vals;
    }
};
