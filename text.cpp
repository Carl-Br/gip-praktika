#include <iostream>

int main(){
    struct {
        int var1;
        int var2;
    } a = { .var2=2,.var1=1};

    std::cout<<a.var1<<std::endl<<a.var2<<std::endl;
}