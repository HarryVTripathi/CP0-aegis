struct Node* partialClone(struct Node** trav, struct Node** cloneHead, struct Node** cloneCurr) {
    if (*cloneHead == NULL) {
        *cloneHead = new Node((*trav)->data);
        *cloneCurr = *cloneHead;
    } else {
        (*cloneCurr)->next = new Node((*trav)->data);
        (*cloneCurr) = (*cloneCurr)->next;
    }
}

struct Node* partition(struct Node* head, int x)
{
    Node* trav1 = head;
    Node* trav2 = head;
    Node* trav3 = head;
    Node* cloneHead = NULL;
    Node* cloneCurr = NULL;
    
    while (trav1 != NULL) {
        if(trav1->data < x) partialClone(&trav1, &cloneHead, &cloneCurr);
        trav1 = trav1->next;
    }
    
    while (trav2 != NULL) {
        if(trav2->data == x) partialClone(&trav2, &cloneHead, &cloneCurr);
        trav2 = trav2->next;
    }
    
    while (trav3 != NULL) {
        if(trav3->data > x) partialClone(&trav3, &cloneHead, &cloneCurr);
        trav3 = trav3->next;
    }
    return cloneHead;
}



// https://practice.geeksforgeeks.org/problems/partition-a-linked-list-around-a-given-value/1