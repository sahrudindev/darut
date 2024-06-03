#include <stdio.h>
#include <string.h>

#define MAX_TRANSAKSI 100
#define MAX_NAMA 50

float saldo = 0;
char riwayat_transaksi[MAX_TRANSAKSI][50];  // Array untuk menyimpan riwayat transaksi
int jumlah_transaksi = 0;

void tampilkanMenu() {
    printf("\n========---- Menu ATM ----========\n");
    printf("1. Cek Saldo\n");
    printf("2. Setor Tunai\n");
    printf("3. Tarik Tunai\n");
    printf("4. Riwayat Transaksi\n");
    printf("5. Keluar\n");
}

void cekSaldo(char nama_nasabah[MAX_NAMA]) {
    printf("Saldo Anda, %s: %.2f\n", nama_nasabah, saldo);
}

void setorTunai(char nama_nasabah[MAX_NAMA]) {
    float jumlah_setor;
    printf("Masukkan jumlah setor tunai: ");
    scanf("%f", &jumlah_setor);

    if (jumlah_setor > 0) {
        saldo += jumlah_setor;
        printf("Setor tunai berhasil. Saldo sekarang: %.2f\n", saldo);
        sprintf(riwayat_transaksi[jumlah_transaksi], "%s setor tunai: +%.2f", nama_nasabah, jumlah_setor);
        jumlah_transaksi++;
    } else {
        printf("Jumlah setor tunai harus lebih besar dari 0.\n");
    }
}

void tarikTunai(char nama_nasabah[MAX_NAMA]) {
    float jumlah_tarik;
    printf("Masukkan jumlah tarik tunai: ");
    scanf("%f", &jumlah_tarik);

    if (jumlah_tarik > 0 && jumlah_tarik <= saldo) {
        saldo -= jumlah_tarik;
        printf("Tarik tunai berhasil. Saldo sekarang: %.2f\n", saldo);
        sprintf(riwayat_transaksi[jumlah_transaksi], "%s tarik tunai: -%.2f", nama_nasabah, jumlah_tarik);
        jumlah_transaksi++;
    } else if (jumlah_tarik <= 0) {
        printf("Jumlah tarik tunai harus lebih besar dari 0.\n");
    } else {
        printf("Saldo tidak mencukupi untuk melakukan tarik tunai.\n");
    }
}

void tampilkanRiwayatTransaksi() {
    printf("\n=== Riwayat Transaksi ===\n");
    for (int i = 0; i < jumlah_transaksi; i++) {
        printf("%s\n", riwayat_transaksi[i]);
    }
}

int main() {
    char nama_nasabah[MAX_NAMA];
    int pilihan;

    printf("Masukkan nama nasabah: ");
    fgets(nama_nasabah, sizeof(nama_nasabah), stdin);
    nama_nasabah[strcspn(nama_nasabah, "\n")] = '\0';  // Menghapus karakter newline di akhir nama
    printf("\nSelamat Datang %s di ATM Bank INI\n", nama_nasabah);

    while (1) {
        tampilkanMenu();

        printf("Pilih menu (1-5): ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1:
                cekSaldo(nama_nasabah);
                break;
            case 2:
                setorTunai(nama_nasabah);
                break;
            case 3:
                tarikTunai(nama_nasabah);
                break;
            case 4:
                tampilkanRiwayatTransaksi();
                break;
            case 5:
                printf("Terima kasih, %s. Sampai jumpa!\n", nama_nasabah);
                return 0;
            default:
                printf("Pilihan tidak valid. Silakan pilih 1-5.\n");
        }
    }

    return 0;
}
