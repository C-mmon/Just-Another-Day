Minimize Sum of an Array by at most K reductions

Given an array of integers arr[] consisting of N integers, the task is to minimize the sum of the given array by performing at most K operations, where each operation involves reducing an array element arr[i] to floor(arr[i]/2).

Approach: To obtain the minimum possible sum, the main idea for every operation is to reduce the maximum element in the array before each operation. 
This can be implemented using MaxHeap. Follow the steps below to solve the problem:

Insert all the array elements into MaxHeap.
Pop the root of the MaxHeap and insert (popped element) / 2 into the MaxHeap
After repeating the above step K times, pop the elements of the MaxHeap one by one and keep adding their values. Finally, print the sum.
