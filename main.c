#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
typedef struct n
{
    char kelime[40];
    int adet;
    struct n*next;
} node;
node*root=NULL;
node*geciciDugum=NULL;
node*traverseDugum=NULL;

void arayaEkle(node*geciciDugum,node*index,node*temp)
{
    strcpy(temp->kelime,geciciDugum->kelime);
    temp->kelime[sizeof(temp->kelime)]='\0';
    temp->adet=geciciDugum->adet;
    strcpy(geciciDugum->kelime,index->kelime);
    geciciDugum->kelime[sizeof(geciciDugum->kelime)]='\0';
    geciciDugum->adet=index->adet;
    strcpy(index->kelime,temp->kelime);
    index->kelime[sizeof(index->kelime)]='\0';
    index->adet=temp->adet;

}
int dugumBoyutu(node*dugum)
{
    int boyut=0;
    while(dugum!=NULL)
    {
        boyut++;
        dugum=dugum->next;
    }
    return boyut;
}
node*listeyiSirala(node*root)
{//listemizi buyukten kucuge siraliyor
    geciciDugum=root;
    node*index=NULL;
    node*temp=(node*)malloc(sizeof(node));
    while(geciciDugum!=NULL)
    {
        index= geciciDugum->next;
        while(index!=NULL)
        {
            if(geciciDugum->adet < index->adet)
            {

                arayaEkle(geciciDugum,index,temp);
            }
            index=index->next;
        }
        geciciDugum=geciciDugum->next;
    }

    return root;
}


//bu fonksiyon Stringte kullanilan tolower fonksiyonunun geri dönüs degeri ile uyumsuz oldugu icin yeniden yazildi ve suradan alindi.
/* kaynak:https://stackoverflow.com/questions/2661766/how-do-i-lowercase-a-string-in-c (erisim tarihi: 26.12.2020)
*/
char* toLower(char* s)
{
    for(char *p=s; *p; p++)
        *p=tolower(*p);
    return s;
}

void yazdir(node*dugum)
{
    int kacinciDugum=1;
    while(dugum!=NULL)
    {
        printf("%2d. %s %d->\n",kacinciDugum,dugum->kelime,dugum->adet);
        dugum=dugum->next;
kacinciDugum++;

    }



}
node*dugumOlustur(char kelime[], int adet)
{ //bize bir dugum olusturuyor
    node*dugum=(node*)malloc(sizeof(node));
    strcpy(dugum->kelime,kelime);
    dugum->kelime[sizeof(dugum->kelime)]='\0';
    dugum->adet=adet;
    dugum->next=NULL;
    return dugum;

}

void basaEkle(node*eklenecek)
{
    eklenecek->next=root;
    root=eklenecek;
}
void sonaEkle(node*r,node*eklenecek)
{
    while(r->next!=NULL)
        r=r->next;
    r->next=eklenecek;
    eklenecek->next=NULL;

}
void dugumdeAra( node*traverseDugum,node*geciciDugum)
{  //dugumde arama islemi yapiliyor eger varsa dugumde sona eklenmiyor adet artiyor ,yok ise sona ekleniyor
    traverseDugum=root;
    int flag=0;
    while(traverseDugum!=NULL)
    {
        int adetKonroller = traverseDugum->adet;
        if(strcmp(traverseDugum->kelime,geciciDugum->kelime) == 0 || strcmp(traverseDugum->kelime,geciciDugum->kelime)==NULL )
        {
            traverseDugum->adet++;
        }
        if(traverseDugum->adet!=adetKonroller)
        {
            flag=1;
            break;
        }
        traverseDugum=traverseDugum->next;


    }
    if(flag==0 )
        sonaEkle(root,geciciDugum);



}
int main()
{
    setlocale(LC_ALL,"Turkish");
    FILE*dosya;
    int i=0;
    char kelime[30];
    dosya=fopen("input.txt","r");
    if(dosya==NULL)
    {
        printf("dosya acilamadi");
        return 0;
    }
    while(!feof(dosya))
    {

        fscanf(dosya,"%s",kelime);
        geciciDugum=dugumOlustur(toLower(kelime),1);

        if(i==0)
        {      //ilk kelime icin dugum olusturuluyor
            basaEkle(geciciDugum);
            i++;
            continue;
        }
        dugumdeAra(traverseDugum,geciciDugum);

    }

    listeyiSirala(root);
    yazdir(root);
    printf("--------------------------------\nlistenin boyutu : %d\n",dugumBoyutu(root));
    fclose(dosya);

    return 0;
}
