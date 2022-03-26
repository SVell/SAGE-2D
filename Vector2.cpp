//
// Created by user on 3/26/2022.
//

#include "Vector2.h"

Vector2::Vector2() {
    x = 0;
    y = 0;
}

Vector2::Vector2(float x, float y) {
    this->x = x;
    this->y = y;
}

Vector2& Vector2::Add(const Vector2 vector) {
    this->x += vector.x;
    this->y += vector.y;

    return *this;
}

Vector2& Vector2::Subtract(const Vector2 vector) {
    this->x -= vector.x;
    this->y -= vector.y;

    return *this;
}

Vector2& Vector2::Multiply(const Vector2 vector) {
    this->x *= vector.x;
    this->y *= vector.y;

    return *this;
}

Vector2& Vector2::Divide(const Vector2 vector) {
    this->x /= vector.x;
    this->y /= vector.y;

    return *this;
}

Vector2& operator+(Vector2 &v1, const Vector2 &v2) {
    return v1.Add(v2);
}

Vector2& operator-(Vector2 &v1, const Vector2 &v2) {
    return v1.Subtract(v2);
}

Vector2& operator*(Vector2 &v1, const Vector2 &v2) {
    return v1.Multiply(v2);
}

Vector2& operator/(Vector2 &v1, const Vector2 &v2) {
    return v1.Divide(v2);
}

Vector2& Vector2::operator+=(const Vector2 &vector) {
    return this->Add(vector);
}

Vector2& Vector2::operator-=(const Vector2 &vector) {
    return this->Subtract(vector);
}

Vector2& Vector2::operator*=(const Vector2 &vector) {
    return this->Multiply(vector);
}

Vector2& Vector2::operator/=(const Vector2 &vector) {
    return this->Divide(vector);
}

std::ostream &operator<<(std::ostream &stream, const Vector2 vector) {
    stream << "(" << vector.x << ", " << vector.y << ")";
    return stream;
}
