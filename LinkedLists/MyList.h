#ifndef MYLIST_H
#define MYLIST_H 
#include "Node.h"
#include <iostream>
#include <set>

template <class T>
class MyList
{
public:
	MyList();
	MyList(Node<T> * m_root);
	~MyList();

    const MyList<T> operator+(const MyList<T>&) const ;

	void insertNode(Node<T> * insert_after_node, Node<T> * m_node);
    
    Node<T> * getHead() const {     return head;    }
    Node<T> * getTail() const {     return tail;    }

	void push_back(T  m_node);
	void push_front(T m_node);
    void push_back(Node<T> * m_node);
    void push_front(Node<T> * m_node);

	Node<T> * pop_back();
	Node<T> * pop_front();

	void removeNode(Node<T> * m_node);
	Node<T> * unlinkNode(Node<T> * m_node);

	void printList();

//	use set to write the record. time O(n), space O(n);
	void removeDuplicateBySet();
//	Bubble idea to check the everyone is duplicate 
//	Time O(n^2)
	void removeDuplicate();

	Node<T> * findLastKthElement(int k);
	void  partitionList(T x);

    Node<T> * findCircularList();
    void isPalidrome();
    bool isPalidromeHelper(Node<T> * next, int deep, Node<T> * middle, int length);

private:
	Node<T> * head;
	Node<T> * tail;
};


template <class T>
MyList<T>::MyList(){
	head = 0;
	tail = 0;
};

template <class T>
MyList<T>::MyList(Node<T> * m_root): head(m_root), tail(m_root){
		// std::cout << "hello " << std::endl;
		// std::cout << "a node is created " << std::endl;
};

template <class T>
MyList<T>::~MyList(){
    // Node<T> * cur = head;
    // Node<T> * beingDelete; 
    // while(cur != 0) {
    //     beingDelete = cur;
    //     cur = cur->getNext();   
    //     delete beingDelete;
    // }
};

template <class T>
const MyList<T> MyList<T>::operator+(const MyList<T> &rhs) const {
    MyList<T> result;

    T carry = 0;
    T reminder = 0;
    Node<T> * lhs_cur = head;
    Node<T> * rhs_cur = rhs.getHead();
    while( lhs_cur != 0 && rhs_cur != 0) {
        reminder = lhs_cur->getData() + rhs_cur->getData() + carry;
        carry = 0;
        if (reminder  < 10)
        {
            result.push_back(reminder);
        }else
        {
            result.push_back(reminder - 10);
            carry = 1;
        }
        lhs_cur = lhs_cur->getNext();
        rhs_cur = rhs_cur->getNext();
    }

        while( lhs_cur != 0) {
            result.push_back( lhs_cur->getData() );
            lhs_cur = lhs_cur->getNext();            
        }
        while( rhs_cur != 0) {
            result.push_back( rhs_cur->getData() );
            rhs_cur = rhs_cur->getNext();
        }

    return result;

}


template <class T>
void MyList<T>::insertNode(Node<T> * insert_after_node, Node<T> * m_node){

	Node<T> * slow = head;
	Node<T> * fast = head->getNext();
	while(fast != 0 && fast != m_node){
		fast = fast->getNext();
		slow = slow->getNext();
	}

	// break the old link
	slow->setNext(m_node->getNext());
	m_node->setNext(insert_after_node->getNext());
	insert_after_node->setNext(m_node);


}

template <class T>
void MyList<T>::push_back(T m_data){

    Node<T> * m_node = new Node<T>(m_data);
	if (head == 0 && tail == 0)
	{
		head = m_node;
		tail = m_node;
	}else{

		tail->setNext(m_node);
		tail = m_node;
	}
}




template <class T>
void MyList<T>::push_front(T m_data){

    Node<T> * m_node = new Node<T>(m_data);

	if (head == 0 && tail == 0)
	{
		head = m_node;
		tail = m_node;
	}else {
		m_node->setNext(head);
		head = m_node;
	}
}

template <class T>
void MyList<T>::push_back(Node<T> * m_node){

    if (head == 0 && tail == 0)
    {
        head = m_node;
        tail = m_node;
    }else{

        tail->setNext(m_node);
        tail = m_node;
    }
}


template <class T>
void MyList<T>::push_front(Node<T> * m_node){

    if (head == 0 && tail == 0)
    {
        head = m_node;
        tail = m_node;
    }else {
        m_node->setNext(head);
        head = m_node;
    }
}


template <class T>
Node<T> * MyList<T>::pop_back(){
	if (head == 0 && tail == 0)
	{
		std::cout << "Empty List" << std::endl;
		return 0;
	}else 
	{

		Node<T> * slow = head;
		Node<T> * fast = slow->getNext();

		while(fast != tail){
			fast = fast->getNext();
			slow = slow->getNext();
		}

		// pop so the tail is going to delete out side the function. 
		tail = slow;
		tail->setNext(0);
		return fast;
	}
}

template <class T>
Node<T> * MyList<T>::pop_front(){
	if ( head == 0 && tail == 0)
	{
		std::cout << "Empty List" << std::endl;
		return 0;
	}else
	{
		Node<T> * result = head;
		head = head->getNext();
		return result;
	}
}


// Node is already found from the list. 
// need a trivial to make sure the linking in the list
template <class T>
void MyList<T>::removeNode(Node<T> * m_node){


	if ( m_node == head && m_node == tail)
	{
		head = 0;
		tail = 0;
	}else if ( m_node == head )
	{
		head = m_node->getNext();
		delete m_node;
	}else{
	
		Node<T> * cur = head;
		while( m_node != cur->getNext() )
			cur = cur->getNext();

		cur->setNext( cur->getNext()->getNext() );

		if ( cur->getNext() == 0)
		{
			tail = cur;
		}

		delete m_node;

	}

}


// remove Node but don't delete it. 
template <class T>
Node<T> * MyList<T>::unlinkNode(Node<T> * m_node){


	if ( m_node == head && m_node == tail)
	{
		head = 0;
		tail = 0;
	}else if ( m_node == head )
	{
		head = m_node->getNext();
		// delete m_node;
	}else{
	
		Node<T> * cur = head;
		while( m_node != cur->getNext() )
			cur = cur->getNext();

		cur->setNext( cur->getNext()->getNext() );

		if ( cur->getNext() == 0)
		{
			tail = cur;
		}
		// delete m_node;
	}

	return m_node;

}



template <class T>
void MyList<T>::printList(){

	Node<T> * cur = head;
	std::cout << "[DEBUG]: Printing List" << std::endl;
	while(cur != 0){
		std::cout << "Now Node: " << cur->getData()
				  << std::endl;
		cur = cur->getNext();
	}
}


// Easy one, use runner. 
// time O(n^2) space O(1)
template <class T>
void MyList<T>::removeDuplicate(){

	if (head == 0)
	{
		std::cout << "[LL]: This is a empty list, nothing to remove" << std::endl;
	}else
	{

		Node<T>  * slow = head;
		Node<T>  * fast; 
		while(slow->getNext() != 0){
			fast = slow->getNext();
			while(fast != 0){

				if (slow->getData() != fast->getData())
				{
					fast = fast->getNext();
				}else
				{
					std::cout << "[LL]: Duplicate Node is removed " << std::endl;
					Node<T> * temp = fast->getNext();
					MyList<T>::removeNode(fast);
					fast = temp;
				}

			}
			slow = slow->getNext();
		}	
	}

}



template <class T>
void MyList<T>::removeDuplicateBySet(){

	std::set<int> record;

	// std::set<int>::iterator it;
	// std::cout << "record contains:";
 //  	for (it=record.begin(); it!=record.end(); ++it)
 //    		std::cout << ' ' << *it;
 //  	std::cout << '\n';



	if (head == 0 && tail == 0)
	{
		std::cout << "[LL]: empty list, nothing to remove" << std::endl;
	}else
	{
	
		Node<T> * cur = head;
		while(cur != 0){

			// std::cout << "DEBUG: " << cur->getData() << " is checking" << std::endl;

			  // std::cout << "record contains:";
			  // for (it=record.begin(); it!=record.end(); ++it)
			  //   std::cout << ' ' << *it;
			  // std::cout << '\n';


			if (record.find(cur->getData()) == record.end())
			{
				// std::cout << "DEBUG: " << cur->getData() << " is not found, add to set" << std::endl;
				record.insert(cur->getData());
				cur = cur->getNext();
			}else
			{
				// std::cout << "DEBUG: " << cur->getData() << " is found, Delete it from List" << std::endl;

				Node<T> * removeHolder = cur;
				cur = cur->getNext();
				MyList<T>::removeNode(removeHolder);

			}
		}
	}
}


template <class T>
Node<T> * MyList<T>::findLastKthElement(int k){
	Node<T> * slow = head;
	Node<T> * fast = slow;
	for (int i = 0; i < k; ++i)
	{
		if (fast != 0)
		{
			fast = fast->getNext();
		}else{
			std::cout << "[DEBUG]: the list size is less than K " << std::endl;
		}
	}

	while(fast != 0){
		fast = fast->getNext();
		slow = slow->getNext();
	}

	std::cout 	<< "[DEBUG]: The " << k 
				<< "Node in the List : "
				<< slow->getData()
				<< std::endl;

	return slow;

}

template <class T>
void  MyList<T>::partitionList(T m_data){


	Node<T> * leftHead = 0;
	Node<T> * leftTail = 0;
	Node<T> * rightHead = 0;
	Node<T> * rightTail = 0;

	// remove the critical one out of list
	// break the link, make it unlink from the old one. 
	// Node<T> * copy_cur = MyList<T>::unlinkNode(x);
	// copy_cur->setNext(0);

    Node<T> * copy_cur;

	Node<T> *	cur = head;
	while(cur != 0){

			std::cout   << "[DEBUG]: testing "          <<  cur->getData()
						<< " Its next: "                <<   cur->getNext()
                        << std::endl;
			copy_cur = MyList<T>::unlinkNode(cur);
			cur = copy_cur->getNext();
			copy_cur->setNext(0);

            // std::cout   << "[DEBUG]: testing "      << cur->getData()
            //             << std::endl;

		if (copy_cur -> getData() < m_data)
		{
			
			if ( leftHead == 0 )
			{
				leftHead = copy_cur;
				leftTail = copy_cur;
			}else
			{
				leftTail->setNext(copy_cur);
				leftTail = copy_cur;
			}
		}else if ( copy_cur->getData() == m_data )
        {
            copy_cur->setNext(rightHead);
            rightHead = copy_cur;

        }else
		{

            if ( rightHead == 0 )
            {
                rightHead = copy_cur;
                rightTail = copy_cur;

            }else
            {
                rightTail->setNext(copy_cur);
                rightTail = copy_cur;
            }

		}

	}
	// connnect two list in to one. 
	leftTail->setNext(rightHead);
	head = leftHead;
	tail = rightTail;

}

template <class T>
Node<T> * MyList<T>::findCircularList(){
    Node<T> * slow = head;
    Node<T> * fast = slow;

   while(fast != 0 && fast->getNext() != 0) {

        std::cout   << "Debug:  slow    :   "   << slow->getData()  << std::endl; 
        std::cout   << "Debug:  fast    :   "   << fast->getData()  << std::endl; 
        slow = slow->getNext();
        fast = fast->getNext()->getNext();

        if (slow == fast)
            break;

    } 

    if (fast == 0 || fast->getNext() == 0)
    {
        std::cout   <<  "Debug: This is not a circular list" <<    std::endl;
        return 0;
    }else
    {

        slow = head; 
        while(slow != fast) {
        
            std::cout   << "Debug:  slow   check:   "   << slow->getData()  << std::endl; 
            std::cout   << "Debug:  fast   check:   "   << fast->getData()  << std::endl; 

            slow = slow->getNext();
            fast = fast->getNext();

        }
        std::cout   <<  "Debug: The first Node start the circular List is " << fast->getData()
                    <<  " addr : "  <<  fast
                    <<  std::endl;

        return fast;
    }



}


template <class T>
void MyList<T>::isPalidrome(){
    // recursion. 
    // if I use the middle point as deep 0, recursion to the middle
    Node<T> * cur = head;
    int length = 0;
    while(cur != 0) {
        ++length;
        cur = cur->getNext();
    }

    // std::cout   << "DEBUG: the length is "    << length    << std::endl;
    int deep = length/2;
    // std::cout   << "DEBUG: the deep is "    << deep    << std::endl;
    cur = head;
    for (int i = 0; i < deep; ++i)
    {
        cur = cur->getNext();
    }

    if (length%2)
    {
        cur = cur->getNext();
    }
    // std::cout   << "DEBUG: the middle is "    << cur->getData()    << std::endl;

    bool test = isPalidromeHelper(head, deep -1, cur, length);
    std::cout << (test ? "It is Palidrome" : " It is not Palidrome") << std::endl;


}

template <class T>
bool MyList<T>::isPalidromeHelper(Node<T> * next, int deep, Node<T> * middle, int length){
 
    // std::cout   <<  "DEBUG: in stack "   << next->getData()
    //             <<  " Deep : "           <<  deep
    //             <<  " Middle: "          <<  middle->getData()
    //             <<  std::endl;

    if (deep == 0)
    {
        Node<T> * cur = middle;
        for (int i = 0; i < deep; ++i)
        {
            cur = cur->getNext();
        }
        if ( next->getData() != cur->getData())
        {
            // std::cout << "DEBUG: A false return at " << deep    << std::endl;
            return false;
        }else{
            // std::cout << "DEBUG: A true return at " << deep    << std::endl;
            return true;
        }

    }

    bool goUpper = MyList<T>::isPalidromeHelper(next->getNext(), deep - 1, middle, length);
    
    if (goUpper)
    {
        // std::cout   << "DEBUG: pop up the stack"    <<  std::endl;
        Node<T> * cur = middle;
        for (int i = 0; i < deep; ++i)
        {
            cur = cur->getNext();
        }
        // std::cout   << "DEBUG: middle is : "    <<   middle->getData()  <<   std::endl;
        // std::cout   << "DEBUG: cur is : "       <<   cur->getData()  <<   std::endl;
        // std::cout   << "DEBUG: next is : "      <<   next->getData()  <<   std::endl;

        if ( next->getData() != cur->getData())
        {
            return false;
        }else{
            return true;
        }

    }else
    {
        return false;
    }

}


#endif


