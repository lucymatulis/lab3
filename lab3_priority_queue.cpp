#include "lab3_priority_queue.hpp"
#include <iostream>
using namespace std;

// PURPOSE: Parametric constructor 
// initializes heap to an array of (n_capacity + 1) elements
PriorityQueue::PriorityQueue(unsigned int n_capacity) {
	heap = new TaskItem*[n_capacity];
	capacity = n_capacity;
	size = 0;
}

// PURPOSE: Explicit destructor of the class PriorityQueue
PriorityQueue::~PriorityQueue() {
}

// PURPOSE: Returns the number of elements in the priority queue
unsigned int PriorityQueue::get_size() const {
	return size;
}

// PURPOSE: Returns true if the priority queue is empty; false, otherwise
bool PriorityQueue::empty() const {
	if(size == 0 || capacity == 0){
		return true;
	}else{
		return false;
	}
}

// PURPOSE: Returns true if the priority queue is full; false, otherwise
bool PriorityQueue::full() const {
	if(size == capacity){
		return true;
	}else{
		return false;
	}
}

// PURPOSE: Prints the contents of the priority queue; format not specified
void PriorityQueue::print() const {

   for(int i = 1; i <= size; i++){
        cout << "Priority " << i << ": " << heap[i]->TaskItem::priority <<endl;
    }
    cout<<"--------------------"<<endl;

}

// PURPOSE: Returns the max element of the priority queue without removing it
// if the priority queue is empty, it returns (-1, "N/A")
PriorityQueue::TaskItem PriorityQueue::max() const {
    if(empty()) {
        return TaskItem(-1, "NULL");
    }else{
        TaskItem temp = *heap[1];
        return temp;
    }
}

// PURPOSE: Inserts the given value into the priority queue
// re-arranges the elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::enqueue(TaskItem val) {
    if(full()){
        return false; //heap is at capacity, cannot engueue a new TaskItem
    }
    if(size ==0){
        heap[1] =new TaskItem(val);
    }else{
       int i = size + 1;
       heap[i]= new TaskItem(val);

       while(i>1 && heap[i/2]->TaskItem::priority < heap[i]->TaskItem::priority){
           TaskItem* temp = heap[i]; //hold new value in temp
           heap[i] = heap[i/2];
           heap[i/2] = temp;
           i = i/2;
       }
    }
    size ++;
	return true;
}

// PURPOSE: Removes the top element with the maximum priority
// re-arranges the remaining elements back into a heap
// returns true if successful and false otherwise
// priority queue does not change in capacity
bool PriorityQueue::dequeue() {

    if(size == 0){
        return false;
    }else if (size == 1){
        delete heap[1];
        size--;
        return true;
    }else{

        swap(heap[1],heap[size]); //set root to be the value of the first node
        delete heap[size]; //delete node that was once the rightest, lowest leaf node
        size--;

        int j = 1;
        int root = 1;
        int right = 2*root+1;
        int left =2*root;

        while(root<=size/2) { //MIGHT NEED TO CHANGE
            int right = 2*root+1;
            int left =2*root;
            //If root is greater than left and right node, leave
            if (heap[left]->TaskItem::priority < heap[root]->TaskItem::priority &&
                heap[right]->TaskItem::priority < heap[root]->TaskItem::priority) {
                return true;
            }//if left child is greater than right child (swap and move down left side)
            else if(heap[left]->TaskItem::priority > heap[right]->TaskItem::priority){
                swap(heap[left], heap[root]);
                root = left;
            } //if right child is greater than left child (swap and move down right side)
            else {
                swap(heap[right], heap[root]);
                root = right;
            }
        }
        j++;
    }
    return true;
}
