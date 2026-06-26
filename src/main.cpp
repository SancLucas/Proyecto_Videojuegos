#include "sfml-utn-inspt.h"
#include <SFML/Graphics.hpp>
#include "rectangle.cpp"
#include "ventana.cpp"


RectangleShape personaje = RectangleShape({60, 60});
const Vector2f POS_INICIAL_PERSONAJE(150, 290);
const float VELOCIDAD = 4.5f;

void leer_eventos(RenderWindow &ventana);
void salto();

float velocidadDelFondo = -0.05f;
int limiteSalto = 18;
int alturaSalto = -limiteSalto;
bool saltar = false;


int main(){
  RenderWindow ventana = RenderWindow({ANCHO_VENT, ALTO_VENT}, "Proyecto Maldito");
  ventana.setFramerateLimit(FRAMERATE);

  vector<RectanguloBack> cuadradoBack = {
      RectanguloBack({96.f, 160.f}, {0, 0}),
      RectanguloBack({540.f, 63.f}, {0, 225}),
      RectanguloBack({270.f, 40.f}, {20, 170}),
      RectanguloBack({192.f, 112.f}, {110, 48}),
      RectanguloBack({115.f, 64.f}, {310, 0}),
      RectanguloBack({80.f, 70.f}, {310, 50}),
      RectanguloBack({120.f, 80.f}, {310, 130}),
      RectanguloBack({80.f, 64.f}, {440, 0}),
      RectanguloBack({100.f, 96.f}, {440, 100}),
      RectanguloBack({112.f, 288.f}, {550, 0}),
      RectanguloBack({80.f, 128.f}, {680, 0}),
      RectanguloBack({150.f, 63.f}, {680, 140}),
      RectanguloBack({150.f, 63.f}, {680, 220}),
      RectanguloBack({176.f, 112.f}, {785, 0}),
      RectanguloBack({150.f, 155.f}, {840, 130}),
      RectanguloBack({200.f, 200.f}, {1000, 0}),
      RectanguloBack({200.f, 63.f}, {1000, 220}),
  };

  vector<RectanguloBack> obstaculos = {
      RectanguloBack({200.f, 50.f}, {1000, 300}),
      RectanguloBack({200.f, 50.f}, {1500, 300}),
  };

  RectanguloBack suelo = RectanguloBack({1200, 50}, {0, 340}, Color::Green);
  personaje.setPosition(POS_INICIAL_PERSONAJE);

  while (ventana.isOpen()){
    leer_eventos(ventana);
    if(saltar == true) salto();

    // esperarColision();





    // Movimiento del fondo
    for (int i = 0; i < cuadradoBack.size(); i++)
    {
      if (cuadradoBack[0].getPosition().x < -1210)
        cuadradoBack[i].move(1210, 0);
      cuadradoBack[i].move(velocidadDelFondo, 0);
    }

    // Siempre se borra la pantalla anterior
    ventana.clear(sf::Color::Blue);

    // Se dibujan los elementos:
    for (RectanguloBack rectagulo : cuadradoBack){
      ventana.draw(rectagulo);
    }
    for (RectanguloBack rectagulo : cuadradoBack){
      rectagulo.move(1210, 0);
      ventana.draw(rectagulo);
    }

    for (int j = 0; j < obstaculos.size(); j++){
      obstaculos[j].move(-2.5, 0);
      ventana.draw(obstaculos[j]);
    }

    ventana.draw(suelo);
    ventana.draw(personaje);

    // Se muestra la pantalla con los elementos dibujados sobre ella:
    ventana.display();
  }
}

void leer_eventos(RenderWindow &ventana){
  // Se "leen" los eventos y se guardan en event.
  Event event = Event();

  // Se recorren los eventos hasta que ya no hayan más
  while (ventana.pollEvent(event)){
    if (event.type == Event::Closed) ventana.close();

    if (Keyboard::isKeyPressed(Keyboard::Space)) saltar = true;
  }
}

void salto(){
  personaje.move(0, alturaSalto);
  if (alturaSalto < limiteSalto)
    alturaSalto++;
  else if (alturaSalto == limiteSalto){
    alturaSalto = -limiteSalto;
    saltar = false;
  }
}