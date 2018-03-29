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

window = Window.New();
window.button:raiseClick();
window.button.click._remove_(window, "onClick");
window.button:raiseClick();
