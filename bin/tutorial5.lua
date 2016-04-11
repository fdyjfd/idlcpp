
Circle = {}
Circle.__index = Circle;

function Circle.New()
	circle= {radius = 1.0}
	setmetatable(circle, Circle);
	circle.shape = paf.tutorial.Shape._Derive_(circle);
	return circle;
end

function Circle:getArea()
	return self.radius * self.radius * 3.1415926;
end

circle = Circle.New();
circle.radius = 2.0;
shapeManager = paf.tutorial.ShapeManager.GetInstance();
shapeManager:addShape(circle.shape);
print(shapeManager:getTotalArea()._);

triangle = paf.tutorial.Triangle();
triangle.m_vertices[0] = paf.tutorial.Point(0,0);
triangle.m_vertices[1] = paf.tutorial.Point(0,1);
triangle.m_vertices[2] = paf.tutorial.Point(1,1);
shapeManager:addShape(triangle);
print(shapeManager:getTotalArea()._);
