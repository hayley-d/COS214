/**
* Strategy class that defines a sort method that is implemented by child classes.
*/
class Sort {
public:
    virtual void sortArray(int* arr, int size) = 0;
};

/**
* Concrete strategy for bubble sort.
*/
class BubbleSort : public Sort {
public:
    void sortArray(int* arr,int size) override {
        for(int i = 0; i < size - 1; i++){
            for(int j = i + 1; j < size; j++) {
                if(arr[i] > arr[j]){
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }
};

class InsertionSort : public Sort {
public:
    void sortArray(int* arr, int size) override {
        int key, j;
        for(int i = 1; i<size; i++) {
          key = arr[i];
          j = i;
          while(j > 0 && arr[j-1]>key) {
             arr[j] = arr[j-1];
             j--;
          }
          arr[j] = key;
       }
    }
};
