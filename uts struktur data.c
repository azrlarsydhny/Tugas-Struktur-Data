#include <stdio.h>
#include <string.h>

#define MAKSIMAL_PESERTA 40
#define MAKSIMAL_UKURAN_LINGKARAN 20

typedef struct {
    char nama[50];
    char jenis_kelamin; 
    int kembar;
} Mahasiswa;

void buatLingkaran(Mahasiswa mahasiswa[], int totalMahasiswa) {
    int indeksLaki = 0, indeksPerempuan = 0, i;
    Mahasiswa lingkaran[MAKSIMAL_UKURAN_LINGKARAN];
    
    printf("\nMembentuk lingkaran api unggun.\n");
    
    for (i = 0; i < totalMahasiswa; i++) {
        if (i == MAKSIMAL_UKURAN_LINGKARAN) {
            printf("\nLingkaran penuh. Tidak ada lagi mahasiswa yang bisa bergabung.\n");
            break;
        }

        if (strcmp(mahasiswa[i].nama, "Cindy") == 0) {
            
            if (mahasiswa[i].jenis_kelamin == 'P') {
                lingkaran[indeksPerempuan++] = mahasiswa[i];
            } else {
                printf("Cindy memilih untuk tidak bergabung di lingkaran ini.\n");
            }
        } else if (mahasiswa[i].kembar) {
           
            printf("%s dan saudara kembarnya bergabung ke dalam lingkaran.\n", mahasiswa[i].nama);
            lingkaran[indeksLaki++] = mahasiswa[i];
        } else {
            lingkaran[indeksLaki++] = mahasiswa[i];
        }

        if (i % 2 == 0) {
            printf("%s bergabung ke dalam lingkaran.\n", mahasiswa[i].nama);
        }
    }

    printf("\nPeserta lingkaran:\n");
    for (i = 0; i < indeksLaki; i++) {
        printf("%s (Jenis Kelamin: %c)\n", lingkaran[i].nama, lingkaran[i].jenis_kelamin);
    }
}

int main() {
    int totalMahasiswa, i;
    Mahasiswa mahasiswa[MAKSIMAL_PESERTA];

    strcpy(mahasiswa[0].nama, "Cindy");
    mahasiswa[0].jenis_kelamin = 'P';
    mahasiswa[0].kembar = 0;

    strcpy(mahasiswa[1].nama, "Irsyad");
    mahasiswa[1].jenis_kelamin = 'L';
    mahasiswa[1].kembar = 1;

    strcpy(mahasiswa[2].nama, "Arsyad");
    mahasiswa[2].jenis_kelamin = 'L';
    mahasiswa[2].kembar = 1;

    strcpy(mahasiswa[3].nama, "Rina");
    mahasiswa[3].jenis_kelamin = 'P';
    mahasiswa[3].kembar = 0;

    totalMahasiswa = 4;

    buatLingkaran(mahasiswa, totalMahasiswa);

    return 0;
}
