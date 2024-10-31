# Data Structures and Algorithms

## Overview

This repository contains implementations and explanations of various data structures and algorithms. Each data structure includes details about its time complexity for common operations and typical use cases.

---

## Table of Contents

1. [Arrays](#arrays)
2. [Linked Lists](#linked-lists)
   - [Singly Linked List](#singly-linked-list)
   - [Doubly Linked List](#doubly-linked-list)
3. [Stacks](#stacks)
   - [Array-Based Stack](#array-based-stack)
   - [Linked List-Based Stack](#linked-list-based-stack)
4. [Queues](#queues)
   - [Array-Based Queue](#array-based-queue)
   - [Linked List-Based Queue](#linked-list-based-queue)
5. [Trees](#trees)
6. [Graphs](#graphs)
7. [Hash Tables](#hash-tables)
8. [Sorting Algorithms](#sorting-algorithms)
9. [Searching Algorithms](#searching-algorithms)

---

## Arrays

### Description
An array is a collection of elements stored in contiguous memory locations, allowing fast access by index.

### Time Complexity
- Access: O(1)
- Search: O(n)
- Insertion: O(n) (at arbitrary position)
- Deletion: O(n)

### Common Operations
- Accessing elements
- Inserting elements
- Deleting elements
- Traversing the array

---

## Linked Lists

### Description
A linked list is a sequence of nodes where each node contains data and a reference to the next node.

### Time Complexity
- Access: O(n)
- Search: O(n)

### Common Operations
- Inserting nodes (at head, tail, or specific position)
- Deleting nodes
- Searching for a value
- Traversing the list

### Singly Linked List

#### Description
A singly linked list allows traversal in one direction, from the head to the tail.

#### Time Complexity
- Insertion: O(1) (at head/tail)
- Deletion: O(1) (at head), O(n) (searching for the node)

#### Common Operations
- Insert at head/tail
- Delete at head/tail
- Search for a value
- Traverse the list

### Doubly Linked List

#### Description
A doubly linked list contains nodes with references to both the next and previous nodes, allowing traversal in both directions.

#### Time Complexity
- Insertion: O(1) (at head/tail)
- Deletion: O(1) (at head/tail), O(n) (searching for the node)

#### Common Operations
- Insert at head/tail
- Delete at head/tail
- Search for a value
- Traverse the list (forward and backward)

---

## Stacks

### Description
A stack is a Last In, First Out (LIFO) data structure where elements are added and removed from the top.

### Time Complexity
- Push: O(1)
- Pop: O(1)
- Peek (Top): O(1)

### Common Operations
- Push (add an element)
- Pop (remove the top element)
- Peek (view the top element without removing it)

#### Array-Based Stack

##### Description
An array-based stack uses an array to store elements.

##### Time Complexity
- Push: O(1)
- Pop: O(1)
- Peek: O(1)

#### Linked List-Based Stack

##### Description
A linked list-based stack uses a linked list to store elements, allowing dynamic memory allocation.

##### Time Complexity
- Push: O(1)
- Pop: O(1)
- Peek: O(1)

---

## Queues

### Description
A queue is a First In, First Out (FIFO) data structure where elements are added at the back and removed from the front.

### Time Complexity
- Enqueue: O(1)
- Dequeue: O(1)
- Peek (Front): O(1)

### Common Operations
- Enqueue (add an element to the back)
- Dequeue (remove an element from the front)
- Peek (view the front element without removing it)

#### Array-Based Queue

##### Description
An array-based queue uses an array to store elements and requires a fixed size.

##### Time Complexity
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)

#### Linked List-Based Queue

##### Description
A linked list-based queue uses a linked list to store elements, allowing dynamic memory allocation.

##### Time Complexity
- Enqueue: O(1)
- Dequeue: O(1)
- Peek: O(1)

### Common Operations
- Enqueue (add an element)
- Dequeue (remove an element)
- Peek (view the front element without removing it)

---

## Trees

### Description
A tree is a hierarchical data structure with nodes connected by edges. Each tree has a root node, and each node can have children.

### Time Complexity
- Access: O(log n) (for balanced trees)
- Search: O(log n) (for balanced trees)
- Insertion: O(log n) (for balanced trees)
- Deletion: O(log n) (for balanced trees)

### Common Operations
- Inserting nodes
- Deleting nodes
- Searching for a value
- Traversing (in-order, pre-order, post-order)

---

## Graphs

### Description
A graph is a collection of nodes (vertices) and edges connecting pairs of nodes.

### Time Complexity
- Adding a vertex: O(1)
- Adding an edge: O(1) (for adjacency list), O(V) (for adjacency matrix)
- Searching: O(V + E) (BFS/DFS)

### Common Operations
- Adding/removing vertices
- Adding/removing edges
- Traversing (BFS, DFS)
- Finding shortest paths (Dijkstra, Bellman-Ford)

---

## Hash Tables

### Description
A hash table is a data structure that stores key-value pairs for efficient data retrieval.

### Time Complexity
- Access: O(1) (average case)
- Insertion: O(1) (average case)
- Deletion: O(1) (average case)

### Common Operations
- Inserting key-value pairs
- Deleting key-value pairs
- Retrieving values by key
- Handling collisions (chaining, open addressing)

---

## Sorting Algorithms

### Description
Sorting algorithms arrange elements in a specific order (ascending or descending).

### Common Algorithms
- Bubble Sort: O(n²)
- Selection Sort: O(n²)
- Insertion Sort: O(n²)
- Merge Sort: O(n log n)
- Quick Sort: O(n log n) (average case)

### Operations
- Sorting an array or list of elements

---

## Searching Algorithms

### Description
Searching algorithms retrieve an element from a data structure.

### Common Algorithms
- Linear Search: O(n)
- Binary Search: O(log n) (requires a sorted array)

### Operations
- Finding an element in a collection

---

## Conclusion

This README provides a high-level overview of common data structures and algorithms, including their time complexities and operations. For more detailed implementations and examples, please refer to the specific files in this repository.

---
