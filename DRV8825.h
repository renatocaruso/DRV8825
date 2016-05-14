/*
Polulu DVR8825
10/2015 - Belo Horizonte
Renato Caruso (facebook/renatocarusos)
"Thanks Felipe"
*/
#ifndef DVR8825_h
#define DVR8825_h

#include "Arduino.h"

class DVR8825
{
  public:
    DVR8825(int pas, int sen);
  	DVR8825(int pas, int sen, int mo0, int mo1, int mo2);
    DVR8825(int pas, int sen, int mo0, int mo1, int mo2 , int slp);
    void marche(int antih, int fracao);
    void desativa();
    void ativa();
  private:
    int _pas;
    int _sen;
    int _mo0;
    int _mo1;
    int _mo2;
    int _slp;
    int _mode;
};
#endif
