#include <iostream>
using namespace std;
struct Node
{ const char * s;
Node * q;
};
int main()
{ Node a[ ] = { { "China", a+1 }, { "France", a+2 }, { "USA", a } };
Node *p = a;
cout << p->s <<'\t';
cout << p->q->s << '\t';
cout << p->q->q->s << '\t';
cout << p->q->q->q->s << endl;
}
