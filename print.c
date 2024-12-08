
void print_perm(int* f, int l) {
	for (int i = 0; i < l; i++)  {
        if (i % 16 == 0 ) printf("\n");
        printf("%03d ", f[i]);
        
    }
    printf("\n");
}
void print_matrix(int X[S][S][S][S]) {
	for (int i = 0; i < S; i++) for (int j = 0; j < S; j++) 
	for (int k = 0; k < S; k++) for (int l = 0; l < S; l++) {
        cursor_to(2 + 6*i + k, 2 + 10*j + 2*l);
        switch (X[i][j][k][l]) {
            case 0 : rgb(255,255,255);printf("O ");break;
            case 1 : rgb(255,255,255);printf("| ");break;
            case 2 : rgb(255,255,255);printf("  ");break;
            default : rgb(255,255,255);printf("%d",X[i][j][k][l] );break;
            //default : printf("? ");break;
        }
    }
} 


int h_dist(int X[S][S][S][S], int Y[S][S][S][S]) {
    int e = 0;
    for (int i = 0; i < S; i++) for (int j = 0; j < S; j++) 
	for (int k = 0; k < S; k++) for (int l = 0; l < S; l++) if (X[i][j][k][l] != Y[i][j][k][l]) e++;
    return e; 
}
