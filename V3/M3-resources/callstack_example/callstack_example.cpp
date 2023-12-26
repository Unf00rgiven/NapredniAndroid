
void function1();
void function2();
void function3();
void function4();
void function5();

int main(){
    function1();
    return 1;
}

void function1(){
    function2();
}

void function2(){
    function3();
}

void function3(){
    function4();
}

void function4(){
    function5();
}

void function5(){
}
