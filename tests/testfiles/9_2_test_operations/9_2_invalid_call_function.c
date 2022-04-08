int ajouter(int a, int b){
    return a+b;
}

int main(){
    int toto = 13;
    toto = toto+ajouter(12,14);
    return toto;
}