#include <iostream>
#include <map>
using namespace std;
// 在此处补充你的代码
class A {

public:
	int value;
public:
        static int count;	
public:
	A() {
	    count++;
	}
	A(int k) :value(k) {
	    count++;
	}
        virtual ~A() {
            count--;
	    std::cout << "A::desctructor" << endl;
	}
};

class B :public A {
public:
	B(int k) : A(k) {
	}
	B(B& b): A(b.value) {
	
	}
	~B() {
	    std::cout<< "B::desctructor" << endl;    
	}
};

int A::count = 0;

void func(B b) { }
int main()
{
        A a1(5),a2;
        cout << A::count << endl;
        B b1(4);
        cout << A::count << endl;
        func(b1);
        cout << A::count << endl;
        A * pa = new B(4);
        cout << A::count << endl;
        delete pa;
        cout << A::count << endl;
        return 0;
}
// declare the destructor function of A as virtual function, when polymorphism is used, the sub class been destructed will automatically call the parent's desctructor.
