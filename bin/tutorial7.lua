p = paf.float.NewArray(3);
p[0] = 1;
p[1] = 2;
p[2] = 3;
ray = paf.tutorial.Ray3f(paf.tutorial.Vector3f.s_zero, paf.tutorial.Vector3f(p));
pt = paf.tutorial.Vector3f(0,0,0);
ray:getPoint(pt, 2);
print(pt.x);
print(pt.y);
print(pt.z);
pt = ray:getPoint(3);
print(pt.x);
print(pt.y);
print(pt.z);
