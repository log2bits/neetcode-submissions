class Node {
public:
    int val;
    Node* next;

    Node(int val, Node* next = nullptr) {
        this->val = val;
        this->next = next;
    }
};

class LinkedList {
public:
    Node* head;

    LinkedList() {
        this->head = nullptr;
    }

    int get(int index) {
        Node* node = this->head;
        for (int i = 0; i < index; i++) {
            if (!node) {
                return -1;
            }
            node = node->next;
        }
        return node ? node->val : -1;
    }

    void insertHead(int val) {
        this->head = new Node(val, this->head);
    }
    
    void insertTail(int val) {
        if (!this->head) {
            this->head = new Node(val);
            return;
        }
        Node* node = this->head;
        while (node->next) {
            node = node->next;
        }
        node->next = new Node(val);
    }

    bool remove(int index) {
        if (!this->head) return false;
        if (index == 0) {
            Node* old = this->head;
            this->head = this->head->next;
            delete old;
            return true;
        }
        Node* prev = this->head;
        for (int i = 0; i < index - 1; i++) {
            if (!prev->next) return false;
            prev = prev->next;
        }
        if (!prev->next) return false;
        Node* old = prev->next;
        prev->next = prev->next->next;
        delete old;
        return true;
    }

    vector<int> getValues() {
        vector<int> values;
        Node* node = this->head;
        while (node) {
            values.push_back(node->val);
            node = node->next;
        }
        return values;
    }
};