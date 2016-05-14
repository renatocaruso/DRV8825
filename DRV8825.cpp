/*
Polulu DRV8825
10/2015 - Belo Horizonte
Renato Caruso (facebook/renatocarusos)
"Thanks Felipe"
*/
#include "DRV8825.h"
DRV8825::DRV8825(int pas, int sen) 
{
  pinMode( pas, OUTPUT);
  pinMode( sen, OUTPUT);
  this-> _pas = pas;
  this-> _sen = sen;
  _mode = 0;
}
DRV8825::DRV8825(int pas, int sen, int mo0, int mo1, int mo2, int slp) 
{
  pinMode( pas, OUTPUT);
  pinMode( sen, OUTPUT);
  pinMode( mo0, OUTPUT);
  pinMode( mo1, OUTPUT);
  pinMode( mo2, OUTPUT);
  pinMode( slp, OUTPUT);
  this-> _pas = pas;
  this-> _sen = sen;
  this-> _mo0 = mo0;
  this-> _mo1 = mo1;
  this-> _mo2 = mo2;
  this-> _slp = slp;
  _mode = 1;
  DRV8825::ativa();
}
void DRV8825::ativa(){
  digitalWrite(_slp, HIGH);
}
void DRV8825::desativa(){
  digitalWrite(_slp, LOW);
}
void DRV8825::marche(int antih, int fracao)
{
switch (_mode)
{
case 0:
  switch (antih) {
    case 1: digitalWrite(_sen, LOW); digitalWrite(_pas, HIGH); digitalWrite(_pas, LOW);  break;
    case 0: digitalWrite(_sen, HIGH); digitalWrite(_pas, HIGH); digitalWrite(_pas, LOW); break;
  }
  break;

case 1:
  if (fracao > 5 || fracao < 0) {
    fracao = 0;
  }
  switch (antih)
  {
    case 1:
      switch (fracao) {
        case 0:
          digitalWrite(_mo0, LOW);
          digitalWrite(_mo1, LOW);
          digitalWrite(_mo2, LOW);
          digitalWrite(_sen, LOW);
          digitalWrite(_pas, HIGH);
          digitalWrite(_pas, LOW);
          break;
        case 1:
          digitalWrite(_mo0, HIGH);
          digitalWrite(_mo1, LOW);
          digitalWrite(_mo2, LOW);
          digitalWrite(_sen, LOW);
          digitalWrite(_pas, HIGH);
          digitalWrite(_pas, LOW);
          break;
        case 2:
          digitalWrite(_mo0, LOW);
          digitalWrite(_mo1, HIGH);
          digitalWrite(_mo2, LOW);
          digitalWrite(_sen, LOW);
          digitalWrite(_pas, HIGH);
          digitalWrite(_pas, LOW);
          break;
        case 3:
          digitalWrite(_mo0, HIGH);
          digitalWrite(_mo1, HIGH);
          digitalWrite(_mo2, LOW);
          digitalWrite(_sen, LOW);
          digitalWrite(_pas, HIGH);
          digitalWrite(_pas, LOW);
          break;
        case 4:
          digitalWrite(_mo0, LOW);
          digitalWrite(_mo1, LOW);
          digitalWrite(_mo2, HIGH);
          digitalWrite(_sen, LOW);
          digitalWrite(_pas, HIGH);
          digitalWrite(_pas, LOW);
          break;
        case 5:
          digitalWrite(_mo0, HIGH);
          digitalWrite(_mo1, HIGH);
          digitalWrite(_mo2, HIGH);
          digitalWrite(_sen, LOW);
          digitalWrite(_pas, HIGH);
          digitalWrite(_pas, LOW);
          break;
      }
      break;
    case 0:
      switch (fracao) {
        case 0:
          digitalWrite(_mo0, LOW);
          digitalWrite(_mo1, LOW);
          digitalWrite(_mo2, LOW);
          digitalWrite(_sen, HIGH);
          digitalWrite(_pas, HIGH);
          digitalWrite(_pas, LOW);
          break;
        case 1:
          digitalWrite(_mo0, HIGH);
          digitalWrite(_mo1, LOW);
          digitalWrite(_mo2, LOW);
          digitalWrite(_sen, HIGH);
          digitalWrite(_pas, HIGH);
          digitalWrite(_pas, LOW);
          break;
        case 2:
          digitalWrite(_mo0, LOW);
          digitalWrite(_mo1, HIGH);
          digitalWrite(_mo2, LOW);
          digitalWrite(_sen, HIGH);
          digitalWrite(_pas, HIGH);
          digitalWrite(_pas, LOW);
          break;
        case 3:
          digitalWrite(_mo0, HIGH);
          digitalWrite(_mo1, HIGH);
          digitalWrite(_mo2, LOW);
          digitalWrite(_sen, HIGH);
          digitalWrite(_pas, HIGH);
          digitalWrite(_pas, LOW);
          break;
        case 4:
          digitalWrite(_mo0, LOW);
          digitalWrite(_mo1, LOW);
          digitalWrite(_mo2, HIGH);
          digitalWrite(_sen, HIGH);
          digitalWrite(_pas, HIGH);
          digitalWrite(_pas, LOW);
          break;
        case 5:
          digitalWrite(_mo0, HIGH);
          digitalWrite(_mo1, HIGH);
          digitalWrite(_mo2, HIGH);
          digitalWrite(_sen, HIGH);
          digitalWrite(_pas, HIGH);
          digitalWrite(_pas, LOW);
          break;
      }
  }
  break;
}
}
