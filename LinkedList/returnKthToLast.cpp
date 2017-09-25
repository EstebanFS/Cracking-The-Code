#include <iostream>

using namespace std;

/*
  Description: Implement an algorithm to find the kth element to last element
               of a single linked list.

  Time Complexity: O(n)
  Space Complexity: O(1)
*/

#define D(x) cout << #x << " = " << x << endl;

struct Node {
    Node *next;
    int data;
};

int returnKthElement(Node *head, int k) {
  Node *firstHead = head;
  Node *secondHead = head;
  int index = 1;
  while(firstHead -> next != NULL && index < k) {
    firstHead = firstHead -> next;
    index++;
  }
  while(firstHead -> next != NULL) {
    firstHead = firstHead -> next;
    secondHead = secondHead -> next;
  }
  return secondHead -> data;
}

void printLinkedList(Node *head) {
  Node *currNode = head;
  while(currNode != NULL) {
    cout << currNode -> data << " -> ";
    currNode = currNode -> next;
  }
  cout << endl;
}

int main() {
  int m, data, k;
  cin >> m;
  Node *head = new Node;
  Node *currNode = head;
  for(int i = 0; i < m; ++i) {
    cin >> data;
    if(!i) {
      head -> data = data;
      head -> next = NULL;
    } else {
      Node *nextNode = new Node;
      nextNode -> data = data;
      nextNode -> next = NULL;
      currNode -> next = nextNode;
      currNode = nextNode;
    }
  }
  cin >> k;
  cout << returnKthElement(head, k) << endl;
  printLinkedList(head);
  return 0;
}
