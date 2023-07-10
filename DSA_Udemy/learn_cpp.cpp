#include <iostream>
#include <string>
using namespace std;

//consteval will work only from c++20 onwards...
/*consteval int func1_get_value(){
    return 3;
}*/

int func2_sum(int x,int y){
    int sum = x+y;
    return sum;
}

//while creating functions, in its definition use & to make it call by reference. Here a will act as reference to the variable being passed while calling the function
//no changes are to be made to the body of the function or for the calling statement. simple do func3(x) where x is a variable.Now changes made to 'a' will reflect for x variable.
int func3(int &a){
    a=25;
    return a;
}

void func4(int A[],int n){
//array cannot be passed by value at all in C or C++. array A is passed by address
}

void func5(int *A, int n){
//Here A can be used to point to an integer as well as the beginning of an array. Generally, use A[] for conveniance.
}

int * func6(int n){
    //Here the function creates an array on the heap and returns a pointer to that array.
    int* p;
    p = (int*)malloc(n*sizeof(int));
    return (p);
}


struct struct1{
    int length;
    int breadth;
};

int func7(struct1 s1){
    //this is pass by value
    return s1.length*s1.breadth;
}

void func8(struct1* s1){
    //this is pass by addresss
    s1->length = 25;
    s1->length = 50;
}


class class1_rectangle{
    private:
    int length;
    int breadth;

    public:
    class1_rectangle(int l,int b){
        //this is a constructor, this would get called when the object is created.
        length = l;
        breadth = b;
    }

    int area(){
        return length*breadth;
    }
    void changelength(int l){
        length = l;
    }
};


void dummy_function(){
    //variable v1
    int v1 = 5;
    //pointer v2
    int* v2 = &v1;
    //reference v3
    int &v3 = v1;
    
    int v4=25;
    //v2 will point now to memory address of v4
    v2 = &v4;
    //v3 will not act as reference to v4, but simple change the value of v1 to the value present in v4 right now. 
    v3 = v4;


    // cout<<func1_get_value()<<endl;
    cout<<func2_sum(10,15)<<endl;
    //Nesting with star and slash is not allowed. Dont nest comments.
    
    //initialise variables in the following 2 ways.
    int x=5;
    int y {5};
    
    //storing string is also possible in the following way.
    string name= "hello";
    cout<<name<<endl;
    
    //getline function allows collecting input values containing spaces.Similar to fgets in c.
    string full_name;
    getline(cin,full_name);
    cout<<full_name<<endl;
    
    //<string> header file is indirectly included in <iostream>. However it is recommended to include it seperately.
    //since the proper working is not guarenteed under indirct inclusion across different compilers.

    //malloc keyword is used to allocate memory in heap in c language. In c++ simply use new keyword.
    int* a = (int*)malloc(5*sizeof(int));
    a[0] = 10;
    delete[] a;


    // 'ptr ->' is used to access memory pointed by pointer in c++. (instead of *ptr)
    struct1 r1 ={10,5};
    struct1* ptr1 = &r1;
    struct1 &ref1 = r1;
    (*ptr1).length=100;
    ptr1 -> length= 250;
    
    struct1* ptr_to_structure = (struct1*)malloc(sizeof(struct1));
    ptr_to_structure -> length = 2000;

    //creating structure in heap using new keyword
    struct1* ptr2 = new struct1{1,2};
    cout<<ptr2->length<<" "<<ptr2->breadth<<endl;
    delete[] ptr2;

    //passing structure as parameter to a function
    struct struct1 s1 = {10,5};
    cout<<func7(s1)<<endl;

    //array cannot be passed as call by value. But when we have a structure containing an array inside it and then when we pass the structure as pass by value.
    //the array inside it will get copied, meaning it is pass by value.


    //creating the object
    class1_rectangle rectangle{10,5};
    cout<<rectangle.area()<<endl;
    rectangle.changelength(20);
    cout<<rectangle.area()<<endl;
}

int main()
{
    return 0;
}