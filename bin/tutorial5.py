import pafpython;
paf = pafpython.paf;

class Circle:
	def __init__(self):
		self.radius = 1.0
		self.shape =  paf.tutorial.Shape._inherit_(self);
	def getArea(self):
		return 3.1415926 * self.radius * self.radius;

circle = Circle();
circle.radius = 2.0;

shapeManager = paf.tutorial.ShapeManager.GetInstance();
shapeManager.addShape(circle.shape);
print(shapeManager.getTotalArea()._);
