#include <iostream>



// template <class T> class Stack;
template <class T>
class Stack {
    friend Stack <T> operator +<>( const Stack <T> &s1 , const Stack <T> &s2);
    std::vector<T> items;
    public:
        bool Stack::empty() {return items.empty();}
        void Stack::push(const T &item) {items.push_back(item)};
        T pop() {
            T last = items.back();
            items.pop_back();
            return last;
        }
};

template <class T>
    Stack<T> operator+(const Stack<T> &s1,const Stack<T> &s2)
    {
        Stack<T> final_stack = s1;
        for(int i=0;i<s1.items.size();i++)
        {
            final_stack.push(s2.items[i]);
        }
        return final_stack;
    }

