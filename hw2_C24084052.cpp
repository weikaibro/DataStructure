#include <iostream>
#include <ctime>
using namespace std;

template <class T> class circularChain;

template <class T> class circularChainNode {
  friend class circularChain <T>;
  private:
    T data;
    circularChainNode <T> *link;

  public:
    circularChainNode(const T& D) {
      this->data = D;
      this->link = NULL;
    }
    void setNextNode(circularChainNode<T> *nextNode) {
      this->link = nextNode;
    }
    char const printNode() {
      return this->data;
    }
};

template <class T> class circularChain {
  private:
    circularChainNode <T> *first;

  public:
    circularChain() {
      first = 0;
    }
    void setFirstNode(circularChainNode<T> *node) {
      this->first = node;
    }
    char printCurrentNode(int pos) {
      circularChainNode<T> *curNode = this->first;
      for (int i = 0; i < pos; i++) {
        if (curNode->link == NULL) {
          curNode->link = first;
          break;
        }
        curNode = curNode->link;
      }
      return curNode->printNode();
    }

    // printList: print all Node's data one by one
    void printList(int playerNum) {
      circularChainNode<T> *curNode = this->first;
      int counter = 0;
      while(curNode) {
        cout << curNode->printNode() << " ";
        curNode = curNode->link;
        counter++;
        if (counter == playerNum) {
          break;
        }
      }
      cout << endl;
    }

    // getNode: get(return) the Node at the specific position
    circularChainNode <T> * getNode(int pos) {
      circularChainNode <T> *target = this->first;
      for (int i = 0; i < pos; i++) {
        // if the pos is much bigger then Chain's len, we break and return the last node
        if(target->link == NULL) {
          break;
        }
        target = target->link;
      }
      return target;
    }

    // insert a new Node in the specific position
    void insertNode(int pos, T data) {
      circularChainNode <T> *newNode = new circularChainNode <T> (data);
      circularChainNode <T> *target = getNode(pos);
      if (pos == 0) {
        newNode->link = target;
        this->first = newNode;
      } else {
        circularChainNode <T> *prev = getNode(pos-1);
        circularChainNode <T> *tmp = prev->link;
        prev->link = newNode;
        newNode->link = tmp;
      }
    }

    // delete the Node in the specific position
    void deleteNode(int pos) {
      circularChainNode <T> *target = getNode(pos);
      if ((pos-1) < 0) {    // no beforeNode, we delete the first one
        this->first = this->first->link;
      } else {
        circularChainNode <T> *prev = getNode(pos-1);
        prev->link = target->link;
      }
    }
};

int main() {
  double seed = time(NULL);
  srand(seed);
  circularChainNode <char> *fn = new circularChainNode <char> ('A');   // first node
  circularChain <char> *LS = new circularChain<char>;  // linked list named LS

  // Gaming initializer
  int curPlayerNum;
  cout << "How many players engage in this game: ";
  cin >> curPlayerNum;
  LS->setFirstNode(fn);
  for (int i = 1; i < curPlayerNum; i++) {
    LS->insertNode(i, char(65 + i));
  }
  cout << "Total players: ";
  LS->printList(curPlayerNum);
  cout << endl;

  // Gaming record
  int originPlayer = curPlayerNum;
  int gameRound = 1;
  int bombPos = 0;
  int bombMov;
  int index = -1;
  char gameLoserArr[curPlayerNum];
  while (true) {
    bombMov = rand() % 4;

    // Deliver the bomb
    cout << "Round " << gameRound << ", begin from player " << LS->printCurrentNode(bombPos);
    cout << ", deliver the bomb to the next " << bombMov << " person, player ";
    bombPos += bombMov;
    while (bombPos >= curPlayerNum) {
      bombPos -= curPlayerNum;
    }
    cout << LS->printCurrentNode(bombPos) << "." << endl;

    // Bomb explosion handler
    if (rand() % 10 < 4) {  // explode
      cout << "Exploded... " << endl;
      cout << "player " << LS->printCurrentNode(bombPos);
      cout << " out, remain " << --curPlayerNum << " players!" << endl;
      gameLoserArr[++index] = LS->printCurrentNode(bombPos);
      LS->deleteNode(bombPos);
    } else {  // safe
      cout << "Safe..." << endl;
    }

    // Remain players 
    cout << "Remaining players: ";
    LS->printList(curPlayerNum);
    cout << "---" << endl;
    gameRound++;
    while (bombPos >= curPlayerNum) {
      bombPos -= curPlayerNum;
    }


    // Game over (then break this while-loop)
    if (curPlayerNum == 1) {
      cout << "Loser order: ";
      for (int i = 0; i < originPlayer - 1; i++) {
        cout << gameLoserArr[i];
        if (i != originPlayer - 2) {
          cout << " -> ";
        }
      }
      cout << "\nWinner: ";
      LS->printList(curPlayerNum);
      cout << endl;
      
      break;
    }

  }

  system("pause");

  return 0;
}