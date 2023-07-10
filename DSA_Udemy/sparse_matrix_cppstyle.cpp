#include <iostream>
using namespace std;

class element{
    public:
        int i;
        int j;
        int x;
};

class sparse{
    private:
        int m;
        int n;
        int nums_non_zero;
        element* e;
    public:
        sparse(int m, int n, int nums_non_zero){
            this->m = m;
            this->n = n;
            this->nums_non_zero = nums_non_zero;
            e = new element[nums_non_zero];
        }
        ~sparse(){
            delete[] e;
        }
        friend istream & operator>>(istream &is, sparse &s){
            cout<<"Enter non-zero elements: ";
            for(int i=0;i<s.nums_non_zero;i++){
                cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
            }
            return is;
        }
        friend ostream & operator<<(ostream &os, sparse &s){
            int k=0;
            for(int i=0;i<s.m;i++){
                for(int j=0;j<s.n;j++){
                    if(s.e[k].i==i && s.e[k].j==j && k<s.nums_non_zero){
                        cout<<s.e[k++].x<<" ";
                    }
                    else{
                        cout<<0<<" ";
                    }
                }
                cout<<endl;
            }
            return os;
        }

        sparse* add(sparse *s){
            if(s->m!=m || s->n!=n){
                return NULL;
            }
            int i,j,k;
            i=j=k=0;
            sparse *result_matrix = new sparse(m,n,nums_non_zero + s->nums_non_zero);
            
            while(i<nums_non_zero && j<s->nums_non_zero){
                if(e[i].i < s->e[j].i){
                    result_matrix->e[k++] = e[i++];
                }
                else if(e[i].i > s->e[j].i){
                    result_matrix->e[k++] = s->e[j++];
                }
                else{
                    if(e[i].j < s->e[j].j){
                        result_matrix->e[k++] = e[i++];
                    }
                    else if(e[i].j > s->e[j].j){
                        result_matrix->e[k++] = s->e[j++];
                    }
                    else{
                        if(e[i].x + s->e[j].x !=0){
                            result_matrix->e[k] = e[i];
                            result_matrix->e[k++].x = e[i++].x + s->e[j++].x;
                        }
                        else{
                            i++;
                            j++;
                        }
                        
                    }
                }
            }
            while(i<nums_non_zero){
                result_matrix->e[k++] = e[i++];
            }
            while(j<s->nums_non_zero){
                result_matrix->e[k++] = s->e[j++];
            }
            result_matrix->nums_non_zero = k;
            return result_matrix;
        }

};

int main() {
    sparse s1(5,5,5);
    sparse s2(5,5,5);
    cin>>s1;
    cin>>s2;
    cout<<endl;
    cout<<s1;
    cout<<endl;
    cout<<s2;
    cout<<endl;
    sparse *resultant_matrix = s1.add(&s2);
    cout<<*resultant_matrix;
    return 0;
}

