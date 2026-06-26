#include "sfml-utn-inspt.h"

const int ANCHO_VENT = 1200;
const int ALTO_VENT = 600;
const int FRAMERATE = 60;

// Tipo de dato custom, borde de la ventana, para detectar coliciones
enum borde_t{
  SUPERIOR,
  INFERIOR,
  IZQUIERDO,
  DERECHO
};