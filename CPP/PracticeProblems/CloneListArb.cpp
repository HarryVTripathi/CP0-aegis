// TBD

int getLength(Node *head) {
    if (head == NULL) return 0;
    
    return 1 + getLength(head->next);
}

Node* cloneNextPointers(Node* head) {
    Node* cloneHead;
    Node* curr;
    Node* trav = head;
    
    while (trav != NULL) {
        if (trav == head) {
            curr = new Node(head->data);
            curr->arb = head->arb == NULL ? NULL : head->arb;
            cloneHead = curr;
        } else {
            curr->next = new Node(trav->data);
            curr = curr->next;
            curr->arb = trav->arb == NULL ? NULL : trav->arb;
        }
        trav->arb = curr;
        trav = trav->next;
    }
    
    return cloneHead;
}

Node *copyList(Node* head) {
    Node* cloneHead = cloneNextPointers(head);
    
    Node *trav = head, *cloneTrav = cloneHead;
    
    while (trav != NULL || cloneTrav != NULL) {
        if (trav->arb == cloneTrav) {
            trav->arb = trav->arb->arb;
        }
    
        if (cloneTrav->arb != NULL) {
            cloneTrav->arb = cloneTrav->arb->arb;
        }

        trav = trav->next;
        cloneTrav = cloneTrav->next;
    }
    
    cout << "org len: " << getLength(head) << endl;
    cout << "clone len: " << getLength(cloneHead) << endl;
    
    if (head == cloneHead) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }
    
    Node *t = head, *u = cloneHead;
    
    while (t != NULL || u != NULL) {
        if (t == u) {
            cout << "F T1" << endl;
        }
        
        if (t->data != u->data) {
            cout << "F T2" << endl;
        }

        if (t->arb != NULL && u->arb != NULL) {
            if (t->arb == u->arb) {
                cout << "F T3" << endl;
            }
            
            if (t->arb->data != u->arb->data) {
                cout << "F T4" << endl;
            }
        }
        t = t->next;
        u = u->next;
    }
    
    t = cloneHead;
    while (t != NULL) {
        if (t->arb != NULL) {
            cout << "(" << t->arb->data <<  ")";
        }
        cout << t->data << "->";
        t = t->next;
    }
    

    return cloneHead;
}