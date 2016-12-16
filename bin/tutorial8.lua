function Indentation(count)
	res = "";
	for i = 1, count do
		res = res .. "\t";
	end
	return res;
end

function ListPrimitiveMember(var, indent, recursive)
	count = var:_getMemberCount_()._;
	for i = 1, count do
		member = var:_getMember_(i - 1);
		print(Indentation(indent) .. member._name_._ .. " : " .. member._category_._name_._);
	end
end

function ListEnumMember(var, indent, recursive)
	count = var:_getEnumeratorCount_()._;
	for i = 1, count do
		member = var:_getEnumerator_(i - 1);
		print(Indentation(indent) .. member._name_._ .. " : " .. member._value_._);
	end
end

function ListClassMember(var, indent, recursive)
	count = var:_getBaseClassCount_()._;
	for i = 1, count do
		baseClass = var:_getBaseClass_(i - 1);
		print(Indentation(indent) .. baseClass._name_._);
	end
	count = var:_getMemberCount_(false)._;
	for i = 1, count do
		member = var:_getMember_(i - 1, false);
		print(Indentation(indent) .. member._name_._ .. " : " .. member._category_._name_._);
		if recursive then
			ListMember(member, indent + 1, recursive);
		end
	end
end

function ListNamespaceMember(var, indent, recursive)
	count = var:_getMemberCount_()._;
	for i = 1, count do
		member = var:_getMember_(i - 1);
		print(Indentation(indent) .. member._name_._ .. " : " .. member._category_._name_._);
		if recursive then
			ListMember(member, indent + 1, recursive);
		end
	end
end;

tab = {}
tab[paf.pafcore.Category.name_space._] = ListNamespaceMember;
tab[paf.pafcore.Category.class_type._] = ListClassMember;
tab[paf.pafcore.Category.primitive_type._] = ListPrimitiveMember;
tab[paf.pafcore.Category.enum_type._] = ListEnumMember;

function ListMember(var, indent, recursive)
	func = tab[var._category_._]
	if func then
		func(var, indent, recursive);
	end
end

function ListDerivedClass(var)
	it = var:_getFirstDerivedClass_();
	while (not it._isNullPtr_._)
	do
		cls = it:deref();
		print(cls._name_._);
		it = it:next();
	end
end

--ListMember(paf,0,1);
ListDerivedClass(paf.pafcore.Metadata);