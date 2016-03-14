
ray = paf.tutorial.Ray3f(paf.tutorial.Vector3f(0,0,0), paf.tutorial.Vector3f(1,2,3));
pt = paf.tutorial.Vector3f(0,0,0);
ray:getPoint(pt, 2);
print(pt.x._);
print(pt.y._);
print(pt.z._);
pt = ray:getPoint(3);
print(pt.x._);
print(pt.y._);
print(pt.z._);
