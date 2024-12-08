


void process_vector(int X[S][S][S][S], int f[P], int dim, int fix_1, int fix_2, int fix_3) {
	int found = 0;
	int next = 0;
	for (int i = 0 ; i < S ; i++ ) {
		switch(dim) {
			case 0: found += place_value[i]*X[i][fix_1][fix_2][fix_3];break;
			case 1: found += place_value[i]*X[fix_1][i][fix_2][fix_3];break;
			case 2: found += place_value[i]*X[fix_1][fix_2][i][fix_3];break;
			case 3: found += place_value[i]*X[fix_1][fix_2][fix_3][i];break;
		}
	}
	next = f[found]; 
	for (int i = 0 ; i < S ; i++ ) {
		switch(dim) {
			case 0: X[i][fix_1][fix_2][fix_3] = next/place_value[i];next -= X[i][fix_1][fix_2][fix_3]*place_value[i];break;
			case 1: X[fix_1][i][fix_2][fix_3] = next/place_value[i];next -= X[fix_1][i][fix_2][fix_3]*place_value[i];break;
			case 2: X[fix_1][fix_2][i][fix_3] = next/place_value[i];next -= X[fix_1][fix_2][i][fix_3]*place_value[i];break;
			case 3: X[fix_1][fix_2][fix_3][i] = next/place_value[i];next -= X[fix_1][fix_2][fix_3][i]*place_value[i];break;
		}
	}
}

void process_dim(int X[S][S][S][S], int f[P], int d) {
	for (int i = 0; i < S; i++) for (int j = 0; j < S; j++) for (int k = 0; k < S; k++) process_vector(X, f, d, i, j, k);
}



void copy_matrix_src_tar(int src[S][S][S][S],int tar[S][S][S][S]) {
	for (int i = 0; i < S; i++) for (int j = 0; j < S; j++) 
	for (int k = 0; k < S; k++) for (int l = 0; l < S; l++) tar[i][j][k][l] = src[i][j][k][l];
}




