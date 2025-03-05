template <typename T>
struct ListNode
{
  ListNode<T> *prev; 
  ListNode<T> *next; 
  T datum;
};

int main()
{
  // Generate ListNode where T is an int...
  ListNode<int> a;
  a.prev = a.next = nullptr; 
  a.datum = 34;

  // Generate ListNode where T is a ListNode<char>...
  ListNode< ListNode<int> > b;
  b.prev = b.next = nullptr; 
  b.datum = a;
}
