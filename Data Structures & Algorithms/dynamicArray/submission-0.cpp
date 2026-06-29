class DynamicArray {
public:
    int* data;
    int size;
    int capacity;

    DynamicArray(int capacity) {
        this->data = new int[capacity];
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
        if (size == capacity) {
            resize();
        }
        data[size] = n;
        size += 1;
    }

    int popback() {
        size -= 1;
        return data[size];
    }

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
};
