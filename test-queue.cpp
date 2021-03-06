#pragma once
//lang::Cpp
#include "queue.h"
#include "string.h"
#include <cassert>

// main entry point for program
int main()
{
	Queue test_queue = Queue();
	Queue test_queue_2 = Queue();
	Object* elem_1 = new Object();

	assert(test_queue.is_empty());
	assert(test_queue.equals(&test_queue_2));

	test_queue.enqueue(elem_1);

	assert(test_queue.size() == 1);
	assert(!test_queue.equals(&test_queue_2));

	Object* removed_elem = test_queue.dequeue();

	assert(elem_1->equals(removed_elem));
	assert(test_queue.is_empty());
	assert(test_queue.equals(&test_queue_2));
	
	for (int i = 0; i < 10; i++)
	{
		Object* o = new Object();
		test_queue.enqueue(o);
	}

	assert(test_queue.size() == 10);

	test_queue.clear();
	
	assert(test_queue.is_empty());

	String* s_1 = new String("");
	String* s_2 = new String("");

	test_queue.enqueue(s_1);
	test_queue.enqueue(s_2);
	test_queue.enqueue(elem_1);

	assert(test_queue.size() == 3);
	assert(!test_queue.equals(&test_queue_2));

    String* s_3 = new String("hello");
    String* s_4 = new String("world");
    Queue test_queue_3 = Queue();
    test_queue_3.enqueue(s_3);
    test_queue_3.enqueue(s_4);
    Object* peeked_elem = test_queue_3.peek();
    assert(s_3->equals(peeked_elem));
    Object* removed_elem_2 = test_queue_3.dequeue();
    
    // delete this since the queue no longer handles this
    delete removed_elem_2;

    peeked_elem = test_queue_3.peek();
    assert(s_4->equals(peeked_elem));

	return 0;
}
