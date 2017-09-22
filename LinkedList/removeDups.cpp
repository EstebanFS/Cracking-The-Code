#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

/*
  Description: Write code to remove duplicates from an unsorted linked list;

  Time Complexity: O(n);
  Space Complexity: O(n);
*/

#define D(x) cout << #x << " = " << x << endl

struct Node {
  Node* next;
  int data;
};

Node* removeDups(Node *head) {
  if(head -> next == NULL) return head;
  unordered_set<int> elements;
  Node *lastNode = head;
  Node *currNode = head -> next;
  while(currNode != NULL) {
    if(elements.count(currNode -> data)) {
      lastNode -> next = currNode -> next;
    } else {
      elements.insert(currNode -> data);
      lastNode = currNode;
    }
    currNode = currNode -> next;
  }
  return head;
}

void printList(Node* head) {
  Node* currNode = head;
  while(currNode != NULL) {
    cout << currNode -> data << " - > ";
    currNode = currNode -> next;
  }
  cout << endl;
}

int main() {
  Node *head = new Node;
  Node *currNode = head;
  head -> data = 0;
  int n, currData;
  cin >> n;
  for(int i = 0; i < n; ++i) {
    cin >> currData;
    Node *newNode = new Node;
    newNode -> data = currData;
    currNode -> next = newNode;
    currNode = newNode;
  }
  head = removeDups(head);
  D("bien");
  printList(head);
}
