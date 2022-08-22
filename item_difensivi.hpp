#ifndef ITEM_DIFENSIVI_HPP
#define ITEM_DIFENSIVI_HPP

#include "item.hpp"

class item_difensivo: public item{
    protected:
        int difesa_fisica_iniziale;
        int difesa_fisica;
        int difesa_magica_iniziale;
        int difesa_magica;
        bool is_equipped;
    public:
        item_difensivo(int dif_f, int dif_m, char rar[]);

        void apply_rune();
        void apply_rarity();
        virtual char get_type();
};

typedef item_difensivo* pItem_def;

#endif