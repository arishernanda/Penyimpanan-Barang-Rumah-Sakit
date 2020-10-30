#include <stdio.h>
#include <string.h>
#include <conio.h>

typedef char string[256];  //Pembuatan variable string

typedef struct{ //Pembuatan ADT alat
    string nama_alat;
    string kode_alat;
    int jumlah;
    string kondisi;
    string tempat;
}alat;

alat InputDataAlat(alat A){  //Fungsi ADT InputDataAlat dengan output A
	printf("\t\t==============================================\n");
    printf("\t\t\t\tINPUT DATA ALAT\n");
    printf("\t\t==============================================\n");
    printf("\n\t\tInput Nama Alat\t\t 	: "); 
	scanf("%s",&A.nama_alat);
    printf("\t\tInput Kode Alat\t\t 	: "); 
	scanf("%s",&A.kode_alat);
    printf("\t\tInput Tempat Alat\t 	: "); 
	scanf("%s",&A.tempat);
    printf("\t\tInput Kondisi (Bagus/Buruk) 	: ");
	scanf("%s",&A.kondisi);
    printf("\t\tInput Jumlah Alat\t 	: "); 
	scanf("%d",&A.jumlah);
    printf("\n\t\t-------------Sukses menginput data-------------");
    getch();
    
	return A;
}

void SimpanDataAlat(alat A){ //Prosedur untuk mengimput data alat ke dalam file
    FILE *out=fopen(A.kode_alat,"a+");
    fprintf(out,"%s#%s#%s#%s#%d\n",A.nama_alat,A.kode_alat,A.tempat,A.kondisi,A.jumlah);
    fclose(out);
}

void TampilkanData(alat A){  //Prosedur untuk menampilkan data alat ke dalam program
    FILE *in=fopen(A.kode_alat,"r"); //Menampilkan file dengan nama file yang sama dengan kode alat yang akan ditampilkan
    if(!in){ //Jika nama file dan kode alat tidak ada maka akan menjalankan perintah printf tersebut
        printf("\n\tFile tidak ditemukan\n");
    }
    else{ //Jika ada file maka akan menscan setiap karakter yang ada pada file tersebut dengan dibatasi oleh tanda pagar 
        while(!feof(in)){ //Maka akan menampilkan data dengan format seperti dibawah dengan memanggil data yang ada di file yang telah discan
            fscanf(in,"%[^#]#%[^#]#%[^#]#%[^#]#%d%",&A.nama_alat,&A.kode_alat,&A.tempat,&A.kondisi,&A.jumlah);
            printf("\t\t==============================================\n");
            printf("\t\t\t\tTAMPILKAN DATA ALAT\n");
            printf("\t\t==============================================\n");
            printf("\n\t\tNama Alat\t: %s\n",A.nama_alat);
            printf("\t\tKode Alat\t: %s\n",A.kode_alat);
            printf("\t\tTempat Alat\t: %s\n",A.tempat);
            printf("\t\tKondisi Alat\t: %s\n",A.kondisi);
            printf("\t\tJumlah Alat\t: %d\n",A.jumlah);
            printf("\t\t_______________________________________________\n");
            printf("\t\t_______________________________________________\n");

        }
        fclose(in);
    }
}

void TampilanMenu(){ //Prosedur untuk menampilkan menu pilihan
	printf("\t\t============================================\n");
    printf("\t\t***PROGRAM PENYIMPANAN BARANG RUMAH SAKIT***\n");
    printf("\t\t============================================\n");
    printf("\n\t\t\t--------MASUKKAN INPUTAN--------\n\n");
    printf("\t\tKetik 1 untuk menginput data\n");
    printf("\t\tKetik 2 untuk menampilkan data\n");
    printf("\t\tKetik 3 untuk keluar\n");
    printf("\n\t\tMasukkan pilihan\t		: "); 
	}
	
void TampilanMenginputDataAlat(){ //Prosedur untuk menampilkan pilihan pertama
	int n,i;
	alat A; 
	printf("\t\tMasukkan jumlah alat yang diinput 	: ");
            scanf("%d",&n);
            if(n<1){ //Jika n<1 maka program akan berhenti 
                printf("Inputan salah hanya bisa menginput jumlah barang lebih dari nol.\n");
            }
            else if(n>0){ //Jika n>0 maka i akan berulang dari 1 maju sampai n dengan pengulangan fungsi input data dan prosedur simpan data
            for(i=1;i<=n;i++){
                    printf("\n\t\tData Alat ke %d\n",i);
                    system("cls");
                    A=InputDataAlat(A);
                    SimpanDataAlat(A);
    				getch();
                    }
            }
}

void TampilanMelihatDataAlat(){ //Prosedur untuk menampilkan pilihan 2
	alat A;
	printf("\t\tMasukkan kode barang\t		: "); 
			scanf("%s",&A.kode_alat);
            system("cls");
            TampilkanData(A);
    		getch();
}	

int main(){
	int pengulangan;
    char kode,y,n;
    pengulangan=0;

    do{
    alat A;
    int n,i;
    int pilihan;
	TampilanMenu();
	scanf("%d",&pilihan);

    if(pilihan==1){
    	TampilanMenginputDataAlat ();
    }
    if(pilihan==2){
    	TampilanMelihatDataAlat ();
    }
    else if(pilihan==3){
    		break;
    }
	else if(pilihan<1||pilihan>2){
        printf("\n\t\tInput yang dimasukkan salah, hanya ada 3 pilihan");
    }
    printf("\n\t\tApakah anda ingin kembali ke menu? (y/n):");
    scanf("%s", &kode);
    if(kode=='y'){
        system("cls");
    }
    else if(kode=='n'){
        break;
    }
    else{
        break;
    }

    }while(pengulangan<1);

	return 0;
}



