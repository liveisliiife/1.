#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

#include "Node.h"

template <class T>
class LinkedList
{
public: 
    LinkedList();
    LinkedList(const LinkedList<T> &obj);
    ~LinkedList();

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

    int getSize() const;
    bool isEmpty() const;
    bool containsNode(Node<T> *node) const;
    int getIndex(Node<T> *node) const;

    Node<T> *getFirstNode() const;
    Node<T> *getLastNode() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void append(const T &data);
    void prepend(const T &data);
    void insertAfterNode(const T &data, Node<T> *node);
    void insertAtIndex(const T &data, int index);
    void moveToIndex(int currentIndex, int newIndex);

    void removeNode(Node<T> *node);
    void removeNode(const T &data);
    void removeNodeAtIndex(int index);
    void removeAllNodes();

    void print() const;

private:


private: 
    Node<T> *head;
    int size;
};

template<class T>
LinkedList<T>::LinkedList()
{
    head = NULL;
	size = 0;
    
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj)
{
   
    head = NULL;
    *this = obj;

}

template<class T>
LinkedList<T>::~LinkedList()
{
    removeAllNodes();
    size =0;
   
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs)
{
    
    if(this == &rhs) return *this;
    removeAllNodes();
    Node<T>  *current = rhs.head;
    for(int i=0; i<rhs.size; i++){
        append(current->data);
        current = current->next;
    }
    size=rhs.size;
    return *this;
   
}

template<class T>
int LinkedList<T>::getSize() const
{
    return size;
  
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    if(head == NULL){
		return true;
	}
	else{
		return false;
	}
   
}

template<class T>
bool LinkedList<T>::containsNode(Node<T> *node) const
{

	if (size == 0){
        return false;
    }
    
    Node <T> *current=head;
    int x = size;
    for(int i=0 ; i<x ; i++){
    	if(current == node){
    		return true;
		}
		else{
			current = current->next;
		}
	}
	return false;
   
}

template<class T>
Node<T> *LinkedList<T>::getFirstNode() const
{
    if (size == 0){
        return NULL;
    }
    return head;
   
}

template<class T>
Node<T> *LinkedList<T>::getLastNode() const
{
    if (head == NULL){
        return NULL;
    }
    return head->prev;
    
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const
{

	if (head == NULL){
        return NULL;
    }
    Node <T> *current=head;
    for(int i=0;i<size;i++){
    	if(current->data == data){
    		return current;
		}
		else{
		    current = current->next;
		}
	}
	return NULL;
    
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const
{
	if (index >= size || index < 0 ) {
		return NULL;
	}
    Node <T> *current=head;
    for(int i=0;i<index;i++){
        current=current->next;
    }
    return current;
    
}

template<class T>
void LinkedList<T>::append(const T &data)
{
    Node<T> * current = new Node<T>(data);


    current->next = NULL;
    current->prev = NULL; 

    if(head == NULL) {
        head = current;
        current->next = head;
        current->prev = head;
    } 
    else {

        Node<T> * temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
            

        temp->next = current;
        current->next = head;
        current->prev = temp;
        head->prev = current;
  }
  size = size +1;
}
   

template<class T>
void LinkedList<T>::prepend(const T &data)
{

    Node<T> * newNode = new Node<T>(data);


    newNode->next = NULL;
    newNode->prev = NULL; 

    if(head == NULL) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } 
    
    else {

        Node<T> * temp = head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }    
    size = size +1;
    
}

template<class T>
void LinkedList<T>::insertAfterNode(const T &data, Node<T> *node)
{

	if ( containsNode(node) && node != NULL ) {
		Node <T> *current=head;
        
        for(int i=0; i<size;i++){
        	if(current == node){      		
        		Node <T> * temp = new Node<T>(data);
        		temp->next = current->next;
        		current->next->prev = temp;
        		current->next = temp;
        		temp->prev = current;
        		size = size + 1;
        		return;
			}
			else{
				current = current->next;
			}
		}
	}
	
    else {
    	return;
    }
    
}

template<class T>
void LinkedList<T>::insertAtIndex(const T &data, int index)
{


	if (index>size || index < 0 ) {
		return ;
	}
    else if (index==0){
        prepend(data);
    }
    else if(index == size){
    	append(data);
	}
    else{
    	Node <T> *current=head;
    	for (int i=0;i<index-1;i++){
        	current=current->next;
    	}
    	
    	Node <T> * temp = new Node<T>(data);
        temp->next = current->next;
        current->next->prev = temp;
        current->next = temp;
        temp->prev = current;
        size = size + 1;
        return;
	}
    
}

template<class T>
int LinkedList<T>::getIndex(Node<T> *node) const
{
    
	if ( containsNode(node) && node != NULL) {
		Node <T> *current=head;
        for(int i=0; i<size;i++){
    	    if(current == node){
    		    return i;
	        }
		    else{
			    current = current->next;
		    }
	    }
	}
	return -1;    
    
}

template<class T>
void LinkedList<T>::moveToIndex(int currentIndex, int newIndex)
{
    
    if(currentIndex>=size) return;

    else{
        if (newIndex >= size) newIndex = size-1;
        Node<T> *curr = head; int i=0;
        while (i!=size){
            if (i == currentIndex) {
                if (i == 0) head = head->next;
                curr->next->prev = curr->prev;               
                curr->prev->next = curr->next;
                size--;
                int j = 1; Node<T> *ccurr = head;
                while (j<newIndex){
                    j++;
                    ccurr=ccurr->next;
                }
                if(newIndex == 0) {
                    curr->next = ccurr;
                    curr->prev = ccurr->prev;
                    ccurr->prev->next = curr;
                    ccurr->prev = curr;
                    head = head->prev;
                    size++;
                    return;
                }
                curr->next = ccurr->next;
                ccurr->next->prev = curr;
                ccurr->next = curr;
                curr->prev = ccurr;
            	size++;
                return;
                }
                i++; curr = curr->next;
        }
    }
}

template<class T>
void LinkedList<T>::removeNode(Node<T> *node)
{
    
    if (size == 1 && head == node){
        delete head;
        head=NULL;
        size = 0;
        return;
    }

	if( containsNode(node) && node != NULL) {
		    
        Node <T> *current=head;
    
        for(int i=0; i<size; i++){
    	
    	    if(current == node){
    		    if(i==0){
    		    	head = head->next;
			    }
			    Node <T> *temp=current;
    		    current->next->prev=current->prev;
    		    current->prev->next=current->next;   
    		    delete temp;
                size = size -1;
    		    return;			
		    }
		    else{
			    current = current->next;
		    }		
	    }
	}

    return;
 
}

template<class T>
void LinkedList<T>::removeNode(const T &data)
{
    
    if (size == 0){
        return ;
    }
    
    else if(size == 1 && head->data == data){
        delete head;
        head = NULL;
        size = 0;
        return;
    }
    else{
    int a = 0;
    Node <T> *current=head;
    for(int i=0; i<size; i++){
    	if(current->data == data){
    		if(current == head){
    			a = a+1;
    			if(a != size){
    				head = head->next;
				}	
				else{
					delete head;
					head = NULL;
					size = 0;
					return;
				} 		
			}
			Node <T> *temp=current;
    		current->next->prev=current->prev;
    		current->prev->next=current->next;          
            size = size -1;
    		delete temp;
    		return;
		}
		else{
			current = current->next;
		}		
	}
    }

}

template<class T>
void LinkedList<T>::removeNodeAtIndex(int index)
{

	if (index<0 || index>=size || head == NULL) {
		return;
	}

    
    if (index==0 && size == 1){
        delete head;
        head=NULL;
        size = 0;
        return;
    }
    else{

    	
    	Node <T> *current=head;
    	
    	if (index ==0){
        	head = head->next;
    	}
    	
    	for (int i=0; i<index ;i++){
        	current = current->next;
    	}
    	
    	Node <T> *temp=current;
    	current->next->prev=current->prev;
    	current->prev->next=current->next;
    	delete temp;
		size = size -1;
    	return;
    }

}

template<class T>
void LinkedList<T>::removeAllNodes()
{
    
    if (head == NULL){
        return ;
    }
    else{
        for(int i=0; i<size-1; i++){
            Node<T> *temp = head;
            head = head->next;
            delete temp;
        }
        delete head; 
        head = NULL;
        size = 0;
        return;
    }

}

template<class T>
void LinkedList<T>::print() const
{
    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T> *node = this->getFirstNode();

    do {
        std::cout << *node << std::endl;
        node = node->next;
    }
    while (node != this->getFirstNode());
}

#endif //LINKEDLIST_H

