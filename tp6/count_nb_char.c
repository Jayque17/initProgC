int CompteCaracteres(FILE* fichier){
    
    int count = 0;
    for(char ch = getc(fichier); ch != EOF; ch = getc(fichier)){

        count += 1;
    }
    return count;
}