#include "necklace.hpp"
#include <cstring>

Collana::Collana (int dif, int d_mag, char rar[]):item_difensivi (dif, d_mag){
            if (strcmp(rar, "raro")==0){
                difesa_magica=difesa_magica+5;
            }
            if (strcmp (rar, "epico")==0){
                difesa_magica=difesa_magica+10;
            }
            if (strcmp (rar, "leggendario")==0){
                difesa_magica=difesa_magica+15;
                //funzione che da un potere oggetti difensivi
            }
}