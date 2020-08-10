#define N 30

void Histogramme(int Note[N], int Histo[21]){
    for(int i = 0; i < 21; ++i){
        Histo[i] = 0;
        for(int j = 0; j < N; ++j){
            if(Note[j] == i)
                Histo[i] += 1;
        }
    }
}