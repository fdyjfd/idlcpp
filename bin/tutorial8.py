import pafpython;

paf = pafpython.paf;


def Indentation(count) : 
	res = "";
	for i in range(count) : 
		res = res +  "\t";
	return res;


def ListPrimitiveMember(var, indent, recursive) :
	count = var._getMemberCount_()._;
	for i in range(count) :
		member = var._getMember_(i);
		print(Indentation(indent) + member._name_._ + " : " + member._category_._name_._);

def ListEnumMember(var, indent, recursive) : 
	count = var._getEnumeratorCount_()._;
	for i in range(count) :
		member = var._getEnumerator_(i);
		print(Indentation(indent) + member._name_._ + " : " + '%d' % member._value_._);

def ListClassMember(var, indent, recursive) :
	count = var._getBaseClassCount_()._;
	for i in range(count) :
		baseClass = var._getBaseClass_(i);
		print(Indentation(indent) + ":" + baseClass._name_._);

	count = var._getMemberCount_(False)._;
	for i in range(count) :
		member = var._getMember_(i, False);
		print(Indentation(indent) + member._name_._ + " : " + member._category_._name_._);
		if recursive :
			ListMember(member, indent + 1, recursive);


def ListNamespaceMember(var, indent, recursive) : 
	count = var._getMemberCount_()._;
	for i in range(count) :
		member = var._getMember_(i);
		print(Indentation(indent) + member._name_._ + " : " + member._category_._name_._);
		if recursive :
			ListMember(member, indent + 1, recursive);


tab = {}
tab[paf.pafcore.Category.name_space._] = ListNamespaceMember;
tab[paf.pafcore.Category.class_type._] = ListClassMember;
tab[paf.pafcore.Category.primitive_type._] = ListPrimitiveMember;
tab[paf.pafcore.Category.enum_type._] = ListEnumMember;


def ListMember(var, indent, recursive) :
	if var._category_._ in tab : 
		tab[var._category_._](var, indent, recursive);


ListMember(paf,0,1);
