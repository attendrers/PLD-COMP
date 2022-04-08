int add(int a, int b){
    return a+b;
}

int mult(int a, int b){
    return a*b;
}

int main(){
    int a = add(5,3) + 5 + mult(3,1);
    return a;
}