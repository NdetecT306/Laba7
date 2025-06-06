#include <iostream>
#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;
//Координаты x и y для рисования.
sf::Vector2f rotate(sf::Vector2f point, float angle) {
    float x = point.x * cos(angle) - point.y * sin(angle);
    float y = point.x * sin(angle) + point.y * cos(angle);
    return sf::Vector2f(x, y);
}
//Движение для рисования кривой Коха
void koch(vector<sf::Vector2f>& points, sf::Vector2f start, sf::Vector2f end, int n) {
    if (n == 0) {
        points.push_back(start);
        points.push_back(end);
        return;
    }
    sf::Vector2f p1 = start + (end - start) / 3.0f;
    sf::Vector2f p2 = start + 2.0f * (end - start) / 3.0f;
    sf::Vector2f delta = p2 - p1;
    sf::Vector2f p3 = p1 + rotate(delta, -M_PI / 3.0f); 
    koch(points, start, p1, n - 1);
    koch(points, p1, p3, n - 1);
    koch(points, p3, p2, n - 1);
    koch(points, p2, end, n - 1);
}
//Открываем окно, задаем его размер, начальные координаты и вызываем рисовашку
int main() {
    int n = 5; 
    float Width = 800;
    float Height = 600;
    float lineLength = Width * 0.8; 
    float startX = (Width - lineLength) / 2.0; 
    float startY = Height / 2.0; 
    sf::Vector2f start(startX, startY + 100.0);  
    sf::Vector2f end(startX + lineLength, startY + 100.0); 
    vector<sf::Vector2f> kochPoints;
    koch(kochPoints, start, end, n);
    sf::RenderWindow window(sf::VideoMode(Width, Height), "Koch Curve");
    window.setFramerateLimit(60); 
    vector<sf::Vertex> lines;
    for (size_t i = 0; i < kochPoints.size() - 1; i++) {
        lines.push_back(sf::Vertex(kochPoints[i], sf::Color::White));
        lines.push_back(sf::Vertex(kochPoints[i + 1], sf::Color::White));
    }
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        for (size_t i = 0; i < lines.size(); i+=2) {
            window.draw(&lines[i], 2, sf::Lines);
        }
        window.display();
    }
    return 0;
}
