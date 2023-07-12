#include <iostream>
using namespace std;

class Rectangle{
    private:
        int length;
        int breadth;
    public:
    Rectangle(){   // default constructor
        length = 0;
        breadth = 0;
    }
    Rectangle(int l,int b){   //parameterized constructor (constructor overloading)
        length = l;
        breadth = b;
    }
    int area(){
        return length*breadth;
    }
    int perimeter(){
        return 2*(length+breadth);
    }
    void setLength(int l){
        length = l;
    }
    void setBreadth(int b){
        breadth = b;
    }
    int getLength(){
        return length;
    }
    int getBreadth(){
        return breadth;
    }
    ~Rectangle(){
        cout<<"Destructor"<<endl;
    }
};

int main(){
    Rectangle r(10,5);
    cout<<"Area is: "<<r.area()<<endl;
    cout<<"Perimeter is: "<<r.perimeter()<<endl;

    return 0;
}

