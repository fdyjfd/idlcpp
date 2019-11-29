Window = {}
Window.__index = Window;

function Window.New()
	window = {}
	setmetatable(window, Window);
	window.button = paf.tutorial.Button();
	window.callback = window.button.click._add_(window, "onClick");	
	return window;
end

function Window:onClick(sender)
	print("Window:onClick()" );
end

test = paf.tutorial.Test();
test.mp["a"] = 1;
test.mp["b"] = 2;

print(test.mp["a"]);
print(test.mp["b"]);

window = Window.New();
window.button:raiseClick();
--window.button.click._remove_(window, "onClick");
--window.button:raiseClick();
