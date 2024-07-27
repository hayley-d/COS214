//
// Created by hayley on 2024/07/27.
//

#ifndef D_H
#define D_H

#include "A.h"
#include "B.h"

class D : public B, public A {
public:
    D();
   ~D() override;
};



#endif //D_H
