// Problem statement
// Create a stack data structure that allows operations such as push (adding an element), pop (removing the top element), top (retrieving the top element), and also provides a way to retrieve the minimum element in constant time.



// Implement the following public functions :

// 1. push(data) :
// This function should take one argument of type integer. It pushes the element into the stack and returns nothing.

// 2. pop() :
// It pops the element from the top of the stack and returns nothing.

// 3. top() :
// It returns the element being kept at the top of the stack.

// 4.  getMin() :
// It returns the smallest element present in the stack.
// Operations Performed on the Stack:
// Query-1(Denoted by an integer 1): Pushes integer data to the stack. (push function)

// Query-2(Denoted by an integer 2): Pops the data kept at the top of the stack. (pop function)

// Query-3(Denoted by an integer 3): Fetches and returns the data being kept at the top of the stack. (top function)

// Query-4(Denoted by an integer 4): Returns the smallest element present in the stack. (getMin() function)

class SpecialStack {
  stack<int> s;
  int mini = INT_MAX;
  /*----------------- Public Functions of SpecialStack -----------------*/
public:
  void push(int data) {
    // for first element
    if (s.empty()) {
      s.push(data);
      mini = data;
    } else {
      if (data < mini) {
        s.push(2 * data - mini);
        mini = data;
      } else {
        s.push(data);
      }
    }
  }

  int pop() {
    if (s.empty()) {
      return -1;
    }

    int curr = s.top();
    s.pop();
    if (curr > mini) {
      return curr;
    } else {
      int prevMin = mini;
      int val = 2 * mini - curr;
      mini = val;
      return prevMin;
    }
  }

  int top() {
    if (s.empty())
      return -1;

    int curr = s.top();
    if (curr < mini) {
      return mini;
    } else {
      return curr;
    }
  }

  bool isEmpty() { return s.empty(); }

  int getMin() {
    if (s.empty())
      return -1;

    return mini;
  }
};