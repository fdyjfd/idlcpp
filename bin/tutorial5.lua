
Circle = {}
Circle.__index = Circle;

function Circle.New()
	circle= {radius = 1.0}
	setmetatable(circle, Circle);
	circle.shape = paf.tutorial.Shape._inherit_(circle);
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
