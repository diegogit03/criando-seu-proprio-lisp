typedef struct {
  float x;
  float y;
} point;

point p;
p.x = 0.1;
p.y = 10.0;

float length = sqrt(p.x * p.x + p.y * p.y);