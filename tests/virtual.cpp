#include<iostream>

using namespace std;

class A {
    public :
        virtual void say(){}
};

class B : public A{
    public :
        void say () override{
            cout << "Said by B";
        }
};

int main(){
    A* a = new B();

    a->say();
    return 0;
}