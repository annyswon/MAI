#include <iostream> 
#include <memory> 
#include <string> 
using namespace std; 

template <typename T> 
class smartpointer { 
T* p; 
public: 
smartpointer(T* tp) { 
p = tp; 
} 
~smartpointer() { 
delete p; 
} 
T* operator->() { 
return p; 
} 

}; 

class ball { 
int x; 
int y; 
public: 
ball(int tx, int ty) { 
x = tx; 
y = ty; 
} 
void setball(int tx, int ty) { 
x = tx; 
y = ty; 
} 
int getx() { 
return x; 
} 
int gety() { 
return y; 
} 
void show() { 
cout « "x is " « x « endl; 
cout « "y is " « y « endl; 
} 
}; 
int main() { 
smartpointer<ball> b(new ball(6, 6)); 
b->show(); 
}
