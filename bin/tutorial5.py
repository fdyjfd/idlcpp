import pafpython;
paf = pafpython.paf;

class Circle:
	def __init__(self):
		self.radius = 1.0
		self.shape =  paf.tutorial.Shape._inherit_(self);

circle = Circle();
circle.radius = 2.0;


i = paf.uint_t.New(0x12345678);
c = paf.short._cast_ptr_(i._address_);
print("%x" % i._);
print("%x" % i._address_._);
print("%x" % c[0]._);


shapeManager = paf.tutorial.ShapeManager.GetInstance();
shapeManager.addShape(circle.shape);
print(shapeManager.getTotalArea()._);

triangle = paf.tutorial.Triangle();
triangle.m_vertices[0] = paf.tutorial.Point(0,0);
triangle.m_vertices[1] = paf.tutorial.Point(0,1);
triangle.m_vertices[2] = paf.tutorial.Point(1,1);
shapeManager.addShape(triangle);
print(shapeManager.getTotalArea()._);
