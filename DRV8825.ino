#include "DRV8825.h"
                                       // DRV8825 motorA ( pin_passo, pin_direção );   ou 
DRV8825 motorA(1, 2, 10, 11, 12, 13);  // DRV8825 motorA ( pin_passo, pin_direção, pin_mo0, pin_mo1, pin_mo2, pin_sleep );

void setup() {

}

void loop() {
  motorA.marche(0, 0);                //  motorA.marche ( horario, passo_cheio ); 
                                      //     "  .   "   ( 1 = !horario, 1 = 1/2 );
                                      //                                2 = 1/4
                                      //                                3 = 1/8
                                      //                                4 = 1/16
                                      //                                5 = 1/32    
delay(2); // observar caracteristicas de rotação e ressonância
//motorA.desativa();  //  corta a energia das bobinas pra deixar o motor 'frouxo' (sem torque de retenção)
//motorA.ativa();     //  retoma
}
