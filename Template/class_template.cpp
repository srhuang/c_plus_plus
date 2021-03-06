#include <iostream>
using namespace std;

template<class T>
class myStack
{
public:
	myStack(int = 10); // default size = 10

	~myStack()
	{
		delete stack_p;
	}

	bool push (const T&);
	bool pop (T&);

	bool isEmpty() const //const function could NOT change any member
	{
		return (-1 == top);
	}

	bool isFull() const
	{

		return (top == size-1);
	}

private:
	int size;
	int top;
	T *stack_p;

};

//Implementation
template<class T>
myStack<T>::myStack(int s)
{
	size = s>0 ? s : 10;
	top = -1;
	stack_p = new T[size];
}

template<class T>
bool myStack<T>::push (const T &value)
{
	if ( ! isFull())
	{
		stack_p[++top] = value;
		return true;
	}

	return false;
}

template<class T>
bool myStack<T>::pop (T &value)
{
	if ( ! isEmpty())
	{
		value = stack_p[top--];
		return true;
	}

	return false;

}

int main ()
{
	myStack<int> AAA(20);

	cout << "Pushing INT into myStack..." << endl;
	int a = 0;
	while ( AAA.push(a))
	{
		cout << a << ' ';
		a++;
	}
	cout << endl;

	cout << "Poping INT from myStack..." << endl;
	while (AAA.pop(a))
	{
		cout << a << ' ';
	}
	cout << endl;

	

}