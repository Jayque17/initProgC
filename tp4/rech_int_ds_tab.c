int position(int t[], int taille, int x){
    for(int i = 0; i < taille; i++){
        if(t[i] == x)
            return i;
    }
    return -1;
}