#include <stdio.h>
int GV = 100;// Global variable
void Local() {
    auto int LV = 5;//local Variable
    printf("Value of local Variable is: %d\n", LV);
}

void Static() {
    static int SV = 10;//Static Variable- Retains the value
    printf("Value of Static Variable is : %d\n", SV++);
}

void Register() {
    register int RV = 15;//Register Variable- It gives faster access to data rather than those stored in RAM
    printf("Value of Register Variable is : %d\n",RV);
}

int main() {
    printf("Global Variable is : %d\n",GV);
    
    Local();
    Static();
    Static();
    Register();
    
    return 0;
}
