#include<iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) {}
};

ListNode* reverseList(ListNode* head) {
    if(head == NULL) return head; // this is for empty list
    if(head->next == NULL) return head; // this will be the last node
    ListNode* curr = reverseList(head->next); // return a pointer of the reversed next node
    head->next->next = head; // h->n->... to h<->n
    head->next = NULL; // h <- n
    return curr; 
}

ListNode* iterate(ListNode* head) {
    if(head == NULL) return head; // handle empty list
    ListNode *prev = head;
    ListNode* curr = head->next;
    ListNode *tmpNext;
    while(curr != NULL) {
        tmpNext = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmpNext;
    }
    head->next = NULL;
    return prev; 
}

// 1->2->3->NULL
// 3->NULL
// curr = [3]
// from 2->3->NULL to 2<->3..NULL to 2<-3 ... NULL
// return 3
// List now look like this 1->2<-3

// head is 1
// curr is 3
// 1->2<-3 to 1 <-> 2 <-3 to 1 <- 2 <- 3
// NULL <- 1 <- 2 <- 3
// return 3