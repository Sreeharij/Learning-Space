#include <iostream>
using namespace std;

struct element{
    int i;
    int j;
    int x;
};

struct sparse{
    int m;
    int n;
    int nums_non_zero;
    element* e; 
};

void create(sparse* s){
    cout<<"Enter number of rows columns and number_of_non_zero_elements: ";
    cin>>s->m>>s->n>>s->nums_non_zero;
    s->e = new element[s->nums_non_zero];
    cout<<"Enter all elements:"<<endl;
    for(int i=0;i<s->nums_non_zero;i++){
        cin>>s->e[i].i>>s->e[i].j>>s->e[i].x;
    }
}
void display(sparse s){
    int k=0;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            if(i==s.e[k].i && j==s.e[k].j){
                cout<<s.e[k].x<<" ";
                k++;
            }
            else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }
}

sparse* add(sparse* s1, sparse* s2){
    if(s1->m!=s2->m || s1->n!=s2->n){
        return 0;
    }
    sparse* sum_arr = new sparse;
    sum_arr->m = s1->m;
    sum_arr->n = s1->n;
    sum_arr->e = new element[s1->nums_non_zero + s2->nums_non_zero];

    int i,j,k;
    i=j=k=0;
    while(i<s1->nums_non_zero && j<s2->nums_non_zero){
        if(s1->e[i].i < s2->e[j].i){
            sum_arr->e[k++] = s1->e[i++];
        }
        else if(s1->e[i].i > s2->e[j].i){
            sum_arr->e[k++] = s2->e[j++];
        }
        else{
            if(s1->e[i].j < s2->e[j].j){
                sum_arr->e[k++] = s1->e[i++];
            }
            else if(s1->e[i].j > s2->e[j].j){
                sum_arr->e[k++] = s2->e[j++];
            }
            else{
                sum_arr->e[k] = s1->e[i];
                //copied the i and j coordinates of the element struct 
                sum_arr->e[k++].x = s1->e[i++].x + s2->e[j++].x;
            }
        }
    }
    for(;i<s1->nums_non_zero;i++) sum_arr->e[k++] = s1->e[i];
    for(;j<s2->nums_non_zero;j++) sum_arr->e[k++] = s1->e[j];
    sum_arr->nums_non_zero = k;
    return sum_arr;
}

int main() {
    sparse s1,s2;
    sparse *s3;
    create(&s1);
    create(&s2);
    s3 = add(&s1,&s2);
    cout<<"Matrix 1:\n";
    display(s1);
    cout<<"\nMatrix 2:\n";
    display(s2);
    cout<<"\n Adding 1 and 2, resultant matrix:\n";
    display(*s3);
    return 0;
}
