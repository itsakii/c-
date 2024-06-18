class Solution{
    private:
    void heapify(vector<int> &arr, int n, int index){
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;
    
        // base case
        if (left >= n && right >= n) return;
    
        // comparison
        if(left < n && arr[largest] < arr[left]){
            largest = left;
        }
        if(right < n && arr[largest] < arr[right]){
            largest = right;
        }
    
        // updating heap
        if(largest != index){
            swap(arr[largest], arr[index]);
            heapify(arr, n, largest);
        }
    }
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int>arr;
        
        for(int &x:a) arr.push_back(x);
        for(int &x:b) arr.push_back(x);
        
        int k = arr.size();
        
        // heapifying the complete array
        for(int i=k/2-1; i>=0; i--){
            heapify(arr, k, i);
        }
        
        return arr;
    }
};