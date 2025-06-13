 #include<iostream>
 using namespace std;
 class Minheap{
    public:
    int arr[50];
    int idx;
    Minheap(){
        idx =1;
    }
    int top(){
        return arr[1];
    }
    void push(int x){
       arr[idx] = x;
       int i= idx;
       idx++;
       while(i!=1){
        int parent = i/2;
        if(arr[i]<arr[parent]){
            swap(arr[i],arr[parent]);
        }
        else break;
        i = parent;
            
        }

    }
    int size(){
        return idx-1;
    }
    void pop(){
        if (idx <= 1) return; 
        arr[1] = arr[idx - 1];
        idx--;

        int i = 1;
        while (true) {
            int left = 2 * i;
            int right = 2 * i + 1;
            int smallest = i;

            if (left < idx && arr[left] < arr[smallest])
                smallest = left;
            if (right < idx && arr[right] < arr[smallest])
                smallest = right;

            if (smallest != i) {
                swap(arr[i], arr[smallest]);
                i = smallest;
            } else break;
        }
    }
    

 };
 int main(){
    Minheap pq;
    pq.push(10);
    pq.push(2);
    cout<<pq.top()<<endl;
    pq.push(11);
    pq.push(12);
    cout<<pq.top()<<endl;
    pq.push(1);
    cout<<pq.top()<<endl;
    cout<<pq.size()<<endl;

 }