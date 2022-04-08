int main(){
    int a = 2;
    int b = 0;
    if (a == 1) {
        if (b == 0) {
            b = 1;
        } else {
            b = 2;
        }
    } else {
        b = -a;
    }
    return b;
}