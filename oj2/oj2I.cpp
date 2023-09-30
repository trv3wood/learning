#include <iostream>
using namespace std;

int main(){
    int n;
    while (cin>>n)
    {
        for(int i=1;i<=n;++i){
            cout<<"* ";
        }
        cout<<endl;
        for(int i=1;i<=n-2;++i){
            cout<<"*";
            for(int j=1;j<=2*n-3;++j){
                cout<<" ";
            }
            cout<<"*"<<endl;
        }
        for(int i=1;i<=n;++i){
            cout<<"* ";
        }
    }
    
}