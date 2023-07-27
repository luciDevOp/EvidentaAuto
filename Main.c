#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct {
    char nr_inmatriculare[8];
    char marca[30];
    char culoare[25];
    int nr_locuri;
    char combustibil[9];
    int c_cilindrica;
    char s_sasiu[18];
    int vechime;
    int km;
} autoturism;

void creare_fisier(char* fn) {
    FILE* f;
    autoturism a;
    f = fopen(fn, "wb");
    if (f == NULL) {
        printf("Eroare la crearea fisierului\n");
        exit(1);
    }
    printf("Introduceti numarul de inamtriculare sau -1 pentru terminare:");
    scanf("%s", a.nr_inmatriculare);
    while (strcmp(a.nr_inmatriculare, "-1")) {
        printf("Introduceti marca: ");
        scanf("%s",a.marca);
        printf("Introduceti culoarea: ");
        scanf("%s",a.culoare);
        printf("Introduceti numarul de locuri: ");
        scanf("%d",&a.nr_locuri);
        printf("Introduceti tipul de combustibil: ");
        scanf("%s",a.combustibil);
        printf("Introduceti capacitatea cilindrica a motorului: ");
        scanf("%d",&a.c_cilindrica);
        printf("Introduceti seria sasiului: ");
        scanf("%s",a.s_sasiu);
        printf("Introduceti vechimea: ");
        scanf("%d",&a.vechime);
        printf("Introduceti numarul de km parcursi: ");
        scanf("%d",&a.km);
        fwrite(&a, sizeof(a), 1, f);
        printf("Introduceti numarul de inmatriculare sau -1 pentru terminare:");
        scanf("%s", a.nr_inmatriculare);
    }
    fclose(f);
}

void listare_fisier(char* fn) {
    FILE * f;
    autoturism a;
    int nr_articole;
    f = fopen(fn,"rb");
    if(f == NULL) {
        printf("Nu s-a reusit deschiderea fisierului\n");
        exit(1);
    }
    nr_articole = fread(&a, sizeof(a), 1, f);
    while (nr_articole == 1) {
    printf("\n=============================");
        printf("\nNr inmatriculare: %s", a.nr_inmatriculare);
        printf("\nMarca: %s", a.marca);
        printf("\nCuloare: %s", a.culoare);
        printf("\nNumar locuri: %d", &a.nr_locuri);
        printf("\nTip combustibil: %s", a.combustibil);
        printf("\nCapacitate cilindrica: %d", &a.c_cilindrica);
        printf("\nSeria sasiu: %s", a.s_sasiu);
        printf("\nVechime: %d", &a.vechime);
        printf("\nNumar km: %d", &a.km);

        nr_articole = fread(&a, sizeof(a), 1, f);
    }
    fclose (f);
}

void adaugare_autoturism(char* fn) {
    FILE* f;
    autoturism a;
    f = fopen(fn, "ab");
    if(f == NULL) {
        printf("Nu s-a reusit deschiderea fisierului\n");
        exit(1);
    }
    printf("Introduceti numarul de inmatriculare sau -1 pentru terminare:");
    scanf("%s", a.nr_inmatriculare);
    while (strcmp(a.nr_inmatriculare, "-1")) {

        printf("Introduceti marca:");
        scanf("%s",a.marca);
        printf("Introduceti culoarea:");
        scanf("%s",a.culoare);
        printf("Introduceti numarul de locuri:");
        scanf("%d",&a.nr_locuri);
        printf("Introduceti tipul de combustibil:");
        scanf("%s",a.combustibil);
        printf("Introduceti capacitatea cilindrica:");
        scanf("%d",&a.c_cilindrica);
        printf("Introduceti seria sasiului:");
        scanf("%s",a.s_sasiu);
        printf("Introduceti vechimea:");
        scanf("%d",&a.vechime);
        printf("Introduceti numarul de km parcursi:");
        scanf("%d",&a.km);

        fwrite(&a, sizeof(a), 1, f);
        printf("Introduceti numarul de inmatriculare sau -1 pentru terminare:");
        scanf("%s", a.nr_inmatriculare);
    }
    fclose(f);
}

void modificarev(char* fn) {
    FILE * f;
    autoturism a;
    char nr_inmat;
    int pos = 0;
    int n_art = 0;
    f = fopen(fn,"rb+");
    if(f == NULL) {
        printf("Nu s-a reusit deschiderea fisierului\n");
        exit(1);
    }
    printf("\nIntroduceti numarul de inmatriculare al autoturismului a carei vechime doriti sa o modificati sau -1 pentru terminare:");
    scanf("%s", nr_inmat);
    while(nr_inmat != NULL) {
     do {
         n_art = fread(&a, sizeof(a), 1, f);
         if(strcmp(a.nr_inmatriculare, nr_inmat) ==0) {
             pos = ftell(f) - sizeof(a);
             break;
          }
     printf("\ndebug nart %d", n_art);
     } while(strcmp(a.nr_inmatriculare, nr_inmat) && n_art == 1);
     if(n_art <1) {
         printf("\nNu exista acest autoturism\n");
         break;
     }
     printf("\nIntroduceti vechimea:");
     scanf("%d", &a.vechime);
     fseek(f, pos, 0);
     fwrite(&a, sizeof(a), 1, f);
     printf("\nIntroduceti numarul de inmatriculare al autoturismului a carei vechime doriti sa o modificati sau -1 pentru terminare:");
     scanf("%s", nr_inmat);
     }
     fclose(f);
}



int main()
{
    char nf[200];
    printf("Introduceti numele fisierului unde se vor salva informatiile despre autoturisme:");
    scanf("%s", nf);
    creare_fisier(nf);
    printf("\nListare autoturisme\n");
    listare_fisier(nf);
    printf("\nAdaugare noi autoturisme\n");
    adaugare_autoturism(nf);
    printf("\nListare autoturisme\n");
    listare_fisier(nf);
    printf("\nModificare vechime\n");
    modificarev(nf);
    return 0;
}
