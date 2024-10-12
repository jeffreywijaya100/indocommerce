#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<string>



int JumlahBarang = 0;
int JumlahTransaksi = 0;

struct Barang{
	char NamaBarang[20];
	int Stok;
	int Harga;
	int nomor;
	int JumlahDibeli;
	
} AllBarang[100];

struct Transaksi{
	char NamaKasir[20];
	struct Barang BarangDibeli[30];
	int nomortransaksi;
	int total;
	int jumlahbarangunik;
} AllTransaksi[100];


void AddBarang(){
	
	
	char NamaProduk[20];	
		int HargaInput;
		char StokInput[20];
		bool IsDigit ;
		int StokFinal = 0;
		do{
			printf("\nNama Produk [5 - 20 Karakter]: ");
			getchar();
			scanf("%[^\n]", &NamaProduk);
			strcpy(AllBarang[JumlahBarang].NamaBarang, NamaProduk);
						
		} while(strlen(NamaProduk) < 5 || strlen(NamaProduk) > 20);
		
		do{
			printf("\nHarga Produk[1,000 - 1,000,000]: ");
			scanf("%d", &HargaInput);
			AllBarang[JumlahBarang].Harga = HargaInput;
			
		}while(HargaInput < 1000 || HargaInput > 1000000);
		
		do{
			int imultiplier = 1;
			IsDigit = true;
			printf("\nStok: ");
			scanf("%s", &StokInput);
			for(int i = 0; i < strlen(StokInput); i++){
				if(isalpha(StokInput[i])){
					IsDigit = false;
				}

				StokFinal = StokFinal + (StokInput[strlen(StokInput) - i - 1]  - 48) * imultiplier;
				imultiplier = imultiplier  * 10;
			}
		}while(IsDigit == false);
		
		AllBarang[JumlahBarang].Stok = StokFinal;
		printf("\nBarang berhasil diinput dengan kode produk KODE%d\n", JumlahBarang + 1);
		getchar();
		getchar();
		
		AllBarang[JumlahBarang].nomor = JumlahBarang + 1;		
		JumlahBarang++;
		
		
}
void ShowBarang(){
	
	printf("\n\n\n\n\n\n\n");
	printf("----------------------------------------------------------------------\n");
	printf("TABEL\n");
	printf("NO. KODE     Nama Barang          Harga      Stok\n");

	for(int i = 0; i<JumlahBarang; i++){
		
		
		printf("%-3d KODE%-4d %-20s Rp.%-7d %-5d\n", i+1, AllBarang[i].nomor, AllBarang[i].NamaBarang, AllBarang[i].Harga, AllBarang[i].Stok );
		
		
		
	}
	printf("----------------------------------------------------------------------\n");
	printf("\n\n\n\n\n\n");
	getchar();
	getchar();
	

	
}
void UpdateStok(){
	int IndexUpdate;
	printf("\n\n\n\n\n\n\n");
	printf("----------------------------------------------------------------------\n");
	printf("TABEL\n");
	printf("NO. KODE     Nama Barang          Harga      Stok\n");

	for(int i = 0; i<JumlahBarang; i++){
		
		
		printf("%-3d KODE%-4d %-20s Rp.%-7d %-5d\n", i+1, AllBarang[i].nomor, AllBarang[i].NamaBarang, AllBarang[i].Harga, AllBarang[i].Stok );
		
		
		
	}
	printf("----------------------------------------------------------------------\n");
	printf("\n\n\n\n\n\n");
	
	do{
		printf("No Barang: ");
		scanf("%d", &IndexUpdate);
		getchar();
		
	}while(IndexUpdate < 1 || IndexUpdate > JumlahBarang);
	
	
	int StokFinal = 0;
	char StokInput[20];
	bool IsDigit;
	do{
			int imultiplier = 1;
			IsDigit = true;
			printf("\nTambahan Stok: ");
			scanf("%s", &StokInput);
			for(int i = 0; i < strlen(StokInput); i++){
				if(isalpha(StokInput[i])){
					IsDigit = false;
				}

				StokFinal = StokFinal + (StokInput[strlen(StokInput) - i - 1]  - 48) * imultiplier;
				imultiplier = imultiplier  * 10;
			}
		}while(IsDigit == false);
		
		AllBarang[IndexUpdate - 1].Stok += StokFinal;
		printf("\nStok Barang [%s] Berhasil di Update\n", AllBarang[IndexUpdate -1].NamaBarang);
		getchar();
		getchar();
	
}
void PilihanStaffGudang(){
int StaffGudang;

do{
	printf("\n\n\n\n");

	printf("---MENU STAFF GUDANG---\n");
	printf("1. Menambah Barang\n");
	printf("2. Lihat Barang\n");
	printf("3. Update Stok\n");
	printf("4. Kembali Menu Utama\n");
	
	printf("\n\n\n");	
	do{		
		printf("pilihan: ");
		scanf("%d", &StaffGudang);
		getchar();
	}while(StaffGudang < 1 || StaffGudang > 4);
	
	
	if(StaffGudang == 1){	
		AddBarang();
		
	}
	
	else if(StaffGudang == 2){
		if(JumlahBarang == 0){
			printf("Data barang kosong");
			getchar();
			getchar();
		}
		else{
			ShowBarang();		
		}
	}
	
	else if(StaffGudang == 3){
		if(JumlahBarang == 0){
			printf("Data barang kosong");
			getchar();
			getchar();
		}
		else{
			UpdateStok();
		}
	}
	else{
		break;
	}

	
}while(true);

}

void MenambahTransaksi(Transaksi *transaksi){
	char NamaKasir[20];
	char Kodestr[4];

	int JumlahPembelian;
	bool TambahItem = true;
	int JumlahBarangUnik = 0;
	int totaltransaksi = 0;
	bool stokhabis = false;
	char KodeTemp[4];
	
	do{
			printf("\nNama Kasir: ");
			
			scanf("%[^\n]", &NamaKasir );
			getchar();
		
			
		}while(strlen(NamaKasir) < 5 || strlen(NamaKasir) > 20);
		
		strcpy(AllTransaksi[JumlahTransaksi].NamaKasir, NamaKasir);
		
	do{
		int final = 0;
		
		
		
		do{
			final = 0;
			printf("\nKode Produk: ");
			scanf("%s", &Kodestr );
			int num = strlen(Kodestr) - 4;
			int iterate = 1;
			for(int x = strlen(Kodestr); x > strlen(Kodestr) - num ; x--){
				
				
				final = final + (Kodestr[x - 1] - 48) * iterate;
				iterate = iterate * 10;
			}
		
			
			
			for(int d = 0; d<4;d++ ){
				KodeTemp[d] = Kodestr[d];
			}
		
			
		}while(strcmp(KodeTemp, "KODE") != 0 || final > JumlahBarang || final < 1);
		
		if(AllBarang[final - 1].Stok <= 0){
			printf("\nStok Barang ini Habis\n");
			getchar();
			getchar();
			stokhabis = true;
			
		}
		
		
		
		
		if(stokhabis == false){
			do{
			printf("\n\nStok Barang [%s]: %d", AllBarang[final - 1].NamaBarang, AllBarang[final - 1].Stok);
			printf("\nJumlah Pembelian: ");
			scanf("%d", &JumlahPembelian);
			
			}while(JumlahPembelian < 1 || JumlahPembelian > AllBarang[final - 1].Stok);
			AllBarang[final - 1].Stok -= JumlahPembelian;
			transaksi[JumlahTransaksi].BarangDibeli[JumlahBarangUnik] = AllBarang[final - 1];
		
			totaltransaksi = totaltransaksi + (transaksi[JumlahTransaksi].BarangDibeli[JumlahBarangUnik].Harga * JumlahPembelian);
			transaksi[JumlahTransaksi].BarangDibeli[JumlahBarangUnik].JumlahDibeli = JumlahPembelian;
		
			JumlahBarangUnik++;
		}
		
		
		
		char konfirmasi[3];
		do{
			printf("\nApakah ingin menambahkan produk? (Y/N): ");
			
			scanf("%s", &konfirmasi);
			getchar();
		}while(strcmp(konfirmasi, "Y") != 0  && strcmp(konfirmasi, "N") != 0 );
		
		if(strcmp(konfirmasi, "Y") == 0){
			TambahItem = true;
			
		}
		else{
			TambahItem = false;
		}
		
	}while(TambahItem == true);	
	
	
	
	
	printf("\nTotal Transaksi TX%d adalah Rp%d\n", JumlahTransaksi + 1, totaltransaksi);
	getchar();

	transaksi[JumlahTransaksi].nomortransaksi = JumlahTransaksi + 1;
	transaksi[JumlahTransaksi].total = totaltransaksi;
	transaksi[JumlahTransaksi].jumlahbarangunik = JumlahBarangUnik;
	JumlahTransaksi++;
	
}
void LihatTransaksi(){
	printf("\n\n\n\n\n\n\n");
	printf("----------------------------------------------------------------------\n");
	printf("TABEL\n");
	printf("NO. KODE   Nama Kasir         Total            Detail Pembelian\n");

	for(int i = 0; i<JumlahTransaksi; i++){
		
		
		printf("\n%-3d TX%-4d %-18s Rp.%-14d", i+1, AllTransaksi[i].nomortransaksi, AllTransaksi[i].NamaKasir, AllTransaksi[i].total );
		
		for(int y = 0; y< AllTransaksi[i].jumlahbarangunik; y++){
			printf("%d. KODE%d - %s - %d pcs - Rp%d\n", y+1, AllTransaksi[i].BarangDibeli[y].nomor ,AllTransaksi[i].BarangDibeli[y].NamaBarang, AllTransaksi[i].BarangDibeli[y].JumlahDibeli, AllTransaksi[i].BarangDibeli[y].Harga);
		
			printf("                                               ");
			
		}
		
		
		
	}
	printf("\n----------------------------------------------------------------------\n");
	printf("\n\n\n\n\n\n");
	getchar();
	getchar();
}


void PilihanKasir(){
	int Kasir;
	
	do{
	
		printf("\n\n\n\n");
		printf("---MENU KASIR---\n");
		
		printf("1. Menambah Transaksi\n");
		printf("2. Menampilkan List Transaksi\n");
	
		printf("3. Kembali Menu Utama\n");
		
		printf("\n\n\n");
		
		
		do{
			printf("pilihan: ");
			scanf("%d", &Kasir);
			getchar();
		}while(Kasir < 1 || Kasir > 3);
		
		if(Kasir == 1){
			if(JumlahBarang == 0){
				printf("Tidak ada Data Barang");
				getchar();
				getchar();
			}
			else{
			MenambahTransaksi(AllTransaksi);
			}
		}
		else if(Kasir == 2){
			if(JumlahTransaksi == 0){
				printf("Data Transaksi Kosong");
				getchar();
				getchar();
			}
			else{
				LihatTransaksi();
			}
			
		}
		else{
			break;
		}
		
	}while(true);
}


int main(){
	int MenuUtama;
	do{
		printf("\n\n\n\n");
	
		printf("---MENU UTAMA---\n");
		printf("1. Staff Gudang\n");
		printf("2. Kasir\n");
		printf("3. Keluar\n");
		printf("\n\n\n");
		
		
		
		do{
			printf("pilihan: ");
			
			scanf("%d", &MenuUtama);
			getchar();

		}while(MenuUtama < 1 || MenuUtama > 3);
		
		
		if(MenuUtama == 1){
			PilihanStaffGudang();
		}
		else if(MenuUtama == 2){
			PilihanKasir();
		}
		else{
			break;
		}
		
		
	}while(true);



}


