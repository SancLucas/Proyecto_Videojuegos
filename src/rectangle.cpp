#include "sfml-utn-inspt.h"

class Rectangulo : public RectangleShape{
  public:
    Rectangulo(const Vector2f& size, const sf::Vector2f& position){
          setFillColor(Color::Cyan);
          setSize(size);
          setPosition(position);
      }
    Rectangulo(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color){
          setFillColor(color);
          setSize(size);
          setPosition(position);
      }
};