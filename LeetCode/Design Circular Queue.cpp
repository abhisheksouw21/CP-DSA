class MyCircularQueue {
public:
  vector<int>a;
       int f=0,r=0;
       int cs=0,N; 
    MyCircularQueue(int k) {
     N=k;
     a.resize(N);
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        a[r] = value;
        r = (r + 1) % N;
        cs++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
       
        f = (f + 1) % N;
        cs--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return a[f];
    }
    
    int Rear() {
        if (isEmpty()) return -1;
      return a[(r - 1 + N) % N];
    }
    
    bool isEmpty() {
        return cs == 0;
    }
    
    bool isFull() {
       return cs == N; 
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */