#include "LevelBase.h"

LevelBase::LevelBase(){}
LevelBase::~LevelBase(){}

void LevelBase::update(){
    this->updateEntidade();
    this->updateColisao();
}

