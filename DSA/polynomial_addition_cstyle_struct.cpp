#include <iostream>
using namespace std;

struct term{
    int coeff;
    int exp;
};
 
struct poly{
    int n;
    struct term* terms;
};

void create(poly *p){
    cout<<"Enter number of terms: ";
    cin>>p->n;
    p->terms = new struct term[p->n];
    cout<<"Enter terms:\n";
    for(int i=0;i<p->n;i++){
        cin>>p->terms[i].coeff>>p->terms[i].exp;
    }
}

void display(struct poly p){
    for (int i=0;i<p.n;i++){
        cout<<p.terms[i].coeff<<"x"<<p.terms[i].exp<<"+";
    }
    cout<<endl;
}

struct poly *add(poly *p1, poly *p2){
    struct poly* sum;
    sum = new poly;
    sum->terms = new term[p1->n + p2->n];

    int i,j,k;
    i=j=k=0;

    while(i<p1->n && j<p2->n){
        if(p1->terms[i].exp > p2->terms[j].exp){
            sum->terms[k++] = p1->terms[i++];
        }
        else if(p1->terms[i].exp < p2->terms[j].exp){
            sum->terms[k++] = p2->terms[j++];
        }
        else{
            sum->terms[k].exp = p1->terms[i].exp;
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
    for(;i<p1->n;i++)sum->terms[k++]=p1->terms[i];
    for(;j<p2->n;j++)sum->terms[k++]=p2->terms[j];

    sum->n = k;
    return sum;
}

int main() {
    poly p1,p2;
    poly *p3;
    create(&p1);
    create(&p2);

    p3 = add(&p1,&p2);
    
    cout<<"\n";
    display(p1);
    cout<<"\n";
    display(p2);
    cout<<"\n";
    display(*p3);
    
    return 0;
}

