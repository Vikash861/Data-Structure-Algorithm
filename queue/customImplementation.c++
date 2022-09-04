#include<bits/stdc++.h>
using namespace std;
class Queue{
	int *arr;
	int qFront;
	int rear;
	int size;
	Queue(int size){
		this->size = size;
		arr = new int[size];
		qFront = 0;
		rear  = 0;
	}
public:

	void push(int data){
		if(rear == size-1){
			cout << "queue is full" << endl;
			return;
		}
		else{
			arr[rear] = data;
			rear++;
		}
	}

	int pop(){
		int data = -1;
		if(qFront == rear){
			cout << "queue is empty" << endl;
			qFront = 0;
			rear  = 0;
		}
		else{
			data = arr[qFront]
			qFront++;
		}
		return data;
	}

	int front(){
		return arr[qFront];
	}

}

int main(){
	Queue q;
	q.push(10);
	cout << q.front() << endl;
}