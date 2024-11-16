class Solution {
public:
    // Function to find the pivot point in a rotated sorted array
    int getPivot(vector<int>& arr, int n) {
        int s = 0;
        int e = n - 1;
        int mid = s + (e - s) / 2;
        cout<<"mid is"<<mid<< endl<<endl;

        while (s < e) {
            if (arr[mid] >= arr[0]) {
                 cout<<"arr[mid] >= arr[0]: arr[mid]"<<arr[mid]<<endl;
                s = mid + 1;
                cout<<"now s is:"<<s << endl;
            } else {
                 cout<<"arr[mid] < arr[0]: arr[mid]"<<arr[mid]<<endl;
                e = mid;
                 cout<<"now e is:"<<e<< endl;
            }
            mid = s + (e - s) / 2;
            cout<<"now mid is:"<<mid<< endl<<endl;
        }
       cout<<"pivot index is "<<s<<endl;
       cout<<"pivot  is "<<arr[s]<<endl;

        return s; // Return the index of the pivot
    }

    // Binary search function to find a key in a sorted array
    int binary_search(vector<int>& arr, int s, int e, int key) {
        int start = s;
        int end = e;
        int mid = start + (end - start) / 2;

        while (start <= end) {
            if (arr[mid] == key) {
                return mid; // Return the index where the key is found
            } else if (arr[mid] < key) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
            mid = start + (end - start) / 2;
        }

        return -1; // Return -1 if the key is not found
    }

    // Main search function for finding an element in a rotated sorted array
    int search(vector<int>& arr, int k) {
        int n = arr.size();
        int pivot = getPivot(arr, n);

        if (k >= arr[pivot] && k <= arr[n - 1]) {
            return binary_search(arr, pivot, n - 1, k); // Search in the right subarray
        } else {
            return binary_search(arr, 0, pivot - 1, k); // Search in the left subarray
        }

        return -1; // Return -1 if the key is not found
    }
};
