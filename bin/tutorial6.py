import pafpython;
paf = pafpython.paf;

v1 = paf.tutorial.Vector3f.New(1,1,2);
v1.z = 1;
print(v1.length._);

v2 = paf.tutorial.Vector3d(1,1,2);
v2.v[2] = 1;
print(v1.getLength()._);
