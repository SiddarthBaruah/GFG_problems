/*
Collision can be handeled in two ways:

0. Chaining
1. Open Adressing
    i. Linear Probling
    ii. Quadratic Probling
    iii. Double Hashing


0. Chaining
    Example we have to store phone numbers
    998-xxx-xxxx-07
    998-xxx-xxxx-08
    998-xxx-xxxx-01
    998-xxx-xxxx-02
    998-xxx-xxxx-11 
    
    and our Hash function is:- 
        index= number%9;
    so for sure the number ending with 00 and 11 , will come in the same index
    so for that we will creat a chain

    These chains can be created by three methods:
        0. Linked List
        1. Dynamic sized array
        2. Self Balancing BST( AVL tree, Red Block tree)
            i. Preferebly use this since it has O(log(n)) for search insert and delete

    So the elements in the same index(also now called nodes) will be contained in the node.

*/