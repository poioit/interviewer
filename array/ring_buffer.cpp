//https://www.embedded.com/electronics-blogs/embedded-round-table/4419407/The-ring-buffer
//http://www.cs.utsa.edu/~wagner/CS2213/queue/queue.html
https://stackoverflow.com/questions/590069/how-would-you-code-an-efficient-circular-buffer-in-java-or-c-sharp

#include <iostream>
#include <vector>
using namespace std;

class RingBuffer{
private:
   int qMaxSize;// max queue size
   int tail = 0;  // front pointer
   int head = 0;  // rear pointer
   int qs = 0;  // size of queue
   vector<char> q;    // actual queue
public:
   RingBuffer(int size) {
      qMaxSize = size;
      tail = 0;
      head = 0;
      qs = 0;
      q = vector<char>(size);
   }

   char pop() {
      if (!empty()) {
         qs--;
         tail = (tail + 1)%qMaxSize;
         cout << "pop:" << q[tail] << endl;
         return q[tail];
      }
      else {
         cout << "Underflow" << endl;;
         return '/0';
      }
   }

   void push(char c) {
      if (!full()) {
         qs++;
         head = (head + 1)%qMaxSize;
         q[head] = c;
         cout << "Push done: " << c << endl;
      }
      else
         cout << "Overflow: " << c << endl;;
   }

   bool empty() {
      return qs == 0;
   }

   bool full(){
      return qs == qMaxSize;
   }

   void dump() {
      cout << "Size: " << qs <<
         ", head: " << head << ", tail: " << tail << ", q: ";
      for (int i = 0; i < qMaxSize; i++)
         cout << "q[" << i << "]=" << q[i] << "; ";
      cout << endl;;
   }
};


int main() {
    RingBuffer q(3);
    q.dump();
    q.push('a');
    q.push('b');
    q.push('c');
    q.push('d');
    q.dump();
    q.pop();
    q.dump();
    q.push('d');
    q.push('e');
    q.dump();
	return 0;
}
