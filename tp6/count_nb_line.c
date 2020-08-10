int CompteLignes(FILE* fichier){
    
    int count = 0;
    for(char ch = fgetc(fichier); ch != EOF; ch = fgetc(fichier)){

        if(ch == '\n'){

            count += 1;
        }
    }
    count += 1;
    return count;
}