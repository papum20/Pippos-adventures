#include "physical.hpp"




Physical::Physical() {
    id = ID_DEFAULT;
    drawn = false;
    updated = false;

    //inizializza animation
    for(int i = 0; i < MAX_ANIMATIONS; i++) 
        animations[i] = NULL;
    animations_n = 0;
}

void Physical::copyPhysical(Physical B) {
    pos = B.pos;
    size = B.size;
    id = B.id;
    animations_n = B.animations_n;
    for(int i = 0; i < animations_n; i++) animations[i] = B.animations[i];
    current_animation = B.current_animation;
}

void Physical::update(pMap map) {
    updated = true;
}

void Physical::destroy() {
    // ELIMINA PUNTATORI ANIMAZIONI
    for(int i = 0; i < MAX_ANIMATIONS; i++)
        if(animations[i] != NULL) animations[i]->delete_list();
    // ELIMINA OGGETTO
    delete this;
}

void Physical::drawAtPosition(Cell scr[CAMERA_HEIGHT][CAMERA_WIDTH], Coordinate win_start, Coordinate win_size, Coordinate pos) {
    drawn = true;
}
void Physical::drawAtOwnPosition(Cell scr[CAMERA_HEIGHT][CAMERA_WIDTH], Coordinate win_start, Coordinate win_size) {
    drawAtPosition(scr, win_start, win_size, pos);
}

void Physical::next_animation(){
    animations[current_animation] = animations[current_animation]->next;
}


#pragma region BOOL_GET_SET
    bool Physical::isInanimate() {
        return id >= ID_INANIMATE_S && id <= ID_INANIMATE_E;
    }
    bool Physical::isCharacter() {
        return id == ID_PLAYER || (id >= ID_ENEMY_S && id <= ID_ENEMY_E);
    }
    bool Physical::isProjectile() {
        return id >= ID_PROJECTILE_S && id <= ID_PROJECTILE_E;
    }
    /*bool Physical::isItem() {
        return id >= ID_ITEM_S && id <= ID_ITEM_E;
    }*/
    bool Physical::isWeapon() {
        return id >= ID_WEAPON_S && id <= ID_WEAPON_E;
    }
    bool Physical::isArtifact() {
        return id >= ID_ITEM_DIFENSIVO_S && id <= ID_ITEM_DIFENSIVO_E;
    }
    bool Physical::isItemDifensivo() {
        return id >= ID_ARTIFACT_S && id <= ID_ARTIFACT_E;
    }
    bool Physical::isSword(){
        if(id==ID_WEAPON_SWORD)
            return true;
        else 
            return false;
    }
    bool Physical::isAxe(){
        if(id==ID_WEAPON_AXE)
            return true;
        else 
            return false;
    }
    bool Physical::isBow(){
        if(id==ID_WEAPON_BOW)
            return true;
        else 
            return false;
    }
    bool Physical::isRod(){
        if(id==ID_WEAPON_ROD)
            return true;
        else 
            return false;
    }
    bool Physical::isArmor(){
        if(id==ID_ITEM_DIFENSIVO_ARMOR)
            return true;
        else 
            return false;
    }
    bool Physical::isShield(){
        if(id==ID_ITEM_DIFENSIVO_SHIELD)
            return true;
        else 
            return false;
    }
    bool Physical::isHelm(){
        if(id==ID_ITEM_DIFENSIVO_HELM)
            return true;
        else 
            return false;
    }
    bool Physical::isBoots(){
        if(id==ID_ITEM_DIFENSIVO_BOOTS)
            return true;
        else 
            return false;
    }
    bool Physical::isNecklace(){
        if(id==ID_ITEM_DIFENSIVO_NECKLACE)
            return true;
        else 
            return false;
    }
    bool Physical::isPotion(){
        if(id==ID_ARTIFACT_POTION)
            return true;
        else 
            return false;
    }
    bool Physical::isRune(){
        if(id==ID_ARTIFACT_RUNE)
            return true;
        else 
            return false;
    }
    bool Physical::findInArray(pPhysical A[ROOM_AREA], int len) {
        bool found = false;
        int i = 0;
        while(!found && i < len) {
            if(A[i] == this) found = true;
            else i++;
        }
        return found;
    }
    bool Physical::animationMask(Coordinate pos) {
	    return getCurrentAnimation().at(pos) != CHAR_EMPTY;
    }
    
    int Physical::getId() {
        return id;
    }
    Coordinate Physical::getPosition() {
        return pos;
    }
    Coordinate Physical::getSize() {
        return size;
    }
    Coordinate Physical::getSpeed() {
        return speed;
    }
    Animation Physical::getCurrentAnimation() {
        return *animations[current_animation];
    }
    Coordinate Physical::lastFrameMovement() {
        return lastMove;
    }

    void Physical::setPosition(Coordinate pos) {
	this->pos = pos;
    } 
    void Physical::resetUpdate() {
        updated = false;
        drawn = false;
    }
#pragma endregion BOOL_GET_SET
