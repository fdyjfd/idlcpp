import pafpython;
paf = pafpython.paf;
File = paf.crt.File;

file = File.New("D:\\GitHub\\idlcpp\\bin\\tutorial9.py", "rb");
if (not file._isNullPtr_._) :
	file.seek(0, File.SeekFlag.seek_end);
	size = file.tell();
	file.seek(0, File.SeekFlag.seek_set);
	buf = paf.char.NewArray(size + 1);
	file.read(buf, size);
	buf[size] = 0;
	print(buf._);