//Method 1 (Divide the space in two halves) 

#include <iostream>
#include <stdlib.h>

using namespace std;

class twoStacks {
	int* arr;
	int size;
	int top1, top2;

public:
	// Constructor
	twoStacks(int n)
	{
		size = n;
		arr = new int[n];
		top1 = n / 2 + 1;
		top2 = n / 2;
	}

	// Method to push an element x to stack1
	void push1(int x)
	{
		// There is at least one empty
		// space for new element
		if (top1 > 0) {
			top1--;
			arr[top1] = x;
		}
		else {
			cout << "Stack Overflow"
				<< " By element :" << x << endl;
			return;
		}
	}

	// Method to push an element
	// x to stack2
	void push2(int x)
	{

		// There is at least one empty
		// space for new element
		if (top2 < size - 1) {
			top2++;
			arr[top2] = x;
		}
		else {
			cout << "Stack Overflow"
				<< " By element :" << x << endl;
			return;
		}
	}

	// Method to pop an element from first stack
	int pop1()
	{
		if (top1 <= size / 2) {
			int x = arr[top1];
			top1++;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}

	// Method to pop an element
	// from second stack
	int pop2()
	{
		if (top2 >= size / 2 + 1) {
			int x = arr[top2];
			top2--;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}
};

/* Driver program to test twoStacks class */
int main()
{
	twoStacks ts(5);
	ts.push1(5);
	ts.push2(10);
	ts.push2(15);
	ts.push1(11);
	ts.push2(7);
	cout << "Popped element from stack1 is "
		<< " : " << ts.pop1()
		<< endl;
	ts.push2(40);
	cout << "\nPopped element from stack2 is "
		<< ": " << ts.pop2()
		<< endl;
	return 0;
}



/*Output: 

Stack Overflow By element :7
Popped element from stack1 is  : 11
Stack Overflow By element :40
Popped element from stack2 is : 15
	
	
	
	Complexity Analysis: 

Time Complexity: 
Push operation : O(1)
Pop operation : O(1)
Auxiliary Space: O(N). 
Use of array to implement stack so. It is not the space-optimized method as explained above. */




#include <iostream>
#include <stdlib.h>

using namespace std;

class twoStacks {
	int* arr;
	int size;
	int top1, top2;

public:
	twoStacks(int n) // constructor
	{
		size = n;
		arr = new int[n];
		top1 = -1;
		top2 = size;
	}

	// Method to push an element x to stack1
	void push1(int x)
	{
		// There is at least one empty space for new element
		if (top1 < top2 - 1) {
			top1++;
			arr[top1] = x;
		}
		else {
			cout << "Stack Overflow";
			exit(1);
		}
	}

	// Method to push an element x to stack2
	void push2(int x)
	{
		// There is at least one empty
		// space for new element
		if (top1 < top2 - 1) {
			top2--;
			arr[top2] = x;
		}
		else {
			cout << "Stack Overflow";
			exit(1);
		}
	}

	// Method to pop an element from first stack
	int pop1()
	{
		if (top1 >= 0) {
			int x = arr[top1];
			top1--;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}

	// Method to pop an element from second stack
	int pop2()
	{
		if (top2 < size) {
			int x = arr[top2];
			top2++;
			return x;
		}
		else {
			cout << "Stack UnderFlow";
			exit(1);
		}
	}
};

/* Driver program to test twoStacks class */
int main()
{
	twoStacks ts(5);
	ts.push1(5);
	ts.push2(10);
	ts.push2(15);
	ts.push1(11);
	ts.push2(7);
	cout << "Popped element from stack1 is "
		<< ts.pop1();
	ts.push2(40);
	cout << "\nPopped element from stack2 is "
		<< ts.pop2();
	return 0;
}
