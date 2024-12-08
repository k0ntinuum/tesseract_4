#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "constant.c"
#include "shuffle.c"
#include "compute.c"
#include "text.c"
#include "print.c"

int main() {
    int M[S][S][S][S];int M_orig[S][S][S][S];
    int f[4][P];int f_inv[4][P];
    for (int i = 0; i < 4; i++) permutize(f[i],P);
    for (int i = 0; i < 4; i++) invert(f[i],f_inv[i], P);
    randomize(M);
    copy_matrix_src_tar(M, M_orig);
    int delay = 200000;
    int T = 40000;
    hide_cursor();
    cls();
    print_matrix(M);
    for (int i = 0; i < T ; i++) {
        //cursor_to(0,0);
        print_matrix(M);
        for (int j = 0; j < 4; j++) process_dim(M, f[j], j);
        //process_dim(M,f[0],0);
        usleep(delay);
    }
    for (int i = 0; i < T ; i++) {
        for (int j = 3; j > -1; j--) process_dim(M, f_inv[j], j);
        //process_dim(M,f_inv[0],0);
        print_matrix(M);
        usleep(delay);
    }
    cursor_to(23,1);
    printf("\n%d decoding errors \n", h_dist(M,M_orig));
    // show_cursor();
    //print_matrix(M_orig);
}
      