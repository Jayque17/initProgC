int CompteMots(FILE* fichier){
    
    int countch = 0;
    int countw = 0;
    for(char ch = fgetc(fichier); ch != EOF; ch = fgetc(fichier)){

        if(ch != ' ' && ch != '\t' && ch != '\n'){
            countch += 1;
        }
        else{
            if(countch > 0){
                countw += 1;
                countch = 0;
            }
        } 
    }
    return countw;
}