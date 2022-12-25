#ifndef _QUEUE_H_
#define _QUEUE_H_
#include<iostream>
#include "Queue.h"
#include "Except.h"
using namespace std;
template<class T>
class Node{
	private:
		T data;
		Node<T> *next;
		template<class T1>
		friend class Queue;
};
template<class T>
class Queue{
	private:
		Node<T> *head;
		Node<T> *tail;
		int size;
	public:
		Queue();
		// copy constructor
		Queue(const Queue&);
		// copy assignment operator
		T& operator=(const T&);
		~Queue();
		bool empty();
		void enqueue(T);
		void dequeue();
		T front();
		T back();

};
template<class T>
Queue<T>::Queue(){
        head = NULL;
}

// copy constructor
template<class T>
Queue<T>::Queue(const Queue &q){

        while(!q.empty()){
                this->enqueue(q.front());
        }
}

// copy assignment operator
template<class T>
T &Queue<T>::operator=(const T &q){

        while(!q.empty()){
                this->enqueue(q.front);
        }
        return *this;
}
template<class T>
Queue<T>::~Queue(){
}

template<class T>
bool Queue<T>::empty(){
        return head == NULL;
}
template<class T>
void Queue<T>::enqueue(T val){
        Node<T> *node = NULL;
        node = new Node<T>[1];
        if(node == NULL){
                // throw an error invalid pointer
                throw(Except("Can not allocate more memory"));
        }
        node->data = val;
        if(empty()){
                head = node;
        }
        else{
                Node<T> *tmp = head;
                while(tmp->next != NULL){
                        tmp = tmp->next;
                }
                tmp->next = node;
                tail = node;
        }
}

template<class T>
void Queue<T>::dequeue(){
        if(empty()){
                // throw an error queue is empty
                throw(Except("Attempt to dequeue empty queue"));
        }
        else{
                T val = head->data;
                head = head->next;
                end = head;
                cout << val << endl;
        }
}
template<class T>
T Queue<T>::front(){
        if(empty()){
                // throw an error queue is empty
                throw(Except("Attempt to dequeue empty queue"));
        }
        else{
                return head->data;
        }
}
template<class T>
T Queue<T>::back(){
        return tail;
}
#endif
