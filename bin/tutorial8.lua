function Indentation(count)
	res = "";
	for i = 1, count do
		res = res .. "\t";
	end
	return res;
end

function ListPrimitiveMember(var, indent, recursive)
	count = var:_getMemberCount_();
	for i = 1, count do
		member = var:_getMember_(i - 1);
		print(Indentation(indent) .. member._name_ .. " : " .. member._category_._name_);
	end
end

function ListEnumMember(var, indent, recursive)
	count = var:_getEnumeratorCount_();
	for i = 1, count do
		member = var:_getEnumerator_(i - 1);
		print(Indentation(indent) .. member._name_ .. " : " .. member._value_);
	end
end

function ListClassMember(var, indent, recursive)
	count = var:_getBaseClassCount_();
	for i = 1, count do
		baseClass = var:_getBaseClass_(i - 1);
		print(Indentation(indent) .. baseClass._name_);
	end
	count = var:_getMemberCount_(false);
	for i = 1, count do
		member = var:_getMember_(i - 1, false);
		print(Indentation(indent) .. member._name_ .. " : " .. member._category_._name_);
		if recursive then
			ListMember(member, indent + 1, recursive);
		end
	end
end

function ListNamespaceMember(var, indent, recursive)
	count = var:_getMemberCount_();
	for i = 1, count do
		member = var:_getMember_(i - 1);
		print(Indentation(indent) .. member._name_ .. " : " .. member._category_._name_);
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
	while (it)
	do
		cls = it:deref();
		print(cls._name_);
		it = it:next();
	end
end

--print(paf.pafcore.Category.name_space._name_);
ListMember(paf,0,0);
--ListDerivedClass(paf.pafcore.Metadata);