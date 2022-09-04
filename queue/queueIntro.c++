#include<bits/stdc++.h>
using namespace std;

int main(){
	//Implementation of queue using stl
	queue<int>q;
	q.push(11);
	q.push(15);
	q.push(13);

	cout << "size of queue is " << q.size() << endl;

	cout << "size of queue is " << q.front() << endl;

	q.pop();

	cout << "size of queue is " << q.front() << endl;

	cout << "size of queue is " << q.size()	<< endl;


	if(q.empty()){
		cout << "q is empty" << endl;
	}
	else{
		cout << "q is not empty" << endl;
	}


}