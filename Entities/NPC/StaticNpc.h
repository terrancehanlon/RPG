#ifndef STATICNPC_H
#define STATICNPC_H


#include "Npc.h"

class StaticNpc : Npc {


    public:
        StaticNpc() : Npc(){
            init();
        }

        void init(TextureManager *tm);



};

#endif