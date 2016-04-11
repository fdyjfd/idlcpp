import pafpython;
paf = pafpython.paf;

class Circle:
	def __init__(self):
		self.radius = 1.0
		self.shape =  paf.tutorial.Shape._Derive_(self);
	def getArea(self):
		return 3.1415926 * self.radius * self.radius;

circle = Circle();
circle.radius = 2.0;

shapeManager = paf.tutorial.ShapeManager.GetInstance();
shapeManager.addShape(circle.shape);
print(shapeManager.getTotalArea()._);

triangle = paf.tutorial.Triangle();
triangle.m_vertices[0] = paf.tutorial.Point(0,0);
triangle.m_vertices[1] = paf.tutorial.Point(0,1);
triangle.m_vertices[2] = paf.tutorial.Point(1,1);
shapeManager.addShape(triangle);
print(shapeManager.getTotalArea()._);
