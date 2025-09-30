
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// defindere velkomst besked
const char velkomne_besked[] = " velkomen til 🪨 📜 ✂️ 🦎 🖖\n";
// starter variablen briger_indpu
char bruger_indput[150];
// bruger indputtet til spilet
int BI_spil = 0;
// RNG værdien der bruges til maskines valg i spilet
int maskine_spil = 0;
// starter variabel wl som bruges ti at starte og stoppe while loopet
int wl = 1;
// sætter en variabel som bruges til at se om spillet skal køre
int gamemode = 0;
// brugeres point
int Bpoint = 0;
// maskines point
int Mpoint = 0;

int main() {
  srand(time(NULL));

  // sprinter velkomst besked
  printf(velkomne_besked);
  // starter et whil loop
  while (wl == 1) {
    // printer "menuen"
    printf("vælg\n");
    printf("(s) singelpalyer \n(e) forlad progamet\n");
    printf(":");
    // henter første bruger indput
    fgets(bruger_indput, sizeof(bruger_indput), stdin);
    // Remove trailing newline if present
    size_t len = strlen(bruger_indput);
    if (len > 0 && bruger_indput[len - 1] == '\n') {
      bruger_indput[len - 1] = '\0';
    }
    // anlysere første bruger indput
    if (stricmp(bruger_indput, "e") == 0) { // er indput e
      // printer forvel besked
      printf("forlader program");
      // stopper while loopet
      wl = 0;
    }
    if (stricmp(bruger_indput, "s") == 0) { // er indput s
      // skriver bedsked som hviser at spilet starter
      printf("starter spilet 🎆\n");
      // stopper while loopet
      gamemode = 1;
      wl = 0;

    } else {
      // ellers printer den fejl besked og stater om ved menu
      printf("genkedener ikke indput proev igen \n");
    }
  }
  while (gamemode == 1) {
    // printer spil menuen (hvad kan man vælge)
    printf("vælg en:\n");
    printf("0=🪨 1=📜 2=✂️ 3=🦎 4=🖖\n");
    // modtager brugerens valg ud fra spil menuen, som en integer.
    scanf("%d", &BI_spil);
    // her finder vi computerens tlifældige indput.
    // først sætter vi et seed = tiden så det forskeligt værgang
    srand(time(NULL));
    // vi bruger så det seed til at genrare et tilfældigt tal mellem 0-2
    // og lagre det i variblen maskine_spil
    maskine_spil = rand() % 3;
    // v
    if (BI_spil > 4) {
      printf("forket indput\n");
    } else {
      // swhitchen her regner subtration af BI_spil og maskine_spil
      // den bruger så resultattet til at vælge den case der gælder
      switch (BI_spil - maskine_spil) {
      case (-4):
        printf("2 \n maskine vinder ❌n");
        ++Mpoint;
        break;
      case (-3):
        printf("-2 \nbruger vinder ✅\n");
        ++Bpoint;
      case (-2):
        printf("2 \n maskine vinder ❌n");
        ++Mpoint;
        break;
      case (-1):
        printf("-2 \nbruger vinder ✅\n");
        ++Bpoint;
        break;
      case (0):
        printf("uafhgjort \n");
        break;
      case (1):
        printf("1 \nbruger vinder ✅\n");
        ++Bpoint;
        break;
      case (2):
        printf("2 \n maskine vinder ❌n");
        ++Mpoint;
        break;
      case (3):
        printf("1 \nbruger vinder ✅\n");
        ++Bpoint;
        break;
      case (4):
        printf("2 \n maskine vinder ❌n");
        ++Mpoint;
      }
    }
    // printer stilingen
    printf("stilinger er B %d : M %d \n", Bpoint, Mpoint);
    // tjerker om om der er nogen der har fået nok point til at vinde
    if (Bpoint == 3 || Mpoint == 3) {
      // tjeker hvem der har vundet og print en pasende besked
      if (Bpoint == 3) {
        printf("tillykke med sejeren 🥇 🎉\n");
      } else {
        printf("whomp whomp du tabte 😢\n");
      }
      // hvis der er nogende har vundet stopper den while loopet
      gamemode = 0;
    }
  }
}