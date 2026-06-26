#include "sfml-utn-inspt.h"

class RectanguloBack : public RectangleShape{
  public:
    RectanguloBack(const Vector2f& size){
          setFillColor(Color::Cyan);
          setSize(size);
    }
    RectanguloBack(const Vector2f& size, const sf::Vector2f& position){
          setFillColor(Color::Cyan);
          setSize(size);
          setPosition(position);
    }
    RectanguloBack(const Vector2f& size, const Color color){
          setFillColor(color);
          setSize(size);
    }
    RectanguloBack(const sf::Vector2f& size, const sf::Vector2f& position, const sf::Color color){
          setFillColor(color);
          setSize(size);
          setPosition(position);
    }
};