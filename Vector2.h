#ifndef INC_2DGAMEENGINE_VECTOR2_H
#define INC_2DGAMEENGINE_VECTOR2_H

#include <iostream>

class Vector2 {

public:
    float x;
    float y;

    Vector2();
    Vector2(float x, float y);

    Vector2& Add(const Vector2 vector);
    Vector2& Subtract(const Vector2 vector);
    Vector2& Multiply(const Vector2 vector);
    Vector2& Divide(const Vector2 vector);

    friend Vector2& operator+(Vector2& v1, const Vector2& v2);
    friend Vector2& operator-(Vector2& v1, const Vector2& v2);
    friend Vector2& operator*(Vector2& v1, const Vector2& v2);
    friend Vector2& operator/(Vector2& v1, const Vector2& v2);

    Vector2& operator+=(const Vector2& vector);
    Vector2& operator-=(const Vector2& vector);
    Vector2& operator*=(const Vector2& vector);
    Vector2& operator/=(const Vector2& vector);

    friend std::ostream& operator<<(std::ostream& stream, const Vector2 vector);
};


#endif //INC_2DGAMEENGINE_VECTOR2_H
