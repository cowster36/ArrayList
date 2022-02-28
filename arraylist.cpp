#include <cstdlib>

template <class DataType>
class ArrayList {
private:
    DataType * data;

public:
    int length = 0;
    int maxLength = 0; 

    ArrayList(int maxLength_) {
        maxLength = maxLength_;
        data = (DataType *) malloc(sizeof(DataType) * maxLength);
    };

    DataType operator[](int index) {
        return data[index];
    };

    void set(int index, DataType val) {
        data[index] = val;
    };

    void push(DataType val) {
        data[length] = val;
        length += 1;
    };

    void pop() {
        length -= 1;
    };

    DataType * getPointer(int index) {
        return data + index;
    };

    void erase(int index) {
        for(int i = index + 1; i < length; i++) {
            data[i - 1] = data[i];
        }

        length -= 1;
    };

    int getIndex(DataType * pointer) {
        return pointer - data;
    };

    void resize(int newLength) {
        DataType * oldPointer = data;
        data = (DataType *) realloc(data, sizeof(DataType) * newLength);

        if(data == NULL) {
            data = oldPointer;
        }
    };

    void forAll(void (* function)(DataType)) {
        for(int i = 0; i < length; i++) {
            function(data[i]);
        }
    };

    void destroy() {
        free(data);
    };
};
