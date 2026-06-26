#include "sfml-utn-inspt.h"
#include "ventana.cpp"

bool colision_con_ventana(const FloatRect &r, borde_t borde)
{
  switch (borde)
  {
  case SUPERIOR:
    return r.top <= 0;
  case INFERIOR:
    return (r.top + r.height) >= ALTO_VENT;
  case IZQUIERDO:
    return r.left <= 0;
  case DERECHO:
    return (r.left + r.width) >= ANCHO_VENT;
  }
  return false;
}