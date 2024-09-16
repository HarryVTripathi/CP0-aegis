Node* merge(Node* p1, Node* p2)
{
    if (p1 == NULL && p2 == NULL) {
        return NULL;
    }
    
    if (p1 == NULL) {
        return p2;
    }
    
    if (p2 == NULL) {
        return p1;
    }
    
    if (p1->data <= p2->data) {
        p1->next = merge(p1->next, p2);
        return p1;
    } else {
        p2->next = merge(p1, p2->next);
        return p2;
    }
}

Node* sortedMerge(Node* head_A, Node* head_B)  
{  
    Node *travA = head_A, *travB = head_B;
    return merge(travA, travB);
}