#include <ropesim>

#include <iostream> 

int main(){

    simlogic::rope r(0, 0, 0, 0, 100);
    for (int i = 0; i < 1000; i++)
    {
        r.step();
    }

    return 0;
}

