
rect1 = paf.tutorial.Rectangle();
rect1.m_min.x = 1;
rect1.m_min.y = 2;

print(rect1.left._);
print(rect1.bottom._);

rect1.right = 3;
rect1.top = 4;

print(rect1.m_max.x._);
print(rect1.m_max.y._);

print(rect1.area._);

rect2 = paf.tutorial.Rectangle(rect1.m_min, paf.tutorial.Point(5,5));
print(rect2:getArea()._);

rect3 = paf.tutorial.Rectangle.Clone(rect2);
print(rect3:getArea()._);
