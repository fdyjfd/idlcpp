
rect1 = paf.tutorial.Rectangle();
rect1.m_min.x = 1;
rect1.m_min.y = 2;

print(rect1.left);
print(rect1.bottom);

rect1.right = 3;
rect1.top = 4;

print(rect1.m_max.x);
print(rect1.m_max.y);

print(rect1.area);

rect2 = paf.tutorial.Rectangle(rect1.m_min, paf.tutorial.Point(5,5));
print(rect2:getArea());

rect3 = paf.tutorial.Rectangle.New(rect2);
print(rect3:getArea());
