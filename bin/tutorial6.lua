v1 = paf.tutorial.Vector3f(1,1,2);
v1.z = 1;
print(v1.length._);

v2 = paf.tutorial.Vector3d(2,2,1);
v2.v[2] = 2;
print(v2:getLength()._);
