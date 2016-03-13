import pafpython;
paf = pafpython.paf;

triangle = paf.tutorial.Triangle();
triangle.m_vertices[0] = paf.tutorial.Point(0,0);
triangle.m_vertices[1] = paf.tutorial.Point(0,1);
triangle.m_vertices[2] = paf.tutorial.Point(1,1);

shapeManager = paf.tutorial.ShapeManager.GetInstance();
shapeManager.addShape(triangle);
print(shapeManager.getTotalArea()._);
