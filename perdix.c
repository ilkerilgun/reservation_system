#include<stdio.h>
#include<string.h>
#define dolu 1
#define bos 0

	


typedef struct rezervasyon
{
int kisi_sayisi;
char ad[20];
char saat[10];
int durum;
}rezervasyonlar;

typedef struct masa
{
int kapasite;
char name[15];
int durum;
rezervasyonlar kisi; 
}masalar;

rezervasyonlar rezervasyon_ekle(rezervasyonlar a){
	printf("\nKişi sayısını giriniz:");
	scanf("%d",&a.kisi_sayisi);	
	
	printf("Boşluk kullanmadan isim giriniz:");
   	scanf("%s", a.ad);
	
	printf("Saat giriniz:");
	scanf("%s",a.saat);
	a.durum=bos;
	return a;

}

void rezervasyon_gor(rezervasyonlar a){
	printf("*********************");
	printf("\nisim: %s",a.ad);
	printf("\nkişi sayısı: %d",a.kisi_sayisi);
	printf("\nsaat: %s",a.saat);
	printf("\ndurum:%d\n",a.durum);
	printf("*********************");
}

void masa_gor(masalar a){
	printf("*********************");
	printf("\nmasa adı: %s",a.name);
	printf("\nkapasite: %d",a.kapasite);
	printf("\ndurum:%d\n",a.durum);
	rezervasyon_gor(a.kisi);
	printf("*********************");
}

int main(){
int secim=0,c=0,i=0,j;
char table[10];
int uyari;


masalar masa_listesi[25]={
	{8,"K1",bos,0},
	{4,"K2",bos,0},
	{4,"K3",bos,0},
	{4,"K4",bos,0},
	{4,"K5",bos,0},
	{4,"K6",bos,0},
	{8,"K7",bos,0},
	{4,"K8",bos,0},
	{4,"K9",bos,0},
	{5,"Y1",bos,0},
	{5,"Y2",bos,0},
	{5,"Y3",bos,0},
	{5,"Y4",bos,0},
	{2,"S1",bos,0},
	{2,"S2",bos,0},
	{2,"S3",bos,0},
	{2,"S4",bos,0},
	{4,"Z1",bos,0},
	{4,"Z2",bos,0},
	{4,"Z3",bos,0},
	{4,"Z5",bos,0},
	{4,"Z6",bos,0},
	{10,"A1",bos,0},
	{10,"A2",bos,0},
	{10,"A3",bos,0},
};
rezervasyonlar liste[50];
for(i=0;i<51;i++)
liste[i].kisi_sayisi=0;

printf("\n*****Perdix Şarapçılık Rezervasyon Sistemi*****\n");

while(1) {

printf("\nManuel masaya yerleştirme:1\nListeye rezervasyon ekleme:2\nRezervasyonları otomatik masalara dağıt:3\n");
printf("\nSeçiminizi girin:");
scanf("%d",&secim);

switch(secim) 
{
	
	case 1:
	
	printf("Masaya manuel yerleştirme\n");
	liste[c]=rezervasyon_ekle(liste[c]);
	//rezervasyon_gor(liste[c]);
	printf("\nMasa adını giriniz:");
	scanf("%s",&table);
	for(i=0;i<25;i++) {
		if(strcmp(table,masa_listesi[i].name)==0) {
			if(masa_listesi[i].durum==bos){
			
				if(masa_listesi[i].kapasite<liste[c].kisi_sayisi){
					printf("\nUyarı: Seçtiğiniz masa kapasitesi kişi sayısından az!!!\nYine de devam etmek için '0'a basınız, iptal için '1'e basınız\n");
					scanf("%d", &uyari);
					
					if(uyari==0){
						
						
						liste[c].durum=dolu;
						masa_listesi[i].kisi=liste[c];
						masa_listesi[i].durum=dolu;
						//rezervasyon_gor(liste[c]);
						masa_gor(masa_listesi[i]);
						printf("\n*-*-*-*-Dikkat masaya kapasitesinden %d kişi fazla yerleştirildi!!-*-*-*-*\n",liste[c].kisi_sayisi-masa_listesi[i].kapasite);
						printf("\n*-*-*-*-*-*-*-*-*-*");
						}
					else if(uyari==1) printf("\nİşlem iptal edildi.");
				}
				else if(masa_listesi[i].kapasite>liste[c].kisi_sayisi || masa_listesi[i].kapasite==liste[c].kisi_sayisi){
					liste[c].durum=dolu;
					masa_listesi[i].kisi=liste[c];
					masa_listesi[i].durum=dolu;
					//rezervasyon_gor(liste[c]);
					masa_gor(masa_listesi[i]);
				    }
		}
		else 
		printf("\nSeçtiğiniz masa doludur!!\n ");
	}
	}
		
	
	c++;
	
	break;
	
	case 2:
	
	printf("\nListeye rezervasyon ekle");
	liste[c]=rezervasyon_ekle(liste[c]);
	
	c++;
	for(i=0;i<c;i++)
	rezervasyon_gor(liste[i]);
	
	
	break;
	
	case 3:
	
	printf("\nMasalara otomatik dağıtma");
	
	for(i=0;i<26;i++){
		if(masa_listesi[i].durum==bos){
			for(j=0;j<51;j++){
				if(liste[j].durum==bos){
					if(liste[j].kisi_sayisi>8 && masa_listesi[i].kapasite>8 && masa_listesi[i].durum==bos){
						liste[j].durum=dolu;
						masa_listesi[i].kisi=liste[j];
						masa_listesi[i].durum=dolu;
						
					}
					else if(liste[j].kisi_sayisi>5 && liste[j].kisi_sayisi<9 && masa_listesi[i].kapasite>5 && masa_listesi[i].kapasite<9 && masa_listesi[i].durum==bos){
						liste[j].durum=dolu;
						masa_listesi[i].kisi=liste[j];
						masa_listesi[i].durum=dolu;
						
					}
					else if(liste[j].kisi_sayisi==5  && masa_listesi[i].kapasite==5  && masa_listesi[i].durum==bos){
						liste[j].durum=dolu;
						masa_listesi[i].kisi=liste[j];
						masa_listesi[i].durum=dolu;
						
					}
					else if(liste[j].kisi_sayisi>2 && liste[j].kisi_sayisi<5 && masa_listesi[i].kapasite>2 && masa_listesi[i].kapasite<5 && masa_listesi[i].durum==bos){
						liste[j].durum=dolu;
						masa_listesi[i].kisi=liste[j];
						masa_listesi[i].durum=dolu;
						
					}
					else if(liste[j].kisi_sayisi>0 && liste[j].kisi_sayisi<3 && masa_listesi[i].kapasite>0 && masa_listesi[i].kapasite<3 && masa_listesi[i].durum==bos){
						liste[j].durum=dolu;
						masa_listesi[i].kisi=liste[j];
						masa_listesi[i].durum=dolu;
						
					}
					
				}
			}
		}
	}
	
	for(j=0;j<51;j++){
		if(liste[j].durum==bos){
			for(i=0;i<26;i++){				/////baaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaakkkkkkkkkkkkkkkkkkkkkkk
				if(masa_listesi[i].durum==bos){
					if((masa_listesi[i].kapasite>liste[j].kisi_sayisi || masa_listesi[i].kapasite==liste[j].kisi_sayisi) && liste[j].durum==bos && liste[j].kisi_sayisi!=0){
						
						liste[j].durum=dolu;
						masa_listesi[i].kisi=liste[j];
						masa_listesi[i].durum=dolu;
					
					}
				}
			}
		}
	}
	
	
	
	printf("\nMasa listesi\n");
	for(i=0;i<25;i++)
	masa_gor(masa_listesi[i]);
	
	break;
	
	
	default:
	printf("\nGeçersiz operasyon!!!\n");
	break;
	
	
}
	
}
}






