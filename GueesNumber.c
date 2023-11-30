#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int random (int min, int max) {
    return rand() % (max - min + 1) + min; // ini buat balikin nilai acak
    //ini buat nge hasil in angka random
}

int main() {
    srand(time(0));
    // ini buat mendapatkan angka yang beda beda tiap detik nya

    int secret, guess, attempts = 0;
    char username[50];
    int guesses = 1;

     secret = random(1, 100);
        // ini buat menghasilkan angka acak dari 1 sampe 100

    printf("========================================\n");
    printf("Selamat datang di Guess the Number Game!!\n");
    printf("========================================\n");
    printf("Bisakah kamu menebak angka rahasia diantara 1 sampai 100!?\n");
    // ini bakal menampilkan pesan selamat datang di game dan memberi tau intruksi buat memainkan game nya

     printf("\nSiapa yang akan bermain : ");
    fgets(username, sizeof(username), stdin); // ini buat nge baca username yang di masukin oleh user
    username[strcspn(username, "\n")] = '\0'; //ini buat nge hapus karakter dari new line, atau buat memutus string sebelum karakter new line
	    // ini buat minta user untuk masukin nama yang bakal memainkan game nya
	
	printf("-----------------------------------------\n");
    printf("Selamat datang %s! Goodluck :>\n", username);
        // ini buat menampilkan pesan selamat datang buat user yang sudah memasukan nama

    while (attempts < 10) {
        if (guesses) {
            printf("\nBerapa tebakan mu: "); //ini untuk membedakan tebakan pertama dan tebakan kedua dan selanjut nya
            guesses = 0;
        } else {
            printf("Tebakan mu: "); // ini adalah tebakan kedua dan selanjut nya
        }
        scanf("%d", &guess); 

        attempts++; //ini buat jumlahin berapa kali percobaan nya

        if (guess == secret) { //meriksa jawaban pemain
            printf("Selamat %s! Kamu berhasil menebak angka nya setelah %d percobaan!\n", username, attempts); // kalo udah bener bakal show pesan kaya gini
            break;
        } else {
            if (guess < secret) { //ini buat cek jawaban pemain terlalu rendah atau terlalu tinggi jika salah
                printf("Terlalu rendah! Coba lagi.\n");
            } else {
                printf("Terlalu tinggi! Coba lagi.\n");
            }
        }
    }

    if (attempts == 10) {
        printf("\nSayang banget kamu kalah %s :( Angka yang benar adalah %d!\n", username, secret); //ini notif ketika kamu salah menjawab setelah 10x tebakan
    } 
    return 0;
}
