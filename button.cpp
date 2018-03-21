#include "button.h"


Button::Button(){
    this->window = 0;
    this->pressed_inner_color = sf::Color::Green;
    this->pressed_outer_color = sf::Color::White;
    this->hovered_inner_color = sf::Color::Green;
    this->hovered_outer_color = sf::Color::White;
    this->normal_inner_color = sf::Color::Green;
    this->normal_outer_color = sf::Color::White;
    this->normal_text_color = sf::Color::Black;
    this->hovered_text_color = sf::Color::Black;
    this->hovered_text_color = sf::Color::Black;
    this->displayed_shape = sf::RectangleShape();
    this->size = sf::Vector2f(0,0);
    this->position = sf::Vector2f(100,100);
    this->indent = 1;
    this->on_click = 0;
    this->on_release = 0;
    this->is_pressed = false;
    this->outline_thickness = 1;
    this->font = sf::Font();
    this->font.loadFromFile("arial.ttf");
    this->text = sf::Text("", font);
    this->state = NORMAL;
    this->is_visible = true;
    this->is_toggle = false;
    this->font_size = 30;
}

Button::Button(sf::RenderWindow &window, sf::Vector2f position, sf::Vector2f size, void (*on_click)(GUIObject *)){
    this->window = &window;
    this->position = position;
    this->size = size;
    this->on_click = on_click;
    
    this->on_release = 0;
    this->pressed_inner_color = sf::Color::Green;
    this->pressed_outer_color = sf::Color::White;
    this->hovered_inner_color = sf::Color::Green;
    this->hovered_outer_color = sf::Color::White;
    this->normal_inner_color = sf::Color::Green;
    this->normal_outer_color = sf::Color::White;
    this->normal_text_color = sf::Color::Black;
    this->hovered_text_color = sf::Color::Black;
    this->hovered_text_color = sf::Color::Black;
    this->displayed_shape = sf::RectangleShape(position);
    this->indent = 1;
    this->is_pressed = false;
    this->outline_thickness = 1;
    this->font = sf::Font();
    this->font.loadFromFile("arial.ttf");
    this->text = sf::Text("", font);
    this->state = NORMAL;
    this->is_visible = true;
    this->is_toggle = false;
    this->font_size = 30;
}

sf::Vector2f Button::getPosition() const{
    return position;
}

sf::Vector2f Button::getSize() const{
    return size;
}

ButtonState Button::getState() const{
    return state;
}

sf::Color Button::getNormalInnerColor() const{
    return normal_inner_color;
}

sf::Color Button::getHoveredInnerColor() const{
    return hovered_inner_color;
}

sf::Color Button::getPressedInnerColor() const{
    return pressed_inner_color;
}

sf::Color Button::getNormalOuterColor() const{
    return normal_outer_color;
}

sf::Color Button::getHoveredOuterColor() const{
    return hovered_outer_color;
}

sf::Color Button::getPressedOuterColor() const{
    return pressed_outer_color;
}

sf::Color Button::getNormalTextColor() const{
    return normal_text_color;
}

sf::Color Button::getHoveredTextColor() const{
    return hovered_text_color;
}

sf::Color Button::getPressedTextColor() const{
    return pressed_text_color;
}

sf::Text Button::getText() const{
    return text;
}

sf::Font Button::getFont() const{
    return font;
}

uint Button::getIndent() const{
    return indent;
}

uint Button::getOutlineThikness() const{
    return outline_thickness;
}

Action Button::getOnClick() const{
    return on_click;
}

Action Button::getOnRelease() const{
    return on_release;
}

void Button::setPosition(const sf::Vector2f position){
    this->position = position;
}

void Button::setSize(const sf::Vector2f size){
    this->size = size;
}

void Button::setNormalInnerColor(const sf::Color color){
    this->normal_inner_color = color;
}

void Button::setHoveredInnerColor(const sf::Color color){
    this->hovered_inner_color = color;
}

void Button::setPressedInnerColor(const sf::Color color){
    this->pressed_inner_color = color;
}

void Button::setNormalOuterColor(const sf::Color color){
    this->normal_outer_color = color;
}

void Button::setHoveredOuterColor(const sf::Color color){
    this->hovered_outer_color = color;
}

void Button::setPressedOuterColor(const sf::Color color){
    this->pressed_outer_color = color;
}

void Button::setNormalTextColor(const sf::Color color){
    this->normal_text_color = color;
}

void Button::setHoveredTextColor(const sf::Color color){
    this->hovered_text_color = color;
}

void Button::setPressedTextColor(const sf::Color color){
    this->pressed_text_color = color;
}

void Button::setText(const std::string text){
    this->text = sf::Text(text, font);
}

void Button::setText(const sf::Text text){
    this->text = text;
}

void Button::setFont(const std::string load_from){
    this->font = sf::Font();
    this->font.loadFromFile(load_from);
}

void Button::setFont(const sf::Font font){
    this->font = font;
}

void Button::setIndent(uint indent){
    this->indent = indent;
}

void Button::setOutlineThickness(uint outline_thickness){
    this->outline_thickness = outline_thickness;
}

void Button::setFontSize(uint size){
    this->font_size = size;
}

void Button::setOnClick(const Action click){
    this->on_click = click;
}

void Button::setOnRelease(const Action release){
    this->on_release = release;
}

void Button::setToggle(const bool is_toggle){
    this->is_toggle = is_toggle;
}

void Button::update(sf::Event &event){
    
    if(sf::Mouse::getPosition(*window).x > this->position.x
            && sf::Mouse::getPosition(*window).x < this->position.x+this->size.x
            && sf::Mouse::getPosition(*window).y > this->position.y
            && sf::Mouse::getPosition(*window).y < this->position.y+this->size.y){
        this->state = HOVERED;
    }
    else
        this->state = NORMAL;
    if((this->state == HOVERED) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        this->state = PRESSED;
    
    if(this->state == PRESSED && !is_pressed && this->on_click != 0){
        on_click(this);
    }
    else if((this->state == NORMAL || this->state == HOVERED)
            && is_pressed && this->on_release != 0){
        on_release(this);
    }
    
    this->is_pressed = (this->state == PRESSED);
    
    //draw
    switch (state) {
    case NORMAL:
        this->displayed_shape.setFillColor(normal_inner_color);
        this->displayed_shape.setOutlineColor(normal_outer_color);
        this->displayed_shape.setPosition(position);
        this->displayed_shape.setSize(size);
        this->displayed_shape.setOutlineThickness(outline_thickness);
        this->text.setFont(font);
        this->text.setColor(normal_text_color);
        break;
    case HOVERED:
        this->displayed_shape.setFillColor(hovered_inner_color);
        this->displayed_shape.setOutlineColor(hovered_outer_color);
        this->displayed_shape.setPosition(position);
        this->displayed_shape.setSize(size);
        this->displayed_shape.setOutlineThickness(outline_thickness);
        this->text.setFont(font);
        this->text.setColor(hovered_text_color);
        break;
    case PRESSED:
        this->displayed_shape.setFillColor(normal_inner_color);
        this->displayed_shape.setOutlineColor(normal_outer_color);
        this->displayed_shape.setPosition(sf::Vector2f(this->position.x+indent, this->position.y+indent));
        this->displayed_shape.setSize(sf::Vector2f(this->size.x-2*indent,this->size.y-2*indent));
        this->displayed_shape.setOutlineThickness(outline_thickness);
        this->text.setFont(font);
        this->text.setColor(pressed_text_color);
        break;
    }
    this->text.setCharacterSize(font_size);
    this->text.setPosition(position.x+size.x/2-text.getGlobalBounds().width/2,
                           position.y+size.y/2-text.getGlobalBounds().height/4*3);
    
    window->draw(displayed_shape);
    window->draw(text);
    
}










