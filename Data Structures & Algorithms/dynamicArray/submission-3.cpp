class DynamicArray {
public:
    int* data;
    int size;
    int capacity;

    DynamicArray(int capacity) {
        this->data = (int*)malloc(capacity * sizeof(int));
        this->size = 0;
        this->capacity = capacity;
    }

    int get(int i) {
        return data[i];
    }

    void set(int i, int n) {
        data[i] = n;
    }

    void pushback(int n) {
        if (size == capacity) resize();
        data[size++] = n;
    }

    int popback() {
        return data[--size];
    }

    void resize() {
        capacity *= 2;
        data = (int*)realloc(data, capacity * sizeof(int));
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
