#include "thing.h"

void function1(Thing t) {
    Thing lt(106);
    Thing* tp1 = new Thing(107);
    Thing* tp2 = new Thing(108);
    delete tp1;
}

int main() {
    Thing t1(101), t2(102);
    Thing* tp1 = new Thing(103);
    function1(t1);
    {
        Thing t3(104);
        Thing* tp = new Thing(105);
    }
    delete tp1;
    return 0;
}
